#ifndef RE2RR_RE2RRANDOMIZERHOOK_H
#define RE2RR_RE2RRANDOMIZERHOOK_H

// The DirectX version we're targeting. (TODO: Add detection and support for both so this isn't needed.)
#define DXVERSION 11

// Whether to show a debug console window on attach or not. Info is still logged to file either way.
#define RE2RRDEBUGWINDOW 1

// Version. This is defined at compile time so this is just a placeholder.
#define RE2RR_VERSION "1.0.0"

// Build number. This is defined at compile time so this is just a placeholder.
#define RE2RR_VERSION_BUILD 1234

#ifndef UNICODE
#define UNICODE
#endif

#ifndef _UNICODE
#define _UNICODE
#endif

#ifndef WIN32_LEAD_AND_MEAN
#define WIN32_LEAD_AND_MEAN
#endif

#ifdef __GNUC__
#define UNUSED(x) UNUSED_##x __attribute__((__unused__))
#else
#define UNUSED(x) UNUSED_##x
#endif

#ifdef __GNUC__
#define UNUSED_FUNCTION(x) __attribute__((__unused__)) UNUSED_##x
#else
#define UNUSED_FUNCTION(x) UNUSED_##x
#endif

#define DIRECTINPUT_VERSION 0x0800

#include <windows.h>

#include "Hooking.h"
#include "Logging.h"
#include "RE2RRUI.h"
#include <MinHook.h>
#include <d3d11.h>
#include <dinput.h>
#include <dxgi.h>
#include <imgui.h>
#include <imgui_impl_dx11.h>
#include <imgui_impl_win32.h>
#include <memory>

#if DXVERSION == 11
// DX11-WW as of 20240102
constexpr uintptr_t ItemPickupFuncOffset = 0xB912D0;
constexpr uintptr_t ItemPutDownKeepFuncOffset = 0x1237FA0;
#elif DXVERSION == 12
// DX12-WW as of 20240102
constexpr uintptr_t ItemPickupFuncOffset = 0x1AD5070;
constexpr uintptr_t ItemPutDownKeepFuncOffset = 0x1E341F0;
#endif

extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND, UINT, WPARAM, LPARAM);

typedef void *(__stdcall *ItemPickup)(uint8_t *, uint8_t *, uint8_t *, uint8_t *);
typedef void(__stdcall *ItemPutDownKeep)(uint8_t *, uint8_t *, uint8_t *);
typedef HRESULT(__stdcall *Present)(IDXGISwapChain *, UINT, UINT);
typedef HRESULT(__stdcall *GetDeviceState)(IDirectInputDevice8 *, DWORD, LPVOID);
typedef HRESULT(__stdcall *GetDeviceData)(IDirectInputDevice8 *, DWORD, LPDIDEVICEOBJECTDATA, LPDWORD, DWORD);
typedef LRESULT(CALLBACK *WNDPROC)(HWND, UINT, WPARAM, LPARAM);

BOOL APIENTRY DllMain(HINSTANCE, DWORD, LPVOID);
DWORD WINAPI MainThread(LPVOID);
DWORD WINAPI ShutdownThread(LPVOID);
bool Startup(void);
void Shutdown(void);
__stdcall void *HookItemPickup(uint8_t *, uint8_t *, uint8_t *, uint8_t *);
__stdcall void HookItemPutDownKeep(uint8_t *, uint8_t *, uint8_t *);
void InitImGui(IDXGISwapChain *, ID3D11Device *);
LRESULT __stdcall WndProc(const HWND, UINT, WPARAM, LPARAM);
HRESULT __stdcall hkPresent(IDXGISwapChain *, UINT, UINT);
HRESULT __stdcall HookGetDeviceState(IDirectInputDevice8 *, DWORD, LPVOID);
HRESULT __stdcall HookGetDeviceData(IDirectInputDevice8 *, DWORD, LPDIDEVICEOBJECTDATA, LPDWORD, DWORD);
void __stdcall SetVTables(void);
void CreateRenderTarget(IDXGISwapChain *);
void CleanupRenderTarget(void);

#endif
