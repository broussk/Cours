#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <float.h>


int main (int argc, char *argv[]){
  
  printf("Le nombre de bits pour representer le type CHAR %d\n", CHAR_BIT);
printf("Le valeur minimale pour une variable de type SIGNED CHAR %d\n", SCHAR_MIN);
printf("Le valeur maximale pour une variable de type SIGNED CHAR %d\n", SCHAR_MAX);
printf("Le valeur maximale pour une variable de type UNSIGNED CHAR %d\n", UCHAR_MAX);
printf("Le valeur minimale pour une variable de type SHORT INT %d\n", SHRT_MIN);
printf("Le valeur maximale pour une variable de type SHORT INT %d\n", SHRT_MAX);
printf("Le valeur maximale pour une variable de type UNSIGNED INT %d\n", UINT_MAX);
printf("Le valeur maximale pour une variable de type UNSIGNED SHORT %d\n", USHRT_MAX);
printf("Le valeur minimale pour une variable de type INT %d\n", INT_MIN);
printf("Le valeur maximale pour une variable de type INT %d\n", INT_MAX);
printf("Le valeur minimale pour une variable de type CHAR %d\n", CHAR_MIN);
printf("Le valeur maximale pour une variable de type CHAR %d\n", CHAR_MAX);
printf("Le valeur minimale pour une variable de type LONG %ld\n", LONG_MIN);
printf("Le valeur maximale pour une variable de type LONG %ld\n", LONG_MAX);
printf("Le nombre maximale de bits dans un caractere multibytes %d\n", MB_LEN_MAX);
printf("Le valeur minimale normalisé positive pour le FLOAT %f\n", FLT_MIN);
printf("Le valeur minimale normalisé positive pour le DOUBLE %lf\n", DBL_MIN);
printf("Le valeur minimale positive pour le FLOAT %f\n", FLT_TRUE_MIN);
printf("Le valeur minimale positive pour le DOUBLE %lf\n", DBL_TRUE_MIN);
printf("Le valeur maximale fini pour le FLOAT %f\n", FLT_MAX);
printf("Le valeur maximale fini pour le DOUBLE %f\n", DBL_MAX);
  
    return 0;

}