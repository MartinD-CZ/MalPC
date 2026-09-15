/* mal_tick.h
 *
 * Millisecond tick and delays for the PC layer, backed by std::chrono. Same API subset as MalSTM's mal_tick.h.
 */

#pragma once

#include "mal_inc.h"


namespace tick
{
	void init();

	uint32_t get();
	void delay(uint32_t ms);
	void delay_us(uint32_t us);
}
