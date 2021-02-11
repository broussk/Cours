#include<stdio.h>

int main(){

    int a, b, somme, max;

    a = 10;
    b = 50;

    int * pa = &a;
    int * pb = &b;

    somme = *pa + *pb;

    if(*pa > *pb){
        max = *pa;
    } else {
        max = *pb;
    }

    printf("%d + %d = %d, le max est: %d",  *pa, *pb, somme, max);

    return 0;
}
