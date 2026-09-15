/* mal_inc.h
 *
 * Root include of the MalPC layer - the PC counterpart of the STM32 family mal_inc.h.
 * Application code includes this (or a peripheral header), never mal_common.h directly.
 */

#pragma once

#include "mal_common.h"

#if !defined(MAL_PC)
#define MAL_PC
#endif


constexpr uint_fast8_t LOWEST_IRQ_PRIORITY = 0;			//no interrupts on the host, kept so shared code compiles
