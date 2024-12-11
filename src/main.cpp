#include <iostream>
#include "player.hpp"

Player create_player() {
    std::string name;
    char symbol;

    // Initialisation du nom et symbole du joueur
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

// Affiche le plateau de jeu
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

int main() {
    Player player1 = create_player();
    std::cout << "Joueur 1: " << player1.name << " avec le symbole " << player1.symbol << std::endl;

    Player player2 = create_player();
    std::cout << "Joueur 2: " << player2.name << " avec le symbole " << player2.symbol << std::endl;

    char board[9] = {'.', '.', '.', '.', '.', '.', '.', '.', '.'};
    draw_game_board(board);

    return 0;
}