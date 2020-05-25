#include <stdio.h>
#include <stdlib.h>
void main(){
    const int T=1.52;
    int C;
    int somme;
    printf("Entrez la somme svp : \n");
    scanf("%d", &C);
    C=0.05*C+(C*T-C);
    printf("6 mois :%d \n",C);
    C+=0.05*C+(C*T-C);
    printf("12 mois :%d \n",C);
    C+=0.05*C+(C*T-C);
    printf("18 mois :%d \n",C);
    C+=0.05*C+(C*T-C);
    C+=0.05*C+(C*T-C);
    printf("30 mois :%d \n",C);
    
}
