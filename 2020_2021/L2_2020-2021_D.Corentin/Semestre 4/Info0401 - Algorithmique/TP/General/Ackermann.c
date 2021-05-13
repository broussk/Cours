#include <stdio.h>

int ackermann(int m, int n){
    if(m==0){
        return n+1;
    }else if( n==0){
        return ackermann(m-1,1);
    }else{
        return ackermann(m-1,ackermann(m,n-1));
    }
}


int main(){

    printf("--Ackermann rec--\n" );
    printf("A(2,2) = %d\n", ackermann(2,2));
    printf("A(3,3) = %d\n", ackermann(3,3));

    return 0;
}