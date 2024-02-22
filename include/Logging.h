#ifndef RE2RR_LOGGING_H
#define RE2RR_LOGGING_H

#ifndef UNICODE
#define UNICODE
#endif

#ifndef _UNICODE
#define _UNICODE
#endif

#ifndef WIN32_LEAD_AND_MEAN
#define WIN32_LEAD_AND_MEAN
#endif

#include <imgui.h>
#include <stdio.h>
#include <windows.h>

#define RE2RRLOGGINGAPI __declspec(dllexport)

#ifdef __cplusplus
extern "C"
{
#endif

	struct UILog
	{
		ImGuiTextBuffer Buf;
		ImGuiTextFilter Filter;
		ImVector<int> LineOffsets;
		bool AutoScroll;

		UILog()
		{
			AutoScroll = true;
			Clear();
		}

		void Clear()
		{
			Buf.clear();
			LineOffsets.clear();
			LineOffsets.push_back(0);
		}

		void AddLog(const char *fmt, ...) IM_FMTARGS(2)
		{
			int old_size = Buf.size();
			va_list args;
			va_start(args, fmt);
			Buf.appendfv(fmt, args);
			va_end(args);
			for (int new_size = Buf.size(); old_size < new_size; old_size++)
				if (Buf[old_size] == '\n')
					LineOffsets.push_back(old_size + 1);
		}

		void AddLogV(const char *fmt, __builtin_va_list args)
		{
			int old_size = Buf.size();
			Buf.appendfv(fmt, args);
			for (int new_size = Buf.size(); old_size < new_size; old_size++)
				if (Buf[old_size] == '\n')
					LineOffsets.push_back(old_size + 1);
		}

		void Draw(const char *title, bool *p_open = NULL)
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
			bool clear = ImGui::Button("Clear");
			ImGui::SameLine();
			bool copy = ImGui::Button("Copy");
			ImGui::SameLine();
			Filter.Draw("Filter", -100.0f);

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
					ImGui::SetScrollHereY(1.0f);
			}
			ImGui::EndChild();
			ImGui::End();
		}
	};

	class RE2RRLOGGINGAPI ImmediateLogger
	{
	private:
		FILE *out;
		UILog *uiLog;

	protected:
	public:
		ImmediateLogger(FILE *out, UILog *uiLog)
		{
			this->out = out;
			this->uiLog = uiLog;
		}

		~ImmediateLogger()
		{
			fflush(out);
		}

		void LogMessage(const char *format, ...)
		{
			va_list args;

			va_start(args, format);
			vprintf(format, args);
			va_end(args);

			va_start(args, format);
			vfprintf(out, format, args);
			fflush(out);
			va_end(args);

			va_start(args, format);
			this->uiLog->AddLogV(format, args);
			va_end(args);
		}

		UILog *GetUILog()
		{
			return this->uiLog;
		}
	};

#ifdef __cplusplus
}
#endif

#endif
