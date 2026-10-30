# Architecture du projet – UML

## 1. Diagramme UML complet

```mermaid
classDiagram
direction TB

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

class Swimmer {
    <<interface>>
    +Swim() int
}

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

class Movement {
    <<abstract interface>>
    +GetMovement()*
}

class Utilities {
    +GetMovement(Entity& entity)
}

class Collisions {
}

class Map {
    -int rows
    -int columns
    -char grid[][]
    +DisplayMap()
    +IsPositionValid(int row, int column) bool
    +CheckCollision(Entity& entity) bool
    +UpdatePosition(Entity& entity)
}

Entity <|-- Player
Player <|-- Warrior
Player <|-- Mage
Warrior <|-- WarriorMage
Mage <|-- WarriorMage

Entity <|-- Enemy
Enemy <|-- Zombie
Enemy <|-- ZombieSwimmer
Enemy <|-- HeadlessZombie

Movement <|.. Zombie
Movement <|.. ZombieSwimmer
Movement <|.. HeadlessZombie

Swimmer <|.. ZombieSwimmer

Utilities ..> Movement : uses
Utilities
