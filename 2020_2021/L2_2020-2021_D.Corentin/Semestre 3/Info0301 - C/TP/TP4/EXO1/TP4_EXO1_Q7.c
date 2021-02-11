#include<stdio.h>

#define MAX 100

int main() {

    int i, j, occ, sizeWord;
    char tab[MAX], word[MAX];

    printf("Entrez une chaine de caractere: \n");
    scanf("%s%*s", tab);

    printf("Entrez un mot: \n");
    scanf("%s%*s", word);

    j = 0;
    occ = 0;
    sizeWord = 0;

    for (i = 0; *(word + i) != '\0'; i++) { sizeWord++; }

    for (i = 0; *(tab + i) != '\0'; i++) {
        if (*(tab + i) == *(word + j)) {
            j++;
        } else if (j >= sizeWord) {
            occ++;
            j = 0;
        }
    }

    printf("Le nombre de fois que le mot est present est: %d", occ);

    return 0;
}