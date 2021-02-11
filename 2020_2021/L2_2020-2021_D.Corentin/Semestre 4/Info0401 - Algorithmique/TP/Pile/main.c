#include <stdio.h>
#include "pile.h"

int ack(int n, int m){
    Pile *p = create();
    push(p, m);
    push(p, n);

    while (isEmpty(p) == 0){
        n = top(p);
        pop(p);
        if(isEmpty(p) == 0){
            m = top(p);
            pop(p);
        } else {
            return n;
        }
        if(m==0){
            push(p, n + 1);
        } else if(n==0){
            push(p, m - 1);
            push(p, 1);
        } else {
            push(p, m - 1);
            push(p, m);
            push(p, n - 1);
        }
    }
    return top(p);
}

int main(){



    printf("egale: %d\n", ack(3, 3));


    return 0;
}


