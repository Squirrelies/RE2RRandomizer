#ifndef RE2RR_RE2RRANDOMIZERHOOK_H
#define RE2RR_RE2RRANDOMIZERHOOK_H

#define DX11

#ifndef UNICODE
#define UNICODE
#endif

#ifndef _UNICODE
#define _UNICODE
#endif

#ifndef WIN32_LEAD_AND_MEAN
#define WIN32_LEAD_AND_MEAN
#endif

#include <windows.h>

#include "Hooking.h"
#include "Logging.h"
#include <MinHook.h>
#include <d3d11.h>
#include <dxgi.h>
#include <imgui.h>
#include <imgui_impl_dx11.h>
#include <imgui_impl_win32.h>
#include <memory>

#ifdef DX11
// DX11-WW as of 20240102
constexpr uintptr_t ItemPickupFuncOffset = 0xB912D0;
constexpr uintptr_t ItemPutDownKeepFuncOffset = 0x1237FA0;
#endif
#ifdef DX12
// DX12-WW as of 20240102
constexpr uintptr_t ItemPickupFuncOffset = 0x1AD5070;
constexpr uintptr_t ItemPutDownKeepFuncOffset = 0x1E341F0;
#endif

typedef void *(__stdcall *ItemPickup)(void *param1, void *param2, void *param3, void *param4);
typedef void(__stdcall *ItemPutDownKeep)(void *param1, void *param2, void *param3);
typedef HRESULT(__stdcall *Present)(IDXGISwapChain *pSwapChain, UINT SyncInterval, UINT Flags);
typedef LRESULT(CALLBACK *WNDPROC)(HWND, UINT, WPARAM, LPARAM);
LRESULT __stdcall WndProc(const HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved);
bool Startup();
void Shutdown();
DWORD WINAPI MainThread(LPVOID lpThreadParameter);

void CreateRenderTarget(IDXGISwapChain *swapChain);
void CleanupRenderTarget();

#endif
