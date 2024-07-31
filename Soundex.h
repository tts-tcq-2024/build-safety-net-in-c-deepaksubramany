#ifndef SOUNDEX_H
#define SOUNDEX_H

#include <ctype.h>
#include <string.h>

// Maps a character to its Soundex code
char getSoundexCode(char c) {
    c = toupper(c);
    if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' ||
        c == 'H' || c == 'W' || c == 'Y') return '0';
    if (c == 'B' || c == 'F' || c == 'P' || c == 'V') return '1';
    if (c == 'C' || c == 'G' || c == 'J' || c == 'K' || c == 'Q' || c == 'S' || c == 'X' || c == 'Z') return '2';
    if (c == 'D' || c == 'T') return '3';
    if (c == 'L') return '4';
    if (c == 'M' || c == 'N') return '5';
    if (c == 'R') return '6';
    return '0'; // Default case for non-mapped characters
}

// Generates a Soundex code from a name
void generateSoundex(const char *name, char *soundex) {
    if (name == NULL || soundex == NULL) {
        if (soundex) {
            soundex[0] = '\0';  // Safe initialization
        }
        return;
    }

    // Initialize Soundex with the first character of the name
    soundex[0] = toupper(name[0]);
    soundex[1] = soundex[2] = soundex[3] = '0';
    soundex[4] = '\0';

    // Generate the Soundex code
    int sIndex = 1;
    char lastCode = getSoundexCode(name[0]);

    for (int i = 1; name[i] != '\0' && sIndex < 4; ++i) {
        char code = getSoundexCode(name[i]);
        if (code != '0' && code != lastCode) {
            soundex[sIndex++] = code;
            lastCode = code;
        }
    }
}
