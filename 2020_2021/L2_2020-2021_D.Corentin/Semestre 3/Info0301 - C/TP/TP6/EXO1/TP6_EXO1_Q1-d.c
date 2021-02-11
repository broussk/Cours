#include <stdio.h>

int multiplier(int ch){
    if ( ch >= 40000 )
        return ( ch / 10 ) ;
    else
        return ( 10 ) ;
}


int main(){
    int i = 45, c ;
    c = multiplier ( i * 1000 ) ;
    printf ( "\n%d", c ) ;
    return 0;
}

