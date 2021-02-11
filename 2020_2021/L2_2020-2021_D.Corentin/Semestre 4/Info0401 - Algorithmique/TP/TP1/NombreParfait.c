#include<stdio.h>

int main(){
    int nb, i, y;
    int somme = 0;

    do{
        printf("Entrer une valeur max pour la recherche de number parfait: \n");
        scanf("%d", &nb);
    } while (nb < 0);


    for (y = 0; y < nb; y++){
        for (i = 1; i < y; i++) if(y % i == 0) somme += i;
        if (y == somme) printf("%d\n", y);
        somme = 0;
    }

    return 0;
}