#include<stdio.h>

#define MAX 100

int main(){

    int i;
    char tab[MAX] ,occ[10]={0};

    printf("Entrez une chaine de caractere composé de chiffre: \n");
    scanf("%s", tab);

    printf("Nombre de occurence: \n");

    for(i = 0; *(tab+i) != '\0'; ++i){
        occ[tab[i]-'0'] ++;
    }

    for(i = 0; i < 10; ++i){
       printf("%d: %d\n", i, *(occ + i));
    }


    return 0;
}