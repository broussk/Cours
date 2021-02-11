#include <stdio.h>


int max(int a, int b, int c){
    return (a > (( b > c) ? b : c)) ? a : (( b > c) ? b : c);
}

int main(void){
    int a = 10, b = 20, c = 8;
    printf("Le max est: %d", max(a, b, c));
    return 0;
}