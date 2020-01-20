#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <float.h>


int a;
double b;
float c;
char d;
unsigned char e;
short int f;


int test = sizeof(a);
int testoc = test * 8;
int test2 = sizeof(b);
int test2oc = test2 * 8;
int test3 = sizeof(c);
int test3oc = test3 * 8;
int test4 = sizeof(d);
int test4oc = test4 * 8;
int test5 = sizeof(e);
int test5oc = test5 * 8;
int test6 = sizeof(f);
int test6oc = test6 * 8;


printf("Taille de int en bit : %d en octets : %d \n", testoc , test);
printf("Taille de double en bit : %d en octets : %d\n", test2oc , test2);
printf("Taille de float en bit : %d en octets : %d \n", test3oc, test3);
printf("Taille de char en bit : %d en octets : %d\n", test4oc , test4);
printf("Taille de unsigned char en bit : %d en octets : %d\n", test5oc , test5);
printf("Taille de short int en bit : %d en octets : %d\n", test6oc , test6);

return 0;

}
