#include<stdio.h>

#define TAILLE_MAX 100

int main(){

    int i, j;
    char tab[TAILLE_MAX], tab2[TAILLE_MAX];

    printf("Entrez une chaine de caractere: \n");
    scanf("%s%*s", tab);

    printf("Entrez une deuxieme chaine de caractere: \n");
    scanf("%s%*s", tab2);

    for (i = 0; *(tab+i)!='\0'; i++);

    for (j = 0; *(tab+j) !='\0'; j++){
        tab[i] = *(tab2 + j);
        i++;
    }

    printf("%s", tab);

    return 0;
}