#ifdef _WIN32
#include <conio.h>
#include <Windows.h>
#else
#include <termios.h>
#include <unistd.h>
#endif


#include <iostream>

#include "controls.h"

int handleKeys() {
#ifdef _WIN32
	switch (_getch()) {
	case 13:
		return ENTER;
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
#else
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
#endif
}

void enableInputBuffering() {
#ifdef _WIN32
	HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
    DWORD mode;
    GetConsoleMode(hInput, &mode);
    mode |= (ENABLE_LINE_INPUT | ENABLE_ECHO_INPUT);
    SetConsoleMode(hInput, mode);
#else
	termios term;
	tcgetattr(STDIN_FILENO, &term);
	term.c_lflag |= (ICANON | ECHO);
	tcsetattr(STDIN_FILENO, TCSANOW, &term);

#endif
	std::cout << "\e[?25h";  // Show the cursor
}

void disableInputBuffering() {
#ifdef _WIN32
	DWORD mode;
	HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
	GetConsoleMode(hInput, &mode);
	SetConsoleMode(hInput, mode & ~ENABLE_ECHO_INPUT & ~ENABLE_LINE_INPUT);
#else
	termios term;
	tcgetattr(STDIN_FILENO, &term);
	term.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(STDIN_FILENO, TCSANOW, &term);

#endif
	std::cout << "\e[?25l";  // Hide the cursor
}