#include <iostream>
#include "player.hpp"
#include "ai.hpp"
#include "utils.hpp"

// Fonction pour créer un joueur en demandant son nom et son symbole
Player create_player(char taken_symbol = '\0') {
    std::string name;
    char symbol;

    // Initialisation du nom et symbole du joueur
    std::cout << "Entrez le nom du joueur: ";
    std::cin >> name;
    std::cout << "Choisissez un symbole (X ou O): ";
    std::cin >> symbol;

    // Validation du symbole
    while ((symbol != 'X' && symbol != 'O') || symbol == taken_symbol) {
        if (symbol == taken_symbol) {
            std::cout << "Symbole déjà pris. Choisissez en un autre: ";
        } else {
            std::cout << "Symbole invalide. Choisissez X ou O: ";
        }
        std::cin >> symbol;
    }

    return Player(name, symbol);
}

// Affiche le plateau de jeu
void draw_game_board(const char board[9]) {
    for (int i = 0; i < 9; ++i) {
        if (board[i] == '.') {
            std::cout << "| " << i + 1 << " "; // Affiche le numéro de la case si elle est vide
        } else {
            std::cout << "| " << board[i] << " "; // Affiche le symbole du joueur si la case est occupée
        }
        if ((i + 1) % 3 == 0) {
            std::cout << "|\n"; // Nouvelle ligne après chaque rangée de 3 cases
        }
    }
}

// Fonction principale pour jouer le jeu
void play_game(Player& player1, Player& player2) {
    char board[9] = {'.', '.', '.', '.', '.', '.', '.', '.', '.'}; // Initialisation du plateau de jeu
    Player* current_player = &player1;

    while (true) {
        draw_game_board(board);
        int move;
        if (current_player->name == "IA") {
            move = static_cast<AI*>(current_player)->make_move(board, player1.symbol);
            std::cout << "IA joue sur la case " << move + 1 << std::endl;
        } else {
            std::cout << current_player->name << ", entrez le numéro de la case où vous voulez jouer: ";
            std::cin >> move;
            move--; // Ajuster pour l'index du tableau

            // Validation du mouvement
            while (move < 0 || move > 8 || board[move] != '.') {
                std::cout << "Mouvement invalide. Essayez encore: ";
                std::cin >> move;
                move--; // Ajuster pour l'index du tableau
            }
        }

        board[move] = current_player->symbol; // Mettre à jour le plateau avec le symbole du joueur

        if (check_winner(board, current_player->symbol)) {
            draw_game_board(board); // Afficher le plateau de jeu
            std::cout << current_player->name << " a gagné!" << std::endl;
            break;
        }

        if (is_board_full(board)) {
            draw_game_board(board); // Afficher le plateau de jeu
            std::cout << "Match nul!" << std::endl;
            break;
        }

        // Alterner les joueurs
        current_player = (current_player == &player1) ? &player2 : &player1;
    }
}

// Fonction pour rejouer
bool play_again() {
    char choice;
    std::cout << "Voulez-vous rejouer ? (y/n): ";
    std::cin >> choice;
    return choice == 'y' || choice == 'Y';
}

int main() {
    while (true) {
        int choice;
        std::cout << "Choisissez le mode de jeu:\n";
        std::cout << "1. Joueur vs Joueur\n";
        std::cout << "2. Joueur vs IA\n";
        std::cin >> choice;

        if (choice == 1) {
            Player player1 = create_player();
            std::cout << "Joueur 1: " << player1.name << " avec le symbole " << player1.symbol << std::endl;

            Player player2 = create_player(player1.symbol);
            std::cout << "Joueur 2: " << player2.name << " avec le symbole " << player2.symbol << std::endl;

            play_game(player1, player2); // Lancer le jeu en mode Joueur contre Joueur
        } else if (choice == 2) {
            Player player1 = create_player();
            std::cout << "Joueur: " << player1.name << " avec le symbole " << player1.symbol << std::endl;

            char ai_symbol = (player1.symbol == 'X') ? 'O' : 'X';
            AI ai_player(ai_symbol);
            std::cout << "IA: " << ai_player.name << " avec le symbole " << ai_player.symbol << std::endl;

            play_game(player1, ai_player); // Lancer le jeu en mode Joueur contre IA
        } else {
            std::cout << "Choix invalide." << std::endl;
        }

        if (!play_again()) {
            break;
        }
    }

    return 0;
}