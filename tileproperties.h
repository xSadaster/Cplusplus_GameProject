/* 
tileproperties copy {
    1, // 1 = no, 0 = yes
    '~',
    BLUE,
};

korvaa nimi 
ensimmäinen rivi = voiko siihen liikkua
toinen = mikä grafiikka
kolmas = väri
neljäs = vihujen chännssi jumppaa sut

jatkuu wasdmove.h ====>

*/

#include <string>
#include "testiprojumappi.h"
tileproperties barriervaaka {
    1,
    '-',
    GRAY,
};
tileproperties barrierpysty {
    1,
    '|',
    GRAY,
};
tileproperties endblock { //corners of the map
    1, // 1 = no, 0 = yes
    '+',
    GRAY,
};
tileproperties puu {
    0, // 1 = no, 0 = yes
    'A',
    GREEN,
};
tileproperties tie_tile {
    0, // 1 = no, 0 = yes
    'H',
    BROWN,
    0.75f // Chance for enemy to spawn
};

tileproperties vesi {
    1, // 1 = no, 0 = yes
    '~',
    BLUE,
};
tileproperties kivi {
    1, // 1 = no, 0 = yes
    'M',
    GRAY,
};tileproperties copy_tile {
    1, // 1 = no, 0 = yes
    '~',
    BLUE,
};
//added boss tile
tileproperties boss_tile {
    0, // 0 = walkable
    'B',
    YELLOW,
    // 1.0f // Always triggers a fight- 
    //EDIT: Removed and made separate logic to check for boss tile to start special fight
};
