#include <stdio.h>
#include <limits.h>

int main()
{
    printf("char : %d octets\n", sizeof(char));
    printf("int : %d octets\n", sizeof(int));
    printf("long : %d octets\n", sizeof(long));
    printf("double : %d octets\n", sizeof(double));
    printf("char : %d bits\n", sizeof(char)*CHAR_BIT);
    printf("int : %d bits\n", sizeof(int)*CHAR_BIT);
    printf("long : %d bits\n", sizeof(long)*CHAR_BIT);
    printf("double : %d bits\n", sizeof(double)*CHAR_BIT);
    return 0;
}
