#pragma once
#include <iostream>
using namespace std;

class Inventory {
private:
    int potions;
    const int maxPotions = 3;
public:
    Inventory() : potions(2) {} // Start with 2 potions for ease of use, was a hassle before.

    bool addPotion() {
        if (potions < maxPotions) {
            ++potions;
            cout << "Picked up a potion! Total potions: " << potions << endl;
            return true;
        } else {
            cout << "Your bag is full!" << endl;
            return false;
        }
    }
    bool usePotion() {
        if (potions > 0) {
            --potions;
            cout << "Used a potion! Potions left: " << potions << endl;
            // The hp restoration code could've been here, but it was easier to handle in combat
            return true;
        } else {
            cout << "No potions left!" << endl;
            return false;
        }
    }
    void showInventory() const {
        cout << "Potions: " << potions << "/" << maxPotions << endl; // Display current potion count
    }
    int getCount() const { return potions; } // Getter for pot count
};