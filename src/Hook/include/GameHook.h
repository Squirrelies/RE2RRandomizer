#ifndef RE2RR_GAMEHOOK_H
#define RE2RR_GAMEHOOK_H

#define DIRECTINPUT_VERSION 0x0800

#include "Common.h"
#include "File.h"
#include "Hashes.h"
#include "Hooking.h"
#include "Logging.h"
#include "Memory.h"
#include "Process.h"
#include "Randomizer.h"
#include "Types.h"
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

// Forward declaration instead of including UI.h to prevent circular ref.
namespace RE2RR::Hook::UI
{
	class UI;
}

extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND, UINT, WPARAM, LPARAM);

typedef void(__stdcall *ItemPlacement1)(uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t, uintptr_t);
typedef uintptr_t(__stdcall *ItemPlacement2)(uintptr_t, uintptr_t, uintptr_t);
typedef uintptr_t(__stdcall *ItemPickup)(uintptr_t, uintptr_t, uintptr_t, uintptr_t);
typedef void(__stdcall *UIMapManagerUpdate)(uintptr_t, uintptr_t);

typedef HRESULT(__stdcall *Present)(IDXGISwapChain *, UINT, UINT);
typedef HRESULT(__stdcall *GetDeviceState)(IDirectInputDevice8 *, DWORD, LPVOID);
typedef LRESULT(CALLBACK *WNDPROC)(HWND, UINT, WPARAM, LPARAM);

namespace RE2RR::Hook
{
	class GameHook
	{
	private:
		// Static function offsets
		static uintptr_t ItemPlacement1FuncOffset;
		static uintptr_t ItemPlacement2FuncOffset;
		static uintptr_t ItemPickupFuncOffset;
		static uintptr_t UIMapManagerUpdateFuncOffset;

		// Member variables
		HINSTANCE dllInstance;
		HANDLE mainThreadHandle;
		bool startupSuccess;
		FILE *stdoutLogFile;
		std::unique_ptr<RE2RR::Common::Logging::UILog> uiLog;
		std::unique_ptr<RE2RR::Common::Logging::ImmediateLogger> logger;
		std::unique_ptr<RE2RR::Hook::UI::UI> ui;
		void **vtableDXGISwapChain;
		void **vtableD3D11Device;
		void **vtableD3D11DeviceContext;
		void **vtableDirectInput8;
		void **vtableDirectInputDevice8;
		ID3D11Device *device;
		ID3D11DeviceContext *deviceContext;
		ID3D11RenderTargetView *mainRenderTargetView;
		bool initPresent;
		bool initGetDeviceStateKB;
		bool initGetDeviceStateM1;
		bool initGetDeviceStateM2;
		bool initGetDeviceStateJ1;
		bool initGetDeviceStateJ2;
		bool isUIOpen;
		UINT resizeWidth;
		UINT resizeHeight;
		HWND window;
		Present presentFunc;
		GetDeviceState getDeviceStateFunc;
		WNDPROC wndProcFunc;
		ItemPickup itemPickupFuncTarget;
		ItemPickup itemPickupFunc;
		UIMapManagerUpdate uiMapManagerUpdateFuncTarget;
		UIMapManagerUpdate uiMapManagerUpdateFunc;
		RE2RR::Types::Enums::RE2RGameVersion gameVersion;
		RE2RR::Types::Enums::RE2RGameEdition gameEdition;
		RE2RR::Types::Enums::RE2RGameDXVersion gameDXVersion;

		// Private constructor/destructor for singleton
		GameHook();
		~GameHook();

		// Private methods
		bool Startup();
		void Shutdown();
		DWORD WINAPI MainThreadProc();
		void FreeDependencyLibrary(const TCHAR *moduleName);
		void InitImGui(IDXGISwapChain *swapChain, ID3D11Device *device);
		void SetVTables();
		void CreateRenderTarget(IDXGISwapChain *swapChain);
		void CleanupRenderTarget();

		// Static hook callbacks
		static DWORD WINAPI MainThreadStatic(LPVOID lpThreadParameter);
		static DWORD WINAPI ShutdownThreadProc(LPVOID lpThreadParameter);
		static LRESULT CALLBACK HookWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
		static HRESULT CALLBACK HookPresent(IDXGISwapChain *swapChain, UINT syncInterval, UINT flags);
		static HRESULT CALLBACK HookGetDeviceState(IDirectInputDevice8 *device, DWORD cbData, LPVOID lpvData);
		static uintptr_t CALLBACK HookItemPickup(uintptr_t param1, uintptr_t param2, uintptr_t param3, uintptr_t param4);
		static void CALLBACK HookUIMapManagerUpdate(uintptr_t param1, uintptr_t param2);

	public:
		// Singleton access method
		static GameHook &GetInstance();

		// Deleted methods
		// GameHook(void) = delete;                        // default ctor (1)
		//~GameHook(void) = delete;                       // default dtor (2)
		GameHook(const GameHook &) = delete; // copy ctor (3)
		// GameHook(const GameHook &&) = delete;            // move ctor (4)
		GameHook &operator=(const GameHook &) = delete; // copy assignment (5)
		// GameHook &operator=(const GameHook &&) = delete; // move assignment (6)

		// Public methods
		bool Initialize(HINSTANCE hinstDLL);
		const RE2RR::Types::Enums::RE2RGameVersion &GetGameVersion();
		const RE2RR::Types::Enums::RE2RGameEdition &GetGameEdition();
		const RE2RR::Types::Enums::RE2RGameDXVersion &GetGameDXVersion();
	};
}

#endif
