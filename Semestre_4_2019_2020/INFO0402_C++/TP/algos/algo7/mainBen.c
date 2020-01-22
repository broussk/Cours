#include <stdio.h>
#include <malloc.h>

int main() {
    //initialisation des entiers
    int i, n, a=0, b=1, c;
    //Demande à l'utilisateur la valeur de n
    printf("Entrez une valeur positive:\n");
    scanf("%d",&n);
    //affichage de a et b
    printf("%d \n",a);
    printf("%d \n",b);
    //Calcul de la suite de Fibonacci
    for(i=2; i<n; i++){
        c=a+b;
        printf("%d \n",c);
        a=b;
        b=c;
    }
    return 0;
}