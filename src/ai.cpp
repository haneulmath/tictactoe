#include "ai.hpp"
#include "utils.hpp"
#include <limits>

AI::AI(char playerSymbol) : Player("IA", playerSymbol) {}

int minimax(char board[9], char currentSymbol, char aiSymbol, char opponentSymbol, bool isMaximizing) {
    if (check_winner(board, aiSymbol)) return 10;
    if (check_winner(board, opponentSymbol)) return -10;
    if (is_board_full(board)) return 0;

    int bestScore = isMaximizing ? std::numeric_limits<int>::min() : std::numeric_limits<int>::max();

    for (int i = 0; i < 9; ++i) {
        if (board[i] == '.') {
            board[i] = currentSymbol;
            int score = minimax(board, isMaximizing ? opponentSymbol : aiSymbol, aiSymbol, opponentSymbol, !isMaximizing);
            board[i] = '.';
            bestScore = isMaximizing ? std::max(score, bestScore) : std::min(score, bestScore);
        }
    }
    return bestScore;
}

int AI::make_move(const char board[9], char opponentSymbol) {
    int bestMove = -1;
    int bestScore = std::numeric_limits<int>::min();
    char tempBoard[9];

    for (int i = 0; i < 9; ++i) {
        tempBoard[i] = board[i];
    }

    for (int i = 0; i < 9; ++i) {
        if (tempBoard[i] == '.') {
            tempBoard[i] = symbol;
            int moveScore = minimax(tempBoard, opponentSymbol, symbol, opponentSymbol, false);
            tempBoard[i] = '.';
            if (moveScore > bestScore) {
                bestScore = moveScore;
                bestMove = i;
            }
        }
    }
    return bestMove;
}