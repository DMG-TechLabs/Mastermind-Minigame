#include "game.h"

#include <vector>

#include "../text/text.h"
#include "../ui/controls.h"

void printCharacter(int selectedItem, int index, int color, char character);
string makeWord(int *indexes, string characters, int length);

string render(string word) {
    string characters = "abcdefghijklmnopqrstuvwxyz0123456789";
    int color = 1;
    int numOfCharacters = word.length();
    int selected = 0;
    int *indexes = new int[numOfCharacters];

    disableInputBuffering();

    // start every character from 'a'
    for (int i = 0; i < numOfCharacters; i++) {
        indexes[i] = 0;
    }

    while (true) {
        system("clear");
        for (int i = 0; i < numOfCharacters; i++) {
            printCharacter(selected, i, color, characters.at(indexes[i]));
            // cout << characters.at(*indexes.at(i)) << " ";
        }

        // Handle user input
        int keyPressed = handleKeys();
        switch (keyPressed) {
            case KEY_LEFT:
                selected = (selected == 0) ? numOfCharacters - 1 : selected - 1;
                break;
            case KEY_RIGHT:
                selected = (selected == numOfCharacters - 1) ? 0 : selected + 1;
                break;
            case KEY_UP:
                indexes[selected] = (indexes[selected] == characters.size() - 1)
                                        ? 0
                                        : indexes[selected] + 1;
                break;
            case KEY_DOWN:
                indexes[selected] = (indexes[selected] == 0)
                                        ? characters.size() - 1
                                        : indexes[selected] - 1;
                break;
            case ENTER:  // Enter
                // delete indexes;
                enableInputBuffering();

                return makeWord(indexes, characters, numOfCharacters);
        }
    }

    return "Error";
}

void start() {
    std::string key = "abcdefgh";
    string user_try = render(key);;


    cout << endl << user_try << endl;
}


void printCharacter(int selectedItem, int index, int color, char character) {
    std::cout << (selectedItem == index
                      ? Text::color("bg", color) + character + Text::normal
                      : Text::blue + character + Text::normal)
              << " ";
}


string makeWord(int *indexes, string characters, int length) {
    string word = "";

    for (int i = 0; i < length; i++) {
        word += characters.at(indexes[i]);
    }

    return word;
}