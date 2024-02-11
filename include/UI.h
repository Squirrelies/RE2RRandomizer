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
	int *character;
	int *scenario;
	int *difficulty;
	Randomizer *randomizer;

protected:
public:
	UI(ImmediateLogger *logger)
	{
		this->logger = logger;
		this->character = new int(0);
		this->scenario = new int(0);
		this->difficulty = new int(0);
		this->randomizer = nullptr;
	}
	~UI()
	{
		delete this->character;
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
