#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>

struct Player {
    std::string name;
    char symbol;

    Player(const std::string& playerName, char playerSymbol);
};

#endif 