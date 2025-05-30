#ifndef CLASSES_H
#define CLASSES_H
#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;

class GameComponent {
public:
    virtual void show() const = 0;
    virtual void act() = 0;
    virtual ~GameComponent() {}
};

class Character : public GameComponent {
protected:
    string name;
    int hp, atk;
public:
    Character() : name("Nameless"), hp(100), atk(10) {}
    Character(string n, int h = 100, int a = 10) : name(n), hp(h), atk(a) {}
    virtual ~Character() {}
    string getName() const { return name; }
    int getHP() const { return hp; }
    int getATK() const { return atk; }
    void setName(const string& n) { name = n; }
    void setHP(int h) { hp = h; }
    void setATK(int a) { atk = a; }
    Character operator+(const Character& other) const {
        return Character(name + "&" + other.name, hp + other.hp, atk + other.atk);
    }
    friend std::ostream& operator<<(std::ostream& os, const Character& c) {
        os << c.name << " [HP: " << c.hp << ", ATK: " << c.atk << "]";
        return os;
    }
    void show() const override { cout << *this << endl; }
    void act() override { cout << name << " waits..." << endl; }
};

//Player class hierarchy
class Player : public Character {
public:
    Player(string n = "Player", int h = 100, int a = 10, int p = 1)
        : Character(n, h, a), potions(p) {}
    virtual ~Player() {}
    int getPotions() const { return potions; }
    void setPotions(int p) { potions = p; }
    void show() const override {
        cout << "[Player] ";
        Character::show();
        cout << "Potions: " << potions << endl;
    }
    void act() override { cout << name << " attacks!" << endl; }
protected:
    int potions;
};
// player subclasses
class Warrior : public Player {
public:
    Warrior(string n = "Warrior") : Player(n, 120, 15, 2) {}
    void act() override { cout << name << " swings a mighty sword!" << endl; }
};

class Tank : public Player {
public:
    Tank(string n = "Tank") : Player(n, 180, 8, 1) {}
    void act() override { cout << name << " braces for impact!" << endl; }
};

class Berserker : public Player {
public:
    Berserker(string n = "Berserker") : Player(n, 70, 25, 1) {}
    void act() override { cout << name << " unleashes a powerful attack!" << endl; }
};

class Enemy : public Character {
    string type;
public:
    Enemy() : Character("Enemy"), type("Unnamed") {}
    Enemy(string n, int h = 80, int a = 8, string t = "Unnamed") : Character(n, h, a), type(t) {}
    ~Enemy() { cout << name << " has been defeated!" << endl; }
    string getType() const { return type; }
    void setType(const string& t) { type = t; }
    void show() const override {
        cout << "[Enemy: " << type << "] ";
        Character::show();
    }
    void act() override { cout << name << " lunges at you!" << endl; }
};

#endif // CLASSES_H