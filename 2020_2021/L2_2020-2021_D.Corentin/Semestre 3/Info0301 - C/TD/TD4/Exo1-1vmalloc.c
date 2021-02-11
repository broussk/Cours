#include <stdio.h>
#include <stdlib.h>

void print_matrice(int size, int **mat){
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

    int i, j ,**m1, **m2, **m3, **m4, **m5, size;

    do{
        printf("Entrez le nombre de ligne des matrices: \n");
        scanf("%d", &size);
    } while (size <= 0);

    m1 = malloc(size * sizeof(int));
    m2 = malloc(size * sizeof(int));
    m3 = malloc(size * sizeof(int));
    m4 = malloc(size * sizeof(int));
    m5 = malloc(size * sizeof(int));

    for (i=0;i<size;i++){
        m1[i] = malloc(size * sizeof(int));
        m2[i] = malloc(size * sizeof(int));
        m3[i] = malloc(size * sizeof(int));
        m4[i] = malloc(size * sizeof(int));
        m5[i] = malloc(size * sizeof(int));
    }


    //M1
    for (i=0;i<size;i++){
        for (j=0;j<size;j++){
            if(i == j){
                m1[i][j] = 0;
            } else if (i < j){
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
            }  else {
                m2[i][j] = 0;
            }
        }
    }


    //M3
    for (i=0;i<size;i++){
        for (j=0;j<size;j++){
            if(j == size-(i+1)){
                m3[i][j] = 1;
            }  else {
                m3[i][j] = 0;
            }
        }
    }


    //M4
    for (i=0;i<size;i++){
        for (j=0;j<size;j++){
            if(i == j || i <j){
                m4[i][j] = 1;
            } else {
                m4[i][j] = 0;
            }
        }
    }

    //M5
    for (i=0;i<size;i++){
        for (j=0;j<size;j++){
            if(i == j || i > j){
                m5[i][j] = 1;
            } else {
                m5[i][j] = 0;
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