#include <stdio.h>

int main()
{
    /*Déclaration des variables */
    int a=5,b;
    char c='C',d='A',e='S';
    short short1=33, short2=50;
    long omen=17.12;
    unsigned int i=0;
    //unsigned long j=0.0001;
    float u=14.18;
    //double n=1933;
    //long double h=15.15;

    /*Les instructions*/
    b=7;
    /*affichage de variable de type <<int>> avec le format <<%d>> */
    printf("%d \n",a);
    printf("\n");
    printf("La valeur de a est égale à %d \n",a);
    printf("a=%d et b=%d \n",a,b);
    /*affichage de variable de type <<long>> avec le format <<%ld>> */
    printf("%ld \n",omen);
    printf("\n");
    printf("La valeur de omen est égale à %ld \n",omen);
    printf("omen=%ld \n",omen);
    /*affichage de variable de type <<char>> avec le format <<%c>> */
    printf("%c \n",c);
    printf("\n");
    printf("La valeur de c est égale à %c \n",c);
    printf("c=%c, d=%c et e=%c \n",c,d,e);
    /*affichage de variable de type <<short>> avec le format <<%d>> */
    printf("%d \n",short1);
    printf("\n");
    printf("La valeur de short1 est égale à %d \n",short1);
    printf("short1=%d et short2=%d \n",short1,short2);
    /*affichage de variable de type <<unsigned int>> avec le format <<%u>> */
    printf("%u \n",i);
    printf("\n");
    printf("La valeur de i est égale à %u \n",i);
    printf("i=%u \n",i);
    /*affichage de variable de type <<float>> avec le format <<%>> */
    printf("%.2f \n",u);
    printf("\n");
    printf("La valeur de u est égale à %.2f \n",u);
    printf("u=%.2f \n",u);

    return(0);
}