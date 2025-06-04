#pragma once
#include <iostream>
#define MAX_POTIONS 3 // Maximum potions in inventory

class Inventory {
private:
    unsigned short potions;
    unsigned short maxPotions = MAX_POTIONS; // Maximum potions allowed
public:
    Inventory() : potions(2) {} // Start with 2 potions
    // Add a potion if not full
    bool addPotion() {
        if (potions < maxPotions) {
            ++potions;
            std::cout << "Picked up a potion! Total potions: " << potions << std::endl;
            return true;
        } else {
            std::cout << "Your bag is full!" << std::endl;
            return false;
        }
    }
    // Use a potion if available
    bool usePotion() {
        if (potions > 0) {
            --potions;
            std::cout << "Used a potion! Potions left: " << potions << std::endl;
            return true;
        } else {
            std::cout << "No potions left!" << std::endl;
            return false;
        }
    }
    // Show potion count
    void showInventory() const {
        std::cout << "Potions: " << potions << "/" << maxPotions << std::endl;
    }
    unsigned short getCount() const { return potions; }
};