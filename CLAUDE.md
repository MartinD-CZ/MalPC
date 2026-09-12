# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## What this is

MalPC lets MAL application code and MalCommon compile and run natively on a PC (Windows / MSVC for now). It is a
mock platform layer, not a simulator: it provides the platform headers an application expects — `mal_inc.h`,
`mal_log.h` (LOGx → stdout/stderr with an uptime prefix, same macro API as MalSTM), `mal_tick.h` (`tick::get`,
`delay`, `delay_us` on `std::chrono`) — and nothing else yet. No peripheral mocks (`Gpio`, `Uart`, …); board code
is expected to be behind `#if` blocks in the application's `bsp.cpp` (see `example_project/Blinky/Src/bsp.cpp`).

## Build

`CMakeLists.txt` defines the INTERFACE library `MalPC` (sources compiled into the app, links `MalCommon`, defines
`MAL_PC`, `NOMINMAX`, `WIN32_LEAN_AND_MEAN`, `_CRT_SECURE_NO_WARNINGS`, `/W4 /EHsc /utf-8` on MSVC). A host build:

```cmake
add_subdirectory(MalCommon)
add_subdirectory(MalPC)
add_executable(AppPC ${SOURCES})
target_link_libraries(AppPC PRIVATE MalPC)
```

configured with `cmake -B BuildWin -G "Visual Studio 17 2022" …` — no toolchain file. `example_project/Blinky`
(`make host`) shows the pattern with a `MAL_HOST` option switching between MalSTM and MalPC in one CMakeLists.

The application still supplies `Inc/mal_conf.h` and an `etl_profile.h` for MSVC (template:
`MalCommon/etl_profile_PC.h`; keep `ETL_CPP23_SUPPORTED 0`, VS2022 lacks `if consteval`).

## Caveats

- MSVC has no weak symbols: `ATTR_WEAK` is empty, so MalCommon's default `_customAssert` (fprintf + abort) is the
  one and only definition — a host build must not define another.
- Anything using `__attribute__` directly won't compile here; use the `ATTR_*` macros or `#pragma pack`.
- Existing host test trees (e.g. a `Tests/` folder with hand-written `mal_log.h`/`mal_tick.h` stubs) can link
  `MalPC` instead and drop the stubs.
