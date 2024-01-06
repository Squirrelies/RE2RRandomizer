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

#ifdef __cplusplus
extern "C"
{
#endif

	typedef HRESULT(__stdcall *D3D11PresentHook)(IDXGISwapChain *pSwapChain, UINT SyncInterval, UINT Flags);
	typedef void(__stdcall *D3D11DrawIndexedHook)(ID3D11DeviceContext *pContext, UINT IndexCount, UINT StartIndexLocation, INT BaseVertexLocation);
	typedef void(__stdcall *D3D11PSSetShaderResourcesHook)(ID3D11DeviceContext *pContext, UINT StartSlot, UINT NumViews, ID3D11ShaderResourceView *const *ppShaderResourceViews);
	typedef void(__stdcall *D3D11ClearRenderTargetViewHook)(ID3D11DeviceContext *pContext, ID3D11RenderTargetView *pRenderTargetView, const FLOAT ColorRGBA[4]);
	typedef HRESULT(__stdcall *D3D11CreateQueryHook)(ID3D11Device *pDevice, const D3D11_QUERY_DESC *pQueryDesc, ID3D11Query **ppQuery);

	class DX11HOOKAPI DX11Hook
	{
	private:
		ImmediateLogger *logger;
		HWND g_hWnd = nullptr;
		HMODULE g_hModule = nullptr;
		ID3D11Device *g_pd3dDevice = nullptr;
		ID3D11DeviceContext *g_pd3dContext = nullptr;
		IDXGISwapChain *g_pSwapChain = nullptr;
		std::once_flag g_isInitialized;
		UINT pssrStartSlot;
		D3D11_SHADER_RESOURCE_VIEW_DESC Descr;

		D3D11PresentHook phookD3D11Present = nullptr;
		D3D11DrawIndexedHook phookD3D11DrawIndexed = nullptr;
		D3D11CreateQueryHook phookD3D11CreateQuery = nullptr;
		D3D11PSSetShaderResourcesHook phookD3D11PSSetShaderResources = nullptr;
		D3D11ClearRenderTargetViewHook phookD3D11ClearRenderTargetViewHook = nullptr;

		DWORD_PTR *pSwapChainVTable = nullptr;
		DWORD_PTR *pDeviceVTable = nullptr;
		DWORD_PTR *pDeviceContextVTable = nullptr;

		void __stdcall ImplHookDX11_Present(ID3D11Device *device, ID3D11DeviceContext *ctx, IDXGISwapChain *swap_chain)
		{
			// Render!
		}

		HRESULT __stdcall PresentHook(IDXGISwapChain *pSwapChain, UINT SyncInterval, UINT Flags)
		{
			// std::call_once(g_isInitialized, [&]()
			//                {
			// pSwapChain->GetDevice(__uuidof(g_pd3dDevice), reinterpret_cast<void**>(&g_pd3dDevice));
			// g_pd3dDevice->GetImmediateContext(&g_pd3dContext);
			// ImGui_ImplDX11_Init(g_pd3dDevice, g_pd3dContext); });

			// ImplHookDX11_Present(g_pd3dDevice, g_pd3dContext, g_pSwapChain); // Our drawing.
			return phookD3D11Present(pSwapChain, SyncInterval, Flags); // Game's drawing.
		}

		void __stdcall DrawIndexedHook(ID3D11DeviceContext *pContext, UINT IndexCount, UINT StartIndexLocation, INT BaseVertexLocation)
		{
			phookD3D11DrawIndexed(pContext, IndexCount, StartIndexLocation, BaseVertexLocation);
		}

		HRESULT __stdcall hookD3D11CreateQuery(ID3D11Device *pDevice, const D3D11_QUERY_DESC *pQueryDesc, ID3D11Query **ppQuery)
		{
			// if (pQueryDesc->Query == D3D11_QUERY_OCCLUSION)
			// {
			// 	D3D11_QUERY_DESC oqueryDesc = CD3D11_QUERY_DESC();
			// 	(&oqueryDesc)->MiscFlags = pQueryDesc->MiscFlags;
			// 	(&oqueryDesc)->Query = D3D11_QUERY_TIMESTAMP;

			// 	return phookD3D11CreateQuery(pDevice, &oqueryDesc, ppQuery);
			// }

			return phookD3D11CreateQuery(pDevice, pQueryDesc, ppQuery);
		}

		void __stdcall hookD3D11PSSetShaderResources(ID3D11DeviceContext *pContext, UINT StartSlot, UINT NumViews, ID3D11ShaderResourceView *const *ppShaderResourceViews)
		{
			// pssrStartSlot = StartSlot;

			// for (UINT j = 0; j < NumViews; j++)
			// {
			// 	ID3D11ShaderResourceView *pShaderResView = ppShaderResourceViews[j];
			// 	if (pShaderResView)
			// 	{
			// 		pShaderResView->GetDesc(&Descr);

			// 		if ((Descr.ViewDimension == D3D11_SRV_DIMENSION_BUFFER) || (Descr.ViewDimension == D3D11_SRV_DIMENSION_BUFFEREX))
			// 		{
			// 			continue; // Skip buffer resources
			// 		}
			// 	}
			// }

			phookD3D11PSSetShaderResources(pContext, StartSlot, NumViews, ppShaderResourceViews);
		}

		void __stdcall ClearRenderTargetViewHook(ID3D11DeviceContext *pContext, ID3D11RenderTargetView *pRenderTargetView, const FLOAT ColorRGBA[4])
		{
			phookD3D11ClearRenderTargetViewHook(pContext, pRenderTargetView, ColorRGBA);
		}

		DWORD GetAllocationProtection(void *address)
		{
			MEMORY_BASIC_INFORMATION mem;
			VirtualQuery(address, &mem, sizeof(mem));
			return mem.AllocationProtect;
		}

	protected:
	public:
		DX11Hook(HMODULE hModule, HWND hWnd, FILE *out)
		{
			logger = new ImmediateLogger(out);
			logger->LogMessage("Start of DX11Hook::ctor()\n");

			// g_hModule = hModule;
			// g_hWnd = hWnd;

			// // INIT
			// D3D_FEATURE_LEVEL levels[] = {D3D_FEATURE_LEVEL_11_1, D3D_FEATURE_LEVEL_11_0};
			// D3D_FEATURE_LEVEL obtainedLevel;
			// DXGI_SWAP_CHAIN_DESC sd;
			// {
			// 	ZeroMemory(&sd, sizeof(sd));
			// 	sd.BufferCount = 1;
			// 	sd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
			// 	sd.BufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;
			// 	sd.BufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
			// 	sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
			// 	sd.Flags = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH;
			// 	sd.OutputWindow = g_hWnd;
			// 	sd.SampleDesc.Count = 1;
			// 	sd.Windowed = true; //((GetWindowLongPtr(g_hWnd, GWL_STYLE) & WS_POPUP) != 0) ? false : true;
			// 	sd.BufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
			// 	sd.BufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;
			// 	sd.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;

			// 	sd.BufferDesc.Width = 2560;
			// 	sd.BufferDesc.Height = 1440;
			// 	sd.BufferDesc.RefreshRate.Numerator = 0;
			// 	sd.BufferDesc.RefreshRate.Denominator = 1;
			// }

			// HRESULT hr = D3D11CreateDeviceAndSwapChain(nullptr, D3D_DRIVER_TYPE_HARDWARE, nullptr, 0, levels, sizeof(levels) / sizeof(D3D_FEATURE_LEVEL), D3D11_SDK_VERSION, &sd, &g_pSwapChain, &g_pd3dDevice, &obtainedLevel, &g_pd3dContext);
			// if (FAILED(hr))
			// {
			// 	logger->LogMessage("Failed to create device and swapchain: 0x%X\n", hr);
			// 	throw new std::runtime_error("Failed to create device and swapchain");
			// }
			// logger->LogMessage("Created device and swapchain: D3D_FEATURE_LEVEL (0x%X)\n", obtainedLevel);

			// MH_STATUS status;
			// DWORD oldProtect;
			// // Swap Chain
			// pSwapChainVTable = (DWORD_PTR *)(g_pSwapChain);
			// pSwapChainVTable = (DWORD_PTR *)(pSwapChainVTable[0]);

			// // [8]	6ED3FAAD	(CDXGISwapChain::Present)
			// logger->LogMessage("Swapchain 1.0\n");
			// auto boundPresentHook = std::bind(&DX11Hook::PresentHook, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3);
			// logger->LogMessage("Swapchain 1.1\n");
			// VirtualProtect(reinterpret_cast<LPVOID>(&boundPresentHook), sizeof(DWORD), PAGE_EXECUTE_READWRITE, &oldProtect);
			// logger->LogMessage("Swapchain 1.2\n");
			// if ((status = MH_CreateHook(reinterpret_cast<LPVOID>((DWORD_PTR *)pSwapChainVTable[8]), &boundPresentHook, reinterpret_cast<LPVOID *>(&phookD3D11Present))) != MH_OK)
			// {
			// 	const char errorMessage[] = "Failed to create hook (PresentHook): %s\n";
			// 	logger->LogMessage(errorMessage, MH_StatusToString(status));
			// 	throw new std::runtime_error(errorMessage);
			// }
			// logger->LogMessage("Swapchain 1.3\n");
			// VirtualProtect(reinterpret_cast<LPVOID>(phookD3D11Present), sizeof(DWORD), PAGE_EXECUTE_READWRITE, &oldProtect);
			// logger->LogMessage("Swapchain 1.4\n");
			// if ((status = MH_EnableHook(reinterpret_cast<LPVOID>((DWORD_PTR *)pSwapChainVTable[8]))) != MH_OK)
			// {
			// 	const char errorMessage[] = "Failed to enable hook (pSwapChainVTable[8]): %s\n";
			// 	logger->LogMessage(errorMessage, MH_StatusToString(status));
			// 	throw new std::runtime_error(errorMessage);
			// }
			// logger->LogMessage("Swapchain 1.5\n");

			// // Device Context
			// pDeviceContextVTable = (DWORD_PTR *)(g_pd3dContext);
			// pDeviceContextVTable = (DWORD_PTR *)(pDeviceContextVTable[0]);

			// // [12]	6C5F2D28	(CContext::ID3D11DeviceContext2_DrawIndexed_<1>)
			// logger->LogMessage("Device Context 1.0\n");
			// auto boundDrawIndexedHook = std::bind(&DX11Hook::DrawIndexedHook, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4);
			// logger->LogMessage("Device Context 1.1\n");
			// VirtualProtect(reinterpret_cast<LPVOID>(&boundDrawIndexedHook), sizeof(DWORD), PAGE_EXECUTE_READWRITE, &oldProtect);
			// logger->LogMessage("Device Context 1.2\n");
			// if ((status = MH_CreateHook(reinterpret_cast<LPVOID>((DWORD_PTR *)pDeviceContextVTable[12]), &boundDrawIndexedHook, reinterpret_cast<LPVOID *>(&phookD3D11DrawIndexed))) != MH_OK)
			// {
			// 	const char errorMessage[] = "Failed to create hook (DrawIndexedHook): %s\n";
			// 	logger->LogMessage(errorMessage, MH_StatusToString(status));
			// 	throw new std::runtime_error(errorMessage);
			// }
			// logger->LogMessage("Device Context 1.3\n");
			// if ((status = MH_EnableHook(reinterpret_cast<LPVOID>((DWORD_PTR *)pDeviceContextVTable[12]))) != MH_OK)
			// {
			// 	const char errorMessage[] = "Failed to enable hook (pDeviceContextVTable[12]): %s\n";
			// 	logger->LogMessage(errorMessage, MH_StatusToString(status));
			// 	throw new std::runtime_error(errorMessage);
			// }
			// logger->LogMessage("Device Context 1.4\n");

			// // [8]	6C5F22C0	(CContext::ID3D11DeviceContext2_SetShaderResources_<1,4>)
			// logger->LogMessage("Device Context 2.0\n");
			// auto boundhookD3D11PSSetShaderResources = std::bind(&DX11Hook::hookD3D11PSSetShaderResources, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4);
			// logger->LogMessage("Device Context 2.1\n");
			// VirtualProtect(reinterpret_cast<LPVOID>(&boundhookD3D11PSSetShaderResources), sizeof(DWORD), PAGE_EXECUTE_READWRITE, &oldProtect);
			// logger->LogMessage("Device Context 2.2\n");
			// if ((status = MH_CreateHook(reinterpret_cast<LPVOID>((DWORD_PTR *)pDeviceContextVTable[8]), &boundhookD3D11PSSetShaderResources, reinterpret_cast<LPVOID *>(&phookD3D11PSSetShaderResources))) != MH_OK)
			// {
			// 	const char errorMessage[] = "Failed to create hook (hookD3D11PSSetShaderResources): %s\n";
			// 	logger->LogMessage(errorMessage, MH_StatusToString(status));
			// 	throw new std::runtime_error(errorMessage);
			// }
			// logger->LogMessage("Device Context 2.3\n");
			// if ((status = MH_EnableHook(reinterpret_cast<LPVOID>((DWORD_PTR *)pDeviceContextVTable[8]))) != MH_OK)
			// {
			// 	const char errorMessage[] = "Failed to enable hook (pDeviceContextVTable[8]): %s\n";
			// 	logger->LogMessage(errorMessage, MH_StatusToString(status));
			// 	throw new std::runtime_error(errorMessage);
			// }
			// logger->LogMessage("Device Context 2.4\n");

			// // [50]	6C5F5945	(CContext::ID3D11DeviceContext2_ClearRenderTargetView_<1>)
			// logger->LogMessage("Device Context 3.0\n");
			// auto boundClearRenderTargetViewHook = std::bind(&DX11Hook::ClearRenderTargetViewHook, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3);
			// logger->LogMessage("Device Context 3.1\n");
			// VirtualProtect(reinterpret_cast<LPVOID>(&boundClearRenderTargetViewHook), sizeof(DWORD), PAGE_EXECUTE_READWRITE, &oldProtect);
			// logger->LogMessage("Device Context 3.2\n");
			// if ((status = MH_CreateHook(reinterpret_cast<LPVOID>((DWORD_PTR *)pDeviceContextVTable[50]), &boundClearRenderTargetViewHook, reinterpret_cast<LPVOID *>(&phookD3D11ClearRenderTargetViewHook))) != MH_OK)
			// {
			// 	const char errorMessage[] = "Failed to create hook (ClearRenderTargetViewHook): %s\n";
			// 	logger->LogMessage(errorMessage, MH_StatusToString(status));
			// 	throw new std::runtime_error(errorMessage);
			// }
			// logger->LogMessage("Device Context 3.3\n");
			// if ((status = MH_EnableHook(reinterpret_cast<LPVOID>((DWORD_PTR *)pDeviceContextVTable[50]))) != MH_OK)
			// {
			// 	const char errorMessage[] = "Failed to enable hook (pDeviceContextVTable[50]): %s\n";
			// 	logger->LogMessage(errorMessage, MH_StatusToString(status));
			// 	throw new std::runtime_error(errorMessage);
			// }
			// logger->LogMessage("Device Context 3.4\n");

			// // Device
			// pDeviceVTable = (DWORD_PTR *)(g_pd3dDevice);
			// pDeviceVTable = (DWORD_PTR *)pDeviceVTable[0];

			// logger->LogMessage("Device 1.0\n");
			// auto boundhookD3D11CreateQuery = std::bind(&DX11Hook::hookD3D11CreateQuery, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3);
			// logger->LogMessage("Device 1.1\n");
			// VirtualProtect(reinterpret_cast<LPVOID>(&boundhookD3D11CreateQuery), sizeof(DWORD), PAGE_EXECUTE_READWRITE, &oldProtect);
			// logger->LogMessage("Device 1.2\n");
			// if ((status = MH_CreateHook(reinterpret_cast<LPVOID>((DWORD_PTR *)pDeviceVTable[24]), &boundhookD3D11CreateQuery, reinterpret_cast<LPVOID *>(&phookD3D11CreateQuery))) != MH_OK)
			// {
			// 	const char errorMessage[] = "Failed to create hook (hookD3D11CreateQuery): %s\n";
			// 	logger->LogMessage(errorMessage, MH_StatusToString(status));
			// 	throw new std::runtime_error(errorMessage);
			// }
			// logger->LogMessage("Device 1.3\n");
			// if ((status = MH_EnableHook(reinterpret_cast<LPVOID>((DWORD_PTR *)pDeviceVTable[24]))) != MH_OK)
			// {
			// 	const char errorMessage[] = "Failed to enable hook (pDeviceVTable[24]): %s\n";
			// 	logger->LogMessage(errorMessage, MH_StatusToString(status));
			// 	throw new std::runtime_error(errorMessage);
			// }
			// logger->LogMessage("Device 1.4\n");

			// logger->LogMessage("Releasing...\n");
			// g_pd3dDevice->Release();
			// g_pd3dContext->Release();
			// g_pSwapChain->Release();

			logger->LogMessage("End of DX11Hook::ctor()\n");
		}

		~DX11Hook()
		{
			logger->LogMessage("Start of DX11Hook::dtor()\n");
			//
			logger->LogMessage("End of DX11Hook::dtor()\n");
			delete logger;
		}
	};

#ifdef __cplusplus
}
#endif

#endif
