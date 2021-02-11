#include <stdio.h>
#include <stdlib.h>

int main(){
//Declarations
    int **pascal = NULL;
    int i, t, j;
//Instructions
    do{
        printf("Saisir taille du triangle de pascal: ");
        scanf("%d", &t);
    }while(t<1);

    pascal = (int **)calloc(t, sizeof(int *)); // <- lignes

    if(pascal == NULL){
        printf("NULL");
        exit(-1);
    }

    for(i=0; i<t; i++){
        pascal[i] = (int *)calloc((i+1), sizeof(int)); // <- lignes
        if(pascal[i] == NULL){
            printf("NULL");
            exit(-2);
        } 
    }

    for(i=0; i<t; i++){
        pascal[i][0] = 1;
        pascal[i][i] = 1;
        for(j=1; j<i; j++){
            pascal[i][j] = pascal[i-1][j] + pascal[i-1][j-1];
        }
    }


    for(i=0; i<t; i++){
        for(j=0; j<=i; j++){ 
            printf("%d ",pascal[i][j]);
        }
        printf("\n");
    }

    for(i=0; i<t; i++){
        free(pascal[i]);
        pascal[i]=NULL;
    }
    
    free(pascal);
    pascal = NULL;
    return 0;
}