#include "DllHook.h"

HINSTANCE dllInstance;
HANDLE mainThreadHandle;
bool startupSuccess;
FILE *stdoutLogFile;
std::unique_ptr<RE2RR::Common::Logging::UILog> uiLog;
std::unique_ptr<RE2RR::Common::Logging::ImmediateLogger> logger;
std::unique_ptr<RE2RR::Hook::UI::UI> ui;
void **vtableDXGISwapChain = nullptr;
void **vtableD3D11Device = nullptr;
void **vtableD3D11DeviceContext = nullptr;
void **vtableDirectInput8 = nullptr;
void **vtableDirectInputDevice8 = nullptr;
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
HWND window;
Present presentFunc;
GetDeviceState getDeviceStateFunc;
WNDPROC wndProcFunc;
ItemPickup itemPickupFuncTarget = nullptr;
ItemPickup itemPickupFunc = nullptr;
UIMapManagerUpdate uiMapManagerUpdateFuncTarget = nullptr;
UIMapManagerUpdate uiMapManagerUpdateFunc = nullptr;
RE2RR::Types::Enums::RE2RGameVersion gameVersion = RE2RR::Types::Enums::RE2RGameVersion::Unknown;
RE2RR::Types::Enums::RE2RGameEdition gameEdition = RE2RR::Types::Enums::RE2RGameEdition::Unknown;
RE2RR::Types::Enums::RE2RGameDXVersion gameDXVersion = RE2RR::Types::Enums::RE2RGameDXVersion::Unknown;

BOOL APIENTRY DllMain(_In_ HINSTANCE hinstDLL, _In_ DWORD fdwReason, _In_ LPVOID UNUSED(lpvReserved))
{
	switch (fdwReason)
	{
		case DLL_PROCESS_ATTACH: // 1
		{
			DisableThreadLibraryCalls(hinstDLL);
			SetThreadPriority(GetCurrentThread(), THREAD_PRIORITY_TIME_CRITICAL);
			if ((startupSuccess = Startup()))
			{
				logger->LogMessage("[RE2R-R] DllMain (DLL_PROCESS_ATTACH) called.\n");
				dllInstance = hinstDLL;
				window = FindWindow(L"via", L"RESIDENT EVIL 2");
				if (window == nullptr)
					window = FindWindow(L"via", L"BIOHAZARD RE:2 Z Version");
				if (window == nullptr)
				{
					logger->LogMessage("[RE2R-R] DllMain (DLL_PROCESS_ATTACH) unable to find game window handle!\n");
					Shutdown();
					return FALSE;
				}
				mainThreadHandle = CreateThread(NULL, 0, MainThread, NULL, 0, NULL);
			}
			else
				return FALSE;
			break;
		}
		case DLL_PROCESS_DETACH: // 0
		{
			Shutdown();
			break;
		}
	}

	return TRUE;
}

DWORD WINAPI MainThread(LPVOID UNUSED(lpThreadParameter))
{
	logger->LogMessage("[RE2R-R] MainThread called.\n");
	SetThreadPriority(GetCurrentThread(), THREAD_PRIORITY_TIME_CRITICAL);

	const std::unique_ptr<char[]> gameExePath = RE2RR::Common::Process::GetProcessModulePathByNameA(GetCurrentProcess(), "re2.exe");
	if (!RE2RR::Hook::Hashes::DetectVersion(gameExePath.get(), gameVersion, gameEdition, gameDXVersion, *logger))
	{
		logger->LogMessage("[RE2R-R] Unable to detect game version, shutting down...\n");
		Shutdown();
		return FALSE; // Bail out if we can't detect version.
	}

	// Set function pointer addresses.
	if (gameEdition == RE2RR::Types::Enums::RE2RGameEdition::WorldWide)
	{
		if (gameDXVersion == RE2RR::Types::Enums::RE2RGameDXVersion::DirectX11)
		{
			if (gameVersion == RE2RR::Types::Enums::RE2RGameVersion::RE2R_20230421_1)
			{
				ItemPlacement1FuncOffset = 0x12CDA20;    // app.ropeway.gamemastering.InventoryManager.addSelectedStock(app.ropeway.gamemastering.InventoryManager.ItemData, app.ropeway.gamemastering.Location.ID, app.ropeway.gamemastering.Map.ID, System.Guid)
				ItemPlacement2FuncOffset = 0x12CC740;    // app.ropeway.gamemastering.InventoryManager.addSelectedStock(app.ropeway.gimmick.action.SetItem.SetItemSaveData)
				ItemPickupFuncOffset = 0xB912D0;         // app.ropeway.gui.GUIMaster.openInventoryGetItemMode(app.ropeway.gamemastering.InventoryManager.StockItem, app.ropeway.gimmick.action.SetItem.SetItemSaveData)
				UIMapManagerUpdateFuncOffset = 0x95E430; // app.ropeway.gamemastering.UIMapManager.update()
			}
		}
		else if (gameDXVersion == RE2RR::Types::Enums::RE2RGameDXVersion::DirectX12)
		{
			if (gameVersion == RE2RR::Types::Enums::RE2RGameVersion::RE2R_20230814_1)
			{
				ItemPlacement1FuncOffset = 0x0;
				ItemPlacement2FuncOffset = 0x0;
				ItemPickupFuncOffset = 0x0;
				UIMapManagerUpdateFuncOffset = 0x0;
			}
		}
	}
	else if (gameEdition == RE2RR::Types::Enums::RE2RGameEdition::CeroZ)
	{
		if (gameDXVersion == RE2RR::Types::Enums::RE2RGameDXVersion::DirectX11)
		{
			if (gameVersion == RE2RR::Types::Enums::RE2RGameVersion::RE2R_20230421_1)
			{
				ItemPlacement1FuncOffset = 0x0;
				ItemPlacement2FuncOffset = 0x0;
				ItemPickupFuncOffset = 0x0;
				UIMapManagerUpdateFuncOffset = 0x0;
			}
		}
		else if (gameDXVersion == RE2RR::Types::Enums::RE2RGameDXVersion::DirectX12)
		{
			if (gameVersion == RE2RR::Types::Enums::RE2RGameVersion::RE2R_20230814_1)
			{
				ItemPlacement1FuncOffset = 0x0;
				ItemPlacement2FuncOffset = 0x0;
				ItemPickupFuncOffset = 0x0;
				UIMapManagerUpdateFuncOffset = 0x0;
			}
		}
	}

	itemPickupFuncTarget = reinterpret_cast<ItemPickup>((uintptr_t)GetModuleHandleW(L"re2.exe") + ItemPickupFuncOffset);
	uiMapManagerUpdateFuncTarget = reinterpret_cast<UIMapManagerUpdate>((uintptr_t)GetModuleHandleW(L"re2.exe") + UIMapManagerUpdateFuncOffset);

	MH_STATUS status;
	do
	{
		SetVTables();
	} while (!TryHookFunction<Present>((Present)vtableDXGISwapChain[8], (Present)HookPresent, &presentFunc, status));

	if (!TryHookFunction<GetDeviceState>((GetDeviceState)vtableDirectInputDevice8[9], (GetDeviceState)HookGetDeviceState, &getDeviceStateFunc, status))
		logger->LogMessage("[RE2R-R] Hook failed (HookGetDeviceState): %s\n", MH_StatusToString(status));

	if (!TryHookFunction<ItemPickup>(itemPickupFuncTarget, (ItemPickup)HookItemPickup, &itemPickupFunc, status))
		logger->LogMessage("[RE2R-R] Hook failed (HookItemPickup): %s\n", MH_StatusToString(status));

	if (!TryHookFunction<UIMapManagerUpdate>(uiMapManagerUpdateFuncTarget, (UIMapManagerUpdate)HookUIMapManagerUpdate, &uiMapManagerUpdateFunc, status))
		logger->LogMessage("[RE2R-R] Hook failed (HookUIMapManagerUpdate): %s\n", MH_StatusToString(status));

	logger->LogMessage("[RE2R-R] Hooked.\n");

	logger->LogMessage("[RE2R-R] Usage:\n");
	logger->LogMessage("\t(F7): Toggle UI)\n");
	logger->LogMessage("\t(F8): Exit)\n");

	return TRUE;
}

DWORD WINAPI ShutdownThread(LPVOID UNUSED(lpThreadParameter))
{
	TerminateThread(mainThreadHandle, 0);
	FreeDependencyLibrary(L"RE2RR.Database.dll");
	FreeDependencyLibrary(L"RE2RR.Types.dll");
	FreeDependencyLibrary(L"RE2RR.Common.dll");
	FreeLibraryAndExitThread(dllInstance, 0);
	return 0;
}

void FreeDependencyLibrary(const TCHAR *moduleName)
{
	HMODULE hModule = GetModuleHandle(moduleName);
	if (hModule)
		FreeLibrary(hModule);
}

bool Startup()
{
	return !fopen_s(&stdoutLogFile, "RE2RR_Core.log", "w") &&
	       (uiLog = std::make_unique<RE2RR::Common::Logging::UILog>()).get() != nullptr &&
	       (logger = std::make_unique<RE2RR::Common::Logging::ImmediateLogger>(stdoutLogFile, *uiLog)).get() != nullptr &&
	       (ui = std::make_unique<RE2RR::Hook::UI::UI>(*logger.get())).get() != nullptr &&
	       MH_Initialize() == MH_OK;
}

void Shutdown()
{
	// This might not have been setup properly if Startup() failed.
	if (startupSuccess)
		logger->LogMessage("[RE2R-R] Shutdown called.\n");

	MH_DisableHook(MH_ALL_HOOKS);
	MH_RemoveHook(MH_ALL_HOOKS);
	MH_Uninitialize();

	// These would only have been setup if we succeeded Startup().
	if (startupSuccess)
	{
		ImGui_ImplDX11_Shutdown(); // pD3D11Device is null already by the time this is called... somehow. This causes a C0000005 ACCESS VIOLATION for trying to dereference a null pointer.
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
		SetWindowLongPtr(window, GWLP_WNDPROC, (LONG_PTR)wndProcFunc);
	}

	if (stdoutLogFile)
		fclose(stdoutLogFile);
	CreateThread(NULL, 0, ShutdownThread, NULL, 0, NULL);
}

__stdcall uintptr_t HookItemPickup(uintptr_t param1, uintptr_t param2, uintptr_t param3, uintptr_t param4)
{
	Randomizer *randomizer;
	if ((void *)param3 == nullptr ||                                             // param3 is required for our purposes always.
	    (void *)param4 == nullptr ||                                             // param4 is required for our purposes always. param4 is null when items that have non-predefined placement by the game such as a defensive item embedded in an enemy so skip it.
	    (randomizer = ui != nullptr ? ui->GetRandomizer() : nullptr) == nullptr) // If we're not randomizing, this will be null.
		return itemPickupFunc(param1, param2, param3, param4);

	RE2RR::Types::RE2RItem *itemToReplace = (RE2RR::Types::RE2RItem *)param3;     // Sometimes uninitialized data, only write here.
	const RE2RR::Types::RE2RItem *currentItem = (RE2RR::Types::RE2RItem *)param4; // This is where we want to read to get what the item is.
	const GUID *itemPositionGuid = (GUID *)param4;                                // The item's position GUID.

	bool itemToReplaceSuccess = RE2RR::Common::Memory::TryReadPointer((const void *)param3, {0x50, 0x10, 0x10}, (void **)&itemToReplace, NAMEOF(itemToReplace), *logger.get());
	bool UNUSED(currentItemSuccess) = RE2RR::Common::Memory::TryReadPointer((const void *)param4, {0x14}, (void **)&currentItem, NAMEOF(currentItem), *logger.get());
	bool itemPositionGuidSuccess = RE2RR::Common::Memory::TryReadPointer((const void *)param4, {0x30}, (void **)&itemPositionGuid, NAMEOF(itemPositionGuid), *logger.get());

	if (!itemToReplaceSuccess ||
	    !itemPositionGuidSuccess)
		return itemPickupFunc(param1, param2, param3, param4);

	if (itemToReplace != nullptr && itemPositionGuid != nullptr)
		randomizer->ItemPickup(*itemToReplace, *itemPositionGuid);

	return itemPickupFunc(param1, param2, param3, param4);
}

__stdcall void HookUIMapManagerUpdate(uintptr_t param1, uintptr_t param2)
{
	uiMapManagerUpdateFunc(param1, param2);

	Randomizer *randomizer = ui != nullptr ? ui->GetRandomizer() : nullptr;
	if (randomizer != nullptr)
	{
		RE2RR::Types::Enums::MapPartsID mapPartsID = *(RE2RR::Types::Enums::MapPartsID *)(param2 + 0xC8);
		RE2RR::Types::Enums::MapID mapID = *(RE2RR::Types::Enums::MapID *)(param2 + 0xCC);
		RE2RR::Types::Enums::FloorID floorID = *(RE2RR::Types::Enums::FloorID *)(param2 + 0xD4);

		if (randomizer->ChangeArea(mapPartsID, mapID, floorID))
			logger->LogMessage("[RE2R-R] HookUIMapManagerUpdate called. %s / %s / %s\n",
			                   RE2RR::Types::Enums::EnumMapPartsIDToString(mapPartsID).get()->c_str(),
			                   RE2RR::Types::Enums::EnumMapIDToString(mapID).get()->c_str(),
			                   RE2RR::Types::Enums::EnumFloorIDToString(floorID).get()->c_str());
	}
}

HRESULT __stdcall HookPresent(IDXGISwapChain *swapChain, UINT syncInterval, UINT flags)
{
	if (!initPresent)
	{
		if (SUCCEEDED(swapChain->GetDevice(__uuidof(ID3D11Device), (void **)&device)))
		{
			InitImGui(swapChain, device);
			initPresent = true;
		}
		else
			return presentFunc(swapChain, syncInterval, flags);
	}

	ImGuiIO &io = ImGui::GetIO();
	if (isUIOpen)
		io.MouseDrawCursor = true;
	else
		io.MouseDrawCursor = false;

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

	if (ui != nullptr)
		ui->DrawMainUI(isUIOpen);

	ImGui::Render();

	deviceContext->OMSetRenderTargets(1, &mainRenderTargetView, NULL);
	ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());
	return presentFunc(swapChain, syncInterval, flags);
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

	return getDeviceStateFunc(device, cbData, lpvData);
}

LRESULT __stdcall HookWndProc(const HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
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

	return CallWindowProc(wndProcFunc, hWnd, uMsg, wParam, lParam);
}

void InitImGui(IDXGISwapChain *swapChain, ID3D11Device *device)
{
	ID3D11Texture2D *backBuffer;
	swapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID *)&backBuffer);
	device->CreateRenderTargetView(backBuffer, nullptr, &mainRenderTargetView);
	backBuffer->Release();
	DWORD lastError = 0;
	SetLastError(lastError);
	wndProcFunc = (WNDPROC)SetWindowLongPtr(window, GWLP_WNDPROC, (LONG_PTR)HookWndProc);
	if ((wndProcFunc == nullptr) && ((lastError = GetLastError()) != 0))
		logger->LogMessage("Error in InitImGui() [SetWindowLongPtr]: %d (0x%lX)\n", lastError, lastError);
	device->GetImmediateContext(&deviceContext);
	CreateRenderTarget(swapChain);
	ImGui::CreateContext();
	ImGuiIO &io = ImGui::GetIO();
	io.ConfigFlags = ImGuiConfigFlags_NoMouseCursorChange | ImGuiConfigFlags_NavEnableKeyboard | ImGuiConfigFlags_NavEnableGamepad;
	io.IniFilename = "RE2RR_ImGui.ini";
	io.LogFilename = "RE2RR_ImGui.log";

	// Include default font AND Consolas.
	// io.Fonts->AddFontDefault();
	// ui->SetFont(io.Fonts->AddFontFromFileTTF("C:\\Windows\\Fonts\\Consola.ttf", 16.0f));

	// Replace default font by adding Consolas as the first font.
	io.Fonts->AddFontFromFileTTF("C:\\Windows\\Fonts\\Consola.ttf", 16.0f);

	ImGui_ImplWin32_Init(window);
	ImGui_ImplDX11_Init(device, deviceContext);
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
