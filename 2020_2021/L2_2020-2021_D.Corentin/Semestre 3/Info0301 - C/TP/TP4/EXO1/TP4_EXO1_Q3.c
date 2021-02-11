#include<stdio.h>

int main(){
    int nb, div;
    int i;
    char tab[5];

    div = 10000;

    do{
        printf("Rentrez un nombre de 5 chiffres: \n");
        scanf("%d", &nb);
    } while (nb < 10000 || nb > 99999);


    for(i=0; i<5; i++){
        *(tab + i) = (char) (nb /div);
        nb = nb % div;
        div /= 10;
        printf("%c ", *(tab+i));
    }

    return(0);
}