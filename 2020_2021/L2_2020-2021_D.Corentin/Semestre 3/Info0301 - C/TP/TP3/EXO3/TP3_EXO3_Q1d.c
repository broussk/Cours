#include<stdio.h>

#define TAILLE_MAX 100

int main(){

    int i;
    char tab[TAILLE_MAX]= {"Je commence a voir les pointeurs en C !"};

    for(i =0; i < TAILLE_MAX; i++){
        printf("%c\n", *(tab + i));
    }

    return 0;
}