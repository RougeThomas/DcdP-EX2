#include "Vigenere.h"

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* chiffre_Vigenere(char* clair, char const* cle)
{
    int i = 0;
    int j = 0;
    int l = strlen(cle);

    while(clair[i] != '\0'){
        if(clair[i] >= 'a' && clair[i] <= 'z'){
            clair[i] += cle[j] - 'a';
            if(clair[i] < 'a' || clair[i] > 'z')
                clair[i] -= 26;
            j = (j+1)%l;
        }
        else if (clair[i] >= 'A' && clair[i] <= 'Z'){
            clair[i] += cle[j] - 'a';
            if(clair[i] < 'A' || clair[i] > 'Z')
                clair[i] -= 26;
            j = (j+1)%l;
        }
        i++;
    }

    return clair;
}

char* dechiffre_Vigenere(char* chiffre, char const* cle)
{
    int i = 0;
    char cle2[strlen(cle)+1];

    while(cle[i] != '\0'){
        cle2[i] = (26 + 'a' - cle[i] + 'a');
        i++;
    }
    cle2[i]='\0';
    chiffre_Vigenere(chiffre, cle2);

    return chiffre;
}

void chiffre_Vigenere_flux_texte(FILE* chiffre, FILE* clair, char const* cle)
{
    char* char_tmp = (char*) malloc(sizeof(char)*2);
    char* cle_tmp = (char*) malloc(sizeof(char)*2);
    int i, l;

    l = strlen(cle);
    i = 0;
    while(feof(clair) == 0) {
        *char_tmp = '\0';
        *cle_tmp = '\0';
        fread(char_tmp, 1, 1, clair);
        if (((*char_tmp >= 'a') && (*char_tmp <= 'z')) || ((*char_tmp >= 'A') && (*char_tmp <= 'Z'))){
            sprintf(cle_tmp, "%c", cle[i++]);
            chiffre_Vigenere(char_tmp, cle_tmp);
            i %= l;
        }
        if (strcmp(char_tmp,"\0") != 0){
            fwrite(char_tmp, 1, 1, chiffre);
        }
    }

    return ;
}

void dechiffre_Vigenere_flux_texte(FILE* clair, FILE* chiffre, char const* cle)
{
    int i = 0;
    char cle2[strlen(cle)+1];

    while(cle[i] != '\0'){
        cle2[i] = (26 + 'a' - cle[i] + 'a');
        i++;
    }
    cle2[i]='\0';
    chiffre_Vigenere_flux_texte(clair, chiffre, cle2);
    
    return;
}

void chiffre_Vigenere_flux_binaire(FILE* chiffre, FILE* clair, char const* cle)
{
    return;
}

void dechiffre_Vigenere_flux_binaire(FILE* clair, FILE* chiffre, char const* cle)
{
    return;
}
