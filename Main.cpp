    /* 

    jos haluutte lisää erillaisia maastoja tähän niin 
    (muista lisää takaisin copy kohdat)

    testausproju.cpp
    1. 
    else if (tileIndex == 99) tile = &copy;  //kopioi ja vaihda numeroksi oma sekä nimeksi
    2. printmap(map1, puu, vesi, tie, ,kivi copy, endblock, barrierpysty, barriervaaka, playerX, playerY);
    tosta copy muuta myös muista
    
    kommentti jatkuu testiprojumappi.h
    ===> mene sinne
    */

#include "mapfiles/testiprojumappi.h"
#include "mapfiles/tileproperties.h"

#include "CBT (combat tai cock and ball torture)\CBT.h"
#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <ctime>
// Defining tiles

int main() {
    std::srand(std::time(nullptr));
    int map1[map_H * map_W] = {
        00, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01,01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 00, 
        02, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10,10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 02,
        02, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10,10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 02,
        02, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10,10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 02,
        02, 11, 11, 11, 11, 11, 11, 11, 11, 12, 12, 11, 11, 11, 11, 11, 11, 11, 11, 11,11, 11, 11, 11, 11, 11, 11, 11, 11, 12, 12, 11, 11, 11, 11, 11, 11, 11, 11, 02,
        02, 11, 11, 11, 11, 11, 11, 11, 11, 12, 12, 11, 11, 11, 11, 11, 11, 11, 11, 11,11, 11, 11, 11, 11, 11, 11, 11, 11, 12, 12, 11, 11, 11, 11, 11, 11, 11, 11, 02,
        02, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10,10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 02,
        02, 10, 10, 10, 13, 13, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10,10, 10, 10, 10, 13, 13, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 02,
        02, 10, 10, 10, 13, 13, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10,10, 10, 10, 10, 13, 13, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 02,
        02, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10,10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 02,
        02, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10,10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 02, 
        02, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10,10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 02,
        02, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10,10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 02,
        02, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10,10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 02,
        02, 11, 11, 11, 11, 11, 11, 11, 11, 12, 12, 11, 11, 11, 11, 11, 11, 11, 11, 11,11, 11, 11, 11, 11, 11, 11, 11, 11, 12, 12, 11, 11, 11, 11, 11, 11, 11, 11, 02,
        02, 11, 11, 11, 11, 11, 11, 11, 11, 12, 12, 11, 11, 11, 11, 11, 11, 11, 11, 11,11, 11, 11, 11, 11, 11, 11, 11, 11, 12, 12, 11, 11, 11, 11, 11, 11, 11, 11, 02,
        02, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10,10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 02,
        02, 10, 10, 10, 13, 13, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10,10, 10, 10, 10, 13, 13, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 02,
        02, 10, 10, 10, 13, 13, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10,10, 10, 10, 10, 13, 13, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 02,
        02, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01,01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 01, 00,
    };

    int playerX = 2, playerY = 2; // Start position

    while (true) {
        system("cls"); // Clear screen 

        printmap(map1, puu, vesi, tie, kivi, copy, endblock, barrierpysty, barriervaaka, playerX, playerY);

        char key = _getch();
        if (key == 'q') break;

        int newX = playerX, newY = playerY;
        if (key == 'w') newX--;
        else if (key == 's') newX++;
        else if (key == 'a') newY--;
        else if (key == 'd') newY++;

        // Check bounds
        if (newX >= 0 && newX < map_H && newY >= 0 && newY < map_W) {
            // Get tile type
            int tileIndex = map1[newX * map_W + newY];
            const tileproperties* tile = nullptr;
            if (tileIndex == 0) tile = &endblock;
            else if (tileIndex == 1) tile = &barrierpysty;
            else if (tileIndex == 2) tile = &barriervaaka;
            else if (tileIndex == 10) tile = &puu;
            else if (tileIndex == 11) tile = &vesi;
            else if (tileIndex == 12) tile = &tie;
            else if (tileIndex == 13) tile = &kivi;
            else if (tileIndex == 99) tile = &copy;

            if (tile && !tile->wall) {
                playerX = newX;
                playerY = newY;
            }
            if (tile && tile->enemychance > 0.0f) {
                float chance = static_cast<float>(std::rand()) / RAND_MAX;
                if (chance < tile->enemychance) {                           
                    std::cout << "Enemy spawned on tile " << tile->gf << "!" << std::endl;
                    // KUTSUKAA MOBISPAWNAUSKOODI TÄSSÄ
                    Entity player = { "Player",
                                    100,
                                    10,
                                    { { "Sword Slash", 8, 12 }, { "Fireball", 10, 15 } }                   //niiku näi
                    };

                    Entity enemy = { "Goblin",
                                    50,
                                    5,
                                    { { "Bite", 3, 7 } }
                    };
                    combat(player, enemy);                      //menee CBT.h kattokaa sielt
                }
            }
        }
    }

    return 0;
}