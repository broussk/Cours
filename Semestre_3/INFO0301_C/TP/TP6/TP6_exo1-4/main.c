#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i=45,c;
    c=verifier(i*1000);
    printf("\n%d",c);
    return 0;
}
verifier(int ch){
if(ch>=40000)
    return (ch/10);
else
    return (10);
}
