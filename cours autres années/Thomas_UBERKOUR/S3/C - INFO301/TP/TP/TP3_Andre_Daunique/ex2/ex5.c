#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <float.h>


int main (int argc, char *argv[]){
int a;
short int f;

int test = sizeof(a);
int testoc = test * 8;
int test6 = sizeof(f);
int test6oc = test6 * 8;

int valmax = pow(2,test6oc) -1 ;
int valmax2 = pow(2,testoc) -1 ;


printf("Le valeur minimale pour une variable de type SHORT INT %d\n", SHRT_MIN);
printf("Le valeur maximale pour une variable de type SHORT INT %d\n", SHRT_MAX);
printf("Le valeur maximale pour une variable de type SHORT INT par vincent %d\n", valmax/2);
printf("Le valeur minimale pour une variable de type SHORT INT par vincent %d\n", -(valmax/2) -1);

printf("Le valeur minimale pour une variable de type INT %d\n", INT_MIN);
printf("Le valeur maximale pour une variable de type INT %d\n", INT_MAX);
printf("Le valeur maximale pour une variable de type INT par vincent %d\n", -valmax2);
printf("Le valeur minimale pour une variable de type INT par vincent %d\n", (valmax2) -1);






return 0;

}
