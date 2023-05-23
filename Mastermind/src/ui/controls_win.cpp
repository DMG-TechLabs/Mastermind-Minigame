#include <conio.h>
#include <windows.h>


#include <iostream>

#include "controls.h"

int handleKeys() {
    switch (getchar()) {
        case 13:
            return ENTER;
        case '\x1b':    // Escape character
            getchar();  // Read '[' character
            switch (getchar()) {
                case 72:
                    return KEY_UP;
                case 80:
                    return KEY_DOWN;
                case 77:
                    return KEY_RIGHT;
                case 75:
                    return KEY_LEFT;
                default:
                    return -1;
            }
    }
}

void enableInputBuffering() {
    SetConsoleMode(hInput, mode);
    std::cout << "\e[?25h"; // Show the cursor
}

void disableInputBuffering() {
    DWORD mode;
    HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
    GetConsoleMode(hInput, &mode);
    SetConsoleMode(hInput, mode & ~ENABLE_ECHO_INPUT & ~ENABLE_LINE_INPUT);
    std::cout << "\e[?25l"; // Hide the cursor
}