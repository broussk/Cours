#include <stdio.h>

int max_pow(int a) {
    int tmp = 1, p = 0;
    if( a < 0){
        return -1;
    } else{
        while(tmp <= a){
            tmp *= 2;
            p++;
        }
    }
    p--;
    return p;
}

int main(void){
    int a = 33;
    printf("La puissance max est: %d",  max_pow(a));
    return 0;
}