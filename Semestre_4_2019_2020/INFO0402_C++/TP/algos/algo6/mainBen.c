#include <stdio.h>
#include <malloc.h>

int main() {
    //initialisation des entiers
    int i, n;
    printf("Entrez une valeur positive:\n");
    scanf("%d",&n);
    //initialisation du tableau
    int f[n];
    f[0]=0;
    printf("%d \n",f[0]);
    f[1]=1;
    printf("%d \n",f[1]);
    //Calcul de la suite de Fibonacci
    for(i=2; i<n; i++){
        f[i]=f[i-1]+f[i-2];
        printf("%d \n",f[i]);
    }
    return 0;
}