#ifndef RE2RR_DLLHOOK_H
#define RE2RR_DLLHOOK_H

#define DIRECTINPUT_VERSION 0x0800

#include "Common.h"
#include "File.h"
#include "Hashes.h"
#include "Hooking.h"
#include "Logging.h"
#include "Process.h"
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

static uintptr_t ItemPlacement1FuncOffset;     // app.ropeway.gamemastering.InventoryManager.addSelectedStock(app.ropeway.gamemastering.InventoryManager.ItemData, app.ropeway.gamemastering.Location.ID, app.ropeway.gamemastering.Map.ID, System.Guid)
static uintptr_t ItemPlacement2FuncOffset;     // app.ropeway.gamemastering.InventoryManager.addSelectedStock(app.ropeway.gimmick.action.SetItem.SetItemSaveData)
static uintptr_t ItemPickupFuncOffset;         // app.ropeway.gui.GUIMaster.openInventoryGetItemMode(app.ropeway.gamemastering.InventoryManager.StockItem, app.ropeway.gimmick.action.SetItem.SetItemSaveData)
static uintptr_t UIMapManagerUpdateFuncOffset; // app.ropeway.gamemastering.UIMapManager.update()

extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND, UINT, WPARAM, LPARAM);

typedef void(__stdcall *ItemPlacement1)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t);
typedef uintptr_t(__stdcall *ItemPlacement2)(uintptr_t, uintptr_t, uintptr_t);
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

__stdcall void HookItemPlacement1(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t);
__stdcall uintptr_t HookItemPlacement2(uintptr_t, uintptr_t, uintptr_t);
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
