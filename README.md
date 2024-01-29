
## Présentation

Le projet consiste en une application de gestion de tâches basée sur une architecture de file d'attente. Les composants principaux de l'application sont `Boss` qui crée des tâches et les place dans une file d'attente, et `Task` (tâche) qui représente une unité de travail. Il y a également un composant `Minion` qui récupère des tâches de la file d'attente, les exécute et envoie les résultats.

Le projet comprend plusieurs fichiers :

- **Boss.py**: Contient la classe `Boss` qui crée des tâches et les ajoute à la file d'attente.

- **Manager.py**: Contient la classe `QueueManager` qui gère la file d'attente et la classe `QueueClient` utilisée par les autres composants pour interagir avec la file d'attente.

- **Minion.py**: Contient la classe `Minion` qui récupère des tâches de la file d'attente, les exécute et envoie les résultats.

- **Task.py**: Contient la classe `Task` qui représente une tâche avec des opérations de travail et de sérialisation/désérialisation JSON.

- **proxy.py**: Un serveur proxy simple qui expose une tâche de la file d'attente au format JSON lorsqu'une requête HTTP GET est effectuée.

- **low_level.cpp**: Un programme C++ qui effectue une tâche en utilisant la bibliothèque Eigen et en récupérant une tâche à partir de la file d'attente via le proxy.

- **CMakeLists.txt**: Le fichier de configuration CMake pour le projet.

## Exécution du Code

Assurez-vous d'avoir Python et CMake installés sur votre machine.

1. **Cloner le dépôt :**

    ```bash
    git clone https://github.com/Dams66/tp_multithreading
    cd tp_multithreading
    ```

2. **Installer les dépendances CMake :**

    ```bash
    mkdir build
    cd build
    cmake ..
    make
    ```

3. **Exécuter les composants Python :**

    ```bash
    python Boss.py
    python Minion.py
    python proxy.py
    ```

4. **Exécuter le programme C++ :**

    ```bash
    ./low_level
    ```
## Performances

### Comparaison entre Python et C++

L'objectif de la dernière séance de TP à été de comparer les performances de la résolution d'une tâche en Python avec la résolution d'une tâche en C++.

Pour évaluer les performances, nous avons mesuré le temps d'exécution de la résolution d'une tâche spécifique avec les deux langages.

- En python : Pour une taille de matrice de 2000, la résolution prend (en moyenne calculée sur 10 tâches) 0.25 secondes par tâches.

- En C++, j'ai rencontré différents problèmes.

Tout d'abord, la récupération de la réponse r suite au get sur le localhost ne marchait pas pour moi (en C++). Quand je laissais la ligne correspondante, mon code compilait mais ne s'exécutais pas (nous avions cherché ensemble lors de la dernière séance la cause du problème mais sans succès). J'ai alors cherché un moyen de contourner le problème en passant une fausse donnée json créée de toute pièce (sans passer par la lecture du localhost pour récupérer le json).
Dans mon code je crée une matrice de taille 5 random que je passe à la tâche. Cependant, je ne l'utilise pas par la suite car j'ai codé en dur le fait que la description du json me renvoie des matrices randoms a et b de taille 2000 (taille fixée pour les tests).

Avec le solver colPivHouseholderQr et une taille de matrice de 2000, la résolution de mon problème prend 22.8486 secondes

Avec le solver lu et une taille de matrice de 2000, la résolution de mon problème prend 10.4782 secondes

Comme on peut le voir, ces temps-ci sont anormalement élevés et sont je pense représentatif d'une mauvaise utilisation de l'hardware. En toute fin de séance, nous avions parlé de l'ajout d'une ligne dans le CMakeList qui autorisais une utilisation GPU ?? Je n'ai pas eu le temps d'implémenter cette solution.

## A propos du PC

Voici les specs de mon pc utilisé pour l'évaluation des performances:

- CPU: Intel Core i9-13980HX 2.2 - 5.6 GHz 24 coeurs

- RAM: 32 Go DDR5 4800MHz

- GPU: NVIDIA GeForce RTX 4070

- OS: Windows 11

## Auteurs

- Soubirant Damien (https://github.com/Dams66)

---
