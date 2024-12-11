#include "ai.hpp"
#include <cstdlib>
#include <ctime>

AI::AI(char playerSymbol) : Player("IA", playerSymbol) {
    std::srand(std::time(0)); 
}

int AI::make_move(const char board[9]) {
    int move;
    do {
        move = std::rand() % 9;
    } while (board[move] != '.');
    return move;
}