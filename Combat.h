// Combat.h
// Handles turn-based combat between player and enemy.
#pragma once
#include <iostream>
#include <conio.h>
#include "Inventory.h"
#include "Classes.h"

// Combat function: returns true if player wins, false if defeated
// Using runtime polymorphism (Character& for both player and enemy)
bool Combat(Character& player, Inventory& inv, Character& enemy) {
    system("cls"); // Clear the console before fight
    std::cout << "\n===== FIGHT: " << enemy.getName() << " =====\n";
    while (player.getHP() > 0 && enemy.getHP() > 0) /*As long as both entities are "alive"*/ {
        std::cout << "\nYour HP: " << player.getHP() << " | Enemy HP: " << enemy.getHP() << "\n";
        inv.showInventory(); //display potion count
        std::cout << "Choose action: \n1. Attack  \n2. Use Potion  \n3. Check Enemy Stats\n> ";
        int action = 0;
        while (true) { //handle input
            char key = _getch();
            if (key == '1') { action = 1; break; }
            if (key == '2') { action = 2; break; }
            if (key == '3') { action = 3; break; }
            if (key == 'q' || key == 'Q') {
                std::cout << "\nAre you sure you want to give up? (y/n)\n";
                char confirm = _getch();
                if (confirm == 'y' || confirm == 'Y') {
                    std::cout << "\nYou gave up and got mauled by the " << enemy.getName() << ".\n";
                    return false; // Treat as defeat
                } else {
                    std::cout << "\nContinuing the fight...\n";
                    continue;
                }
            }
        }
        std::cout << std::endl;
        if (action == 2) {
            if (inv.getCount() > 0) {
                inv.usePotion();
                int healAmount = 20 + rand() % 11;
                player.setHP(player.getHP() + healAmount);
                std::cout << "Healed for " << healAmount << "! Current HP: " << player.getHP() << std::endl;
            } else {
                std::cout << "No potions left!" << std::endl;
            }
            continue;
        } else if (action == 3) {
            
            std::cout << enemy.getName() << " (HP: " << enemy.getHP() << ", ATK: " << enemy.getATK() << ")" << std::endl;
            continue;
        }
        // Player attack 
        player.act(); // virtual call
        unsigned short dmg = player.getATK();
        std::cout << "The " << enemy.getName() << " takes " << dmg << " damage!\n" << std::endl;
        enemy.setHP(enemy.getHP() - dmg);
        if (enemy.getHP() <= 0) {
            system("cls");
            std::cout << "You defeated the " << enemy.getName() << "!\n" << std::endl;
            // 50% chance to find a potion after victory, and only if inventory is not full
            if (inv.getCount() < 3 && (rand() % 100) < 50) {
                inv.addPotion();
            }
            std::cout << "Press e to continue..." << std::endl;
            char cont;
            do {
                cont = _getch();
            } while (cont != 'e' && cont != 'E');
            return true;
        }
        // Enemy turn (polymorphic)
        enemy.act(); // virtual call
        unsigned short edmg = enemy.getATK();
        std::cout << "The " << enemy.getName() << " deals " << edmg << " damage to you!\n";
        player.setHP(player.getHP() - edmg);
        if (player.getHP() <= 0) {
            std::cout << player.getName() << " has perished\n";
            break;
        }
    }
    if (player.getHP() > 0 && enemy.getType() == "Boss") {
        std::cout << player.getName() << " has survived the encounter!\n";
        std::cout << "And saved their village from the " << enemy.getName() << "!\n";
        return true;
    }
    return false;
}