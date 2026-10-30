# Game Architecture – UML Class Diagram

## 1. Complete UML Diagram

```mermaid
classDiagram
direction TB

%% =========================
%% ENTITY
%% =========================

class Entity {
    <<abstract>>
    -int life = 1
    -int Damage = 1
    -char avatar
    +int Row
    +int Column
    +setLife(int life)
    +getLife() int
    +setAvatar(char avatar)
    +getAvatar() char
    +Attack(Entity& target, Entity& attacker, int Damage)
    +Defend(Entity& target, Entity& defender, int Damage)
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
    -int life = 5
    -int Damage = 1
    +SetLife(int lifeWarrior)
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
    -int life = 5
    -int wmAttackGrille[4][4]
    +attackSpecial()
}

%% =========================
%% ENEMY
%% =========================

class Enemy {
    <<abstract>>
    +Enum TypeEnemy
    +int Damage = 1
    +Movement()
    +IsCollisionBlocked() bool
}

class Zombie {
    -char avatar = 'Z'
    -int Damage = 1
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
    +GetMovement(Entity& entity)
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
    +CheckCollision(Entity& entity) bool
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

Game "1" *-- "1" Map : owns
Game ..> Player : manages
Game ..> Enemy
