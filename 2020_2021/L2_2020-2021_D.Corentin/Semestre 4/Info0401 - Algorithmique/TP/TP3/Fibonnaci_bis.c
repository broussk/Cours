#include <stdio.h>

int main(){
    int i, size, nb1, nb2, nb3;

    printf("Entre une valeur \n");
    scanf("%d", &size);

    nb1 = 0;
    printf("f(0) = %d \n", nb1);
    nb2 = 1;
    printf("f(1) = %d \n", nb2);

    for(i = 2; i < size; i++){
        nb3 = nb1 + nb2;
        nb1 = nb2;
        nb2 = nb3;
        printf("f(%d) = %d \n", i, nb3);
    }

    return 0;
}