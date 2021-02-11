#include<stdio.h>

#define MAX 20

int main(){

    int tab[MAX], tab2[MAX], tabFinal[MAX];
    int i, j, tmp, sizeTab1, sizeTab2, sizeTab3;

    do{
        printf("Taille du first tableau (<%d): ", MAX);
        scanf("%d", &sizeTab1);
    } while (sizeTab1 < 0 || sizeTab1 > MAX);

    do{
        printf("Taille du second tableau (<%d): ", MAX);
        scanf("%d", &sizeTab2);
    } while (sizeTab2 < 0 || sizeTab2 > MAX);


    printf("Saisi du first tableau: \n");
    for(i = 0; i < sizeTab1; i++){
        printf("tab[%d] :", i);
        scanf("%d", &tab[i]);
    }

    printf("Saisi du second tableau: \n");
    for(i = 0; i < sizeTab2; i++){
        printf("tab2[%d] :", i);
        scanf("%d", &tab2[i]);
    }


    for(i = 0; i < sizeTab1; i++){
        tabFinal[i] = tab[i];
    }

    sizeTab3 = sizeTab1 + sizeTab2;

    for(i = 0, j = sizeTab1; j < sizeTab3 && i < sizeTab2; i++, j++){
        tabFinal[j] = tab2[i];
    }

    for(j=1;j<=sizeTab3;j++){
        for(i=0;i<sizeTab3-1;i++){
            if (tabFinal[i] > tabFinal[i+1]) {
                tmp = tabFinal[i];
                tabFinal[i] = tabFinal[i+1];
                tabFinal[i+1] = tmp;
            }
        }
    }

    printf("Tableau trie et fusionne : \n");
    for(i = 0; i < sizeTab3; i++){
        printf("[%d] | ", tabFinal[i]);
    }
    return 0;
}