#ifndef RE2RR_UI_H
#define RE2RR_UI_H

#include "DllHook.h"
#include "Logging.h"
#include <imgui.h>
#include <imgui_impl_dx11.h>
#include <imgui_impl_win32.h>

class UI
{
private:
	ImmediateLogger *logger;

protected:
public:
	UI(ImmediateLogger *logger)
	{
		this->logger = logger;
	}
	~UI()
	{
	}

	void __stdcall DrawMainUI(bool *);
	void __stdcall DrawFileImportSeedUI(bool *);
	void __stdcall DrawFileExportSeedUI(bool *);
	void __stdcall DrawHelpAboutRE2RRUI(bool *);
};

#endif
