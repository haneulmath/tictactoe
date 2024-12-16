# TICTACTOE

## Éxécution du programme 
- Lancer TicTacToe
- Testé sur MacOS

## Organisation du code
Le projet est organisé en plusieurs fichiers pour une meilleure modularité et lisibilité :

- `main.cpp` : Contient la fonction principale et gère le flux principal du jeu, y compris la création des joueurs et le choix du mode de jeu.
- `player.hpp` et `player.cpp` : Définissent la structure `Player` et son constructeur.
- `ai.hpp` et `ai.cpp` : Définissent la classe `AI` qui hérite de `Player` et implémentent les méthodes pour que l'IA fasse un mouvement en utilisant l'algorithme minimax.
- `utils.hpp` et `utils.cpp` : Contiennent des fonctions utilitaires comme `check_winner` pour vérifier si un joueur a gagné et `is_board_full` pour vérifier si le plateau est plein.

## Choix d'implémentation
- **Modularité** : Le code est divisé en plusieurs fichiers pour séparer les différentes responsabilités (gestion des joueurs, IA, utilitaires).
- **IA avec Minimax** : L'ordinateur utilise l'algorithme minimax pour évaluer les meilleurs mouvements possibles.

## Améliorations
### Permettre au joueur de relancer une partie
- Ajout d'une fonction `play_again` qui demande au joueur s'il souhaite rejouer après la fin d'une partie. 
- Les paramètres entrés au début de la partie sont conservés. 
- Pour changer de mode de jeu il faut quitter la partie. 

###  Améliorations possibles
- **Interface graphique** : Ajouter une interface graphique pour rendre le jeu plus attractif.
- **Niveaux de difficulté** : Implémenter différents niveaux de difficulté pour l'IA.
- **Statistiques** : Enregistrer et afficher les statistiques des joueurs (nombre de victoires, défaites, etc.).

## Bilan
1. **Choix du joueur qui commence** :
   - Initialement, le joueur qui commence était toujours le même.
   - Utilisation de la fonction `rand()` pour choisir aléatoirement le joueur qui commence.

2. **Validation des symboles des joueurs** :
   - Les joueurs pouvaient choisir des symboles invalides ou le même symbole, ce qui causait des conflits.
   - Ajout de vérifications pour s'assurer que les joueurs choisissent les symboles valides (X ou O).

3. **Implémentation de l'algorithme Minimax** :
   - L'algorithme minimax était complexe à implémenter correctement, surtout pour gérer les différents états du plateau de jeu.
   - Décomposition de l'algorithme en étapes plus petites et tests unitaires pour vérifier chaque partie de l'algorithme.

4. **Gestion des entrées utilisateur** :
   - Les entrées utilisateur incorrectes pouvaient causer des plantages ou des comportements inattendus.
   - Ajout de boucles de validation pour redemander les entrées en cas d'erreur.

5. **Détection des conditions de victoire et de match nul** :
   - La vérification des conditions de victoire et de match nul devait être précise pour éviter les erreurs de logique.
   - Implémentation des fonctions `check_winner` et `is_board_full` pour centraliser et simplifier la logique de vérification des conditions de fin de jeu.

