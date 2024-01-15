#include "RE2RRandomizerHook.h"

HINSTANCE dllInstance;
HANDLE mainThreadHandle;
FILE *stdoutLogFile;
ImmediateLogger *logger;
RE2RRUI *re2rrUI;
bool allocedConsole = true;
bool attachedConsole = true;
void **vtableDXGISwapChain = nullptr;
void **vtableD3D11Device = nullptr;
void **vtableD3D11DeviceContext = nullptr;
void **vtableDirectInput8 = nullptr;
void **vtableDirectInputDevice8 = nullptr;
Present oPresent;
GetDeviceState oGetDeviceState;
GetDeviceData oGetDeviceData;
HWND window = FindWindow(L"via", L"RESIDENT EVIL 2");
WNDPROC oWndProc;
ID3D11Device *device;
ID3D11DeviceContext *deviceContext;
ID3D11RenderTargetView *mainRenderTargetView;
bool initPresent = false;
bool initGetDeviceStateKB = false;
bool initGetDeviceStateM1 = false;
bool initGetDeviceStateM2 = false;
bool initGetDeviceStateJ1 = false;
bool initGetDeviceStateJ2 = false;
bool isUIOpen = true;
UINT resizeWidth = 0U;
UINT resizeHeight = 0U;
ItemPickup itemPickupFuncTarget = reinterpret_cast<ItemPickup>((uintptr_t)GetModuleHandleW(L"re2.exe") + ItemPickupFuncOffset);
ItemPickup itemPickupFunc = nullptr;
ItemPutDownKeep itemPutDownKeepFuncTarget = reinterpret_cast<ItemPutDownKeep>((uintptr_t)GetModuleHandleW(L"re2.exe") + ItemPutDownKeepFuncOffset);
ItemPutDownKeep itemPutDownKeepFunc = nullptr;

BOOL APIENTRY DllMain(_In_ HINSTANCE hinstDLL, _In_ DWORD fdwReason, _In_ LPVOID UNUSED(lpvReserved))
{
	switch (fdwReason)
	{
		case DLL_PROCESS_ATTACH: // 1
		{
			DisableThreadLibraryCalls(hinstDLL);
			SetThreadPriority(GetCurrentThread(), THREAD_PRIORITY_TIME_CRITICAL);
			if (Startup())
			{
				logger->LogMessage("[RE2R-R] DllMain (DLL_PROCESS_ATTACH) called.\n");
				dllInstance = hinstDLL;
				mainThreadHandle = CreateThread(NULL, 0, MainThread, NULL, 0, NULL);
			}
			break;
		}
	}

	return TRUE;
}

DWORD WINAPI MainThread(LPVOID UNUSED(lpThreadParameter))
{
	logger->LogMessage("[RE2R-R] Menu called.\n");
	SetThreadPriority(GetCurrentThread(), THREAD_PRIORITY_TIME_CRITICAL);

	MH_STATUS status;
	do
	{
		SetVTables();
	} while (!HookFunction<Present>((Present)vtableDXGISwapChain[8], (Present)hkPresent, &oPresent, status));
	if (!HookFunction<GetDeviceState>((GetDeviceState)vtableDirectInputDevice8[9], (GetDeviceState)HookGetDeviceState, &oGetDeviceState, status))
		logger->LogMessage("[RE2R-R] Hook failed (HookGetDeviceState): %s\n", MH_StatusToString(status));
	if (!HookFunction<GetDeviceData>((GetDeviceData)vtableDirectInputDevice8[10], (GetDeviceData)HookGetDeviceData, &oGetDeviceData, status))
		logger->LogMessage("[RE2R-R] Hook failed (HookGetDeviceData): %s\n", MH_StatusToString(status));

	// HookGetDeviceData

	if (!HookFunction<ItemPickup>(itemPickupFuncTarget, (ItemPickup)HookItemPickup, &itemPickupFunc, status))
		logger->LogMessage("[RE2R-R] Hook failed (HookItemPickup): %s\n", MH_StatusToString(status));
	if (!HookFunction<ItemPutDownKeep>(itemPutDownKeepFuncTarget, (ItemPutDownKeep)HookItemPutDownKeep, &itemPutDownKeepFunc, status))
		logger->LogMessage("[RE2R-R] Hook failed (HookItemPutDownKeep): %s\n", MH_StatusToString(status));

	logger->LogMessage("[RE2R-R] Hooked.\n");

	logger->LogMessage("[RE2R-R] Usage:\n");
	logger->LogMessage("\t(F7): Toggle UI)\n");
	logger->LogMessage("\t(F8): Exit)\n");
	return TRUE;
}

DWORD WINAPI ShutdownThread(LPVOID UNUSED(lpThreadParameter))
{
	Sleep(100);
	FreeLibraryAndExitThread(dllInstance, 0);
	return 0;
}

bool Startup()
{
#if RE2RRDEBUGWINDOW == 1
	FILE *dummy;
	allocedConsole = AllocConsole();
	if (!allocedConsole)
		attachedConsole = AttachConsole(ATTACH_PARENT_PROCESS);
#endif
	return
#if RE2RRDEBUGWINDOW == 1
	    (allocedConsole || attachedConsole) && // CONIN$ & CONOUT$
	    !freopen_s(&dummy, "CONIN$", "r", stdin) &&
	    !freopen_s(&dummy, "CONOUT$", "w", stdout) &&
	    !freopen_s(&dummy, "CONOUT$", "w", stderr) &&
#endif
	    !fopen_s(&stdoutLogFile, "RE2RR_Core.log", "w") &&
	    (logger = new ImmediateLogger(stdoutLogFile)) != nullptr &&
	    (re2rrUI = new RE2RRUI(logger)) != nullptr &&
	    MH_Initialize() == MH_OK;
}

void Shutdown()
{
	logger->LogMessage("[RE2R-R] Shutdown called.\n");
	MH_DisableHook(MH_ALL_HOOKS);
	MH_RemoveHook(MH_ALL_HOOKS);
	MH_Uninitialize();
	ImGui_ImplDX11_Shutdown();
	ImGui_ImplWin32_Shutdown();
	ImGui::DestroyContext();
	CleanupRenderTarget();
	if (deviceContext)
	{
		deviceContext->Release();
		deviceContext = nullptr;
	}
	if (device)
	{
		device->Release();
		device = nullptr;
	}
	SetWindowLongPtr(window, GWLP_WNDPROC, (LONG_PTR)oWndProc);
	Sleep(100);
	if (re2rrUI != nullptr)
	{
		delete re2rrUI;
		re2rrUI = nullptr;
	}
	if (logger != nullptr)
	{
		delete logger;
		logger = nullptr;
	}
	fclose(stdoutLogFile);
	fclose(stdin);
	fclose(stdout);
	fclose(stderr);
#if RE2RRDEBUGWINDOW == 1
	if (allocedConsole)
		FreeConsole();
#endif
	CreateThread(NULL, 0, ShutdownThread, NULL, 0, NULL);
	TerminateThread(mainThreadHandle, 0);
}

__stdcall void *HookItemPickup(uint8_t *param1, uint8_t *param2, uint8_t *param3, uint8_t *param4)
{
	uint32_t *itemId = (uint32_t *)(param3 + 0x70);   // R8
	uint8_t *idlocation = (uint8_t *)(param4 + 0x30); // R9
	logger->LogMessage("[RE2R-R] HookItemPickup called: %d (0x%x): 0x%x, 0x%x, 0x%x, 0x%x, 0x%x, 0x%x\n", *itemId, *itemId, idlocation[0], idlocation[1], idlocation[2], idlocation[3], idlocation[4], idlocation[5]);
	return itemPickupFunc(param1, param2, param3, param4);
}

__stdcall void HookItemPutDownKeep(uint8_t *param1, uint8_t *param2, uint8_t *param3)
{
	uint32_t *itemId = (uint32_t *)(param2 + 0x14); // RDI
	logger->LogMessage("[RE2R-R] HookItemPutDownKeep called: %d (0x%x)\n", *itemId, *itemId);
	itemPutDownKeepFunc(param1, param2, param3);
}

void InitImGui(IDXGISwapChain *swapChain, ID3D11Device *device)
{
	// device->GetImmediateContext(&deviceContext);
	ID3D11Texture2D *backBuffer;
	swapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID *)&backBuffer);
	device->CreateRenderTargetView(backBuffer, nullptr, &mainRenderTargetView);
	backBuffer->Release();
	DWORD lastError = 0;
	SetLastError(lastError);
	oWndProc = (WNDPROC)SetWindowLongPtr(window, GWLP_WNDPROC, (LONG_PTR)WndProc);
	if ((oWndProc == nullptr) && ((lastError = GetLastError()) != 0))
		logger->LogMessage("Error in InitImGui() [SetWindowLongPtr]: %d (0x%lX)\n", lastError, lastError);
	device->GetImmediateContext(&deviceContext);
	CreateRenderTarget(swapChain);
	ImGui::CreateContext();
	ImGuiIO &io = ImGui::GetIO();
	io.ConfigFlags = ImGuiConfigFlags_NoMouseCursorChange | ImGuiConfigFlags_NavEnableKeyboard | ImGuiConfigFlags_NavEnableGamepad;
	io.IniFilename = "RE2RR_ImGui.ini";
	io.LogFilename = "RE2RR_ImGui.log";
	ImGui_ImplWin32_Init(window);
	ImGui_ImplDX11_Init(device, deviceContext);
}

LRESULT __stdcall WndProc(const HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	if (ImGui_ImplWin32_WndProcHandler(hWnd, uMsg, wParam, lParam))
		return true;

	switch (uMsg)
	{
		case WM_INPUT:
		{
			ImGuiIO &io = ImGui::GetIO();
			if (io.WantCaptureMouse) // Stop sending mouse input to the game if ImGui wants to capture it.
				return DefWindowProc(hWnd, uMsg, wParam, lParam);
			break;
		}

		case WM_KEYDOWN:
		{
			switch (wParam)
			{
				case VK_F7:
					isUIOpen = !isUIOpen;
					break;

				case VK_F8:
					Shutdown();
					break;
			}
			break;
		}

		case WM_SIZE:
		{
			if (wParam == SIZE_MINIMIZED)
				return DefWindowProc(hWnd, uMsg, wParam, lParam);
			resizeWidth = (UINT)LOWORD(lParam); // Queue resize
			resizeHeight = (UINT)HIWORD(lParam);
			// return DefWindowProc(hWnd, uMsg, wParam, lParam);
			break;
		}

		case WM_SYSCOMMAND:
		{
			if ((wParam & 0xfff0) == SC_KEYMENU) // Disable ALT application menu
				return DefWindowProc(hWnd, uMsg, wParam, lParam);
			break;
		}

		case WM_DESTROY:
		{
			Shutdown();
			return DefWindowProc(hWnd, uMsg, wParam, lParam);
		}
	}

	return CallWindowProc(oWndProc, hWnd, uMsg, wParam, lParam);
}

HRESULT __stdcall hkPresent(IDXGISwapChain *swapChain, UINT syncInterval, UINT flags)
{
	if (!initPresent)
	{
		if (SUCCEEDED(swapChain->GetDevice(__uuidof(ID3D11Device), (void **)&device)))
		{
			InitImGui(swapChain, device);
			initPresent = true;
		}
		else
			return oPresent(swapChain, syncInterval, flags);
	}

	ImGuiIO &io = ImGui::GetIO();
	if (io.AppFocusLost)
		io.MouseDrawCursor = false;
	else
		io.MouseDrawCursor = true;

	if (resizeWidth != 0 && resizeHeight != 0)
	{
		CleanupRenderTarget();
		swapChain->ResizeBuffers(0, resizeWidth, resizeHeight, DXGI_FORMAT_UNKNOWN, 0);
		resizeWidth = resizeHeight = 0;
		CreateRenderTarget(swapChain);
	}

	ImGui_ImplDX11_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();

	re2rrUI->DrawMainUI(&isUIOpen);
	// ImGui::ShowDemoWindow();

	ImGui::Render();

	deviceContext->OMSetRenderTargets(1, &mainRenderTargetView, NULL);
	ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());
	return oPresent(swapChain, syncInterval, flags);
}

HRESULT __stdcall HookGetDeviceState(IDirectInputDevice8 *device, DWORD cbData, LPVOID lpvData)
{
	if (!initGetDeviceStateKB && cbData == 256)
	{
		logger->LogMessage("HookGetDeviceState() -> KB Init\n");
		device->SetCooperativeLevel(window, DISCL_NONEXCLUSIVE | DISCL_FOREGROUND);
		initGetDeviceStateKB = true;
	}
	else if (!initGetDeviceStateM1 && cbData == sizeof(DIMOUSESTATE))
	{
		logger->LogMessage("HookGetDeviceState() -> Mouse 1 Init\n");
		device->SetCooperativeLevel(window, DISCL_NONEXCLUSIVE | DISCL_FOREGROUND);
		initGetDeviceStateM1 = true;
	}
	else if (!initGetDeviceStateM2 && cbData == sizeof(DIMOUSESTATE2))
	{
		logger->LogMessage("HookGetDeviceState() -> Mouse 2 Init\n");
		device->SetCooperativeLevel(window, DISCL_NONEXCLUSIVE | DISCL_FOREGROUND);
		initGetDeviceStateM2 = true;
	}
	else if (!initGetDeviceStateJ1 && cbData == sizeof(DIJOYSTATE))
	{
		logger->LogMessage("HookGetDeviceState() -> Joypad 1 Init\n");
		device->SetCooperativeLevel(window, DISCL_NONEXCLUSIVE | DISCL_FOREGROUND);
		initGetDeviceStateJ1 = true;
	}
	else if (!initGetDeviceStateJ2 && cbData == sizeof(DIJOYSTATE2))
	{
		logger->LogMessage("HookGetDeviceState() -> Joypad 2 Init\n");
		device->SetCooperativeLevel(window, DISCL_NONEXCLUSIVE | DISCL_FOREGROUND);
		initGetDeviceStateJ2 = true;
	}

	if (cbData == sizeof(DIMOUSESTATE))
	{
		DIMOUSESTATE *mouseData = (DIMOUSESTATE *)lpvData;
		for (int i = 0; i < 4; ++i)
			if (mouseData->rgbButtons[i] != 0)
				logger->LogMessage("HookGetDeviceState() -> Mouse 1: rgbButtons[%d] = 0x%X", i, mouseData->rgbButtons[i]);
	}
	else if (cbData == sizeof(DIMOUSESTATE2))
	{
		DIMOUSESTATE2 *mouseData = (DIMOUSESTATE2 *)lpvData;
		for (int i = 0; i < 8; ++i)
			if (mouseData->rgbButtons[i] != 0)
				logger->LogMessage("HookGetDeviceState() -> Mouse 2: rgbButtons[%d] = 0x%X", i, mouseData->rgbButtons[i]);
	}
	else if (cbData == sizeof(DIJOYSTATE))
	{
		DIJOYSTATE *joypadData = (DIJOYSTATE *)lpvData;
		for (int i = 0; i < 128; ++i)
			if (joypadData->rgbButtons[i] != 0)
				logger->LogMessage("HookGetDeviceState() -> Joypad 1: rgbButtons[%d] = 0x%X", i, joypadData->rgbButtons[i]);
	}
	else if (cbData == sizeof(DIJOYSTATE2))
	{
		DIJOYSTATE2 *joypadData = (DIJOYSTATE2 *)lpvData;
		for (int i = 0; i < 128; ++i)
			if (joypadData->rgbButtons[i] != 0)
				logger->LogMessage("HookGetDeviceState() -> Joypad 2: rgbButtons[%d] = 0x%X", i, joypadData->rgbButtons[i]);
	}

	return oGetDeviceState(device, cbData, lpvData);
}

// SEEMS UNUSED
HRESULT __stdcall HookGetDeviceData(IDirectInputDevice8 *device, DWORD cbObjectData, LPDIDEVICEOBJECTDATA rgdod, LPDWORD pdwInOut, DWORD dwFlags)
{
	// ImGuiIO &io = ImGui::GetIO();
	for (unsigned long i = 0; i < *pdwInOut; ++i)
	{
		for (unsigned long i = 0; i < 32; ++i)
			if (rgdod[i].dwOfs == (FIELD_OFFSET(DIMOUSESTATE, rgbButtons) + i) && rgdod[i].dwData != 0)
				logger->LogMessage("[MB%d]: %d", i, rgdod[i].dwData);
		for (unsigned long i = 0; i < 32; ++i)
			if (rgdod[i].dwOfs == DIJOFS_BUTTON(i) && rgdod[i].dwData != 0)
				logger->LogMessage("[JB%d]: %d", i, rgdod[i].dwData);
	}

	return oGetDeviceData(device, cbObjectData, rgdod, pdwInOut, dwFlags);
}

void __stdcall SetVTables(void)
{
	logger->LogMessage("SetVTables() 1.0\n");

	DXGI_SWAP_CHAIN_DESC sd;
	memset(&sd, 0, sizeof(sd));
	sd.BufferCount = 1;
	sd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	sd.OutputWindow = window;
	sd.SampleDesc.Count = 1;
	sd.Windowed = TRUE;
	sd.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;

	const D3D_FEATURE_LEVEL featureLevels[] = {D3D_FEATURE_LEVEL_11_1, D3D_FEATURE_LEVEL_11_0, D3D_FEATURE_LEVEL_10_1, D3D_FEATURE_LEVEL_10_0};
	IDXGISwapChain *dxgiSwapChain;
	ID3D11Device *d3d11Device;
	ID3D11DeviceContext *d3d11DeviceContext;
	IDirectInput8 *directInput8;
	IDirectInputDevice8 *directInputDevice8;
	HRESULT result;
	if ((result = D3D11CreateDeviceAndSwapChain(
	         nullptr,
	         D3D_DRIVER_TYPE_HARDWARE,
	         nullptr,
	         0,
	         featureLevels,
	         sizeof(featureLevels) / sizeof(D3D_FEATURE_LEVEL),
	         D3D11_SDK_VERSION,
	         &sd,
	         &dxgiSwapChain,
	         &d3d11Device,
	         nullptr,
	         &d3d11DeviceContext)) == S_OK &&
	    (result = DirectInput8Create(
	         dllInstance,
	         DIRECTINPUT_VERSION,
	         IID_IDirectInput8,
	         (void **)&directInput8,
	         NULL)) == DI_OK &&
	    (result = directInput8->CreateDevice(
	         GUID_SysKeyboard,
	         &directInputDevice8,
	         NULL)) == DI_OK)
	{
		logger->LogMessage("SetVTables() 1.1t\n");

		vtableDXGISwapChain = (void **)calloc(40, sizeof(void *));
		memcpy(vtableDXGISwapChain, *(void ***)dxgiSwapChain, 40 * sizeof(void *));

		vtableD3D11Device = (void **)calloc(43, sizeof(void *));
		memcpy(vtableD3D11Device, *(void ***)d3d11Device, 43 * sizeof(void *));

		vtableD3D11DeviceContext = (void **)calloc(144, sizeof(void *));
		memcpy(vtableD3D11DeviceContext, *(void ***)d3d11DeviceContext, 144 * sizeof(void *));

		vtableDirectInput8 = (void **)calloc(11, sizeof(void *));
		memcpy(vtableDirectInput8, *(void ***)directInput8, 11 * sizeof(void *));

		vtableDirectInputDevice8 = (void **)calloc(32, sizeof(void *));
		memcpy(vtableDirectInputDevice8, *(void ***)directInputDevice8, 32 * sizeof(void *));

		directInputDevice8->Release();
		directInput8->Release();
		d3d11DeviceContext->Release();
		d3d11Device->Release();
		dxgiSwapChain->Release();

		logger->LogMessage("SetVTables() 1.2 (IDXGISwapChain::Present: %p, IDXGISwapChain1::Present1: %p)\n", vtableDXGISwapChain[8], vtableDXGISwapChain[22]);
	}

	if (result != S_OK)
		logger->LogMessage("SetVTables() 1.1f (HRESULT %d (0x%lX))\n", result, result);
}

void CreateRenderTarget(IDXGISwapChain *swapChain)
{
	ID3D11Texture2D *backBuffer;
	swapChain->GetBuffer(0, IID_PPV_ARGS(&backBuffer));
	device->CreateRenderTargetView(backBuffer, nullptr, &mainRenderTargetView);
	backBuffer->Release();
}

void CleanupRenderTarget()
{
	if (mainRenderTargetView)
	{
		mainRenderTargetView->Release();
		mainRenderTargetView = nullptr;
	}
}
