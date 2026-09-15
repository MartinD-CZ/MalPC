#include "mal_log.h"
#include "mal_tick.h"

#include <cstdarg>
#include <cstdio>


static constexpr char logChr[] = {'T', 'I', 'W', 'E'};


/** Function to log data, should only be called with LOGx macros.
 *
 * @param level			Level of log, see enum.
 * @param outputIntro	If true, the runtime intro is output.
 * @param msg			Message to print, printf-style.
 */
void mal::log::func(Level level, bool outputIntro, const char* msg, ...)
{
	FILE* out = (level >= Level::WARNING) ? stderr : stdout;

	if (outputIntro)
		fprintf(out, "%lu ms %c: ", (unsigned long)tick::get(), logChr[(size_t)level]);

	va_list vaList;
	va_start(vaList, msg);
	vfprintf(out, msg, vaList);
	va_end(vaList);

	fflush(out);
}
