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

#define DIRECTINPUT_VERSION 0x0800

#include <windows.h>

#include "Hooking.h"
#include "Logging.h"
#include <MinHook.h>
#include <d3d11.h>
#include <dinput.h>
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

typedef void *(__stdcall *ItemPickup)(void *, void *, void *, void *);
typedef void(__stdcall *ItemPutDownKeep)(void *, void *, void *);
typedef HRESULT(__stdcall *Present)(IDXGISwapChain *, UINT, UINT);
typedef HRESULT(__stdcall *GetDeviceState)(IDirectInputDevice8 *, DWORD, LPVOID);
typedef LRESULT(CALLBACK *WNDPROC)(HWND, UINT, WPARAM, LPARAM);
LRESULT __stdcall WndProc(const HWND, UINT, WPARAM, LPARAM);
extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND, UINT, WPARAM, LPARAM);

BOOL APIENTRY DllMain(HMODULE, DWORD, LPVOID);
bool Startup();
void Shutdown();
DWORD WINAPI MainThread(LPVOID);

void CreateRenderTarget(IDXGISwapChain *);
void CleanupRenderTarget();

#endif
