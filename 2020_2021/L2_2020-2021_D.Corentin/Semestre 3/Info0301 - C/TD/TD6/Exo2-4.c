#include <stdio.h>
#include <math.h>

int premier(int n){​​
    int i = 2;
    int premier=1;
    while((premier==1)&&i<=sqrt(n)){​​
        if(n%i==0){​​
            premier=0;
        }​​
           i++;
    }​​
    return premier;
}


 
int premier( int a ){​​​​
    int i,tem=1;
    for (i=2;tem==1 && i<=sqrt(a);i++){​​​​
     if (a%i==0)  {​​​​ tem=0;}​​​​
}​​​​
return tem;
}​​​​

int main()
{​​​​
    printf("%d", premier(23));
    return 0;
}​​​​​​