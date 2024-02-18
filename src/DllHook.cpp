#include "DllHook.h"

HINSTANCE dllInstance;
HANDLE mainThreadHandle;
FILE *stdoutLogFile;
ImmediateLogger *logger;
UI *ui;
SeedGenerator *seedGenerator;
bool allocedConsole = true;
bool attachedConsole = true;
void **vtableDXGISwapChain = nullptr;
void **vtableD3D11Device = nullptr;
void **vtableD3D11DeviceContext = nullptr;
void **vtableDirectInput8 = nullptr;
void **vtableDirectInputDevice8 = nullptr;
Present oPresent;
GetDeviceState oGetDeviceState;
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
bool isUIOpen = false;
UINT resizeWidth = 0U;
UINT resizeHeight = 0U;
ItemPickup itemPickupFuncTarget = reinterpret_cast<ItemPickup>((uintptr_t)GetModuleHandleW(L"re2.exe") + ItemPickupFuncOffset);
ItemPickup itemPickupFunc = nullptr;
// ItemPutDownKeep itemPutDownKeepFuncTarget = reinterpret_cast<ItemPutDownKeep>((uintptr_t)GetModuleHandleW(L"re2.exe") + ItemPutDownKeepFuncOffset);
// ItemPutDownKeep itemPutDownKeepFunc = nullptr;
SetCurrentScenarioType setCurrentScenarioTypeFuncTarget = reinterpret_cast<SetCurrentScenarioType>((uintptr_t)GetModuleHandleW(L"re2.exe") + SetCurrentScenarioTypeFuncOffset);
SetCurrentScenarioType setCurrentScenarioTypeFunc = nullptr;
SetCurrentDifficulty setCurrentDifficultyFuncTarget = reinterpret_cast<SetCurrentDifficulty>((uintptr_t)GetModuleHandleW(L"re2.exe") + SetCurrentDifficultyFuncOffset);
SetCurrentDifficulty setCurrentDifficultyFunc = nullptr;
SetLoadLocation setLoadLocationFuncTarget = reinterpret_cast<SetLoadLocation>((uintptr_t)GetModuleHandleW(L"re2.exe") + SetLoadLocationFuncOffset);
SetLoadLocation setLoadLocationFunc = nullptr;
GetLoadArea getLoadAreaFuncTarget = reinterpret_cast<GetLoadArea>((uintptr_t)GetModuleHandleW(L"re2.exe") + GetLoadAreaFuncOffset);
GetLoadArea getLoadAreaFunc = nullptr;
SetLoadArea setLoadAreaFuncTarget = reinterpret_cast<SetLoadArea>((uintptr_t)GetModuleHandleW(L"re2.exe") + SetLoadAreaFuncOffset);
SetLoadArea setLoadAreaFunc = nullptr;
EntriedMap entriedMapFuncTarget = reinterpret_cast<EntriedMap>((uintptr_t)GetModuleHandleW(L"re2.exe") + EntriedMapFuncOffset);
EntriedMap entriedMapFunc = nullptr;
SetRoomMapId setRoomMapIdFuncTarget = reinterpret_cast<SetRoomMapId>((uintptr_t)GetModuleHandleW(L"re2.exe") + SetRoomMapIdFuncOffset);
SetRoomMapId setRoomMapIdFunc = nullptr;
OnChangeMapIdentifier onChangeMapIdentifierFuncTarget = reinterpret_cast<OnChangeMapIdentifier>((uintptr_t)GetModuleHandleW(L"re2.exe") + OnChangeMapIdentifierFuncOffset);
OnChangeMapIdentifier onChangeMapIdentifierFunc = nullptr;
GetMapArea getMapAreaFuncTarget = reinterpret_cast<GetMapArea>((uintptr_t)GetModuleHandleW(L"re2.exe") + GetMapAreaFuncOffset);
GetMapArea getMapAreaFunc = nullptr;
LocationThroughManagerUpdate locationThroughManagerUpdateFuncTarget = reinterpret_cast<LocationThroughManagerUpdate>((uintptr_t)GetModuleHandleW(L"re2.exe") + LocationThroughManagerUpdateFuncOffset);
LocationThroughManagerUpdate locationThroughManagerUpdateFunc = nullptr;
GetLocationID getLocationIDFuncTarget = reinterpret_cast<GetLocationID>((uintptr_t)GetModuleHandleW(L"re2.exe") + GetLocationIDFuncOffset);
GetLocationID getLocationIDFunc = nullptr;
UIMapManagerUpdate uiMapManagerUpdateFuncTarget = reinterpret_cast<UIMapManagerUpdate>((uintptr_t)GetModuleHandleW(L"re2.exe") + UIMapManagerUpdateFuncOffset);
UIMapManagerUpdate uiMapManagerUpdateFunc = nullptr;

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

	if (!HookFunction<ItemPickup>(itemPickupFuncTarget, (ItemPickup)HookItemPickup, &itemPickupFunc, status))
		logger->LogMessage("[RE2R-R] Hook failed (HookItemPickup): %s\n", MH_StatusToString(status));

	// if (!HookFunction<ItemPutDownKeep>(itemPutDownKeepFuncTarget, (ItemPutDownKeep)HookItemPutDownKeep, &itemPutDownKeepFunc, status))
	// 	logger->LogMessage("[RE2R-R] Hook failed (HookItemPutDownKeep): %s\n", MH_StatusToString(status));

	if (!HookFunction<SetCurrentScenarioType>(setCurrentScenarioTypeFuncTarget, (SetCurrentScenarioType)HookSetCurrentScenarioType, &setCurrentScenarioTypeFunc, status))
		logger->LogMessage("[RE2R-R] Hook failed (HookSetCurrentScenarioType): %s\n", MH_StatusToString(status));

	if (!HookFunction<SetCurrentDifficulty>(setCurrentDifficultyFuncTarget, (SetCurrentDifficulty)HookSetCurrentDifficulty, &setCurrentDifficultyFunc, status))
		logger->LogMessage("[RE2R-R] Hook failed (HookSetCurrentDifficulty): %s\n", MH_StatusToString(status));

	// if (!HookFunction<SetLoadLocation>(setLoadLocationFuncTarget, (SetLoadLocation)HookSetLoadLocation, &setLoadLocationFunc, status))
	// 	logger->LogMessage("[RE2R-R] Hook failed (HookSetLoadLocation): %s\n", MH_StatusToString(status));

	// if (!HookFunction<GetLoadArea>(getLoadAreaFuncTarget, (GetLoadArea)HookGetLoadArea, &getLoadAreaFunc, status))
	// 	logger->LogMessage("[RE2R-R] Hook failed (HookGetLoadArea): %s\n", MH_StatusToString(status));

	// if (!HookFunction<SetLoadArea>(setLoadAreaFuncTarget, (SetLoadArea)HookSetLoadArea, &setLoadAreaFunc, status))
	// 	logger->LogMessage("[RE2R-R] Hook failed (HookSetLoadArea): %s\n", MH_StatusToString(status));

	// if (!HookFunction<EntriedMap>(entriedMapFuncTarget, (EntriedMap)HookEntriedMap, &entriedMapFunc, status))
	// 	logger->LogMessage("[RE2R-R] Hook failed (HookEntriedMap): %s\n", MH_StatusToString(status));

	// if (!HookFunction<SetRoomMapId>(setRoomMapIdFuncTarget, (SetRoomMapId)HookSetRoomMapId, &setRoomMapIdFunc, status))
	// 	logger->LogMessage("[RE2R-R] Hook failed (HookSetRoomMapId): %s\n", MH_StatusToString(status));

	// if (!HookFunction<OnChangeMapIdentifier>(onChangeMapIdentifierFuncTarget, (OnChangeMapIdentifier)HookOnChangeMapIdentifier, &onChangeMapIdentifierFunc, status))
	// 	logger->LogMessage("[RE2R-R] Hook failed (HookOnChangeMapIdentifier): %s\n", MH_StatusToString(status));

	// if (!HookFunction<GetMapArea>(getMapAreaFuncTarget, (GetMapArea)HookGetMapArea, &getMapAreaFunc, status))
	// 	logger->LogMessage("[RE2R-R] Hook failed (HookGetMapArea): %s\n", MH_StatusToString(status));

	// if (!HookFunction<LocationThroughManagerUpdate>(locationThroughManagerUpdateFuncTarget, (LocationThroughManagerUpdate)HookLocationThroughManagerUpdate, &locationThroughManagerUpdateFunc, status))
	// 	logger->LogMessage("[RE2R-R] Hook failed (HookLocationThroughManagerUpdate): %s\n", MH_StatusToString(status));

	// if (!HookFunction<GetLocationID>(getLocationIDFuncTarget, (GetLocationID)HookGetLocationID, &getLocationIDFunc, status))
	// 	logger->LogMessage("[RE2R-R] Hook failed (HookGetLocationID): %s\n", MH_StatusToString(status));

	if (!HookFunction<UIMapManagerUpdate>(uiMapManagerUpdateFuncTarget, (UIMapManagerUpdate)HookUIMapManagerUpdate, &uiMapManagerUpdateFunc, status))
		logger->LogMessage("[RE2R-R] Hook failed (HookUIMapManagerUpdate): %s\n", MH_StatusToString(status));

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
	    (ui = new UI(logger)) != nullptr &&
	    (seedGenerator = new SeedGenerator(logger)) != nullptr &&
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
	if (seedGenerator != nullptr)
	{
		delete seedGenerator;
		seedGenerator = nullptr;
	}
	if (ui != nullptr)
	{
		delete ui;
		ui = nullptr;
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

// Hooking System.Boolean app.ropeway.gui.GUIMaster.openInventoryGetItemMode(RCX, RDX, R8, R9);
// param1 (RCX) = ???
// param2 (RDX) = this * (app.ropeway.gui.GUIMaster *)
// param3 (R8) = app.ropeway.gamemastering.InventoryManager.StockItem
// param3 (R8) + 0x60 = app.ropeway.gamemastering.InventoryManager.PrimitiveItem
// param3 (R8) + 0x70 = app.ropeway.gamemastering.InventoryManager.PrimitiveItem.ItemId (app.ropeway.gamemastering.Item.ID *)
// param4 (R9) = app.ropeway.gimmick.action.SetItem.SetItemSaveData
// param4 (R9) + 0x30 = app.ropeway.gimmick.action.SetItem.SetItemSaveData.ItemPositionGuid (GUID *)
__stdcall uintptr_t HookItemPickup(uintptr_t param1, uintptr_t param2, uintptr_t param3, uintptr_t param4)
{
	Randomizer *randomizer = ui->GetRandomizer();
	if (randomizer == nullptr)
		return itemPickupFunc(param1, param2, param3, param4);

	// logger->LogMessage("[RE2R-R] HookItemPickup(%p, %p, %p, %p) called.\n", param1, param2, param3, param4);
	logger->LogMessage("[RE2R-R] HookItemPickup called. { %s, %s }\n", ((app_ropeway_gamemastering_InventoryManager_PrimitiveItem *)(param4 + 0x14))->ToString().c_str(), GUIDToString((GUID *)(param4 + 0x30)).c_str());

	app_ropeway_gamemastering_InventoryManager_PrimitiveItem *itemToReplace = (app_ropeway_gamemastering_InventoryManager_PrimitiveItem *)(param3 + 0x70); // Sometimes uninitialized data, only write here.
	app_ropeway_gamemastering_InventoryManager_PrimitiveItem *currentItem = (app_ropeway_gamemastering_InventoryManager_PrimitiveItem *)(param4 + 0x14);   // This is where we want to read to get what the item is.
	GUID *itemPositionGuid = (GUID *)(param4 + 0x30);

	randomizer->ItemPickup(itemToReplace, currentItem, itemPositionGuid);
	return itemPickupFunc(param1, param2, param3, param4);
}

// __stdcall void HookItemPutDownKeep(uintptr_t param1, uintptr_t param2, uintptr_t param3)
// {
// 	Randomizer *randomizer = ui->GetRandomizer();
// 	if (randomizer == nullptr)
// 		itemPutDownKeepFunc(param1, param2, param3);
// 	uint32_t *itemId = (uint32_t *)(param2 + 0x14); // RDI + 0x14 (uniqueID)

// 	randomizer->ItemPutdown(itemId);
// 	itemPutDownKeepFunc(param1, param2, param3);
// }

__stdcall void HookSetCurrentScenarioType(uintptr_t param1, uintptr_t param2, RE2RREnums::Scenario *param3)
{
	logger->LogMessage("[RE2R-R] HookSetCurrentScenarioType called: %s\n", RE2RREnums::EnumScenarioToString(*param3).c_str());
	setCurrentScenarioTypeFunc(param1, param2, param3);
}

__stdcall void HookSetCurrentDifficulty(uintptr_t param1, uintptr_t param2, RE2RREnums::Difficulty *param3)
{
	logger->LogMessage("[RE2R-R] HookSetCurrentDifficulty called: %s\n", RE2RREnums::EnumDifficultyToString(*param3).c_str());
	setCurrentDifficultyFunc(param1, param2, param3);
}

__stdcall void HookSetLoadLocation(uintptr_t param1, uintptr_t param2, RE2RREnums::LocationID *param3)
{
	logger->LogMessage("[RE2R-R] HookSetLoadLocation called: %s\n", RE2RREnums::EnumLocationIDToString(*param3).c_str());
	setLoadLocationFunc(param1, param2, param3);
}

__stdcall RE2RREnums::MapID *HookGetLoadArea(void)
{
	RE2RREnums::MapID *mapId = getLoadAreaFunc();
	logger->LogMessage("[RE2R-R] HookGetLoadArea called: %s\n", RE2RREnums::EnumMapIDToString(*mapId).c_str());
	return mapId;
}

__stdcall void HookSetLoadArea(uintptr_t param1, uintptr_t param2, RE2RREnums::MapID *param3)
{
	logger->LogMessage("[RE2R-R] HookSetLoadArea called: %s\n", RE2RREnums::EnumMapIDToString(*param3).c_str());
	setLoadAreaFunc(param1, param2, param3);
}

__stdcall void HookEntriedMap(uintptr_t param1, uintptr_t param2, RE2RREnums::MapPartsID param3, RE2RREnums::FloorID param4)
{
	logger->LogMessage("[RE2R-R] HookEntriedMap called: %s / %s\n", RE2RREnums::EnumMapPartsIDToString(param3).c_str(), RE2RREnums::EnumFloorIDToString(param4).c_str());
	entriedMapFunc(param1, param2, param3, param4);
}

__stdcall void HookSetRoomMapId(uintptr_t param1, uintptr_t param2, RE2RREnums::MapPartsID param3)
{
	logger->LogMessage("[RE2R-R] HookSetRoomMapId called: %s\n", RE2RREnums::EnumMapPartsIDToString(param3).c_str());
	setRoomMapIdFunc(param1, param2, param3);
}

__stdcall void HookOnChangeMapIdentifier(uintptr_t param1, uintptr_t param2, app_ropeway_MansionManager_MapIdentifier *param3, app_ropeway_MansionManager_MapIdentifier *param4)
{
	logger->LogMessage("[RE2R-R] HookOnChangeMapIdentifier called: %s / %s\n", param3->ToString().c_str(), param4->ToString().c_str());
	onChangeMapIdentifierFunc(param1, param2, param3, param4);
}

__stdcall RE2RREnums::MapArea HookGetMapArea(uintptr_t param1, uintptr_t param2, RE2RREnums::MapID param3, via_vec3 *param4)
{
	RE2RREnums::MapArea mapArea = getMapAreaFunc(param1, param2, param3, param4);
	logger->LogMessage("[RE2R-R] HookGetMapArea called: %s / %s -> %s\n", RE2RREnums::EnumMapIDToString(param3).c_str(), param4->ToString().c_str(), RE2RREnums::EnumMapAreaToString(mapArea).c_str());
	return mapArea;
}

__stdcall void HookLocationThroughManagerUpdate(uintptr_t param1, uintptr_t param2)
{
	locationThroughManagerUpdateFunc(param1, param2);
	RE2RREnums::LocationID *locationID = (RE2RREnums::LocationID *)(param2 + 0xA4);
	RE2RREnums::MapID *mapID = (RE2RREnums::MapID *)(param2 + 0xD0);

	if (*locationID != RE2RREnums::LocationID::invalid && *mapID != RE2RREnums::MapID::Invalid)
		logger->LogMessage("[RE2R-R] HookLocationThroughManagerUpdate called. %s / %s\n", RE2RREnums::EnumLocationIDToString(*locationID).c_str(), RE2RREnums::EnumMapIDToString(*mapID).c_str());
}

__stdcall RE2RREnums::LocationID HookGetLocationID(uintptr_t param1, RE2RREnums::MapID param2)
{
	RE2RREnums::LocationID locationID = getLocationIDFunc(param1, param2);
	logger->LogMessage("[RE2R-R] HookGetLocationID called: %s -> %s\n", RE2RREnums::EnumMapIDToString(param2).c_str(), RE2RREnums::EnumLocationIDToString(locationID).c_str());
	return locationID;
}

__stdcall void HookUIMapManagerUpdate(uintptr_t param1, uintptr_t param2)
{
	uiMapManagerUpdateFunc(param1, param2);

	Randomizer *randomizer = ui->GetRandomizer();
	if (randomizer != nullptr)
	{
		RE2RREnums::MapPartsID mapPartsID = *(RE2RREnums::MapPartsID *)(param2 + 0xC8);
		RE2RREnums::MapID mapID = *(RE2RREnums::MapID *)(param2 + 0xCC);
		RE2RREnums::FloorID floorID = *(RE2RREnums::FloorID *)(param2 + 0xD4);

		if (randomizer->ChangeArea(mapPartsID, mapID, floorID))
			logger->LogMessage("[RE2R-R] HookUIMapManagerUpdate called. %s / %s / %s\n",
			                   RE2RREnums::EnumMapPartsIDToString(mapPartsID).c_str(),
			                   RE2RREnums::EnumMapIDToString(mapID).c_str(),
			                   RE2RREnums::EnumFloorIDToString(floorID).c_str());
	}
}

void InitImGui(IDXGISwapChain *swapChain, ID3D11Device *device)
{
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

	ui->DrawMainUI(&isUIOpen);
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

	return oGetDeviceState(device, cbData, lpvData);
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
