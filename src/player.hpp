#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>

// Structure représentant un joueur
struct Player {
    std::string name; 
    char symbol;      

    // Constructeur pour initialiser un joueur avec un nom et un symbole
    Player(const std::string& playerName, char playerSymbol);
};

#endif