#include <stdio.h>

int main()
{
    /*Déclaration des variables*/
    int a=5,b;
    //char c[1]={'C'};
    short d=1 ;
    long e=1;
    unsigned int i=1;
    unsigned long f=1;
    float j=0;
    //double;
    //long double ;

    /* code */
    b=7;
    printf("%d\n",a);
    printf("\n");
    printf("valeur a = %d\n",a);
    printf("a= %d et b= %d\n",a,b);
    printf("valeur d = %d\n",d);
    //printf("valeur C = %S\n",c);
    printf("valeur e = %ld\n",e);
    printf("valeur f = %lu\n",f);
    printf("valeur i= %du\n",i);
    printf("valeur j= %lf\n",j);
    return 0;
}
