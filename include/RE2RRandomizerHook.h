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

#include "DX11Hook.h"
#include <MinHook.h>
#include <memory>
#include <windows.h>

#ifdef __cplusplus
extern "C"
{
#endif

	BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved);
	bool Startup();
	void Shutdown();
	DWORD WINAPI MainThread(LPVOID lpThreadParameter);
	DWORD WINAPI DX11Thread(LPVOID lpThreadParameter);
	DWORD WINAPI EjectThread(LPVOID lpThreadParameter);

#ifdef __cplusplus
}
#endif

#endif
