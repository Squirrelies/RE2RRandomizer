#ifndef RE2RRANDOMIZERHOOK_H
#define RE2RRANDOMIZERHOOK_H

#ifndef UNICODE
#define UNICODE
#endif

#ifndef _UNICODE
#define _UNICODE
#endif

#ifndef WIN32_LEAD_AND_MEAN
#define WIN32_LEAD_AND_MEAN
#endif

#include "Logging.h"
#include <MinHook.h>
#include <d3d11.h>
#include <dxgi.h>
#include <imgui.h>
#include <imgui_impl_dx11.h>
#include <imgui_impl_win32.h>
#include <memory>
#include <windows.h>

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved);
bool Startup();
void Shutdown();
DWORD WINAPI MainThread(LPVOID lpThreadParameter);
void HookDX11();
template <class FuncT>
bool HookFunction(FuncT target, FuncT hook, FuncT *original);

#endif
