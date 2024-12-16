#include "utils.hpp"

// Fonction qui vérifie si un joueur a gagné
bool check_winner(const char board[9], char symbol) {
    // Vérification des lignes et des colonnes
    for (int i = 0; i < 3; ++i) {
        // Vérification des lignes
        if ((board[i * 3] == symbol && board[i * 3 + 1] == symbol && board[i * 3 + 2] == symbol) || 
            // Vérification des colonnes
            (board[i] == symbol && board[i + 3] == symbol && board[i + 6] == symbol)) {
            return true;
        }
    }
    // Vérification des diagonales
    if ((board[0] == symbol && board[4] == symbol && board[8] == symbol) || // Diagonale principale
        (board[2] == symbol && board[4] == symbol && board[6] == symbol)) { // Diagonale secondaire
        return true;
    }
    return false;
}

// Fonction qui vérifie si le plateau est plein
bool is_board_full(const char board[9]) {
    // Parcourt toutes les cases du plateau
    for (int i = 0; i < 9; ++i) {
        // Si une case est vide, retourne false
        if (board[i] == '.') {
            return false;
        }
    }
    // Si toutes les cases sont pleines, retourne true
    return true;
}