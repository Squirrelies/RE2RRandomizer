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

#define RE2RRANDOMIZERHOOKAPI __declspec(dllexport)

#include <MinHook.h>
#include <memory>
#include <windows.h>

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved);
bool Startup();
void Shutdown();
DWORD WINAPI MenuThread(LPVOID lpThreadParameter);
DWORD WINAPI EjectThread(LPVOID lpThreadParameter);

#endif
