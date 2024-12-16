#include "ai.hpp"
#include "utils.hpp"
#include <limits>

// Constructeur de la classe AI
AI::AI(char playerSymbol) : Player("IA", playerSymbol) {}

// Fonction minimax pour évaluer les meilleurs mouvements possibles
int minimax(char board[9], char currentSymbol, char aiSymbol, char opponentSymbol, bool isMaximizing) {
    // Vérifie si l'ordinateur a gagné
    if (check_winner(board, aiSymbol)) return 10;
    // Vérifie si l'adversaire a gagné
    if (check_winner(board, opponentSymbol)) return -10;
    // Vérifie si le plateau est plein
    if (is_board_full(board)) return 0;

    // Initialise le meilleur score en fonction du joueur (maximisant ou minimisant)
    int bestScore = isMaximizing ? std::numeric_limits<int>::min() : std::numeric_limits<int>::max();

    // Parcourt toutes les cases du plateau
    for (int i = 0; i < 9; ++i) {
        // Vérifie si la case est vide
        if (board[i] == '.') {
            // Place le symbole actuel dans la case
            board[i] = currentSymbol;
            // Appelle récursivement minimax pour évaluer ce mouvement
            int score = minimax(board, isMaximizing ? opponentSymbol : aiSymbol, aiSymbol, opponentSymbol, !isMaximizing);
            // Annule le mouvement
            board[i] = '.';
            // Met à jour le meilleur score en fonction du joueur (maximisant ou minimisant)
            bestScore = isMaximizing ? std::max(score, bestScore) : std::min(score, bestScore);
        }
    }
    return bestScore;
}

// Méthode pour que l'ordinateur fasse un mouvement
int AI::make_move(const char board[9], char opponentSymbol) {
    int bestMove = -1;
    int bestScore = std::numeric_limits<int>::min();
    char tempBoard[9];

    // Copie le plateau actuel dans un plateau temporaire
    for (int i = 0; i < 9; ++i) {
        tempBoard[i] = board[i];
    }

    // Parcourt toutes les cases du plateau
    for (int i = 0; i < 9; ++i) {
        // Vérifie si la case est vide
        if (tempBoard[i] == '.') {
            // Place le symbole de l'ordinateur dans la case
            tempBoard[i] = symbol;
            // Évalue ce mouvement en utilisant minimax
            int moveScore = minimax(tempBoard, opponentSymbol, symbol, opponentSymbol, false);
            // Annule le mouvement
            tempBoard[i] = '.';
            // Met à jour le meilleur mouvement si le score est meilleur
            if (moveScore > bestScore) {
                bestScore = moveScore;
                bestMove = i;
            }
        }
    }
    return bestMove;
}