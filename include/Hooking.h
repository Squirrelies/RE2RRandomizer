#ifndef RE2RR_HOOKING_H
#define RE2RR_HOOKING_H

#ifndef UNICODE
#define UNICODE
#endif

#ifndef _UNICODE
#define _UNICODE
#endif

#ifndef WIN32_LEAD_AND_MEAN
#define WIN32_LEAD_AND_MEAN
#endif

#include <MinHook.h>

template <class FuncT>
bool HookFunction(FuncT target, FuncT hook, FuncT *original, MH_STATUS &status)
{
	MH_STATUS createHookStatus, enableHookStatus;
	createHookStatus = MH_CreateHook(target, hook, original);
	enableHookStatus = MH_EnableHook(target);
	if (createHookStatus != MH_OK)
		status = createHookStatus;
	else if (enableHookStatus != MH_OK)
		status = enableHookStatus;
	else
		status = MH_OK;

	return status == MH_OK;
}

#endif
