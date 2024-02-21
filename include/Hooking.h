#ifndef RE2RR_HOOKING_H
#define RE2RR_HOOKING_H

#include <MinHook.h>

/// @brief Attempts to hook the target function, calling the hook function in its place.
/// @tparam FuncT The typedef prototype of the function to hook.
/// @param target The target function.
/// @param hook The hook function.
/// @param original A reference to the original function.
/// @param status The status code for the hook.
/// @return A boolean indicating whether we succeeded in creating and enabling the hook.
template <class FuncT>
bool TryHookFunction(FuncT target, FuncT hook, FuncT *original, MH_STATUS &status);

#endif
