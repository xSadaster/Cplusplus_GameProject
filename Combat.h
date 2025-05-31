#ifndef COMBAT_H_INCLUDED
#define COMBAT_H_INCLUDED
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <conio.h>
#include "Inventory.h"

using namespace std;

// Combat function
bool Combat(Player& player, Inventory& inv, Enemy& enemy) {
    cout << "\n===== FIGHT: " << enemy.getName() << " =====\n";
    while (player.getHP() > 0 && enemy.getHP() > 0) {
        cout << "\nYour HP: " << player.getHP() << " | Enemy HP: " << enemy.getHP() << "\n";
        inv.showInventory();
        cout << "Choose action: 1. Attack  2. Use Potion  3. Check Enemy Stats\n> ";
        int action;
        while (true) {
            if (!(cin >> action)) {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Invalid input. Please enter a number (1, 2, or 3): ";
                continue;
            }
            if (action < 1 || action > 3) {
                cout << "Invalid choice. Please enter 1, 2, or 3: ";
                continue;
            }
            break;
        }
        if (action == 2) {
            if (inv.getCount() > 0) {
                inv.usePotion();
                player.setHP(player.getHP() + 20);
                cout << "Healed! Current HP: " << player.getHP() << "\n";
            } else {
                cout << "No potions left!\n";
            }
            continue;
        } else if (action == 3) {
            cout << enemy << endl;
            continue; // Does not take a turn
        }
        // Player attack (polymorphic)
        player.act();
        int dmg = player.getATK();
        cout << "The " << enemy.getName() << " takes " << dmg << " damage!\n";
        enemy.setHP(enemy.getHP() - dmg);
        if (enemy.getHP() <= 0) {
            cout << "You defeated the " << enemy.getName() << "!\n";
            cout << "Press e to continue..." << endl;
            char cont;
            do {
                cont = _getch();
            } while (cont != 'e' && cont != 'E');
            break;
        }
        // Enemy turn (polymorphic)
        enemy.act();
        int edmg = enemy.getATK();
        cout << "The " << enemy.getName() << " hits you for " << edmg << " damage!\n";
        player.setHP(player.getHP() - edmg);
        if (player.getHP() <= 0) {
            cout << player.getName() << " has perished\n";
            break;
        }
    }
    if (player.getHP() > 0) {
        // 30% chance to find a potion after victory, and only if inventory is not full
        if (inv.getCount() < 3 && (rand() % 100) < 30) {
            inv.addPotion();
            cout << "You found a Potion!\n";
        }
        return true;
    } else {
        return false;
    }
}
#endif // COMBAT_H_INCLUDED