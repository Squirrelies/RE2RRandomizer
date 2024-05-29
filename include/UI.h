#ifndef RE2RR_UI_H
#define RE2RR_UI_H

#include "Common.h"
#include "DllHook.h"
#include "Logging.h"
#include <imgui.h>
#include <imgui_impl_dx11.h>
#include <imgui_impl_win32.h>

namespace RE2RRUI
{
	class UI
	{
	private:
		ImmediateLogger *logger;
		RE2RREnums::Scenario *scenario;
		RE2RREnums::Difficulty *difficulty;
		Randomizer *randomizer;
		ImFont *font;
		std::random_device randomDevice;

	protected:
	public:
		UI(ImmediateLogger *logger)
		{
			this->logger = logger;
			this->scenario = new RE2RREnums::Scenario(RE2RREnums::Scenario::LEON_A);
			this->difficulty = new RE2RREnums::Difficulty(RE2RREnums::Difficulty::NORMAL);
			this->randomizer = nullptr;
			this->font = nullptr;
		}
		~UI()
		{
			this->logger = nullptr;

			delete this->scenario;
			this->scenario = nullptr;

			delete this->difficulty;
			this->difficulty = nullptr;

			delete this->randomizer;
			this->randomizer = nullptr;

			this->font = nullptr;
		}

		void __stdcall DrawMainUI(bool *);
		void __stdcall DrawLogUI(bool *);
		void __stdcall DrawHelpAboutRE2RRUI(bool *);
		void __stdcall DrawDebugOverlay(bool *, bool *);
		void __stdcall SetFont(ImFont *);
		Randomizer *GetRandomizer(void);
	};
}

#endif
