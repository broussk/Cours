#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int taille,i,j;
    double res;
    int **Cloud= NULL;
    int* X= NULL;
    int* Y= NULL;
    int* Z= NULL;
    

    //Initialisation de la taille des tableaux
    printf("Entrez la taille des tableaux :");
    scanf("%d",&taille);

    //Initialisation des tableaux
    X = malloc(taille * sizeof(int));
    Y = malloc(taille * sizeof(int));
    Z = malloc(taille * sizeof(int));
    Cloud = malloc((taille) * sizeof(double*));
    for (i = 0 ; i < taille ; i++)
    {
        Cloud[i] = malloc(3 * sizeof(double));
    }  

    //Remplissage des tableaux
    srand(time(NULL));
    for(i=0;i<taille;i++){
        X[i]=rand()%(1000+1000)-1000;
        Y[i]=rand()%(1000+1000)-1000;
        Z[i]=rand()%(1000+1000)-1000;
    }

    for(i=0;i<taille;i++){
        Cloud[i][0]=X[i];
        Cloud[i][1]=Y[i];
        Cloud[i][2]=Z[i];
    }

    for(i=0;i<taille;i++){
        printf("Cloud[%d] X= %d  Y= %d  Z= %d \n",i,X[i],Y[i],Z[i]);
    }




    free(X);
    free(Y);
    free(Z);
    return (0);
}