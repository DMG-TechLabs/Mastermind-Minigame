cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 11)

project(MastermindMinigame)

if(UNIX)
    set(UNIX_SOURCES
        src/ui/controls_unix.cpp
    )
endif(UNIX)

if(WIN32)
    set(WIN_SOURCES
        src/ui/controls_win.cpp
    )
endif(WIN32)

set(SOURCES
    src/ui/controls.h

    src/text/text.h
    src/text/text.cpp

    src/game/game.h
    src/game/game.cpp

    src/main.cpp
)

add_executable(MastermindMinigame ${SOURCES} ${UNIX_SOURCES} ${WIN_SOURCES})
# add_library(MastermindMinigame ${SOURCES} ${UNIX_SOURCES} ${WIN_SOURCES})