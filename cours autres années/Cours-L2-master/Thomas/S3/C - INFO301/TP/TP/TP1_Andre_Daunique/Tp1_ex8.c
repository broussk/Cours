#include <stdio.h>

void main(){
    int a,annees,semaines,jours;
    printf("nombre de jour\n");
    do{
    scanf("%d",&a);
    }while(a<0);
    annees=a/365;
    a=a%365;
    semaines=a/7;
    a=a%7;
    jours=a;
    printf("Annees: %d \nSemaines: %d \njours: %d",annees,semaines,jours);
}