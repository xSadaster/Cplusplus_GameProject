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
class Character : public GameComponent { //Not used directly, but is a base class for Player and Enemy
private:
    int hp;
    int atk;
protected:
    string name;
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

// Player subclass- that hass a name, hp and atk
// but all Player subclasses will have their own hp & atk
class Player : public Character {
public:
    Player() : Character("Player") {}
    Player(string n, int h = 120, int a = 15)
        : Character(n, h, a) {}
    ~Player() {} // No message because we don't want multiple destructor messages to clutter the output

    void show() const override {
        cout << "[Player] ";
        Character::show();
    }
    void act() override {
        cout << name << " attacks!" << endl; // Default action for player, will be overridden by subclasses
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

// Player subclasses for different classes
class Tank : public Player {
public:
    Tank(string n = "Tank") : Player(n, 100, 10) {}
    ~Tank() {} //no need for custom destructor message
    void act() override {
        cout << name << " blocks and counterattacks!" << endl;
    }
};

class Warrior : public Player {
public:
    Warrior(string n = "Warrior") : Player(n, 80, 15) {}
    ~Warrior() {}
    void act() override {
        cout << name << " swings a mighty sword!" << endl;
    }
};

class Berserker : public Player {
public:
    Berserker(string n = "Berserker") : Player(n, 60, 25) {}
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
    ~Enemy() {} // No custom destructor message because we handle that elsewhere.

    string getType() const { return type; }
    void setType(const string& t) { type = t; }

    void show() const override {
        cout << "[Enemy: " << type << "] ";
        Character::show();
    }
    void act() override {
        cout << name << " Attacks!" << endl; //
    }
    // Operator overloading for output, has to use getters to access private members.
    friend ostream& operator<<(ostream& os, const Enemy& e) {
        os << "[Enemy: " << e.type << "] " << e.getName() << " [HP: " << e.getHP() << ", ATK: " << e.getATK() << "]";
        return os;
    }
};

// Boss subclass from enemy
class Boss : public Enemy {
public:
    Boss(string n = "Dragon", int h = 120, int a = 25)
        : Enemy(n, h, a, "Boss") {}
    ~Boss() {}
    void act() override {
        cout << getName() << " breathes a massive wave of fire!" << endl;
    }
};
