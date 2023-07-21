cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(MastermindMinigame)

include_directories(include)

set(SOURCES
    src/ui/controls.cpp

    src/text/text.cpp

    src/game/game.cpp
    src/game/checks.cpp

    src/main.cpp
)

set(HEADERS
    include/game.h
    include/checks.h
    include/controls.h
    include/text.h
)

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})
# add_library(${PROJECT_NAME} ${SOURCES} ${HEADERS})
