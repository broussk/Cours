#include <stdio.h>

void main(){
    double a,b,c,moyenne,variance;
    printf ("saisir 3 nombre\n");
    fflush(stdin);
    scanf("%lf,%lf,%lf",&a,&b,&c);
    moyenne=(a+b+c)/3;
    variance=((a-moyenne)*(a-moyenne)+(b-moyenne)*(b-moyenne)+(c-moyenne)*(c-moyenne))/3;
    printf("moyenne= %lf et variance = %lf",moyenne,variance);

}