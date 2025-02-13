#ifndef RE2RR_LOGGING_H
#define RE2RR_LOGGING_H

#include "Common.h"
#include <imgui.h>
#include <stdio.h>
#include <windows.h>

namespace RE2RR::Common::Logging
{
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

		LIBRARY_EXPORT_API void Clear();
		LIBRARY_EXPORT_API void AddLog(const char *fmt, ...) IM_FMTARGS(2);
		LIBRARY_EXPORT_API void AddLogV(const char *fmt, __builtin_va_list args);
		LIBRARY_EXPORT_API void Draw(const char *title, bool *p_open = NULL);
	};

	class ImmediateLogger
	{
	private:
		FILE *out;
		UILog &uiLog;

	protected:
	public:
		ImmediateLogger(FILE *out, UILog &uiLog) : out(out), uiLog(uiLog)
		{
		}

		~ImmediateLogger()
		{
			fflush(out);
		}

		LIBRARY_EXPORT_API void LogMessage(const char *format, ...);
		LIBRARY_EXPORT_API UILog &GetUILog();
	};
}

#endif
