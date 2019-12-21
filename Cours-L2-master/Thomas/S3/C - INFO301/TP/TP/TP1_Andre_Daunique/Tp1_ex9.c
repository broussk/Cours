#include <stdio.h>

void main(){
    int a,annees,mois,jours;
    printf("nombre de jour\n");
    do{
    scanf("%d",&a);
    }while(a<0);
    annees=a/365;
    a=a%365;
    mois=a/30;
    a=a%30;
    jours=a;
    printf("Annees: %d \nmois: %d \njours: %d",annees,mois,jours);
}