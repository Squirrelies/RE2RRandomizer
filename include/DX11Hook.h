#ifndef DX11HOOK_H
#define DX11HOOK_H

#ifndef WIN32_LEAD_AND_MEAN
#define WIN32_LEAD_AND_MEAN
#endif

#include <windows.h>

#include "Logging.h"
#include "Strings.h"
#include <DXGI.h>
#include <MinHook.h>
#include <d3d11.h>
#include <functional>
#include <imgui.h>
#include <imgui_impl_dx11.h>
#include <imgui_impl_win32.h>
#include <mutex>
#include <stdexcept>
#include <string>

#define DX11HOOKAPI __declspec(dllexport)

extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

#ifdef __cplusplus
extern "C"
{
#endif
	typedef HRESULT(__stdcall *DXGISwapChainPresentFunc)(IDXGISwapChain *swapChain, UINT SyncInterval, UINT Flags);

	class DX11HOOKAPI DX11Hook
	{
	private:
		ImmediateLogger *logger;
		std::once_flag isInitialized;
		bool *initSuccess = new bool;

		WNDPROC originalWindowProcedure;
		HWND hWnd;
		ID3D11Device *d3d11Device;
		ID3D11DeviceContext *d3d11DeviceContext;
		ID3D11RenderTargetView *d3d11RenderTargetView;

		DXGISwapChainPresentFunc targetDXGISwapChainPresent = nullptr;
		DXGISwapChainPresentFunc originalDXGISwapChainPresent = nullptr;

		void **vtableDXGISwapChain = nullptr;
		void **vtableD3D11Device = nullptr;
		void **vtableD3D11DeviceContext = nullptr;

		bool TryGetVTables()
		{
			logger->LogMessage("Start of DX11Hook::TryGetVTables() 1.0\n");

			DXGI_SWAP_CHAIN_DESC sd;
			memset(&sd, 0, sizeof(sd));
			sd.BufferCount = 1;
			sd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
			sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
			// sd.OutputWindow = GetForegroundWindow();
			sd.OutputWindow = FindWindow(L"via", L"RESIDENT EVIL 2");
			sd.SampleDesc.Count = 1;
			sd.Windowed = TRUE;
			sd.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;

			const D3D_FEATURE_LEVEL featureLevels[] = {D3D_FEATURE_LEVEL_11_1, D3D_FEATURE_LEVEL_11_0};
			IDXGISwapChain *dxgiSwapChain;

			if (D3D11CreateDeviceAndSwapChain(
			        nullptr,
			        D3D_DRIVER_TYPE_HARDWARE,
			        nullptr,
			        0,
			        featureLevels,
			        sizeof(featureLevels) / sizeof(D3D_FEATURE_LEVEL),
			        D3D11_SDK_VERSION,
			        &sd,
			        &dxgiSwapChain,
			        &d3d11Device,
			        nullptr,
			        &d3d11DeviceContext) == S_OK)
			{
				logger->LogMessage("Start of DX11Hook::TryGetVTables() 1.1t\n");
				vtableDXGISwapChain = *reinterpret_cast<void ***>(dxgiSwapChain);
				vtableD3D11Device = *reinterpret_cast<void ***>(d3d11Device);
				vtableD3D11DeviceContext = *reinterpret_cast<void ***>(d3d11DeviceContext);

				dxgiSwapChain->Release();
				d3d11Device->Release();
				d3d11DeviceContext->Release();

				targetDXGISwapChainPresent = (DXGISwapChainPresentFunc)vtableDXGISwapChain[8];

				return true;
			}

			logger->LogMessage("Start of DX11Hook::TryGetVTables() 1.1f\n");
			return false;
		}

		DWORD GetAllocationProtection(void *address)
		{
			MEMORY_BASIC_INFORMATION mem;
			VirtualQuery(address, &mem, sizeof(mem));
			return mem.AllocationProtect;
		}

		LRESULT __stdcall WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
		{
			if (ImGui_ImplWin32_WndProcHandler(hWnd, msg, wParam, lParam))
				return true;

			return CallWindowProc(originalWindowProcedure, hWnd, msg, wParam, lParam);
		}

		HRESULT __stdcall DXGISwapChainPresentHook(IDXGISwapChain *swapChain, UINT SyncInterval, UINT Flags)
		{
			try
			{
				std::call_once(
				    isInitialized,
				    [=, this]()
				    {
					    logger->LogMessage("Start of DX11Hook::DXGISwapChainPresentHook()[std::call_once] 1.0\n");
					    if (SUCCEEDED(swapChain->GetDevice(__uuidof(ID3D11Device), (void **)&d3d11Device)))
					    {
						    logger->LogMessage("Start of DX11Hook::DXGISwapChainPresentHook()[std::call_once] 1.1t\n");
						    d3d11Device->GetImmediateContext(&d3d11DeviceContext);
						    DXGI_SWAP_CHAIN_DESC sd;
						    logger->LogMessage("Start of DX11Hook::DXGISwapChainPresentHook()[std::call_once] 1.2 (0x%X)\n",
						                       swapChain->GetDesc(&sd));
						    hWnd = sd.OutputWindow;
						    ID3D11Texture2D *backBuffer;
						    logger->LogMessage("Start of DX11Hook::DXGISwapChainPresentHook()[std::call_once] 1.3 (0x%X)\n",
						                       swapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (void **)&backBuffer));
						    logger->LogMessage("Start of DX11Hook::DXGISwapChainPresentHook()[std::call_once] 1.4 (0x%X)\n",
						                       d3d11Device->CreateRenderTargetView(backBuffer, nullptr, &d3d11RenderTargetView));
						    logger->LogMessage("Start of DX11Hook::DXGISwapChainPresentHook()[std::call_once] 1.5(%d)\n",
						                       backBuffer->Release());
						    originalWindowProcedure = (WNDPROC)SetWindowLongPtrW(hWnd, GWLP_WNDPROC, (LONG_PTR)(WNDPROC)&WndProc);
						    ImGui::CreateContext();
						    ImGuiIO &io = ImGui::GetIO();
						    io.ConfigFlags = ImGuiConfigFlags_NoMouseCursorChange;
						    logger->LogMessage("Start of DX11Hook::DXGISwapChainPresentHook()[std::call_once] 1.6 (%s)\n",
						                       ImGui_ImplWin32_Init(hWnd) ? "true" : "false");
						    logger->LogMessage("Start of DX11Hook::DXGISwapChainPresentHook()[std::call_once] 1.7 (%s)\n",
						                       ImGui_ImplDX11_Init(d3d11Device, d3d11DeviceContext) ? "true" : "false");
						    *initSuccess = true;
						    logger->LogMessage("Start of DX11Hook::DXGISwapChainPresentHook()[std::call_once] 1.8\n");
					    }
					    else
						    throw new std::runtime_error("Failed in DX11Hook::DXGISwapChainPresentHook()[std::call_once] 1.1f");
				    });
			}
			catch (std::exception &ex)
			{
				logger->LogMessage("Failed in DX11Hook::DXGISwapChainPresentHook()[std::call_once] 1.?e (%s)\n", ex.what());
			}

			if (*initSuccess == 1)
			{
				logger->LogMessage("Start of DX11Hook::DXGISwapChainPresentHook()[initSuccess] 1.0 (%s: 0x%X)\n", *initSuccess ? "true" : "false", *initSuccess);
				ImGui_ImplDX11_NewFrame();
				ImGui_ImplWin32_NewFrame();

				ImGui::NewFrame();

				ImGui::ShowDemoWindow();

				ImGui::EndFrame();
				ImGui::Render();

				d3d11DeviceContext->OMSetRenderTargets(1, &d3d11RenderTargetView, nullptr);
				ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());
			}

			return originalDXGISwapChainPresent(swapChain, SyncInterval, Flags); // Game's drawing.
		}

	protected:
	public:
		DX11Hook(FILE *out)
		{
			logger = new ImmediateLogger(out);
			logger->LogMessage("Start of DX11Hook::ctor()\n");
			*initSuccess = false;

			if (TryGetVTables())
			{
				MH_STATUS status;
				if ((status = MH_CreateHook(reinterpret_cast<void **>(targetDXGISwapChainPresent), (LPVOID)&DXGISwapChainPresentHook, reinterpret_cast<void **>(&originalDXGISwapChainPresent))) != MH_OK)
					logger->LogMessage("Failed in DX11Hook::ctor()[MH_CreateHook(targetDXGISwapChainPresent)]: %s\n", MH_StatusToString(status));

				if ((status = MH_EnableHook(reinterpret_cast<void **>(targetDXGISwapChainPresent))) != MH_OK)
					logger->LogMessage("Failed in DX11Hook::ctor()[MH_EnableHook(targetDXGISwapChainPresent)]: %s\n", MH_StatusToString(status));
			}
			else
				logger->LogMessage("Failed in DX11Hook::ctor()[TryGetVTables()]\n");

			logger->LogMessage("End of DX11Hook::ctor()\n");
		}

		~DX11Hook()
		{
			logger->LogMessage("Start of DX11Hook::dtor()\n");
			*initSuccess = false;
			MH_DisableHook(reinterpret_cast<void **>(targetDXGISwapChainPresent));
			ImGui_ImplDX11_Shutdown();
			ImGui_ImplWin32_Shutdown();
			ImGui::DestroyContext();
			if (d3d11RenderTargetView)
			{
				d3d11RenderTargetView->Release();
				d3d11RenderTargetView = nullptr;
			}
			if (d3d11DeviceContext)
			{
				d3d11DeviceContext->Release();
				d3d11DeviceContext = nullptr;
			}
			if (d3d11Device)
			{
				d3d11Device->Release();
				d3d11Device = nullptr;
			}
			SetWindowLongPtrW(hWnd, GWLP_WNDPROC, (LONG_PTR)originalWindowProcedure);
			logger->LogMessage("End of DX11Hook::dtor()\n");
			delete logger;
		}

		void ToggleUI()
		{
		}
	};

#ifdef __cplusplus
}
#endif

#endif
