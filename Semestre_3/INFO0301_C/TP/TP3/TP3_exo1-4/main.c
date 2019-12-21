#include <stdio.h>
#include <limits.h>

int main()
{
    double x,y;
    long lx=1234567891231465789.654321;
    y=100*lx;
    x=(float)y/100;

    if(x>INT_MAX){
        printf("-1");
    }
    else{
        printf("le long tronque est maintenant egal a : %lf\n",x);
    }
    return 0;
}
