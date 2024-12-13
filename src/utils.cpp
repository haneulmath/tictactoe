#include "utils.hpp"

bool check_winner(const char board[9], char symbol) {
    // Vérifiation des lignes, colonnes et diagonales
    for (int i = 0; i < 3; ++i) {
        if ((board[i * 3] == symbol && board[i * 3 + 1] == symbol && board[i * 3 + 2] == symbol) || // Lignes
            (board[i] == symbol && board[i + 3] == symbol && board[i + 6] == symbol)) { // Colonnes
            return true;
        }
    }
    if ((board[0] == symbol && board[4] == symbol && board[8] == symbol) || // Diagonale principale
        (board[2] == symbol && board[4] == symbol && board[6] == symbol)) { // Diagonale secondaire
        return true;
    }
    return false;
}

// Vérification de l'état du plateau de jeu
bool is_board_full(const char board[9]) {
    for (int i = 0; i < 9; ++i) {
        if (board[i] == '.') {
            return false;
        }
    }
    return true;
}