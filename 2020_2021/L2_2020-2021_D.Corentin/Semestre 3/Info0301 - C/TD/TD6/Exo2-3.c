#include <stdio.h>
 
int absolue (int a){​​​​
    return a < 0 ? (-1 *a) : a;
}​​​​
 
int main()
{​​​​
    printf("%d", absolue(-2));
    return 0;
}​​​​