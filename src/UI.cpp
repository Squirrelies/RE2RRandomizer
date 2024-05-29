#include "UI.h"

void __stdcall RE2RRUI::UI::DrawMainUI(bool *open)
{
	// Always shown items (shown even if the Main UI is hidden)
	static bool show_Overlay = false;
	if (show_Overlay)
		DrawOverlay(&show_Overlay, open);

	// If the Main UI is hidden, exit here.
	if (!*open)
		return;

	// Conditionally shown items (shown only if the Main UI is showing)
	static int_fast32_t randomSeed = randomDevice();
	static bool show_Log = false;
	static bool show_Help_AboutRE2RR = false;
	if (show_Log)
		DrawLogUI(&show_Log);
	else if (show_Help_AboutRE2RR)
		DrawHelpAboutRE2RRUI(&show_Help_AboutRE2RR);

	// Specify a default position/size in case there's no data in the .ini file.
	ImGuiIO &io = ImGui::GetIO();
	ImGui::SetNextWindowPos(ImVec2(io.DisplaySize.x / 4, io.DisplaySize.y / 4), ImGuiCond_FirstUseEver);
	ImGui::SetNextWindowSize(ImVec2(400, 260), ImGuiCond_FirstUseEver);

	if (!ImGui::Begin("Resident Evil 2 REmake Randomizer (RE2RR)", open, ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoCollapse))
	{
		ImGui::End();
		return;
	}

	// Menu Bar
	if (ImGui::BeginMenuBar())
	{
		if (ImGui::BeginMenu("File"))
		{
			ImGui::MenuItem("Overlay", NULL, &show_Overlay);
			ImGui::EndMenu();
		}

		if (ImGui::BeginMenu("Help"))
		{
			ImGui::MenuItem("About RE2RR", NULL, &show_Help_AboutRE2RR);
			ImGui::EndMenu();
		}
		ImGui::EndMenuBar();
	}

	ImGui::SeparatorText("Character/Scenario");
	ImGui::RadioButton("Leon A", (int32_t *)scenario, (int32_t)RE2RREnums::Scenario::LEON_A);
	ImGui::SameLine();
	ImGui::RadioButton("Leon B", (int32_t *)scenario, (int32_t)RE2RREnums::Scenario::LEON_B);
	ImGui::Spacing();

	ImGui::RadioButton("Claire A", (int32_t *)scenario, (int32_t)RE2RREnums::Scenario::CLAIRE_A);
	ImGui::SameLine();
	ImGui::RadioButton("Claire B", (int32_t *)scenario, (int32_t)RE2RREnums::Scenario::CLAIRE_B);
	ImGui::Spacing();

	ImGui::SeparatorText("Difficulty");
	// ImGui::RadioButton("Assisted", difficulty, (int32_t)RE2RREnums::Difficulty::EASY);
	// ImGui::SameLine();
	ImGui::RadioButton("Standard", (int32_t *)difficulty, (int32_t)RE2RREnums::Difficulty::NORMAL);
	ImGui::SameLine();
	ImGui::RadioButton("Hardcore", (int32_t *)difficulty, (int32_t)RE2RREnums::Difficulty::HARD);
	ImGui::Spacing();

	ImGui::Spacing();
	ImGui::Spacing();

	ImGui::InputInt("Seed", &randomSeed, 1, 1000);
	if (ImGui::Button("Generate New Seed"))
	{
		logger->LogMessage("Generate New Seed clicked!\n");
		randomSeed = randomDevice();
	}
	ImGui::SameLine();
	if (ImGui::Button("Randomize"))
	{
		logger->LogMessage("Randomize clicked!\n");

		if (randomizer != nullptr)
			delete randomizer;
		randomizer = new Randomizer(logger);
		randomizer->Randomize(difficulty, scenario, randomSeed);
	}
	ImGui::SameLine();
	if (ImGui::Button("Show/Hide Log"))
		show_Log = !show_Log;

	ImGui::End();
}

void __stdcall RE2RRUI::UI::DrawLogUI(bool *open)
{
	if (this->logger == nullptr)
		return;

	ImGui::SetNextWindowSize(ImVec2(1280, 720), ImGuiCond_FirstUseEver);
	ImGui::SetNextWindowPos(ImVec2(50, 50), ImGuiCond_FirstUseEver);
	this->logger->GetUILog()->Draw("RE2RR Log", open);
}

void __stdcall RE2RRUI::UI::DrawOverlay(bool *open, bool *mainUIOpen)
{
	ImGuiWindowFlags window_flags = ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoFocusOnAppearing | ImGuiWindowFlags_NoNav;
	if (mainUIOpen != nullptr && !*mainUIOpen)
		window_flags |= ImGuiWindowFlags_NoMove;
	ImGui::SetNextWindowPos(ImVec2(5, 5), ImGuiCond_FirstUseEver);
	ImGui::SetNextWindowBgAlpha(0.20f);
	if (ImGui::Begin("RE2RR Debug Overlay", open, window_flags))
	{
		// if (font != nullptr)
		// 	ImGui::PushFont(font);
		if (randomizer == nullptr)
			ImGui::Text("Randomizer not initialized!");
		else
		{
			ImGui::Text("Scenario: %s", RE2RREnums::EnumScenarioToString(randomizer->GetScenario()).c_str());
			ImGui::Text("Difficulty: %s", RE2RREnums::EnumDifficultyToString(randomizer->GetDifficulty()).c_str());
			ImGui::Text("Map Part: %s", RE2RREnums::EnumMapPartsIDToString(randomizer->GetMapPartsID()).c_str());
			ImGui::Text("Map: %s", RE2RREnums::EnumMapIDToString(randomizer->GetMapID()).c_str());
			ImGui::Text("Floor: %s", RE2RREnums::EnumFloorIDToString(randomizer->GetFloorID()).c_str());
			ImGui::Text("Last Item: { %s }", randomizer->GetLastInteractedItem()->ToString().c_str());
			ImGui::Text("Last Guid: %s", GUIDToString(randomizer->GetLastInteractedItemPositionGuid()).c_str());
		}
		// if (font != nullptr)
		// 	ImGui::PopFont();
	}
	ImGui::End();
}

void __stdcall RE2RRUI::UI::DrawHelpAboutRE2RRUI(bool *open)
{
	// Specify a default position/size in case there's no data in the .ini file.
	ImGuiIO &io = ImGui::GetIO();
	ImGui::SetNextWindowPos(ImVec2(io.DisplaySize.x / 4, io.DisplaySize.y / 4), ImGuiCond_FirstUseEver);

	if (!ImGui::Begin("RE2RR: About", open, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_AlwaysAutoResize))
	{
		ImGui::End();
		return;
	}

	ImGui::Text("Resident Evil 2 (2019) Randomizer");
	ImGui::Text("v%s (%d)", RE2RR_VERSION, RE2RR_VERSION_BUILD);
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
		ImGui::Text("v%s (%d)", RE2RR_VERSION, RE2RR_VERSION_BUILD);
		ImGui::Separator();
		ImGui::Text("Build datetime: %s %s", __DATE__, __TIME__);
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

void RE2RRUI::UI::SetFont(ImFont *font)
{
	this->font = font;
}

Randomizer *RE2RRUI::UI::GetRandomizer(void)
{
	return randomizer;
}