#include <stdio.h>

#define MAX 10

int main() {

    int i, j, max = 0, pos = -1, size, tab[MAX];

    do {
        printf("Entrez une taille <%d)", MAX);
        scanf("%d", &size);
    } while (size < 0 || size > MAX);


    for(i = 0; i<size; i++){
        printf("tab[%d] : ", i);
        scanf("%d", &tab[i]);
    }

    for(i = 0; i < size; i++){
        int nb = 0;
        for(j = 0; j < size; j++){
            if(tab[i] == tab[j]) nb++;
        }
        if(nb > max){
            max = nb;
            pos = i;
        }
    }

    if(pos == -1 ) printf("Pas de majorite");
    else printf("Majorite : %d", tab[pos]);

    return 0;
}
