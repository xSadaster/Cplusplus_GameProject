#include "tileproperties.h" // also calls testiprojumappi.h
#include "Classes.h"
#include "Combat.h" // also calls Inventory.h for potion reward chance after combat

#include <iostream> 
#include <conio.h> // For _getch()
#include <cstdlib> // For srand() and rand()
#include <ctime> // For time()
#include <vector> 
#include <string>
using namespace std;

int main() {
    srand(static_cast<unsigned int>(time(nullptr))); // Seed for random number generation
    
    // Ask for player name and class and some lore
    cout << "Welcome!\n";
    cout << "The evil dragon has taken over the land, and you are the only one who can stop it.\n";
    cout << "Enter your name, hero: ";
    string pname;
    getline(cin, pname);
    cout << "Choose your class:\n1. Warrior\n2. Tank\n3. Berserker\n> ";
    int classChoice;
    cin >> classChoice;
    cin.ignore(); // Clear the newline character from the input buffer
    Player* Playable_character = nullptr;
    if (classChoice == 2) Playable_character = new Tank(pname);
    else if (classChoice == 3) Playable_character = new Berserker(pname);
    else Playable_character = new Warrior(pname);
    Inventory inv;
    inv.addPotion(); // Give the player one potion at the start

    // Map setup, we could have multiple maps and plan to add entering other areas (maps) later.
    int map1[map_H * map_W] = {
        00, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 00, 
        02, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 02,
        02, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 02,
        02, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 02,
        02, 11, 11, 11, 11, 11, 11, 11, 11, 12, 12, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 12, 12, 11, 11, 11, 11, 11, 11, 11, 11, 02,
        02, 11, 11, 11, 11, 11, 11, 11, 11, 12, 12, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 12, 12, 11, 11, 11, 11, 11, 11, 11, 11, 02,
        02, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 02,
        02, 10, 10, 10, 13, 13, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 13, 13, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 02,
        02, 10, 10, 10, 13, 13, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 13, 13, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 02,
        02, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 02,
        02, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 02, 
        02, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 02,
        02, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 02,
        02, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 02,
        02, 11, 11, 11, 11, 11, 11, 11, 11, 12, 12, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 12, 12, 11, 11, 11, 11, 11, 11, 11, 11, 02,
        02, 11, 11, 11, 11, 11, 11, 11, 11, 12, 12, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 12, 12, 11, 11, 11, 11, 11, 11, 11, 11, 02,
        02, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 02,
        02, 10, 10, 10, 13, 13, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 13, 13, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 77, 10, 02,
        02, 10, 10, 10, 13, 13, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 13, 13, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 02,
        02, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 00,
    };
    int playerX = 2, playerY = 2; //Starting position
    while (true) {
        system("cls"); // Clear the console
        printmap(map1, puu, vesi, tie_tile, kivi, copy_tile, endblock, barrierpysty, barriervaaka, boss_tile, playerX, playerY);
        char key = _getch();
        if (key == 'q') break; // Exit the game

        int newX = playerX, newY = playerY; //Handle movement
        if (key == 'w') newX--;
        else if (key == 's') newX++;
        else if (key == 'a') newY--;
        else if (key == 'd') newY++;
        // Check bounds and tile properties
        if (newX >= 0 && newX < map_H && newY >= 0 && newY < map_W) {
            int tileIndex = map1[newX * map_W + newY];
            const tileproperties* tile = nullptr;
            if (tileIndex == 0) tile = &endblock; //endblock = end of the map
            else if (tileIndex == 1) tile = &barrierpysty; //barrierpysty = vertical barrier
            else if (tileIndex == 2) tile = &barriervaaka; //barriervaaka = horizontal barrier
            else if (tileIndex == 10) tile = &puu; //puu = wood
            else if (tileIndex == 11) tile = &vesi; //vesi = water
            else if (tileIndex == 12) tile = &tie_tile; //tie_tile = road
            else if (tileIndex == 13) tile = &kivi; //kivi = stone
            else if (tileIndex == 99) tile = &copy_tile; //copy_tile = copy of the tile
            if (tile && !tile->wall) { //if the tile is not a wall
                playerX = newX;
                playerY = newY;
            }

            // Random combat trigger
            if (tile && tile->enemychance > 0.0f) { //if the tile has a chance for an enemy
                float chance = static_cast<float>(rand()) / RAND_MAX; //Generate a random float between 0 and 1
                if (chance < tile->enemychance) {
                    // Enemy encounter
                    Enemy enemy("Goblin", 30 + rand() % 20, 6 + rand() % 5, "Goblin");
                    bool survived = Combat(*Playable_character, inv, enemy);
                    if (!survived) {
                        cout << "Game Over!\n";
                        delete Playable_character; //Clean up player character
                        cout << "Press any key to exit...";
                        _getch(); // Wait for user input before closing
                        return 0;
                    }
                }
            }
            // Boss tile encounter
            if (tileIndex == 77) {
                Enemy boss("Dragon", 120, 25, "Boss");
                cout << "You have encountered the Dragon!\n";
                bool survived = Combat(*Playable_character, inv, boss);
                if (survived) {
                    cout << "\nCongratulations! You defeated the Dragon and achieved the GOOD ENDING!\n";
                    delete Playable_character;
                    cout << "Press any key to exit...";
                    _getch();
                    return 0;
                } else {
                    cout << "Game Over!\n";
                    delete Playable_character;
                    cout << "Press any key to exit...";
                    _getch();
                    return 0;
                }
            }
        }
    }
    delete Playable_character; // Clean up player character
    return 0; 
}