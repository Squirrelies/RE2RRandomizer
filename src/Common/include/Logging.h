#ifndef RE2RR_LOGGING_H
#define RE2RR_LOGGING_H

#include "Common.h"
#include <exception>
#include <format>
#include <imgui.h>
#include <print>
#include <source_location>
// #include <stdio.h>
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
		LIBRARY_EXPORT_API void AddLog(const char *str);
		LIBRARY_EXPORT_API void AddLog(const std::string_view str);
		template <typename... Args>
		LIBRARY_EXPORT_API inline void AddLogF(std::string_view fmt, Args &&...args)
		{
			AddLog(std::vformat(fmt, std::make_format_args(args...)));
		}
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
			std::fflush(out);
		}

		LIBRARY_EXPORT_API void LogMessage(std::string_view message);
		template <typename... Args>
		LIBRARY_EXPORT_API inline void LogMessage(std::string_view fmt, Args &&...args)
		{
			LogMessage(std::vformat(fmt, std::make_format_args(args...)));
		}
		LIBRARY_EXPORT_API void LogException(const std::exception &ex, const std::source_location &location = std::source_location::current());
		LIBRARY_EXPORT_API UILog &GetUILog();
	};
}

#endif
