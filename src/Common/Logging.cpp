#include "Logging.h"

namespace RE2RR::Common::Logging
{
	void UILog::Clear()
	{
		Buf.clear();
		LineOffsets.clear();
		LineOffsets.push_back(0);
	}

	void UILog::AddLog(const char *str)
	{
		int old_size = Buf.size();
		Buf.append(str);
		for (const int new_size = Buf.size(); old_size < new_size; old_size++)
			if (Buf[old_size] == '\n')
				LineOffsets.push_back(old_size + 1);
	}

	void UILog::AddLog(const std::string_view str)
	{
		int old_size = Buf.size();
		Buf.append(std::string(str).c_str());
		for (const int new_size = Buf.size(); old_size < new_size; old_size++)
			if (Buf[old_size] == '\n')
				LineOffsets.push_back(old_size + 1);
	}

	template <typename... Args>
	inline void UILog::AddLogF(std::string_view fmt, Args &&...args)
	{
		AddLog(std::format(fmt, std::forward<Args>(args)...).c_str());
	}

	void UILog::Draw(const char *title, bool *p_open)
	{
		if (!ImGui::Begin(title, p_open))
		{
			ImGui::End();
			return;
		}

		// Options menu
		if (ImGui::BeginPopup("Options"))
		{
			ImGui::Checkbox("Auto-scroll", &AutoScroll);
			ImGui::EndPopup();
		}

		// Main window
		if (ImGui::Button("Options"))
			ImGui::OpenPopup("Options");
		ImGui::SameLine();
		const bool clear = ImGui::Button("Clear");
		ImGui::SameLine();
		const bool copy = ImGui::Button("Copy");
		ImGui::SameLine();
		Filter.Draw("Filter", -100.0F);

		ImGui::Separator();

		if (ImGui::BeginChild("scrolling", ImVec2(0, 0), ImGuiChildFlags_None, ImGuiWindowFlags_HorizontalScrollbar))
		{
			if (clear)
				Clear();
			if (copy)
				ImGui::LogToClipboard();

			ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(0, 0));
			const char *buf = Buf.begin();
			const char *buf_end = Buf.end();
			if (Filter.IsActive())
			{
				for (int line_no = 0; line_no < LineOffsets.Size; line_no++)
				{
					const char *line_start = buf + LineOffsets[line_no];
					const char *line_end = (line_no + 1 < LineOffsets.Size) ? (buf + LineOffsets[line_no + 1] - 1) : buf_end;
					if (Filter.PassFilter(line_start, line_end))
						ImGui::TextUnformatted(line_start, line_end);
				}
			}
			else
			{
				ImGuiListClipper clipper;
				clipper.Begin(LineOffsets.Size);
				while (clipper.Step())
				{
					for (int line_no = clipper.DisplayStart; line_no < clipper.DisplayEnd; line_no++)
					{
						const char *line_start = buf + LineOffsets[line_no];
						const char *line_end = (line_no + 1 < LineOffsets.Size) ? (buf + LineOffsets[line_no + 1] - 1) : buf_end;
						ImGui::TextUnformatted(line_start, line_end);
					}
				}
				clipper.End();
			}
			ImGui::PopStyleVar();

			if (AutoScroll && ImGui::GetScrollY() >= ImGui::GetScrollMaxY())
				ImGui::SetScrollHereY(1.0F);
		}
		ImGui::EndChild();
		ImGui::End();
	}

	void ImmediateLogger::LogMessage(const std::string_view message)
	{
		std::print("{:s}", message.data());
		std::print(out, "{:s}", message.data());
		std::fflush(out);
		this->uiLog.AddLog(message);
	}

	template <typename... Args>
	inline void LogMessage(const std::string_view fmt, const Args &&...args)
	{
		LogMessage(std::format(fmt, std::forward<Args>(args)...));
	}

	void ImmediateLogger::LogException(const std::exception &ex, const std::source_location &location)
	{
		RE2RR::Common::lastExceptionMessage = ex.what();
		const std::string format = std::format("[RE2R-R] {:s} Exception: {:s}\n{:s} @ {:s}:{:d}:{:d}\n",
		                                       typeid(ex).name(),
		                                       RE2RR::Common::lastExceptionMessage,
		                                       location.function_name(),
		                                       location.file_name(),
		                                       location.line(),
		                                       location.column());
		puts(format.c_str());
		fputs(format.c_str(), out);
		fflush(out);
		this->uiLog.AddLog(format.c_str());
	}

	UILog &ImmediateLogger::GetUILog()
	{
		return this->uiLog;
	}
}
