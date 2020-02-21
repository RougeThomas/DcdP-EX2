#include "ROT13.h"
#include "Cesar.h"

#include <stddef.h>

char* chiffre_ROT13(char* clair)
{
    return chiffre_Cesar(clair, 'a'+13 );
}

char* dechiffre_ROT13(char* chiffre)
{
    return chiffre_ROT13(chiffre);
}
