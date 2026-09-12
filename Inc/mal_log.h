/* mal_log.h
 *
 * Logger for the PC layer: same LOGx macro API and mal::log namespace as MalSTM, but messages go straight to
 * stdout (TRACE/INFO) or stderr (WARNING/ERROR) prefixed with the uptime. MAL_LOG_LEVEL from mal_conf.h applies.
 */

#ifndef MAL_LOG_H_
#define MAL_LOG_H_

#include "mal_inc.h"

#ifndef MAL_LOG_LEVEL
#define MAL_LOG_LEVEL		0		//sets the minimal level of log, which will be output
#endif

#if !defined(MAL_LOG_TYPE)
#define MAL_LOG_TYPE		1
#endif


namespace mal
{
	namespace log
	{
		enum class Level
		{
			TRACE = 0,
			INFO = 1,
			WARNING = 2,
			ERROR = 3
		};

		inline constexpr char HEX2ASCII[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

		inline void init(size_t) {}		//no buffer needed on the host, kept so application code is unchanged
		inline void process() {}
		void func(Level level, bool outputIntro, const char* msg, ...);
	}
}


#if (MAL_LOG_LEVEL < 1)
#define LOGT(...)				mal::log::func(mal::log::Level::TRACE, true, __VA_ARGS__)
#define LOGT_NOINTRO(...)		mal::log::func(mal::log::Level::TRACE, false, __VA_ARGS__)
#else
#define LOGT(...)
#define LOGT_NOINTRO(...)
#endif

#if (MAL_LOG_LEVEL < 2)
#define LOGI(...)				mal::log::func(mal::log::Level::INFO, true, __VA_ARGS__)
#define LOGI_NOINTRO(...)		mal::log::func(mal::log::Level::INFO, false, __VA_ARGS__)
#else
#define LOGI(...)
#define LOGI_NOINTRO(...)
#endif

#if (MAL_LOG_LEVEL < 3)
#define LOGW(...)				mal::log::func(mal::log::Level::WARNING, true, __VA_ARGS__)
#define LOGW_NOINTRO(...)		mal::log::func(mal::log::Level::WARNING, false, __VA_ARGS__)
#else
#define LOGW(...)
#define LOGW_NOINTRO(...)
#endif

#if (MAL_LOG_LEVEL < 4)
#define LOGE(...)				mal::log::func(mal::log::Level::ERROR, true, __VA_ARGS__)
#define LOGE_NOINTRO(...)		mal::log::func(mal::log::Level::ERROR, false, __VA_ARGS__)
#else
#define LOGE(...)
#define LOGE_NOINTRO(...)
#endif

#endif /* MAL_LOG_H_ */
