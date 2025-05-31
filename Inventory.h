#pragma once
#include <iostream>
using namespace std;

class Inventory {
private:
    int potions;
    const int maxPotions = 3;
public:
    Inventory() : potions(2) {} // Start with 2 potions
    // Add a potion if not full
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
    // Use a potion if available
    bool usePotion() {
        if (potions > 0) {
            --potions;
            cout << "Used a potion! Potions left: " << potions << endl;
            return true;
        } else {
            cout << "No potions left!" << endl;
            return false;
        }
    }
    // Show potion count
    void showInventory() const {
        cout << "Potions: " << potions << "/" << maxPotions << endl;
    }
    int getCount() const { return potions; }
};