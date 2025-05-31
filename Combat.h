#ifndef COMBAT_H_INCLUDED
#define COMBAT_H_INCLUDED
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <conio.h>
#include <stack>
#include "Inventory.h"
#include "Classes.h"
using namespace std;

// Combat function
bool Combat(Player& player, Inventory& inv, Enemy& enemy) {
     system("cls"); // Clear the console before fight
    cout << "\n===== FIGHT: " << enemy.getName() << " =====\n";
    while (player.getHP() > 0 && enemy.getHP() > 0) /*As long as both entities are "alive"*/ {
        cout << "\nYour HP: " << player.getHP() << " | Enemy HP: " << enemy.getHP() << "\n";
        inv.showInventory(); //display potion count
        cout << "Choose action: \n1. Attack  \n2. Use Potion  \n3. Check Enemy Stats\n> ";
        int action = 0;
        while (true) { //handle input
            char key = _getch();
            if (key == '1') { action = 1; break; }
            if (key == '2') { action = 2; break; }
            if (key == '3') { action = 3; break; } }
        cout << endl; // Add space after input before action output
        if (action == 2) {
            if (inv.getCount() > 0) {
                inv.usePotion();
                int healAmount = 20 + rand() % 11; //Heal between 20 and 30 HP
                player.setHP(player.getHP() + healAmount);
                cout << "Healed for " << healAmount << "! Current HP: " << player.getHP() << endl;
            } else {
                cout << "No potions left!" << endl;
            }
            continue;
        } else if (action == 3) {
            cout << enemy << endl; // Uses the overloaded operator<< to display enemy stats
            continue; // Does not take a turn
        }
        // Player attack 
        player.act();
        int dmg = player.getATK();
        cout << "The " << enemy.getName() << " takes " << dmg << " damage!\n" << endl;
        enemy.setHP(enemy.getHP() - dmg);
        if (enemy.getHP() <= 0) {
            system("cls"); // Clear the console before victory message
            cout << "You defeated the " << enemy.getName() << "!\n" << endl;
            // 50% chance to find a potion after victory, and only if inventory is not full
            if (inv.getCount() < 3 && (rand() % 100) < 50) {
                inv.addPotion(); // potion acquisition text handled in Inventory class
            }
            cout << "Press e to continue..." << endl;
            char cont;
            do {
                cont = _getch();
            } while (cont != 'e' && cont != 'E'); //Caps doesnt matter
            return true; // True indicates victory
        }
        // Enemy turn (polymorphic)
        enemy.act();
        int edmg = enemy.getATK();
        cout << "The " << enemy.getName() << " deals " << edmg << " damage to you!\n";
        player.setHP(player.getHP() - edmg);
        if (player.getHP() <= 0) {
            cout << player.getName() << " has perished\n";
            break;
        }
    }
    if (player.getHP() > 0 && enemy.getType() == "Boss") {
        cout << player.getName() << " has survived the encounter!\n";
       cout << "And saved their village from the " << enemy.getName() << "!\n";
        return true;
    }
    return false;
}
#endif // COMBAT_H_INCLUDED