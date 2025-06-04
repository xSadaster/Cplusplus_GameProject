/*
  testiprojumappi.h
  - Map rendering and tile property struct.
  - Handles color codes and map printing.
*/
#include <string>
#include <iostream>
#define CURSOR_TOP_LEFT "\033[H"
#define RESET   "\033[0m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define GREEN   "\033[32m"
#define BROWN   "\033[38;5;52m"
#define GRAY    "\033[90m"
#define RED     "\033[31m"

#ifndef TESTIPROJUMAPPI_H_INCLUDED
#define TESTIPROJUMAPPI_H_INCLUDED
// Tile property struct
struct tileproperties {
    bool wall; // 1 = wall, 0 = walkable
    char gf;   // glyph
    std::string colour;
    float enemychance = 0.0f; // chance for enemy spawn
};
const int map_W = 40;
const int map_H = 20;
// Print the map with all tile types and player position
void printmap(const unsigned short map[map_H * map_W], const tileproperties& puu, const tileproperties& vesi, const tileproperties& tie_tile, const tileproperties& kivi, const tileproperties& copy_tile, const tileproperties& endblock, const tileproperties& barrierpysty, const tileproperties& barriervaaka, const tileproperties& boss_tile, const tileproperties& shop_tile, unsigned short playerX, unsigned short playerY) {
    std::cout << CURSOR_TOP_LEFT;
    for (int i = 0; i < map_H; i++) {
        for (int j = 0; j < map_W; j++) {
            if (i == playerX && j == playerY) {
                std::cout << '@';
                continue;
            }
            int value = map[i * map_W + j];
            if (value == 1) {
                std::cout << barriervaaka.colour << barriervaaka.gf << RESET;
            } else if (value == 2) {
                std::cout << barrierpysty.colour << barrierpysty.gf << RESET;
            } else if (value == 0) {
                std::cout << endblock.colour << endblock.gf << RESET;
            } else if (value == 10) {
                std::cout << puu.colour << puu.gf << RESET;
            } else if (value == 11) {
                std::cout << vesi.colour << vesi.gf << RESET;
            } else if (value == 12) {
                std::cout << tie_tile.colour << tie_tile.gf << RESET;
            } else if (value == 13) {
                std::cout << kivi.colour << kivi.gf << RESET;
            } else if (value == 99) {
                std::cout << copy_tile.colour << copy_tile.gf << RESET;
            } else if (value == 77) {
                std::cout << boss_tile.colour << boss_tile.gf << RESET;
            } else if (value == 55) {
                std::cout << shop_tile.colour << shop_tile.gf << RESET;
            } else {
                std::cout << value;
            }
        }
        std::cout << std::endl;
    }
}
#endif // TESTIPROJUMAPPI_H_INCLUDED