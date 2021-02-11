#include <stdio.h>

int present(char *ch, char c){
    if(*ch == '\0') return 0;
    return (*ch == c)?1 : present(ch+1, c);
}

int main(){
    char chaine[30] = "Je suis un caractere.";
    char car;
    printf("Entrez votre caractère : ");
    scanf("%c", &car);
    if (present(chaine, car))
        printf("Le caractère '%c' est présent dans :\n%s\n", car, chaine);
    else
        printf("Le caractère '%c' n'est pas présent dans :\n%s\n", car, chaine);
}