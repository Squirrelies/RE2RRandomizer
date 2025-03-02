#ifndef RE2RR_UI_H
#define RE2RR_UI_H

#include "Common.h"
#include "GameHook.h"
#include "Logging.h"
#include "Strings.h"
#include <imgui.h>
#include <imgui_impl_dx11.h>
#include <imgui_impl_win32.h>

namespace RE2RR::Hook::UI
{
	class UI
	{
	private:
		RE2RR::Common::Logging::ImmediateLogger &logger;
		RE2RR::Types::Enums::Scenario *scenario;
		RE2RR::Types::Enums::Difficulty *difficulty;
		Randomizer *randomizer;
		ImFont *font;
		std::random_device randomDevice;
		int_fast32_t randomSeed = randomDevice();

		bool show_Debug_DisableRandomize = false;
		bool show_Debug_DebugOverlay = false;
		bool show_Help_AboutRE2RR = false;
		bool show_Log = false;

	protected:
	public:
		UI(RE2RR::Common::Logging::ImmediateLogger &logger) : logger(logger)
		{
			// this->logger = logger;
			this->scenario = new RE2RR::Types::Enums::Scenario(RE2RR::Types::Enums::Scenario::LEON_A);
			this->difficulty = new RE2RR::Types::Enums::Difficulty(RE2RR::Types::Enums::Difficulty::NORMAL);
			this->randomizer = nullptr;
			this->font = nullptr;
		}
		~UI()
		{
			// this->logger = nullptr;

			delete this->scenario;
			this->scenario = nullptr;

			delete this->difficulty;
			this->difficulty = nullptr;

			delete this->randomizer;
			this->randomizer = nullptr;

			this->font = nullptr;
		}

		void __stdcall DrawMainUI(const bool &);
		void __stdcall DrawLogUI(const bool &);
		void __stdcall DrawHelpAboutRE2RRUI(const bool &);
		void __stdcall DrawDebugOverlay(const bool &, const bool &);
		void __stdcall SetFont(ImFont *);
		Randomizer *GetRandomizer(void);
	};
}

#endif
