#include <stdio.h>

void jiaayjo ( int q, int g );

main( ) {
 int p = 23, f = 24 ;
 jiaayjo (p, f) ;
 printf ( "\n%d %d", p, f ) ;
}


void jiaayjo ( int *q, int *g ){
    *q = *q + *q ;
    *g = *g + *g ;
} 