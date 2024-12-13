#ifndef AI_HPP
#define AI_HPP

#include "player.hpp"

class AI : public Player {
public:
    AI(char playerSymbol);
    int make_move(const char board[9], char opponentSymbol);
};

int minimax(char board[9], char currentSymbol, char aiSymbol, char opponentSymbol, bool isMaximizing);

#endif