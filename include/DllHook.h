#ifndef RE2RR_DLLHOOK_H
#define RE2RR_DLLHOOK_H

#define GAMEEDITION_WW 0
#define GAMEEDITION_CEROZ 1
// The game edition we're targeting. (TODO: Add detection and support for both so this isn't needed.)
#define GAMEEDITION GAMEEDITION_CEROZ

#define DXVERSION_11 0
#define DXVERSION_12 1
// The DirectX version we're targeting. (TODO: Add detection and support for both so this isn't needed.)
#define DXVERSION DXVERSION_11

// Whether to show a debug console window on attach or not. Info is still logged to file either way.
#define RE2RRDEBUGWINDOW 1

// ImGUI configuration options.
#define IMGUI_USER_CONFIG "ImGUIConfig.h"

// Version. This is defined at compile time so this is just a placeholder.
#define RE2RR_VERSION "1.0.0"

// Build number. This is defined at compile time so this is just a placeholder.
#define RE2RR_VERSION_BUILD 202405281

#define DIRECTINPUT_VERSION 0x0800

#include "Common.h"
#include "File.h"
#include "Hashes.h"
#include "Hooking.h"
#include "Logging.h"
#include "Randomizer.h"
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
#include <windows.h>

#if (DXVERSION == DXVERSION_11 && GAMEEDITION == GAMEEDITION_WW)
// DX11-WW as of 20240102
constexpr uintptr_t ItemPickupFuncOffset = 0xB912D0;         // app.ropeway.gui.GUIMaster.openInventoryGetItemMode(app.ropeway.gamemastering.InventoryManager.StockItem, app.ropeway.gimmick.action.SetItem.SetItemSaveData)
constexpr uintptr_t UIMapManagerUpdateFuncOffset = 0x95E430; // app.ropeway.gamemastering.UIMapManager.update()
#elif (DXVERSION == DXVERSION_12 && GAMEEDITION == GAMEEDITION_WW)
// DX12-WW as of 20240102
constexpr uintptr_t ItemPickupFuncOffset = 0xB912D0;
constexpr uintptr_t UIMapManagerUpdateFuncOffset = 0x95E430;
#elif (DXVERSION == DXVERSION_11 && GAMEEDITION == GAMEEDITION_CEROZ)
// DX11-CeroZ as of 20240102
constexpr uintptr_t ItemPickupFuncOffset = 0xB912D0;
constexpr uintptr_t UIMapManagerUpdateFuncOffset = 0x95E430;
#elif (DXVERSION == DXVERSION_12 && GAMEEDITION == GAMEEDITION_CEROZ)
// DX12-CeroZ as of 20240102
constexpr uintptr_t ItemPickupFuncOffset = 0xB912D0;
constexpr uintptr_t UIMapManagerUpdateFuncOffset = 0x95E430;
#endif

extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND, UINT, WPARAM, LPARAM);

typedef uintptr_t(__stdcall *ItemPickup)(uintptr_t, uintptr_t, uintptr_t, uintptr_t);
typedef void(__stdcall *UIMapManagerUpdate)(uintptr_t, uintptr_t);

typedef HRESULT(__stdcall *Present)(IDXGISwapChain *, UINT, UINT);
typedef HRESULT(__stdcall *GetDeviceState)(IDirectInputDevice8 *, DWORD, LPVOID);
typedef LRESULT(CALLBACK *WNDPROC)(HWND, UINT, WPARAM, LPARAM);

BOOL APIENTRY DllMain(HINSTANCE, DWORD, LPVOID);
DWORD WINAPI MainThread(LPVOID);
DWORD WINAPI ShutdownThread(LPVOID);
bool Startup(void);
void Shutdown(void);

__stdcall uintptr_t HookItemPickup(uintptr_t, uintptr_t, uintptr_t, uintptr_t);
__stdcall void HookUIMapManagerUpdate(uintptr_t, uintptr_t);
HRESULT __stdcall HookPresent(IDXGISwapChain *, UINT, UINT);
HRESULT __stdcall HookGetDeviceState(IDirectInputDevice8 *, DWORD, LPVOID);
LRESULT __stdcall HookWndProc(const HWND, UINT, WPARAM, LPARAM);

void InitImGui(IDXGISwapChain *, ID3D11Device *);
void __stdcall SetVTables(void);
void CreateRenderTarget(IDXGISwapChain *);
void CleanupRenderTarget(void);

#endif
