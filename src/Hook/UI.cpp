#include "UI.h"

namespace RE2RR::Hook::UI
{
	using namespace std::string_view_literals;

	UI::UI(RE2RR::Common::Logging::ImmediateLogger &logger) : logger(logger)
	{
		// this->logger = logger;
		this->scenario = new RE2RR::Types::Enums::Scenario(RE2RR::Types::Enums::Scenario::LEON_A);
		this->difficulty = new RE2RR::Types::Enums::Difficulty(RE2RR::Types::Enums::Difficulty::NORMAL);
		this->randomizer = nullptr;
		this->font = nullptr;
	}

	UI::~UI()
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

	void __stdcall UI::DrawMainUI(const bool &open)
	{
		// Always shown items (shown even if the Main UI is hidden)
		if (show_Debug_DebugOverlay)
			DrawDebugOverlay(show_Debug_DebugOverlay, open);

		// If the Main UI is hidden, exit here.
		if (!open)
			return;

		// Conditionally shown items (shown only if the Main UI is showing)
		if (show_Log)
			DrawLogUI(show_Log);

		if (show_Help_AboutRE2RR)
			DrawHelpAboutRE2RRUI(show_Help_AboutRE2RR);

		// Specify a default position/size in case there's no data in the .ini file.
		ImGuiIO &io = ImGui::GetIO();
		ImGui::SetNextWindowPos(ImVec2(io.DisplaySize.x / 4, io.DisplaySize.y / 4), ImGuiCond_FirstUseEver);
		ImGui::SetNextWindowSize(ImVec2(400, 260), ImGuiCond_FirstUseEver);
		if (!ImGui::Begin(std::format("RE2R Randomizer: v{:s}", RE2RR::Common::Version::SemVer).c_str(), (bool *)&open, ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoCollapse))
		{
			ImGui::End();
			return;
		}

		// Menu Bar
		if (ImGui::BeginMenuBar())
		{
			if (ImGui::BeginMenu("File"))
			{
				if (ImGui::MenuItem("Export Cheat Sheet", NULL, false, true))
				{
					logger.LogMessage("Export Cheat Sheet clicked!\n"sv);
					randomizer->ExportCheatSheet();
				}
				ImGui::EndMenu();
			}

			if (ImGui::BeginMenu("View"))
			{
				ImGui::MenuItem("Show Log", NULL, &show_Log);
				ImGui::EndMenu();
			}

			if (RE2RR::Common::IsDebug)
			{
				if (ImGui::BeginMenu("Debug"))
				{
					ImGui::MenuItem("Debug Overlay", NULL, &show_Debug_DebugOverlay);
					ImGui::MenuItem("Disable Randomization", NULL, &show_Debug_DisableRandomize);
					ImGui::EndMenu();
				}
			}

			if (ImGui::BeginMenu("Help"))
			{
				ImGui::MenuItem("About RE2RR", NULL, &show_Help_AboutRE2RR);
				ImGui::EndMenu();
			}
			ImGui::EndMenuBar();
		}

		ImGui::SeparatorText("Character/Scenario");
		ImGui::RadioButton("Leon A", (int32_t *)scenario, (int32_t)RE2RR::Types::Enums::Scenario::LEON_A);
		ImGui::SameLine();
		ImGui::RadioButton("Leon B", (int32_t *)scenario, (int32_t)RE2RR::Types::Enums::Scenario::LEON_B);
		ImGui::Spacing();

		ImGui::RadioButton("Claire A", (int32_t *)scenario, (int32_t)RE2RR::Types::Enums::Scenario::CLAIRE_A);
		ImGui::SameLine();
		ImGui::RadioButton("Claire B", (int32_t *)scenario, (int32_t)RE2RR::Types::Enums::Scenario::CLAIRE_B);
		ImGui::Spacing();

		ImGui::SeparatorText("Difficulty");
		// ImGui::RadioButton("Assisted", difficulty, (int32_t)RE2RR::Types::Enums::Difficulty::EASY);
		// ImGui::SameLine();
		ImGui::RadioButton("Standard", (int32_t *)difficulty, (int32_t)RE2RR::Types::Enums::Difficulty::NORMAL);
		ImGui::SameLine();
		ImGui::RadioButton("Hardcore", (int32_t *)difficulty, (int32_t)RE2RR::Types::Enums::Difficulty::HARD);
		ImGui::Spacing();

		ImGui::Spacing();
		ImGui::Spacing();

		ImGui::InputInt("Seed", &randomSeed, 1, 1000);
		if (ImGui::Button("Generate New Seed"))
		{
			logger.LogMessage("Generate New Seed clicked!\n"sv);
			randomSeed = randomDevice();
		}
		ImGui::SameLine();
		if (randomizer == nullptr && ImGui::Button("Attach"))
		{
			logger.LogMessage("Attach clicked for seed {:d}!\n"sv, randomSeed);
			randomizer = new Randomizer(logger, show_Debug_DisableRandomize);
			randomizer->Randomize(*difficulty, *scenario, randomSeed);
		}
		else if (randomizer != nullptr && ImGui::Button("Detach"))
		{
			logger.LogMessage("Detach clicked!\n"sv);
			delete randomizer;
			randomizer = nullptr;
		}

		ImGui::End();
	}

	void __stdcall UI::DrawLogUI(const bool &open)
	{
		// if (this->logger == nullptr)
		// 	return;

		ImGui::SetNextWindowSize(ImVec2(1280, 720), ImGuiCond_FirstUseEver);
		ImGui::SetNextWindowPos(ImVec2(50, 50), ImGuiCond_FirstUseEver);
		this->logger.GetUILog().Draw("RE2RR Log", (bool *)&open);
	}

	void __stdcall UI::DrawDebugOverlay(const bool &open, const bool &mainUIOpen)
	{
		ImGuiWindowFlags window_flags = ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoFocusOnAppearing | ImGuiWindowFlags_NoNav;
		if (!mainUIOpen)
			window_flags |= ImGuiWindowFlags_NoMove;
		ImGui::SetNextWindowPos(ImVec2(5, 5), ImGuiCond_FirstUseEver);
		ImGui::SetNextWindowBgAlpha(0.20f);
		if (ImGui::Begin("RE2RR Debug Overlay", (bool *)&open, window_flags))
		{
			// if (font != nullptr)
			// 	ImGui::PushFont(font);
			if (randomizer == nullptr)
				ImGui::Text("Randomizer not initialized!");
			else
			{
				ImGui::Text("Scenario: %s", RE2RR::Types::Enums::EnumScenarioToString(randomizer->GetScenario()).get()->c_str());
				ImGui::Text("Difficulty: %s", RE2RR::Types::Enums::EnumDifficultyToString(randomizer->GetDifficulty()).get()->c_str());
				ImGui::Text("Floor: %s", randomizer->GetFloorName().get()->c_str());
				ImGui::Text("Map: %s", randomizer->GetMapName().get()->c_str());
				ImGui::Text("Map Part: %s", randomizer->GetMapPartsName().get()->c_str());
				ImGui::Text("Last Guid: %s", RE2RR::Common::Guid::ToString(randomizer->GetLastInteractedItemPositionGuid()).c_str());
				ImGui::Text("Last Original Item: { %s }", randomizer->GetLastInteractedItem().ToString().get()->c_str());
				ImGui::Text("Last Randomized Item: { %s }", randomizer->GetLastRandomizedItem().ToString().get()->c_str());
				ImGui::Text("Last Exception: %s", RE2RR::Common::GetLastExceptionMessage().c_str());
			}
			// if (font != nullptr)
			// 	ImGui::PopFont();
		}
		ImGui::End();
	}

	void __stdcall UI::DrawHelpAboutRE2RRUI(const bool &open)
	{
		// Specify a default position/size in case there's no data in the .ini file.
		ImGuiIO &io = ImGui::GetIO();
		ImGui::SetNextWindowPos(ImVec2(io.DisplaySize.x / 4, io.DisplaySize.y / 4), ImGuiCond_FirstUseEver);

		if (!ImGui::Begin("RE2RR: About", (bool *)&open, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_AlwaysAutoResize))
		{
			ImGui::End();
			return;
		}
		GameHook &hook = GameHook::GetInstance();

		ImGui::Text("Resident Evil 2 (2019) Randomizer");
		ImGui::Text("v%s", RE2RR::Common::Version::SemVer.data());
		ImGui::Separator();
		ImGui::BulletText("Contributors\n\tBenn Powell\n\tSquirrelies");
		ImGui::Spacing();
		ImGui::Spacing();
		bool copyToClipboard = ImGui::Button("Copy to clipboard");
		ImGui::Spacing();
		if (ImGui::BeginChild("buildInfo", ImVec2(0, 0), ImGuiChildFlags_FrameStyle | ImGuiChildFlags_AutoResizeX | ImGuiChildFlags_AutoResizeY, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_AlwaysAutoResize))
		{
			if (copyToClipboard)
			{
				ImGui::LogToClipboard();
				ImGui::LogText("```\n"); // Back quotes will make text appears without formatting when pasting on GitHub
			}

			ImGui::Text("Resident Evil 2 (2019) Randomizer");
			ImGui::Text("v%s", RE2RR::Common::Version::SemVer.data());
			ImGui::Text("%s %s (%s)",
			            RE2RR::Types::Enums::EnumRE2RGameEditionToString(hook.GetGameEdition()).get()->c_str(),
			            RE2RR::Types::Enums::EnumRE2RGameDXVersionToString(hook.GetGameDXVersion()).get()->c_str(),
			            RE2RR::Types::Enums::EnumRE2RGameVersionToString(hook.GetGameVersion()).get()->c_str());
			ImGui::Separator();
			ImGui::Text("Build datetime: %s %s", __DATE__, __TIME__);
			ImGui::Text("Debug build: %s", RE2RR::Common::IsDebug ? "true" : "false");
			ImGui::Text("sizeof(void *): %d", (int)sizeof(void *));
#ifdef _WIN32
			ImGui::Text("define: _WIN32");
#endif
#ifdef _WIN64
			ImGui::Text("define: _WIN64");
#endif
			ImGui::Text("define: __cplusplus=%d", (int)__cplusplus);
#ifdef __STDC__
			ImGui::Text("define: __STDC__=%d", (int)__STDC__);
#endif
#ifdef __STDC_VERSION__
			ImGui::Text("define: __STDC_VERSION__=%d", (int)__STDC_VERSION__);
#endif
#ifdef __GNUC__
			ImGui::Text("define: __GNUC__=%d", (int)__GNUC__);
#endif
#ifdef __clang_version__
			ImGui::Text("define: __clang_version__=%s", __clang_version__);
#endif

#ifdef _MSC_VER
			ImGui::Text("define: _MSC_VER=%d", _MSC_VER);
#endif
#ifdef _MSVC_LANG
			ImGui::Text("define: _MSVC_LANG=%d", (int)_MSVC_LANG);
#endif
#ifdef __MINGW32__
			ImGui::Text("define: __MINGW32__");
#endif
#ifdef __MINGW64__
			ImGui::Text("define: __MINGW64__");
#endif

			if (copyToClipboard)
			{
				ImGui::LogText("\n```");
				ImGui::LogFinish();
			}
			ImGui::EndChild();
		}

		ImGui::End();
	}

	void UI::SetFont(ImFont *font)
	{
		this->font = font;
	}

	Randomizer *UI::GetRandomizer(void)
	{
		return randomizer;
	}
}
