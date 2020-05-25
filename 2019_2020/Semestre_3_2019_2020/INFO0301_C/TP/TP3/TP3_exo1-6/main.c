#include <stdio.h>
#include <math.h>
#include <limits.h>

int main()
{
    int po;
    po=sizeof(char)*CHAR_BIT;
    printf("char : %d \n", pow(2,po));
    printf("int : %d \n", pow(2,sizeof(int)*CHAR_BIT));
    printf("long : %d \n", pow(2,sizeof(long)*CHAR_BIT));
    printf("double : %d \n", pow(2,sizeof(double)*CHAR_BIT));
    return 0;
}
