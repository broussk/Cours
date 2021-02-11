#include<stdio.h>

#define TAILLE_MAX 100

int main(){

    int i, same = 1;
    char tab[TAILLE_MAX], tab2[TAILLE_MAX];


    printf("Entrez une premiere phrase: \n");
    scanf("%[^\n]s%*s", tab);


    printf("Entrez une deuxieme phrase: \n");
    scanf("%[^\n]s%*s", tab2);


    for(i =0; i < TAILLE_MAX; i++){
        if(*(tab + i) != *(tab2 + i)){
            same = 0;
        }
    }

    if (same == 1){
        printf("Les deux chaines sont identique. \n");
    } else {
        printf("Les deux chaines ne sont pas identique. \n");
    }

    return 0;
}