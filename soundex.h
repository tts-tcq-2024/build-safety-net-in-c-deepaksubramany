#ifndef SOUNDEX_H
#define SOUNDEX_H

#include <ctype.h>

char getSoundexCode(char c);

void generateSoundex(const char *name, char *soundex);

#endif // SOUNDEX_H
