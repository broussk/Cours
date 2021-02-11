#include <stdio.h>

int A(int n, int m){
    if(m==0){
        return n+1;
    }else if(m > 0 && n==0){
        return A(m-1,1);
    }else{
        return A(m-1,A(m,n-1));
    }
}

int main(){
    printf("%d",A(2,2));
    return 1;
}