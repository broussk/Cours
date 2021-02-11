#include<stdio.h>

#define MAX 100

int main(){

    int i;
    char tab[MAX] = "Bonjour a tous";

    for (i=0; i<MAX; i++){
        if(*(tab + i) != '\0'){
            printf("%c\t", *(tab + i));
        }
    }

    return 0;
}