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
	status = MH_CreateHook(target, hook, original);
	if (status != MH_OK)
		return false;

	status = MH_EnableHook(target);
	if (status != MH_OK)
		return false;

	return true;
}

#endif
