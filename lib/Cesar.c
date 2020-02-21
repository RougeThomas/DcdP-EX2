#include "Cesar.h"
#include "Vigenere.h"

#include <stddef.h>

char* chiffre_Cesar(char* clair, char const cle)
{
    char cle2[1];
    cle2[0] = cle;
    return chiffre_Vigenere(clair, cle2);
}

char* dechiffre_Cesar(char* chiffre, char const cle)
{
    char cle2 = 26 + 'a' - cle + 'a';
    return chiffre_Cesar(chiffre, cle2);
}
