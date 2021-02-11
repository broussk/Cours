#include <stdio.h>
int main()
{
   int i;

   for(i = 0; i <320; i +=20){
       printf("%d ****** %.1f\n", i, ((5.0/9.0)*(i-32)));
   }

    return 0;
}