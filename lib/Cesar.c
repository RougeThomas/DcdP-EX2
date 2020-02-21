#include "Cesar.h"

#include <stddef.h>

char* chiffre_Cesar(char* clair, char const cle)
{
    int i = 0;
    char decalage = cle - 'a';

    while(clair[i] != '\0'){
        if((clair[i] >= 'a' && clair[i] <= 'z') || (clair[i] >= 'A' && clair[i] <= 'Z')){
            clair[i] = (clair[i] - 'a' + decalage)%26 + 'a';
        }
        i++;
    }

    return clair;
}

char* dechiffre_Cesar(char* chiffre, char const cle)
{
    
    return NULL;
}
