#include <stdio.h>
#include <stdlib.h>

int main(){
    int nb, entier, one, zero,  i, size;
    int * bin;


    do{
        printf("- Entrez un entier posifif:");
        scanf("%d", &nb);
    } while (nb < 0);

    one = 0;
    zero = 0;
    size = 0;

    entier=nb;

    while(entier > 0){
        entier/=2;
        size++;
    }

    bin = malloc(size * sizeof(int));

    for(i=0; i < size; i++){
        bin[i]= nb % 2;
        nb/=2;
    }


    printf("- Taille du tableau: %d\n", size);
    printf("- Contenu du tableau: ");

    for(i = i-1; i >= 0; i--){
        printf("%d ",  bin[i]);
        if(bin[i] == 1){
            one++;
        }else{
            zero++;
        }
    }

    printf("\n- Nombre de \"1\": %d\n- Nombre de \"0\": %d\n", one, zero);

    free(bin);
    return(0);
}