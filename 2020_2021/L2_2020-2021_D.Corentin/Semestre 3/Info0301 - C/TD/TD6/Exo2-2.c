#include <stdio.h>
 
int egaux (int a, int b, int c){​​​​
    return (a==b || a==c || b==c);
}​​​​
 
int main()
{​​​​
    printf("%d", egaux(1, 6, 6));
    return 0;
}​​​​