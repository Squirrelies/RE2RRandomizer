#include "RE2RRandomizerHook.h"
#include "DX11Hook.h"
#define DX11

HMODULE dllHandle;
FILE *stdoutLogFile;
ImmediateLogger *logger;
DX11Hook *dx11Hook;

#ifdef DX12
// DX12-WW as of 20240102
constexpr uintptr_t ItemPickupFuncOffset = 0x1AD5070;
constexpr uintptr_t ItemPutDownKeepFuncOffset = 0x1E341F0;
#endif
#ifdef DX11
// DX11-WW as of 20240102
constexpr uintptr_t ItemPickupFuncOffset = 0xB912D0;
constexpr uintptr_t ItemPutDownKeepFuncOffset = 0x1237FA0;
#endif

typedef void *(*ItemPickup)(void *param1, void *param2, void *param3, void *param4);
ItemPickup itemPickupFuncTarget = reinterpret_cast<ItemPickup>((uintptr_t)GetModuleHandleW(L"re2.exe") + ItemPickupFuncOffset);
ItemPickup itemPickupFunc = nullptr;

typedef void (*ItemPutDownKeep)(void *param1, void *param2, void *param3);
ItemPutDownKeep itemPutDownKeepFuncTarget = reinterpret_cast<ItemPutDownKeep>((uintptr_t)GetModuleHandleW(L"re2.exe") + ItemPutDownKeepFuncOffset);
ItemPutDownKeep itemPutDownKeepFunc = nullptr;

__fastcall void *HookItemPickup(void *param1, void *param2, void *param3, void *param4)
{
	uint32_t *itemId = (uint32_t *)(param3 + 0x70);   // R8
	uint8_t *idlocation = (uint8_t *)(param4 + 0x30); // R9
	logger->LogMessage("[RE2R-R] HookItemPickup called: %d (0x%x): 0x%x, 0x%x, 0x%x, 0x%x, 0x%x, 0x%x\n", *itemId, *itemId, idlocation[0], idlocation[1], idlocation[2], idlocation[3], idlocation[4], idlocation[5]);
	return itemPickupFunc(param1, param2, param3, param4);
}

__fastcall void HookItemPutDownKeep(void *param1, void *param2, void *param3)
{
	uint32_t *itemId = (uint32_t *)(param2 + 0x14); // RDI
	logger->LogMessage("[RE2R-R] HookItemPutDownKeep called: %d (0x%x)\n", *itemId, *itemId);
	itemPutDownKeepFunc(param1, param2, param3);
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
	switch (ul_reason_for_call)
	{
		case DLL_PROCESS_ATTACH:
		{
			DisableThreadLibraryCalls(hModule);
			if (Startup())
			{
				logger->LogMessage("[RE2R-R] DllMain (DLL_PROCESS_ATTACH) called.\n");
				dllHandle = hModule;
				CreateThread(NULL, 0, MainThread, NULL, 0, NULL);
				CreateThread(NULL, 0, DX11Thread, NULL, 0, NULL);
			}
		}
		default:
		{
			break;
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
	delete logger;
	delete dx11Hook;
	MH_DisableHook(MH_ALL_HOOKS);
	MH_Uninitialize();
	fclose(stdoutLogFile);
	FreeConsole();
	CreateThread(NULL, 0, EjectThread, NULL, 0, NULL);
}

DWORD WINAPI MainThread(LPVOID lpThreadParameter)
{
	logger->LogMessage("[RE2R-R] Menu called.\n");

	MH_STATUS status;
	if ((status = MH_CreateHook(reinterpret_cast<LPVOID>(itemPickupFuncTarget), reinterpret_cast<LPVOID>(&HookItemPickup), reinterpret_cast<LPVOID *>(&itemPickupFunc))) != MH_OK)
	{
		logger->LogMessage("[RE2R-R] MinHook CreateHook (itemPickupFuncTarget) failed: %s\n", MH_StatusToString(status));
		Shutdown();
		return 2;
	}

	if ((status = MH_EnableHook(reinterpret_cast<LPVOID>(itemPickupFuncTarget))) != MH_OK)
	{
		logger->LogMessage("[RE2R-R] MinHook EnableHook (itemPickupFuncTarget) failed: %s\n", MH_StatusToString(status));
		Shutdown();
		return 3;
	}

	if ((status = MH_CreateHook(reinterpret_cast<LPVOID>(itemPutDownKeepFuncTarget), reinterpret_cast<LPVOID>(&HookItemPutDownKeep), reinterpret_cast<LPVOID *>(&itemPutDownKeepFunc))) != MH_OK)
	{
		logger->LogMessage("[RE2R-R] MinHook CreateHook (itemPutDownKeepFuncTarget) failed: %s\n", MH_StatusToString(status));
		Shutdown();
		return 2;
	}

	if ((status = MH_EnableHook(reinterpret_cast<LPVOID>(itemPutDownKeepFuncTarget))) != MH_OK)
	{
		logger->LogMessage("[RE2R-R] MinHook EnableHook (itemPutDownKeepFuncTarget) failed: %s\n", MH_StatusToString(status));
		Shutdown();
		return 3;
	}

	logger->LogMessage("[RE2R-R] Usage:\n");
	logger->LogMessage("\t(F8) Exit\n");

	while (true)
	{
		Sleep(16);
		if (GetAsyncKeyState(VK_F8) & 0x01)
		{
			logger->LogMessage("F8 key pressed, exiting...\n");
			break;
		}
	}

	Shutdown();
	return 0;
}

DWORD WINAPI DX11Thread(LPVOID lpThreadParameter)
{
	logger->LogMessage("DX11Thread start\n");
	dx11Hook = new DX11Hook(dllHandle, FindWindow(L"via", L"RESIDENT EVIL 2"), stdoutLogFile);

	logger->LogMessage("DX11Thread loop\n");
	while (dx11Hook != nullptr)
	{
		Sleep(1);
	}
	logger->LogMessage("DX11Thread end\n");

	return 0;
}

DWORD WINAPI EjectThread(LPVOID lpThreadParameter)
{
	Sleep(100);
	FreeLibraryAndExitThread(dllHandle, 0);
	return 0;
}