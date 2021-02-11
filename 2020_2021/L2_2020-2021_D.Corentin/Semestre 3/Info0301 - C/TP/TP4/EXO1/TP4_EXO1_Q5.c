#include<stdio.h>

#define MAX 100

int main(){

    int i;
    char tab[MAX], tabF[MAX], var;

    printf("Entrez une chaine de caractere: \n");
    scanf("%s", tab);

    for (i = 0; *(tab+i)!= '\0' ; i++) {
        var = *(tab+i);
        if((var >= 'A' && var <= 'Z') || (var >= 'a' && var <= 'z')){
            *(tabF + i) = var;
        }
        printf("%c", *(tabF+i));
    }

    return 0;
}