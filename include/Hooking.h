#ifndef RE2RR_HOOKING_H
#define RE2RR_HOOKING_H

#include "Common.h"
#include <MinHook.h>

/// @brief Attempts to hook the target function, calling the hook function in its place.
/// @tparam FuncT The typedef prototype of the function to hook.
/// @param target The target function.
/// @param hook The hook function.
/// @param original A reference to the original function.
/// @param status The status code for the hook.
/// @return A boolean indicating whether we succeeded in creating and enabling the hook.
template <typename FuncT>
bool TryHookFunction(FuncT target, FuncT hook, FuncT *original, MH_STATUS &status)
{
	status = MH_CreateHook((LPVOID)target, (LPVOID)hook, (LPVOID *)original);
	if (status != MH_OK)
		return false;

	status = MH_EnableHook((LPVOID)target);
	if (status != MH_OK)
		return false;

	return true;
}

#endif
