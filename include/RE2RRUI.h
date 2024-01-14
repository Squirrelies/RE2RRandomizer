#ifndef RE2RR_RE2RRUI_H
#define RE2RR_RE2RRUI_H

#include "Logging.h"
#include "RE2RRandomizerHook.h"
#include <imgui.h>
#include <imgui_impl_dx11.h>
#include <imgui_impl_win32.h>

class RE2RRUI
{
private:
	ImmediateLogger *logger;

protected:
public:
	RE2RRUI(ImmediateLogger *logger)
	{
		this->logger = logger;
	}
	void __stdcall DrawMainUI(bool *);
	void __stdcall DrawFileImportSeedUI(bool *);
	void __stdcall DrawFileExportSeedUI(bool *);
	void __stdcall DrawHelpAboutRE2RRUI(bool *);
};

#endif
