#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i=45,c;
    c=verifier(i);
    printf("\n%d",c);
    return 0;
}
verifier(int ch){
    if(ch>=45)
        return (100);
    else
        return(10*10);
}
