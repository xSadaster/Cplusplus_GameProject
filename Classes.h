#pragma once
#include <iostream>
#include <string>

// Abstract Base Class
class GameComponent {
public:
    virtual void show() const = 0; // Purely virtual
    virtual void act() = 0;        // Virtual for polymorphism
    virtual ~GameComponent() {}    // Virtual destructor
};

// Derived Class
class Character : public GameComponent { //Not used directly, but is a base class for Player and Enemy
private:
    short hp;
    short atk;
protected:
    std::string name;
public:  // Default constructor
    Character() : name("NoName"), hp(1), atk(1) {} // Parameterized constructor
    Character(std::string n, short h = 1, short a = 1) : name(n), hp(h), atk(a) {}
    virtual ~Character() {} // Destructor
    
    // Getters and setters
    std::string getName() const { return name; }
    short getHP() const { return hp; }
    short getATK() const { return atk; }
    void setName(const std::string& n) { name = n; }
    void setHP(unsigned short h) { hp = h; }
    void setATK(unsigned short a) { atk = a; }
    // Add virtual getType for runtime polymorphism
    virtual std::string getType() const { return "Character"; }

    // Virtual functions
    virtual void show() const override {
        std::cout << name << " [HP: " << hp << ", ATK: " << atk << "]" << std::endl; }
    virtual void act() override {
        std::cout << name << " waits..." << std::endl;}
};

// Player subclass- that hass a name, hp and atk
// but all Player subclasses will have their own hp & atk
class Player : public Character {
public:
    Player() : Character("Player") {}
    Player(std::string n, int h = 120, int a = 15)
        : Character(n, h, a) {}
    ~Player() {} // No message because we don't want multiple destructor messages to clutter the output

    void show() const override {
        std::cout << "[Player] ";
        Character::show();
    }
    void act() override {
        std::cout << name << " attacks!" << std::endl; // Default action for player, will be overridden by subclasses
    }
    // Operator overloading for Player: - for HP, + for ATK
    Player operator-(int hp) const {
        Player result = *this;
        result.setHP(getHP() - hp);
        return result;
    }
    Player operator+(int atk) const {
        Player result = *this;
        result.setATK(getATK() + atk);
        return result;
    }
};

// Tank class (defensive player)
class Tank : public Player {
public:
    Tank(std::string n = "Tank") : Player(n, 100, 10) {}
    ~Tank() {} //no need for custom destructor message
    void act() override {
        std::cout << name << " blocks and counterattacks!" << std::endl;
    }
};

// Warrior class (balanced player)
class Warrior : public Player {
public:
    Warrior(std::string n = "Warrior") : Player(n, 80, 15) {}
    ~Warrior() {}
    void act() override {
        std::cout << name << " swings a mighty sword!" << std::endl; //overr
    }
};

// Berserker class (high attack player)
class Berserker : public Player {
public:
    Berserker(std::string n = "Berserker") : Player(n, 60, 25) {}
    ~Berserker() {}
    void act() override {
        std::cout << name << " goes into a frenzy!" << std::endl;
    }
};

// Enemy class
class Enemy : public Character {
private:
    std::string type;
public:
    Enemy() : Character("Enemy"), type("Goblin") {} //default constructor
    Enemy(std::string n, unsigned short h = 80, unsigned short a = 8, std::string t = "Goblin") : Character(n, h, a), type(t) {}
    ~Enemy() {} // No custom destructor message because we handle that elsewhere.

    std::string getType() const { return type; }
    void setType(const std::string& t) { type = t; }
    void show() const override {
        std::cout << "[Enemy: " << type << "] ";
        Character::show();
    }
    void act() override {
        std::cout << name << " Attacks!" << std::endl;
    }
    // Overload << for easy stat display
    friend std::ostream& operator<<(std::ostream& os, const Enemy& e) {
        os << "[Enemy: " << e.type << "] " << e.getName() << " [HP: " << e.getHP() << ", ATK: " << e.getATK() << "]";
        return os;
    }
};

// Boss class (inherits Enemy)
class Boss : public Enemy {
public:
    Boss(std::string n = "Dragon", unsigned short h = 120, unsigned short a = 25) : Enemy(n, h, a, "Boss") {}
    ~Boss() {}
    void act() override {
        std::cout << getName() << " breathes a massive wave of fire!" << std::endl;
    }
};
