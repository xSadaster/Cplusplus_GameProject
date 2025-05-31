/* 
tileproperties copy {
    1, // 0 = no, 1 = yes
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
tileproperties endblock {
    1, // 0 = no, 1 = yes
    '+',
    GRAY,
};
tileproperties puu {
    0, // 0 = no, 1 = yes
    'A',
    GREEN,
};
tileproperties tie_tile {
    0, // 0 = no, 1 = yes
    'H',
    BROWN,
    0.75f // Chance for enemy spawn
};

tileproperties vesi {
    1, // 0 = no, 1 = yes
    '~',
    BLUE,
};
tileproperties kivi {
    1, // 0 = no, 1 = yes
    'M',
    GRAY,
};tileproperties copy_tile {
    1, // 0 = no, 1 = yes
    '~',
    BLUE,
};
tileproperties boss_tile {
    0, // 0 = walkable
    'B',
    YELLOW,
    1.0f // Always triggers boss fight
};
