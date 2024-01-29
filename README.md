
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


## Auteurs

- Soubirant Damien (https://github.com/Dams66)

--- 