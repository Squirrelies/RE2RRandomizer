#ifndef RE2RR_DLLHOOK_H
#define RE2RR_DLLHOOK_H

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

#define DIRECTINPUT_VERSION 0x0800

#include <windows.h>

#include "Hooking.h"
#include "Logging.h"
#include "Randomizer.h"
#include "SeedGenerator.h"
#include "Types.h"
#include "UI.h"
#include <MinHook.h>
#include <d3d11.h>
#include <d3d12.h>
#include <dinput.h>
#include <dxgi.h>
#include <imgui.h>
#include <imgui_impl_dx11.h>
#include <imgui_impl_dx12.h>
#include <imgui_impl_win32.h>
#include <memory>

#if DXVERSION == 11
// DX11-WW as of 20240102
constexpr uintptr_t ItemPickupFuncOffset = 0xB912D0;
// constexpr uintptr_t ItemPutDownKeepFuncOffset = 0x1237FA0;
constexpr uintptr_t SetCurrentScenarioTypeFuncOffset = 0x1C46590;
constexpr uintptr_t SetCurrentDifficultyFuncOffset = 0x1C46920;
constexpr uintptr_t SetLoadLocationFuncOffset = 0x1C48300;
constexpr uintptr_t SetLoadAreaFuncOffset = 0x1C48350;
#elif DXVERSION == 12
// DX12-WW as of 20240102
constexpr uintptr_t ItemPickupFuncOffset = 0x1AD5070;
// constexpr uintptr_t ItemPutDownKeepFuncOffset = 0x1E341F0;
constexpr uintptr_t SetCurrentScenarioTypeFuncOffset = 0x0000000;
constexpr uintptr_t SetCurrentDifficultyFuncOffset = 0x0000000;
constexpr uintptr_t SetLoadLocationFuncOffset = 0x0000000;
constexpr uintptr_t SetLoadAreaFuncOffset = 0x0000000;
#endif

extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND, UINT, WPARAM, LPARAM);

typedef uintptr_t(__stdcall *ItemPickup)(uintptr_t, uintptr_t, uintptr_t, uintptr_t);
// typedef void(__stdcall *ItemPutDownKeep)(uintptr_t, uintptr_t, uintptr_t);
typedef void(__stdcall *SetCurrentScenarioType)(uintptr_t, uintptr_t, RE2RREnums::Scenario *);
typedef void(__stdcall *SetCurrentDifficulty)(uintptr_t, uintptr_t, RE2RREnums::Difficulty *);
typedef void(__stdcall *SetLoadLocation)(uintptr_t, uintptr_t, RE2RREnums::LocationID *);
typedef void(__stdcall *SetLoadArea)(uintptr_t, uintptr_t, RE2RREnums::MapID *);

typedef HRESULT(__stdcall *Present)(IDXGISwapChain *, UINT, UINT);
typedef HRESULT(__stdcall *GetDeviceState)(IDirectInputDevice8 *, DWORD, LPVOID);
typedef LRESULT(CALLBACK *WNDPROC)(HWND, UINT, WPARAM, LPARAM);

BOOL APIENTRY DllMain(HINSTANCE, DWORD, LPVOID);
DWORD WINAPI MainThread(LPVOID);
DWORD WINAPI ShutdownThread(LPVOID);
bool Startup(void);
void Shutdown(void);
__stdcall uintptr_t HookItemPickup(uintptr_t, uintptr_t, uintptr_t, uintptr_t);
//__stdcall void HookItemPutDownKeep(uintptr_t, uintptr_t, uintptr_t);
__stdcall void HookSetCurrentScenarioType(uintptr_t, uintptr_t, RE2RREnums::Scenario *);
__stdcall void HookSetCurrentDifficulty(uintptr_t, uintptr_t, RE2RREnums::Difficulty *);
__stdcall void HookSetLoadLocation(uintptr_t, uintptr_t, RE2RREnums::LocationID *);
__stdcall void HookSetLoadArea(uintptr_t, uintptr_t, RE2RREnums::MapID *);
void InitImGui(IDXGISwapChain *, ID3D11Device *);
LRESULT __stdcall WndProc(const HWND, UINT, WPARAM, LPARAM);
HRESULT __stdcall hkPresent(IDXGISwapChain *, UINT, UINT);
HRESULT __stdcall HookGetDeviceState(IDirectInputDevice8 *, DWORD, LPVOID);
void __stdcall SetVTables(void);
void CreateRenderTarget(IDXGISwapChain *);
void CleanupRenderTarget(void);

#endif
