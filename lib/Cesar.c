#include "Cesar.h"

#include <stddef.h>

char* chiffre_Cesar(char* clair, char const cle)
{
    int i = 0;
    char decalage = cle - 'a';

    while(clair[i] != '\0'){
        if(clair[i] >= 'a' && clair[i] <= 'z'){
            clair[i] = (clair[i] - 'a' + decalage)%26 + 'a';
        }
        else if (clair[i] >= 'A' && clair[i] <= 'Z'){
            clair[i] = (clair[i] - 'A' + decalage)%26 + 'A';
        }
        i++;
    }

    return clair;
}

char* dechiffre_Cesar(char* chiffre, char const cle)
{
    int i = 0;
    char decalage = cle - 'a';

    while(chiffre[i] != '\0'){
        if(chiffre[i] >= 'a' && chiffre[i] <= 'z'){
            chiffre[i] = (chiffre[i] - 'a' - decalage)%26 + 'a';
            if(chiffre[i] < 'a')
                chiffre[i] += 26;
        }
        else if (chiffre[i] >= 'A' && chiffre[i] <= 'Z'){
            chiffre[i] = (chiffre[i] - 'A' - decalage)%26 + 'A';
            if(chiffre[i] < 'A')
                chiffre[i] += 26;
        }
        i++;
    }

    return chiffre;
}
