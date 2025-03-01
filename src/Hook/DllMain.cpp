#include "DllMain.h"

BOOL APIENTRY DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID UNUSED(lpvReserved))
{
	switch (fdwReason)
	{
		case DLL_PROCESS_ATTACH: // 1
		{
			DisableThreadLibraryCalls(hinstDLL);
			SetThreadPriority(GetCurrentThread(), THREAD_PRIORITY_TIME_CRITICAL);

			RE2RR::Hook::GameHook *hook = RE2RR::Hook::GameHook::GetInstance();
			if (!hook->Initialize(hinstDLL))
			{
				RE2RR::Hook::GameHook::DestroyInstance();
				return FALSE;
			}
			break;
		}
		case DLL_PROCESS_DETACH: // 0
		{
			RE2RR::Hook::GameHook::DestroyInstance();
			break;
		}
	}

	return TRUE;
}
