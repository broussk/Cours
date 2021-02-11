#include <stdio.h>

void swap (int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}


int main(){
    int a = 10, b = 20;
    printf("Avant swap a: %d b: %d\n", a, b);
    swap(&a, &b);
    printf("Apres swap a: %d b: %d", a, b);
    return 0;
}
