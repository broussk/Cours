#include <stdio.h>

int main(){

    char ch[100];
    char *p;
    int l;

    printf("Entrez une chaine de caracrtère (max 100): \n");
    scanf("%s", ch);

    for(p = ch; *p; p++);
    l = p - ch;

    printf("La taille de la chaine est: %d\n", l);
    return 0;
}