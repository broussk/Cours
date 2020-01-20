#include <stdio.h>
#include <stdlib.h>
#define TAILLE 999

int main()
{
    char tab[TAILLE]={'m','o','t','s'};
    int i;
    for(i=0;i<5;i++){
        printf("%c\t",tab[i]);
    }
    return 0;
}
