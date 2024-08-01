#include <stdio.h>
#include <assert.h>
#include "soundex.h"

void testGenerateSoundex() {
    char soundex[5];

    generateSoundex("Smith", soundex);
    assert(strcmp(soundex, "S530") == 0);

    generateSoundex("Jackson", soundex);
    assert(strcmp(soundex, "J025") == 0);

    generateSoundex("Gordon", soundex);
    assert(strcmp(soundex, "G653") == 0);

    generateSoundex("G", soundex);
    assert(strcmp(soundex, "G000") == 0);

    generateSoundex("", soundex);
    assert(strcmp(soundex, "0000") == 0);

    generateSoundex("A", soundex);
    assert(strcmp(soundex, "A000") == 0);
}

int main() {
    testGenerateSoundex();
    printf("All tests passed!\n");
    return 0;
}
