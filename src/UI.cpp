#include "UI.h"

void __stdcall UI::DrawMainUI(bool *open)
{
	if (!*open)
		return;

	static bool show_File_ImportSeed = false;
	static bool show_File_ExportSeed = false;
	static bool show_Help_AboutRE2RR = false;

	// Specify a default position/size in case there's no data in the .ini file.
	ImGuiIO &io = ImGui::GetIO();
	ImGui::SetNextWindowPos(ImVec2(io.DisplaySize.x / 4, io.DisplaySize.y / 4), ImGuiCond_FirstUseEver);
	ImGui::SetNextWindowSize(ImVec2(330, 240), ImGuiCond_FirstUseEver);

	if (show_File_ImportSeed)
		DrawFileImportSeedUI(&show_File_ImportSeed);
	else if (show_File_ExportSeed)
		DrawFileExportSeedUI(&show_File_ExportSeed);
	else if (show_Help_AboutRE2RR)
		DrawHelpAboutRE2RRUI(&show_Help_AboutRE2RR);

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
			ImGui::MenuItem("Import Seed", NULL, &show_File_ImportSeed);
			ImGui::MenuItem("Export Seed", NULL, &show_File_ExportSeed);
			ImGui::EndMenu();
		}

		if (ImGui::BeginMenu("Help"))
		{
			ImGui::MenuItem("About RE2RR", NULL, &show_Help_AboutRE2RR);
			ImGui::EndMenu();
		}
		ImGui::EndMenuBar();
	}

	ImGui::SeparatorText("Character");
	ImGui::RadioButton("Leon", character, 0);
	ImGui::SameLine();
	ImGui::RadioButton("Claire", character, 1);
	ImGui::Spacing();

	ImGui::SeparatorText("Scenario");
	ImGui::RadioButton("A", scenario, 0);
	ImGui::SameLine();
	ImGui::RadioButton("B", scenario, 1);
	ImGui::Spacing();

	ImGui::SeparatorText("Difficulty");
	ImGui::RadioButton("Assisted", difficulty, 0);
	ImGui::SameLine();
	ImGui::RadioButton("Standard", difficulty, 1);
	ImGui::SameLine();
	ImGui::RadioButton("Hardcore", difficulty, 2);
	ImGui::Spacing();

	ImGui::Spacing();
	ImGui::Spacing();

	if (ImGui::Button("Generate Seed"))
	{
		logger->LogMessage("Generate Seed clicked!\n");

		SeedGenerator seedGenerator(logger);
		seedGenerator.GenerateSeed((Character)*character, (Scenario)*scenario, (Difficulty)*difficulty, true);
		if (randomizer != nullptr)
			delete randomizer;
		randomizer = new Randomizer(logger, seedGenerator.GetSeed(), (Difficulty *)difficulty, (Scenario *)scenario, (Character *)character);
	}
	ImGui::SameLine();
	if (ImGui::Button("Enable Randomizer"))
		logger->LogMessage("Enable Randomizer clicked!\n");

	ImGui::End();
}

void __stdcall UI::DrawFileImportSeedUI(bool *open)
{
	// Specify a default position/size in case there's no data in the .ini file.
	ImGuiIO &io = ImGui::GetIO();
	ImGui::SetNextWindowPos(ImVec2(io.DisplaySize.x / 4, io.DisplaySize.y / 4), ImGuiCond_FirstUseEver);
	ImGui::SetNextWindowSize(ImVec2(380, 280), ImGuiCond_FirstUseEver);

	if (!ImGui::Begin("RE2RR: Import Seed", open, ImGuiWindowFlags_NoCollapse))
	{
		ImGui::End();
		return;
	}

	ImGui::End();
}

void __stdcall UI::DrawFileExportSeedUI(bool *open)
{
	// Specify a default position/size in case there's no data in the .ini file.
	ImGuiIO &io = ImGui::GetIO();
	ImGui::SetNextWindowPos(ImVec2(io.DisplaySize.x / 4, io.DisplaySize.y / 4), ImGuiCond_FirstUseEver);
	ImGui::SetNextWindowSize(ImVec2(380, 280), ImGuiCond_FirstUseEver);

	if (!ImGui::Begin("RE2RR: Export Seed", open, ImGuiWindowFlags_NoCollapse))
	{
		ImGui::End();
		return;
	}

	ImGui::End();
}

void __stdcall UI::DrawHelpAboutRE2RRUI(bool *open)
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

Randomizer *UI::GetRandomizer(void)
{
	return randomizer;
}