# Game Architecture – UML Class Diagram

## Complete UML Diagram

```mermaid
classDiagram
direction TB

%% =========================
%% ENTITY
%% =========================

class Entity {
    <<abstract>>
    #int life = 1
    #int damage = 1
    #char avatar
    +int Row
    +int Column
    +setAvatar(char avatar)
    +getAvatar() char
    +GetDirections()
    +Damage(Entity& attacker, int damage)
    +CanDead() bool
}

%% =========================
%% PLAYER
%% =========================

class Player {
    <<abstract>>
}

class Warrior {
    -char avatar = 'W'
    +Attack()
    +CanKillWhenCollid(int Damage, Entity& Ennemies, Collisions[] collid)
}

class Mage {
    -int[][] specialGrille
    +attackSpecial(int[][] specialGrille)
}

class WarriorMage {
    -char avatar = 'G'
    -int[][] wmAttackGrille
    +Attack()
    +attackSpecial()
}

%% =========================
%% ENEMY
%% =========================

class Enemy {
    <<abstract>>
    +TypeEnemy typeEnemy
    +Movement()
    +IsCollisionBlocked() bool
}

class Zombie {
    -char avatar = 'Z'
    +Movement() override
    +GetMovement() override
}

class ZombieSwimmer {
    -int oxygen = 3
    +Movement() override
    +GetMovement() override
    +Swim() int
}

class HeadlessZombie {
    +Movement() override
    +GetMovement() override
}

%% =========================
%% ENUM
%% =========================

class TypeEnemy {
    <<enumeration>>
    Zombie
    ZombieSwimmer
    HeadlessZombie
}

%% =========================
%% INTERFACES
%% =========================

class Movement {
    <<interface>>
    +GetMovement()*
}

class Swimmer {
    <<interface>>
    +Swim()*
}

%% =========================
%% UTILITIES
%% =========================

class Utilities {
    +Vector2 position
}

%% =========================
%% COLLISIONS
%% =========================

class Collisions {
    +CheckCollision(Entity& entity, Map& map) bool
    +CheckEntityCollision(Entity& entity, Entity& other) bool
    +IsBlocked(int row, int column, Map& map) bool
}

%% =========================
%% MAP
%% =========================

class Map {
    -int rows
    -int columns
    -int[][] grid
    +InitializeMap()
    +DisplayMap()
    +IsPositionValid(int row, int column) bool
    +UpdatePosition(Entity& entity)
    +GetCell(int row, int column) int
}

%% =========================
%% GAME SINGLETON
%% =========================

class Game {
    <<Singleton>>
    -static Game* instance
    -Map map
    -bool isRunning
    -Game()
    +static Game& GetInstance()
    +Initialize()
    +Start()
    +Update()
    +End()
    +GetMap() Map&
}

%% =========================
%% INHERITANCE
%% =========================

Entity <|-- Player
Player <|-- Warrior
Player <|-- Mage

Warrior <|-- WarriorMage
Mage <|-- WarriorMage

Entity <|-- Enemy
Enemy <|-- Zombie
Enemy <|-- ZombieSwimmer
Enemy <|-- HeadlessZombie

%% =========================
%% INTERFACE IMPLEMENTATION
%% =========================

Movement <|.. Zombie
Movement <|.. ZombieSwimmer
Movement <|.. HeadlessZombie

Swimmer <|.. ZombieSwimmer

%% =========================
%% ASSOCIATIONS
%% =========================

Enemy --> TypeEnemy : uses

Game "1" *-- "1" Map : owns

Game ..> Player : manages
Game ..> Enemy : manages

Collisions ..> Entity : checks
Collisions ..> Map : checks
Entity ..> Utilities : uses

note for WarriorMage "Multiple inheritance.\nWarrior and Mage use virtual inheritance from Player in C++."

note for Collisions "Centralizes collision detection.\nMap handles terrain and boundaries.\nEnemy defines its collision behavior."
```

## 3. Explication de la classe Collisions

La classe `Collisions` sert de gestionnaire central des collisions.

| Classe | Responsabilité |
|---|---|
| Entity | Contient la position et les caractéristiques communes |
| Enemy | Définit le comportement et les règles propres aux ennemis |
| Map | Gère les cases, les obstacles et les limites |
| Collisions | Vérifie les collisions entre entités et avec la carte |

Exemple de fonctionnement :

1. Une entité souhaite se déplacer.
2. `Map` fournit les informations sur la case ciblée.
3. `Collisions` vérifie si le déplacement est autorisé.
4. Si la case est libre, `Map` met à jour la position.
5. Si une collision est détectée, le déplacement est refusé ou traité selon le type d'entité.

**Important :** `IsCollisionBlocked()` dans `Enemy` doit uniquement définir le comportement de collision propre à l'ennemi. La détection effective reste centralisée dans `Collisions`.
