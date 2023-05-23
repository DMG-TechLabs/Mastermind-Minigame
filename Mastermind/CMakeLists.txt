cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 11)

project(MastermindMinigame)

set(SOURCES
    src/ui/controls.h
    src/ui/controls.cpp

    src/text/text.h
    src/text/text.cpp

    src/game/game.h
    src/game/game.cpp

    src/main.cpp
)

add_executable(MastermindMinigame ${SOURCES})
# add_library(MastermindMinigame ${SOURCES} ${UNIX_SOURCES} ${WIN_SOURCES})