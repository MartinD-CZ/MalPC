# MalPC
Layer to run the MAL on a PC (Windows / MSVC for now). Provides `mal_inc.h`, `mal_log.h` (stdout/stderr) and `mal_tick.h` (std::chrono) on top of MalCommon, so board-independent application code and MalCommon can be compiled and run natively - for host builds and unit tests.

See `CLAUDE.md` for the layout and `example_project/Blinky` in mal_dev (`make host`) for a complete host build.
