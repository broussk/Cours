#include <stdio.h>

int function(int *);

void main() {
 int i = 35, *z ;
 z = function ( &i ) ;
 printf ( "\n%d", z ) ;
}

int* function ( int *m ){
 return ( m + 2 ) ;
} 