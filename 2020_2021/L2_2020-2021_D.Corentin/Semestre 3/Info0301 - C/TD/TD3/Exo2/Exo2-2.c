#include <stdio.h>

#define max 100

int main(){

    char tab[max] = "Bonjour a tous !";
    int i, end;

    for(end = 0; *(tab +end) != '\0' ; end++);

    for(i = end-1; i >= 0 ; i--){
        printf("%c ", *(tab + i));
    }

    return 0;
}
