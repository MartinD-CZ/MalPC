#include "mal_tick.h"

#include <chrono>
#include <thread>


static std::chrono::steady_clock::time_point s_start = std::chrono::steady_clock::now();


/** Resets the tick counter. Optional on the PC, kept for symmetry with the MCU layers.
 *
 */
void tick::init()
{
	s_start = std::chrono::steady_clock::now();
}


/** Returns milliseconds since init() (or program start).
 *
 */
uint32_t tick::get()
{
	auto elapsed = std::chrono::steady_clock::now() - s_start;
	return (uint32_t)std::chrono::duration_cast<std::chrono::milliseconds>(elapsed).count();
}


void tick::delay(uint32_t ms)
{
	std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}


void tick::delay_us(uint32_t us)
{
	std::this_thread::sleep_for(std::chrono::microseconds(us));
}
