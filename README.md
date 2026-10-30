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
    +Damage(Entity& target, Entity& attacker, int Damage)
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
    -char avatar = 'M'
    -int specialGrille[3][3]
    +attackSpecial(int specialGrille[3][3])
}

class WarriorMage {
    -char avatar = 'G'
    -int wmAttackGrille[4][4]
    -int specialGrille[3][3]
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
    +CheckCollision(Entity& entity) bool
    +IsBlocked(int row, int column) bool
}

%% =========================
%% MAP
%% =========================

class Map {
    -int rows
    -int columns
    -char grid[][]
    +InitializeMap()
    +DisplayMap()
    +IsPositionValid(int row, int column) bool
    +UpdatePosition(Entity& entity)
    +GetCell(int row, int column) char
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
Player <|-- WarriorMage

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
Map ..> Collisions : uses
Entity ..> Utilities : uses
```
