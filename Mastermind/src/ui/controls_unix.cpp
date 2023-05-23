#include <termios.h>
#include <unistd.h>

#include <iostream>

#include "controls.h"

int handleKeys() {
    switch (getchar()) {
        case '\n':
            return ENTER;
        case '\x1b':    // Escape character
            getchar();  // Read '[' character
            switch (getchar()) {
                case 'A':
                    return KEY_UP;
                case 'B':
                    return KEY_DOWN;
                case 'C':
                    return KEY_RIGHT;
                case 'D':
                    return KEY_LEFT;
                default:
                    return -1;
            }
    }
}

void enableInputBuffering() {
    termios term;
    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag |= (ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &term);

    std::cout << "\e[?25h";  // Show the cursor
}

void disableInputBuffering() {
    termios term;
    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &term);

    std::cout << "\e[?25l";  // Hide the cursor
}