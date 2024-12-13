#include "ai.hpp"
#include <cstdlib>
#include <ctime>

AI::AI(char playerSymbol) : Player("IA", playerSymbol) {
    std::srand(std::time(0)); 
}

// Fonction qui vérifie si l'ordinateur peut bloquer l'adversaire
bool can_block(const char board[9], char symbol, int& move) {
    for (int i = 0; i < 3; ++i) {
        // Vérification des lignes
        if (board[i * 3] == symbol && board[i * 3 + 1] == symbol && board[i * 3 + 2] == '.') {
            move = i * 3 + 2;
            return true;
        }
        if (board[i * 3] == symbol && board[i * 3 + 2] == symbol && board[i * 3 + 1] == '.') {
            move = i * 3 + 1;
            return true;
        }
        if (board[i * 3 + 1] == symbol && board[i * 3 + 2] == symbol && board[i * 3] == '.') {
            move = i * 3;
            return true;
        }
        // Vérification des colonnes
        if (board[i] == symbol && board[i + 3] == symbol && board[i + 6] == '.') {
            move = i + 6;
            return true;
        }
        if (board[i] == symbol && board[i + 6] == symbol && board[i + 3] == '.') {
            move = i + 3;
            return true;
        }
        if (board[i + 3] == symbol && board[i + 6] == symbol && board[i] == '.') {
            move = i;
            return true;
        }
    }
    // Vérification des diagonales
    if (board[0] == symbol && board[4] == symbol && board[8] == '.') {
        move = 8;
        return true;
    }
    if (board[0] == symbol && board[8] == symbol && board[4] == '.') {
        move = 4;
        return true;
    }
    if (board[4] == symbol && board[8] == symbol && board[0] == '.') {
        move = 0;
        return true;
    }
    if (board[2] == symbol && board[4] == symbol && board[6] == '.') {
        move = 6;
        return true;
    }
    if (board[2] == symbol && board[6] == symbol && board[4] == '.') {
        move = 4;
        return true;
    }
    if (board[4] == symbol && board[6] == symbol && board[2] == '.') {
        move = 2;
        return true;
    }
    return false;
}

// Fonction qui détermine le coup de l'ordinateur
int AI::make_move(const char board[9], char opponentSymbol) {
    int move;
    // Si l'ordinateur peut bloquer l'adversaire, il le fait
    if (can_block(board, opponentSymbol, move)) {
        return move;
    }
    // Sinon, il choisit un coup aléatoire
    do {
        move = std::rand() % 9;
    } while (board[move] != '.');
    return move;
}