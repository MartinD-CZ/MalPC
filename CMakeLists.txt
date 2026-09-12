# MalPC - runs MAL application code on a PC (Windows / MSVC for now).
#
# Provides the platform headers an application expects (mal_inc.h, mal_log.h, mal_tick.h) on top of MalCommon, so
# board-independent code and MalCommon itself can be compiled and run natively. It is an INTERFACE library like the
# other Mal* layers: the sources are compiled into the application, which supplies mal_conf.h in its include path.
#
#     add_subdirectory(MalCommon)
#     add_subdirectory(MalPC)
#     add_executable(MyAppPC ${SOURCES})
#     target_link_libraries(MyAppPC PRIVATE MalPC)

add_library(MalPC INTERFACE)

target_sources(MalPC INTERFACE
    "Src/mal_log.cpp"
    "Src/mal_tick.cpp"
)

target_include_directories(MalPC INTERFACE
    "Inc"
)

target_compile_definitions(MalPC INTERFACE
    "MAL_PC"
    "NOMINMAX"
    "WIN32_LEAN_AND_MEAN"
    "_CRT_SECURE_NO_WARNINGS"
)

if (MSVC)
    target_compile_options(MalPC INTERFACE "/W4" "/EHsc" "/utf-8")
endif()

target_link_libraries(MalPC INTERFACE MalCommon)
