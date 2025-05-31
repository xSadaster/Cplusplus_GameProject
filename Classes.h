#pragma once
#include <iostream>
#include <string>
#include <array>
using namespace std;

// Abstract Base Class
class GameComponent {
public:
    virtual void show() const = 0; // Purely virtual
    virtual void act() = 0;        // Virtual for polymorphism
    virtual ~GameComponent() {}    // Virtual destructor
};

// Derived Class
class Character : public GameComponent {
protected:
    string name;
    int hp;
    int atk;
public:
    // Default constructor
    Character() : name("NoName"), hp(1), atk(1) {}
    // Parameterized constructor
    Character(string n, int h = 1, int a = 1) : name(n), hp(h), atk(a) {}
    virtual ~Character() {} // Destructor
    
    // Getters and setters
    string getName() const { return name; }
    int getHP() const { return hp; }
    int getATK() const { return atk; }
    void setName(const string& n) { name = n; }
    void setHP(int h) { hp = h; }
    void setATK(int a) { atk = a; }

    // Virtual functions
    virtual void show() const override {
        cout << name << " [HP: " << hp << ", ATK: " << atk << "]" << endl;
    }
    virtual void act() override {
        cout << name << " waits..." << endl;
    }
};

// Player subclass
class Player : public Character {
public:
    Player() : Character("Player") {}
    Player(string n, int h = 120, int a = 15, int p = 3)
        : Character(n, h, a) {}
    ~Player() {
        cout << "It's over for " << name << "..." << endl;
    }

    void show() const override {
        cout << "[Player] ";
        Character::show();
    }
    void act() override {
        cout << name << " attacks with sword!" << endl;
    }
};

// Player subclasses for different classes
class Tank : public Player {
public:
    Tank(string n = "Tank") : Player(n, 100, 10, 2) {}
    ~Tank() {} //no need for custom destructor message
    void act() override {
        cout << name << " blocks and counterattacks!" << endl;
    }
};

class Warrior : public Player {
public:
    Warrior(string n = "Warrior") : Player(n, 80, 15, 2) {}
    ~Warrior() {}
    void act() override {
        cout << name << " swings a mighty sword!" << endl;
    }
};

class Berserker : public Player {
public:
    Berserker(string n = "Berserker") : Player(n, 60, 25, 1) {}
    ~Berserker() {}
    void act() override {
        cout << name << " goes into a frenzy!" << endl;
    }
};

// Enemy subclass
class Enemy : public Character {
private:
    string type;
public:
    Enemy() : Character("Enemy"), type("Goblin") {} //default constructor
    Enemy(string n, int h = 80, int a = 8, string t = "Goblin") : Character(n, h, a), type(t) {}
    ~Enemy() { cout << "" << name << " defeated!" << endl; } // Destructor message

    string getType() const { return type; }
    void setType(const string& t) { type = t; }

    void show() const override {
        cout << "[Enemy: " << type << "] ";
        Character::show();
    }
    void act() override {
        cout << name << " lunges at you!" << endl;
    }
    // Operator overloading for output
    friend ostream& operator<<(ostream& os, const Enemy& e) {
        os << "[Enemy: " << e.type << "] " << e.name << " [HP: " << e.hp << ", ATK: " << e.atk << "]";
        return os;
    }
};
