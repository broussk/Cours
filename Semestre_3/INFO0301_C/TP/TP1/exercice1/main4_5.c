#include <stdio.h>
int main(){
    //déclaration des variables
    int a=5,b;
    char c='C';
    short d=2.1;
    long e=123456789;
    unsigned int f=23;
    unsigned long g=23546879;
    float h=9;
    double i=456789321;
    long double j=3;
    //LES INSTRUCTIONS
    b=7;
    //AFFICHAGE DE VARIABLES DE TYPE "INT" AVEC LE FORMAT "%d"
    printf("%d \n",a);
    printf("\n");
    printf("La valeur de a est egale a %d \n",a);
    printf("a=%d et b=%d \n",a,b);
    //AFFICHAGE DE VARIABLES DE TYPE "LONG" AVEC LE FORMAT "%ld"
    printf("long Double j=%Lg \n",j);
    printf("float h=%f \n",h);
    printf("char c=%c \n",c);
    printf("short d=%d \n",d);
    printf("long e=%d \n",e);
    printf("unsigned int f=%d \n",f);
    printf("unsigned long g=%Ld \n",g);
    printf("double i=%Lg \n",i);
    return 0;
}
