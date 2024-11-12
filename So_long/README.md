# So_long

## Description

**So_long** est un projet de l'école 42 ayant pour objectif de créer un jeu en 2D inspiré du célèbre jeu "Sokoban". Ce jeu consiste à déplacer un personnage dans un labyrinthe afin de ramasser tous les objets présents et atteindre la sortie. Le projet est conçu pour renforcer les compétences en programmation graphique, en gestion de fenêtres, et en manipulation d'événements via la bibliothèque graphique **MiniLibX**.

## Table des matières
1. [Fonctionnalités](#fonctionnalités)
2. [Prérequis](#prérequis)
3. [Installation](#installation)
4. [Utilisation](#utilisation)
5. [Contrôles du jeu](#contrôles-du-jeu)
6. [Auteurs](#auteurs)

## Fonctionnalités

- Affichage d'une fenêtre graphique en 2D avec MiniLibX.
- Lecture de fichiers de carte au format `.ber`.
- Déplacement du personnage dans un labyrinthe.
- Collecte de tous les objets avant d'atteindre la sortie.
- Fermeture de la fenêtre via des événements clavier ou souris.
- Compteur de mouvements visible dans la fenêtre de jeu.
- Gestion des erreurs de carte et affichage de messages d'erreur en cas de carte invalide.

## Prérequis

Pour compiler et exécuter ce projet, vous devez avoir les éléments suivants :

- **macOS** ou **Linux** (MiniLibX étant conçu pour ces systèmes).
- **Make** pour compiler le projet.
- La bibliothèque graphique **MiniLibX**, incluse dans le projet.
  
## Installation

1. **Clonez le dépôt** :
   ```bash
   git clone https://github.com/username/so_long.git
   cd so_long

 2. Compilation : Utilisez make pour compiler le projet :
```bash
make
```
Cela génère un exécutable appelé so_long.

## Utilisation

Pour lancer le jeu, utilisez la commande suivante, suivie du chemin d'un fichier de carte .ber :

./so_long maps/map.ber

Le fichier .ber doit respecter une structure spécifique :
  La carte doit être un rectangle composé de caractères prédéfinis :
        1 pour les murs
        0 pour les espaces vides
        P pour la position de départ du joueur (un seul P par carte)
        C pour les objets à collecter
        E pour la sortie du labyrinthe

### Exemple de carte

Voici un exemple de carte valide (dans un fichier .ber) :
```bash
111111
1P0C01
100001
1C0E01
111111
```

### Contrôles du jeu
- Touches fléchées ou W/A/S/D pour déplacer le personnage dans les quatre directions.
- Échap pour quitter le jeu ou la croix de la fenetre.

