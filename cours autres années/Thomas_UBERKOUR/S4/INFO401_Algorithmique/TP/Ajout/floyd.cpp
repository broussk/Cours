#include <stdio.h>
int floyd(){
    int n, i,  c, a = 1;
    printf("entrez le nombre de ligne\n");
    scanf("%d", &n);
    for (i = 1; i <= n; i++){
        for (c = 1; c <= i; c++){
            printf("%d ",a);
            a++;
        }
        printf("\n");
    }
    return 0;
}
void print_floyd(int n) {
    static int row = 1, c = 1;
    int d;
    if (n <= 0){
        return;
    }
    for (d = 1; d <= row; ++d){
        printf("%d ", c++);
    }
    printf("\n");
    row++;
    print_floyd(--n);
}
int floydrecur(){
    int n, i,  c, a = 1;
    printf("entrez le nombre de ligne à afficher\n");
    scanf("%d", &n);
    print_floyd(n);
    return 0;
}

