#include <stdio.h>


#define MAX  30

void print_matrice(int size, int mat[MAX][MAX]){
    int i, j;
    for (i=0;i<size;i++){
        for (j=0;j<size;j++){
            printf("%d ",mat[i][j] );
        }
        printf("\n");
    }
    printf("\n");
}


int main(){

    int i, j ,m1[MAX][MAX] = {0}, m2[MAX][MAX] = {0}, m3[MAX][MAX] = {0}, m4[MAX][MAX] = {0}, m5[MAX][MAX] = {0}, size;

    do{
        printf("Entrez le nombre de ligne des matrices: \n");
        scanf("%d", &size);
    } while (size <= 0 || size > MAX);


    //M1
    for (i=0;i<size;i++){
        for (j=0;j<size;j++){
            if (i < j){
                m1[i][j] = 1;
            } else {
                m1[i][j] = -1;
            }
        }
    }

    //M2
    for (i=0;i<size;i++){
        for (j=0;j<size;j++){
            if(i == j){
                m2[i][j] = 1;
            }
        }
    }


    //M3
    for (i=0;i<size;i++){
        for (j=0;j<size;j++){
            if(i + j == size-1){
                m3[i][j] = 1;
            }
        }
    }


    //M4
    for (i=0;i<size;i++){
        for (j=0;j<size;j++){
            if(i == j || i <j){
                m4[i][j] = 1;
            }
        }
    }

    //M5
    for (i=0;i<size;i++){
        for (j=0;j<size;j++){
            if(i == j || i > j){
                m5[i][j] = 1;
            }
        }
    }

    print_matrice(size, m1);
    print_matrice(size, m2);
    print_matrice(size, m3);
    print_matrice(size, m4);
    print_matrice(size, m5);


    return(0);
}
