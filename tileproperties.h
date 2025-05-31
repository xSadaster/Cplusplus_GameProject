/*
  tileproperties.h
  - Defines tile types and their properties for the map.
  - Each tile has: walkability, glyph, color, and enemy spawn rate.
*/

#include <string>
#include "testiprojumappi.h"

tileproperties barriervaaka {
    1, '-', GRAY,
};
tileproperties barrierpysty {
    1, '|', GRAY,
};
tileproperties endblock {
    1, '+', GRAY,
};
tileproperties puu {
    0, 'A', GREEN, 0.01f // 1% enemy spawn
};
tileproperties tie_tile {
    0, 'H', BROWN, 0.75f // 75% enemy spawn
};
tileproperties vesi {
    1, '~', BLUE,
};
tileproperties kivi {
    1, 'M', GRAY,
};
tileproperties copy_tile {
    1, '~', BLUE,
};
tileproperties boss_tile {
    0, 'B', RED,
    // Enemy spawn chance handled in logic
};
tileproperties shop_tile {
    0, 'S', YELLOW, 0.0f // No enemy spawn
};
