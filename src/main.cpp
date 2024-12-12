#include <iostream>
#include "player.hpp"
#include "ai.hpp"

// Fonction pour créer un joueur en demandant son nom et son symbole
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
            std::cout << "| " << i + 1 << " "; // Affiche le numéro de la case si elle est vide
        } else {
            std::cout << "| " << board[i] << " "; // Affiche le symbole du joueur si la case est occupée
        }
        if ((i + 1) % 3 == 0) {
            std::cout << "|\n"; // Nouvelle ligne après chaque rangée de 3 cases
        }
    }
}

// Vérifie si un joueur a gagné
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

// Vérifie si le plateau est plein
bool is_board_full(const char board[9]) {
    for (int i = 0; i < 9; ++i) {
        if (board[i] == '.') {
            return false;
        }
    }
    return true;
}

// Fonction principale pour jouer le jeu
void play_game(Player& player1, Player& player2) {
    char board[9] = {'.', '.', '.', '.', '.', '.', '.', '.', '.'}; // Initialisation du plateau de jeu
    Player* current_player = &player1;

    while (true) {
        draw_game_board(board);
        int move;
        if (current_player->name == "IA") {
            move = static_cast<AI*>(current_player)->make_move(board);
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

int main() {
    int choice;
    std::cout << "Choisissez le mode de jeu:\n";
    std::cout << "1. Joueur vs Joueur\n";
    std::cout << "2. Joueur vs IA\n";
    std::cin >> choice;

    if (choice == 1) {
        Player player1 = create_player();
        std::cout << "Joueur 1: " << player1.name << " avec le symbole " << player1.symbol << std::endl;

        Player player2 = create_player();
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

    return 0;
}