#include<stdio.h>

#define MAX 100

int main(){

    int i, j, ind, sizeWord;
    char tab[MAX], word[MAX];

    printf("Entrez une chaine de caractere: \n");
    scanf("%s%*s", tab);

    printf("Entrez un mot: \n");
    scanf("%s%*s", word);

    j = 0;
    ind = -1;
    sizeWord = 0;

    for (i = 0; *(word+i)!= '\0' ; i++) {sizeWord++;}


    for (i = 0; *(tab+i)!= '\0' ; i++) {
        if(*(tab+i) == *(word+j)){
            j++;
            if(ind == -1){
                ind = i;
            }
        } else if (j >= sizeWord){
           break;
        } else {
            j = 0;
            ind = -1;
        }
    }

    if(ind == -1){
        printf("-1");
    } else {
        printf("L'indice de la premiere lettre du mot est: %d", ind);
    }

    return 0;
}