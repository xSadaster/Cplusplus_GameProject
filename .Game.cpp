#include "tileproperties.h" // also calls testiprojumappi.h for map dimensions and tile properties
#include "Combat.h" // also calls Classes.h and Inventory.h for inventory and class handling
// So no need to include those twice :D

#include <iostream> 
#include <conio.h> // For _getch() (input handling)
#include <cstdlib> // For random number generation
#include <ctime> // For time(), also a part of the random number generation
#include <vector> 
#include <string>
using namespace std;

// Helper function to get tileproperties pointer by tile index
const tileproperties* getTileByIndex(int tileIndex) {
    if (tileIndex == 0) return &endblock;
    else if (tileIndex == 1) return &barrierpysty;
    else if (tileIndex == 2) return &barriervaaka;
    else if (tileIndex == 10) return &puu;
    else if (tileIndex == 11) return &vesi;
    else if (tileIndex == 12) return &tie_tile;
    else if (tileIndex == 13) return &kivi;
    else if (tileIndex == 99) return &copy_tile;
    else if (tileIndex == 77) return &boss_tile;
    return nullptr;
}

// Helper function to generate a random enemy
Enemy generateRandomEnemy() {
    int pick = rand() % 4;
    switch (pick) {
        case 0:
            return Enemy("Troll", 25 + rand() % 20, 6 + rand() % 4, "Troll");
        case 1:
            return Enemy("Orc", 40 + rand() % 20, 10 + rand() % 5, "Orc");
        case 2:
            return Enemy("Wolf", 30 + rand() % 15, 8 + rand() % 5, "Wolf");
        default:
            return Enemy("Slime", 20 + rand() % 10, 4 + rand() % 3, "Slime");
    }
}

// Function to handle player creation
Player* createPlayer() {
    cout << "Welcome!\n";
    cout << "A dragon has taken over the land, \nand you are the only one who can stop it.\n";
    cout << "Enter your name, hero: ";
    string pname;
    getline(cin, pname);
    cout << "Choose your class:\n1. Warrior\n2. Tank\n3. Berserker\n> ";
    int classChoice = 1;
    char classKey = 0;
    while (true) {
        classKey = _getch();
        if (classKey == '1') {
            classChoice = 1;
            break;
        } else if (classKey == '2') {
            classChoice = 2;
            break;
        } else if (classKey == '3') {
            classChoice = 3;
            break;
        }
    }
    if (classChoice == 2) return new Tank(pname);
    else if (classChoice == 3) return new Berserker(pname);
    else return new Warrior(pname);
}

// Function to set up the map
void setupMap(int* map1) {
    int temp[map_H * map_W] = {
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
    for (int i = 0; i < map_H * map_W; ++i) map1[i] = temp[i];
}

// The main game loop
void gameLoop(Player* Playable_character, Inventory& inv, int* map1) {
    int playerX = 2, playerY = 2;
    while (true) {
        system("cls");
        printmap(map1, puu, vesi, tie_tile, kivi, copy_tile, endblock, barrierpysty, barriervaaka, boss_tile, playerX, playerY);
        char key = _getch();
        if (key == 'q') break;
        int newX = playerX, newY = playerY;
        if (key == 'w') newX--;
        else if (key == 's') newX++;
        else if (key == 'a') newY--;
        else if (key == 'd') newY++;
        if (newX >= 0 && newX < map_H && newY >= 0 && newY < map_W) {
            int tileIndex = map1[newX * map_W + newY];
            const tileproperties* tile = getTileByIndex(tileIndex);
            if (tile && !tile->wall) {
                playerX = newX;
                playerY = newY;
            }
            if (tile && tile->enemychance > 0.0f) {
                float chance = static_cast<float>(rand()) / RAND_MAX;
                if (chance < tile->enemychance) {
                    Enemy enemy = generateRandomEnemy();
                    bool survived = Combat(*Playable_character, inv, enemy);
                    if (!survived) {
                        cout << "Game Over!\n";
                        delete Playable_character;
                        cout << "Press any key to exit...";
                        _getch();
                        return;
                    }
                }
            }
            if (tileIndex == 77) {
                Boss boss;
                system("cls");
                cout << "You have encountered the Dragon!\n";
                bool survived_boss = Combat(*Playable_character, inv, boss);
                if (survived_boss) {
                    cout << "\nCongratulations! You defeated the Dragon and achieved the GOOD ENDING!\n";
                    cout << "Press any key to exit...";
                    _getch();
                    delete Playable_character;
                    return;
                } else {
                    cout << "Game Over!\n";
                    delete Playable_character;
                    cout << "Press any key to exit...";
                    _getch();
                    return;
                }
            }
        }
    }
    delete Playable_character;
}

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));
    Player* Playable_character = createPlayer(); // Run the player creation function
    Inventory inv; // Create an inventory
    inv.addPotion(); inv.addPotion(); // add 2 potions to start with
    int map1[map_H * map_W];
    setupMap(map1); //setup map1
    gameLoop(Playable_character, inv, map1); // Run the gameplay loop
    return 0;
}