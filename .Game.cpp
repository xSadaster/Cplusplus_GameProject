#include "tileproperties.h" // also calls testiprojumappi.h for map dimensions and tile properties
#include "Combat.h" // also calls Classes.h and Inventory.h for inventory and class handling
// So no need to include those twice :D

#include <iostream> 
#include <conio.h> // For _getch() (input handling)
#include <cstdlib> // For random number generation
#include <ctime> // For time(), also a part of the random number generation
#include <map>
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
    else if (tileIndex == 55) return &shop_tile;
    else if (tileIndex == 99) return &copy_tile;
    else if (tileIndex == 77) return &boss_tile;
    return nullptr;
}

// Helper function to generate a random enemy with varying stats (the +rand()%X )
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
    int classChoice = 1; //default to Warrior (balanced)
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
        }}
    if (classChoice == 2) return new Tank(pname);
    else if (classChoice == 3) return new Berserker(pname);
    else return new Warrior(pname); // Default to Warrior if no valid choice
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
        02, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 55, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 02, 
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

// The game whole game runs in this function
void gameplay_loop(Player* Playable_character, Inventory& inv, int* map1) {
    int playerX = 2, playerY = 2;
    map<string, int> defeatedEnemies; // Track defeated enemy types
    while (true) {
        system("cls");
        printmap(map1, puu, vesi, tie_tile, kivi, copy_tile, endblock, barrierpysty, barriervaaka, boss_tile, shop_tile, playerX, playerY);
        char key = _getch();
        if (key == 'q' || key == 'Q') { //added confirmation to exit
        cout << "Are you sure you want to quit? (y/n)\n";
            char confirm = _getch();
            if (confirm == 'y' || confirm == 'Y') {
                cout << "Thanks for playing!\n";
                cout << "Enemies defeated this run:\n";
                for (const auto& pair : defeatedEnemies) {
                    cout << pair.first << ": " << pair.second << endl;
                }
                delete Playable_character;
                cout << "Press any key to exit...";
                _getch();
                return; // Exit the game
            } else {
                continue; // Continue the game
            }
            break; // Exit the game
        }


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
                    if (survived) {
                        defeatedEnemies[enemy.getType()]++;
                    } else {
                        cout << "Game Over!\n";
                        cout << "\nEnemies defeated this run:\n";
                        for (const auto& pair : defeatedEnemies) {
                            cout << pair.first << ": " << pair.second << endl;
                        }
                        delete Playable_character;
                        cout << "Press any key to exit...";
                        _getch();
                        return;
                    }
                }
            }
            if (tileIndex == 77) { // Boss tile
                Boss boss;
                system("cls");
                cout << "You have encountered the Dragon!\n";
                bool survived_boss = Combat(*Playable_character, inv, boss);
                if (survived_boss) {
                    defeatedEnemies["Boss"]++;
                    cout << "\nCongratulations! You defeated the Dragon and achieved the GOOD ENDING!\n";
                    cout << "\nEnemies defeated this run:\n";
                    for (const auto& pair : defeatedEnemies) {
                        cout << pair.first << ": " << pair.second << endl;
                    }
                    cout << "Press any key to exit...";
                    _getch();
                    delete Playable_character;
                    return;
                } else {
                    cout << "Game Over!\n";
                    cout << "\nEnemies defeated this run:\n";
                    for (const auto& pair : defeatedEnemies) {
                        cout << pair.first << ": " << pair.second << endl;
                    }
                    delete Playable_character;
                    cout << "Press any key to exit...";
                    _getch();
                    return;
                }
            }
            if (tileIndex == 55) { // Shop tile
                system("cls");
                cout << "A shady looking person claims they can convert your health to attack damage, \ndo you accept their deal? (lose 20hp gain 2atk)\n";
                cout << "Current stats \nHP: " << Playable_character->getHP() << " ATK: " << Playable_character->getATK() << "\n";
                cout << "1: Yes\n2: No\n> ";
                char shopChoice = 0;
                while (true) {
                    shopChoice = _getch();
                    if (shopChoice == '1' || shopChoice == '2') break; // valid input
                }
                if (shopChoice == '1') {
                    if (Playable_character->getHP() > 20) {
                        *Playable_character = *Playable_character - 20;
                        *Playable_character = *Playable_character + 2;
                        cout << "You feel weaker... but stronger at the same time! (-20 HP, +2 ATK)\n";
                    } else {
                        cout << "You don't have enough HP to make the deal!\n";
                    }
                } else {
                    cout << "You walk away from the deal.\n";
                }
                cout << "Press any key to continue...";
                _getch();
                continue;
            }
        }
    }
    cout << "\nEnemies defeated this run:\n";
    for (const auto& pair : defeatedEnemies) {
        cout << pair.first << ": " << pair.second << endl;
    }
    delete Playable_character;
}

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));
    Player* Playable_character = createPlayer(); // Run the player creation function
    Inventory inv; // Create an inventory
    // inv.addPotion(); inv.addPotion(); // add 2 potions to start with -- Handled in inventory constructor
    int map1[map_H * map_W];
    setupMap(map1); //setup map1
    gameplay_loop(Playable_character, inv, map1); // Run the gameplay loop
    return 0;
}