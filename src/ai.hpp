#ifndef AI_HPP
#define AI_HPP

#include "player.hpp"

// Classe AI qui hérite de la classe Player
class AI : public Player {
public:
    // Constructeur qui initialise l'ordinateur avec un symbole de joueur
    AI(char playerSymbol);

    // Méthode pour que l'ordinateur fasse un mouvement
    int make_move(const char board[9], char opponentSymbol);
};

// Fonction minimax pour évaluer les meilleurs mouvements possibles
int minimax(char board[9], char currentSymbol, char aiSymbol, char opponentSymbol, bool isMaximizing);

#endif 