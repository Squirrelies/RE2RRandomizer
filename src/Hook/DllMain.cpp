#include "DllMain.h"

BOOL APIENTRY DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID UNUSED(lpvReserved))
{
	switch (fdwReason)
	{
		case DLL_PROCESS_ATTACH: // 1
		{
			DisableThreadLibraryCalls(hinstDLL);
			SetThreadPriority(GetCurrentThread(), THREAD_PRIORITY_TIME_CRITICAL);
			return RE2RR::Hook::GameHook::GetInstance().Initialize(hinstDLL);
		}
	}

	return TRUE;
}
