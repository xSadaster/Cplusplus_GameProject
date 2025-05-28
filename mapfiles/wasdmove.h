/*

1. void (*printFunc)(const int*, int, int,
                      const tileproperties&, const tileproperties&,
                      const tileproperties&, const tileproperties&, const tileproperties&,const tileproperties&,const tileproperties&,
                      int, int),
    lisää yksi kpl const tileproperties&

    2. const tileproperties& copy korvaa tämä
    3. else if (tileIndex == 99) tile = &copy; ja tämäkin
    4. printFunc(map, map_W, map_H, puu, vesi, tie, copy, endblock, barrierpysty, barriervaaka, playerX, playerY);
        lisää tohonki

3. 


*/


#ifndef WASDMOVE_H_INCLUDED
#define WASDMOVE_H_INCLUDED

#include <conio.h>
#include <iostream>
#include "testiprojumappi.h"


inline void wasdMoveLoop(
    int* map, int map_W, int map_H,
    int& playerX, int& playerY,
    void (*printFunc)(const int*, int, int,
                      const tileproperties&,const tileproperties&, const tileproperties&,
                      const tileproperties&, const tileproperties&, const tileproperties&,const tileproperties&,const tileproperties&,
                      int, int),
    const tileproperties& puu,
    const tileproperties& barrierpysty,
    const tileproperties& barriervaaka,
    const tileproperties& endblock,
    const tileproperties& vesi,
    const tileproperties& tie,
    const tileproperties& kivi,
    const tileproperties& copy
) {
    bool running = true;
    while (running) {
        if (_kbhit()) {
            char key = _getch();
            int newX = playerX;
            int newY = playerY;

            if (key == 'w') newX--;
            else if (key == 's') newX++;
            else if (key == 'a') newY--;
            else if (key == 'd') newY++;
            else if (key == 'q') { running = false; break; }

            if (newX >= 0 && newX < map_H && newY >= 0 && newY < map_W) {
                int tileIndex = map[newX * map_W + newY];
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
            }

            printFunc(map, map_W, map_H, puu, vesi, tie, kivi, copy, endblock, barrierpysty, barriervaaka, playerX, playerY);
        }
    }
}

#endif // WASDMOVE_H_INCLUDED
