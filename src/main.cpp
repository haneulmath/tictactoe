#include <iostream>
#include "player.hpp"

Player create_player() {
    std::string name;
    char symbol;

    std::cout << "Entrez le nom du joueur: ";
    std::cin >> name;

    std::cout << "Choisissez un symbole (X ou O): ";
    std::cin >> symbol;

    // Validation du symbole
    while (symbol != 'X' && symbol != 'O') {
        std::cout << "Symbole invalide. Choisissez X ou O: ";
        std::cin >> symbol;
    }

    return Player(name, symbol);
}

void draw_game_board(const char board[9]) {
    for (int i = 0; i < 9; ++i) {
        if (board[i] == '.') {
            std::cout << "| " << i + 1 << " ";
        } else {
            std::cout << "| " << board[i] << " ";
        }
        if ((i + 1) % 3 == 0) {
            std::cout << "|\n";
        }
    }
}

bool check_winner(const char board[9], char symbol) {
    // Vérifie les lignes, colonnes et diagonales
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

bool is_board_full(const char board[9]) {
    for (int i = 0; i < 9; ++i) {
        if (board[i] == '.') {
            return false;
        }
    }
    return true;
}

void play_game(Player& player1, Player& player2) {
    char board[9] = {'.', '.', '.', '.', '.', '.', '.', '.', '.'};
    Player* current_player = &player1;

    while (true) {
        draw_game_board(board);
        int move;
        std::cout << current_player->name << ", entrez le numéro de la case où vous voulez jouer: ";
        std::cin >> move;

        // Validation du mouvement
        while (move < 1 || move > 9 || board[move - 1] != '.') {
            std::cout << "Choix invalide. Essayez encore: ";
            std::cin >> move;
        }

        board[move - 1] = current_player->symbol;

        if (check_winner(board, current_player->symbol)) {
            draw_game_board(board);
            std::cout << current_player->name << " a gagné" << std::endl;
            break;
        }

        if (is_board_full(board)) {
            draw_game_board(board);
            std::cout << "Match nul" << std::endl;
            break;
        }

        // Alterner les joueurs
        current_player = (current_player == &player1) ? &player2 : &player1;
    }
}

int main() {
    Player player1 = create_player();
    std::cout << "Joueur 1: " << player1.name << " avec le symbole " << player1.symbol << std::endl;

    Player player2 = create_player();
    std::cout << "Joueur 2: " << player2.name << " avec le symbole " << player2.symbol << std::endl;

    play_game(player1, player2);

    return 0;
}