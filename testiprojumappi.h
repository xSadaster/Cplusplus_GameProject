/*
kommentti jatkuu lisäykseen
1. void printmap(const int map[map_H * map_W], const tileproperties& puu,const tileproperties& vesi,const tileproperties& tie_tile,const tileproperties& kivi,const tileproperties& copy_tile,const tileproperties& endblock, const tileproperties& barrierpysty, const tileproperties& barriervaaka, int playerX, int playerY) {
 korvaa const tileproperties& copy_tile 
 2. else if (value == 13) {
                cout << kivi.colour << kivi.gf << RESET;
            }
    else if (value == 99) {
                cout << copy_tile.colour << copy_tile.gf << RESET;
            }
    korvaa omalla valuella sekä muuttujat
    jatkuu tileproperties ===>
*/


#include <string>
#include <iostream>
#include <vector>
#define CURSOR_TOP_LEFT "\033[H"
#define RESET   "\033[0m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define GREEN   "\033[32m"
#define BROWN   "\033[38;5;52m"
#define GRAY    "\033[90m"
using namespace std;

#ifndef TESTIPROJUMAPPI_H_INCLUDED
#define TESTIPROJUMAPPI_H_INCLUDED

struct tileproperties {
    bool wall; // 0 = no wall, 1 = wall
    char gf;
    string colour;
    float enemychance = 0.0f; 
};

const int map_W = 40;
const int map_H = 20;

 void printmap(const int map[map_H * map_W], const tileproperties& puu,const tileproperties& vesi,const tileproperties& tie_tile,const tileproperties& kivi,const tileproperties& copy_tile,const tileproperties& endblock, const tileproperties& barrierpysty, const tileproperties& barriervaaka, const tileproperties& boss_tile, const tileproperties& shop_tile, int playerX, int playerY) {
    cout << CURSOR_TOP_LEFT;
    for (int i = 0; i < map_H; i++) {
        for (int j = 0; j < map_W; j++) {
            if (i == playerX && j == playerY) {
                cout << '@';
                continue;
            }
            int value = map[i * map_W + j];
            if (value == 1) {
                cout << barriervaaka.colour << barriervaaka.gf << RESET;
            } else if (value == 2) {
                cout << barrierpysty.colour << barrierpysty.gf << RESET;
            } else if (value == 0) {
                cout << endblock.colour << endblock.gf << RESET;
            } else if (value == 10) {
                cout << puu.colour << puu.gf << RESET;
            } else if (value == 11) {
                cout << vesi.colour << vesi.gf << RESET;
            } else if (value == 12) {
                cout << tie_tile.colour << tie_tile.gf << RESET;
            } else if (value == 13) {
                cout << kivi.colour << kivi.gf << RESET;
            } else if (value == 99) {
                cout << copy_tile.colour << copy_tile.gf << RESET;
            } else if (value == 77) {
                cout << boss_tile.colour << boss_tile.gf << RESET;
            } else if (value == 55) {
                cout << shop_tile.colour << shop_tile.gf << RESET;
            } else {
                cout << value;
            }
        }
        cout << endl;
    }
}
#endif // TESTIPROJUMAPPI_H_INCLUDED