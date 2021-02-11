#include <stdio.h>
int main()
{
   int i, c;
   float f;

   printf("F ****** F->C ****** C->F\n");
   for(i = 0; i <320; i +=20){
       f = ((5.0/9.0)*(i-32));
       c = (( 9 * f ) / 5 ) + 32;
       printf("%d ****** %.1f ****** %d\n", i, f, c);
   }

    return 0;
}