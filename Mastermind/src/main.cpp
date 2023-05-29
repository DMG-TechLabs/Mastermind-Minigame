#include <iostream>
#include <string>

#include "./game/game.h"

int main(){
    std::string characters = "abcdefghijklmnopqrstuvwxyz0123456789";

    std::string key = "abcdef";
    start(key, characters);


    return 0;
}