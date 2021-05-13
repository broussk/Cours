#include <stdio.h>

int fib(int n){
    if (n <= 1) return n;
    return fib(n-1) + fib(n-2);
}

int main() {
    int nb;

    do{
        printf("Fibonnaci de ? \n");
        scanf("%d", &nb);
    } while (nb < 0);

    printf("Fib de %d : %d", nb,  fib(nb));

    return 0;
}
