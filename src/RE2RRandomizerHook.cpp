#include "RE2RRandomizerHook.h"

HMODULE dllHandle;
FILE *stdoutLogFile;
ImmediateLogger *logger;

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
	switch (ul_reason_for_call)
	{
		case DLL_PROCESS_ATTACH:
		{
			DisableThreadLibraryCalls(hModule);
			SetThreadPriority(GetCurrentThread(), THREAD_PRIORITY_TIME_CRITICAL);
			if (Startup())
			{
				logger->LogMessage("[RE2R-R] DllMain (DLL_PROCESS_ATTACH) called.\n");
				dllHandle = hModule;
				CreateThread(NULL, 0, MainThread, NULL, 0, NULL);
			}
		}
	}

	return TRUE;
}

bool Startup()
{
	FILE *dummy;
	return (AllocConsole() || AttachConsole(ATTACH_PARENT_PROCESS)) && // CONIN$ & CONOUT$
	       !freopen_s(&dummy, "CONIN$", "r", stdin) &&
	       !freopen_s(&dummy, "CONOUT$", "w", stdout) &&
	       !freopen_s(&dummy, "CONOUT$", "w", stderr) &&
	       !fopen_s(&stdoutLogFile, "RE2R-Randomizer-stdout.log", "w") &&
	       (logger = new ImmediateLogger(stdoutLogFile)) != nullptr &&
	       MH_Initialize() == MH_OK;
}

void Shutdown()
{
	logger->LogMessage("[RE2R-R] Shutdown called.\n");
	MH_DisableHook(MH_ALL_HOOKS);
	MH_RemoveHook(MH_ALL_HOOKS);
	MH_Uninitialize();
	if (logger != nullptr)
	{
		delete logger;
		logger = nullptr;
	}
	fclose(stdoutLogFile);
	FreeConsole();
}

ItemPickup itemPickupFuncTarget = reinterpret_cast<ItemPickup>((uintptr_t)GetModuleHandleW(L"re2.exe") + ItemPickupFuncOffset);
ItemPickup itemPickupFunc = nullptr;

ItemPutDownKeep itemPutDownKeepFuncTarget = reinterpret_cast<ItemPutDownKeep>((uintptr_t)GetModuleHandleW(L"re2.exe") + ItemPutDownKeepFuncOffset);
ItemPutDownKeep itemPutDownKeepFunc = nullptr;

__stdcall void *HookItemPickup(void *param1, void *param2, void *param3, void *param4)
{
	uint32_t *itemId = (uint32_t *)(param3 + 0x70);   // R8
	uint8_t *idlocation = (uint8_t *)(param4 + 0x30); // R9
	logger->LogMessage("[RE2R-R] HookItemPickup called: %d (0x%x): 0x%x, 0x%x, 0x%x, 0x%x, 0x%x, 0x%x\n", *itemId, *itemId, idlocation[0], idlocation[1], idlocation[2], idlocation[3], idlocation[4], idlocation[5]);
	return itemPickupFunc(param1, param2, param3, param4);
}

__stdcall void HookItemPutDownKeep(void *param1, void *param2, void *param3)
{
	uint32_t *itemId = (uint32_t *)(param2 + 0x14); // RDI
	logger->LogMessage("[RE2R-R] HookItemPutDownKeep called: %d (0x%x)\n", *itemId, *itemId);
	itemPutDownKeepFunc(param1, param2, param3);
}

Present oPresent;
HWND window = FindWindow(L"via", L"RESIDENT EVIL 2");
WNDPROC oWndProc;
ID3D11Device *device;
ID3D11DeviceContext *deviceContext;
ID3D11RenderTargetView *mainRenderTargetView;
bool init = false;
bool isUIOpen = true;
UINT resizeWidth = 0U;
UINT resizeHeight = 0U;

void InitImGui(IDXGISwapChain *swapChain, ID3D11Device *device)
{
	device->GetImmediateContext(&deviceContext);
	ID3D11Texture2D *backBuffer;
	swapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID *)&backBuffer);
	device->CreateRenderTargetView(backBuffer, nullptr, &mainRenderTargetView);
	backBuffer->Release();
	oWndProc = (WNDPROC)SetWindowLongPtr(window, GWLP_WNDPROC, (LONG_PTR)WndProc);
	device->GetImmediateContext(&deviceContext);
	CreateRenderTarget(swapChain);
	ImGui::CreateContext();
	ImGuiIO &io = ImGui::GetIO();
	io.ConfigFlags |= ImGuiConfigFlags_NoMouseCursorChange | ImGuiConfigFlags_NavEnableKeyboard | ImGuiConfigFlags_NavEnableGamepad;
	ImGui_ImplWin32_Init(window);
	ImGui_ImplDX11_Init(device, deviceContext);
}

LRESULT __stdcall WndProc(const HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	if (ImGui_ImplWin32_WndProcHandler(hWnd, uMsg, wParam, lParam))
		return true;

	switch (uMsg)
	{
		case WM_SIZE:
			if (wParam == SIZE_MINIMIZED)
				return 0;
			resizeWidth = (UINT)LOWORD(lParam); // Queue resize
			resizeHeight = (UINT)HIWORD(lParam);
			return 0;
		case WM_SYSCOMMAND:
			if ((wParam & 0xfff0) == SC_KEYMENU) // Disable ALT application menu
				return 0;
			break;
		case WM_DESTROY:
			Shutdown();
			return 0;
	}

	return CallWindowProc(oWndProc, hWnd, uMsg, wParam, lParam);
}

HRESULT __stdcall hkPresent(IDXGISwapChain *swapChain, UINT syncInterval, UINT flags)
{
	if (!init)
	{
		if (SUCCEEDED(swapChain->GetDevice(__uuidof(ID3D11Device), (void **)&device)))
		{
			InitImGui(swapChain, device);
			init = true;
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

	// ImGui::Begin("ImGui Window");
	// ImGui::End();
	ImGui::ShowDemoWindow(&isUIOpen);

	ImGui::Render();

	deviceContext->OMSetRenderTargets(1, &mainRenderTargetView, NULL);
	ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());
	return oPresent(swapChain, syncInterval, flags);
}

static void **vtableDXGISwapChain = nullptr;
static void **vtableD3D11Device = nullptr;
static void **vtableD3D11DeviceContext = nullptr;

static void __stdcall SetVTables(void)
{
	logger->LogMessage("Start of SetVTables() 1.0\n");

	DXGI_SWAP_CHAIN_DESC sd;
	memset(&sd, 0, sizeof(sd));
	sd.BufferCount = 1;
	sd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	sd.OutputWindow = window;
	sd.SampleDesc.Count = 1;
	sd.Windowed = TRUE;
	sd.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;

	const D3D_FEATURE_LEVEL featureLevels[] = {D3D_FEATURE_LEVEL_10_1, D3D_FEATURE_LEVEL_11_0};
	IDXGISwapChain *dxgiSwapChain;
	ID3D11Device *d3d11Device;
	ID3D11DeviceContext *d3d11DeviceContext;
	if (D3D11CreateDeviceAndSwapChain(
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
	        &d3d11DeviceContext) == S_OK)
	{
		logger->LogMessage("Start of SetVTables() 1.1t\n");

		vtableDXGISwapChain = (void **)calloc(40, sizeof(void *));
		memcpy(vtableDXGISwapChain, *(void ***)dxgiSwapChain, 40 * sizeof(void *));

		vtableD3D11Device = (void **)calloc(43, sizeof(void *));
		memcpy(vtableD3D11Device, *(void ***)d3d11Device, 43 * sizeof(void *));

		vtableD3D11DeviceContext = (void **)calloc(144, sizeof(void *));
		memcpy(vtableD3D11DeviceContext, *(void ***)d3d11DeviceContext, 144 * sizeof(void *));

		dxgiSwapChain->Release();
		d3d11Device->Release();
		d3d11Device = nullptr;

		logger->LogMessage("Start of SetVTables() 1.2 (IDXGISwapChain::Present: %p, IDXGISwapChain1::Present1: %p)\n", vtableDXGISwapChain[8], vtableDXGISwapChain[22]);
	}
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

DWORD WINAPI MainThread(LPVOID lpThreadParameter)
{
	logger->LogMessage("[RE2R-R] Menu called.\n");
	SetThreadPriority(GetCurrentThread(), THREAD_PRIORITY_TIME_CRITICAL);

	MH_STATUS status;
	do
	{
		SetVTables();
	} while (!HookFunction<Present>((Present)vtableDXGISwapChain[8], (Present)hkPresent, &oPresent, status));
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
