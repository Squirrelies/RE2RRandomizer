#ifndef LOGGING_H
#define LOGGING_H

#ifndef WIN32_LEAD_AND_MEAN
#define WIN32_LEAD_AND_MEAN
#endif

#include <windows.h>

#include <stdio.h>

#define LOGGINGAPI __declspec(dllexport)

#ifdef __cplusplus
extern "C"
{
#endif

	class LOGGINGAPI ImmediateLogger
	{
	private:
		FILE *out;

	protected:
	public:
		ImmediateLogger(FILE *out)
		{
			this->out = out;
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
		}
	};

#ifdef __cplusplus
}
#endif

#endif
