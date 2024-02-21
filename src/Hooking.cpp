#include "Hooking.h"

template <class FuncT>
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
