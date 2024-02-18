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
	RE2RREnums::Scenario *scenario;
	RE2RREnums::Difficulty *difficulty;
	Randomizer *randomizer;

protected:
public:
	UI(ImmediateLogger *logger)
	{
		this->logger = logger;
		this->scenario = new RE2RREnums::Scenario(RE2RREnums::Scenario::LEON_A);
		this->difficulty = new RE2RREnums::Difficulty(RE2RREnums::Difficulty::NORMAL);
		this->randomizer = nullptr;
	}
	~UI()
	{
		delete this->scenario;
		delete this->difficulty;
		delete this->randomizer;
	}

	void __stdcall DrawMainUI(bool *);
	void __stdcall DrawFileImportSeedUI(bool *);
	void __stdcall DrawFileExportSeedUI(bool *);
	void __stdcall DrawHelpAboutRE2RRUI(bool *);
	Randomizer *GetRandomizer(void);
};

#endif
