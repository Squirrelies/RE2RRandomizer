#include "RE2RRandomizerHook.h"

// register volatile unsigned int ItemPickupLocation asm("%r9+30h");
// register volatile unsigned int ItemPickupId asm("%r8+70h");
// register volatile unsigned int ItemPutdownId asm("%rdi+14h");

typedef unsigned long long(__fastcall *ItemPickup)(long long param1, long long param2, unsigned long long param3, unsigned long long param4);
ItemPickup itemPickupFuncTarget = reinterpret_cast<ItemPickup>(0x1AD507F);
ItemPickup itemPickupFunc = nullptr;
__fastcall unsigned long long HookItemPickup(long long param1, long long param2, unsigned long long param3, unsigned long long param4)
{
	volatile int itemId;
	asm volatile("movl 70(%%r8), %0" : "=a"(itemId)); // Copy long (4-byte) value into variable.

	return itemPickupFunc(param1, param2, param3, param4);
}

HMODULE dllHandle;
FILE *cout;
BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
	switch (ul_reason_for_call)
	{
		case DLL_PROCESS_ATTACH:
		{
			if (Startup())
			{
				printf("[RE2R-R] DllMain (DLL_PROCESS_ATTACH) called.\n");
				dllHandle = hModule;
				CreateThread(NULL, 0, MenuThread, NULL, 0, NULL);
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
	return AllocConsole() && freopen_s(&cout, "CONOUT$", "w", stdout);
}

void Shutdown()
{
	printf("[RE2R-R] Shutdown called.\n");
	fclose(cout);
	FreeConsole();
	CreateThread(NULL, 0, EjectThread, NULL, 0, NULL);
}

DWORD WINAPI MenuThread(LPVOID lpThreadParameter)
{
	printf("[RE2R-R] Menu called.\n");

	MH_STATUS status;
	if ((status = MH_Initialize()) != MH_OK)
	{
		printf("[RE2R-R] MinHook Initialize failed: %s\n", MH_StatusToString(status));
		Shutdown();
		return 1;
	}

	if ((status = MH_CreateHook(reinterpret_cast<void **>(itemPickupFuncTarget), reinterpret_cast<void **>(&HookItemPickup), reinterpret_cast<void **>(&itemPickupFunc))) != MH_OK)
	{
		printf("[RE2R-R] MinHook CreateHook failed: %s\n", MH_StatusToString(status));
		Shutdown();
		return 2;
	}

	printf("[RE2R-R] Usage:\n");
	printf("\t(F8) Exit\n");

	while (true)
	{
		Sleep(16);
		if (GetAsyncKeyState(VK_F8) & 0x01)
		{
			printf("F8 key pressed, exiting...\n");
			break;
		}
	}

	Shutdown();
	return 0;
}

DWORD WINAPI EjectThread(LPVOID lpThreadParameter)
{
	Sleep(100);
	FreeLibraryAndExitThread(dllHandle, 0);
	return 0;
}
