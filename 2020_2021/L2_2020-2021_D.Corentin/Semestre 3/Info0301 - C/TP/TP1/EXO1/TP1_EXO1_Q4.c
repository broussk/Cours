#include <stdio.h>

int main(){

    /*Déclaraton des variables*/

     int a = 5, b;
     char c = 'A';
     short s = 10;
     long l = -45645687;
     unsigned int ui = 1;
     unsigned long ul = 1000000;
     float f = 36.80;
     double d = -3;14;
     long double ld = 345678.5678;

     /*Les instructions*/

     b= 7;

     /*Affichage de varibale type <<int>> avec le format <<%d>>*/
     printf("a = %d et b = %d\n", a, b);

     /*Affichage de varibale type <<char>> avec le format <<%d>>*/
     printf("c = %c\n", c);

     /*Affichage de varibale type <<short>> avec le format <<%hd>>*/
     printf("s = %hd\n", s);

     /*Affichage de varibale type <<long>> avec le format <<%ld>>*/
     printf("ld = %ld\n", l);

     /*Affichage de varibale type <<unsigned int> avec le format <<%d>*/
     printf("ui= %d\n", ui);

     /*Affichage de varibale type <<unsigned long> avec le format <<%ld>*/
     printf("ul= %ld\n", ul);
      
     /*Affichage de varibale type <<float> avec le format <<%f>*/
     printf("f %f\n", f);

     /*Affichage de varibale type <<double>> avec le format <<%lf>*/
     printf("d= %lf\n", d);

     /*Affichage de varibale type <<long double>> avec le format <<%L>*/
     printf("ld= %LF\n", ld);

















    return 0;
}