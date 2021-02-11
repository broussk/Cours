#include <stdio.h>

int verifier (int ch) {
    if (ch >= 45)
        return (100);
    else
        return ( 10 * 10 );
}


int main(){
    int i = 45, c ;
    c = verifier ( i ) ;
    printf ( "\n%d", c ) ;
    return 0;
}
