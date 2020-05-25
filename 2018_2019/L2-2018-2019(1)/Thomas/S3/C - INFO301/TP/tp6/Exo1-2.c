#include <stdio.h>
#include <math.h>
void main(){
    int taille,i;
    double res;
    int* vec1= NULL;
    int* vec2= NULL;

    //Initialisation de la taille des tableaux
    printf("Entrez la taille des tableaux :");
    scanf("%d",&taille);

    //Initialisation des tableaux
    vec1 = malloc(taille * sizeof(int));
    vec2 = malloc(taille * sizeof(int));

    //Remplissage des tableaux
    for(i=0;i<taille;i++){
        printf("vec1[%d] = ",i);
        scanf("%d",&vec1[i]);
    }

    for(i=0;i<taille;i++){
        printf("vec2[%d] = ",i);
        scanf("%d",&vec2[i]);
    }

    //Calcul des distances de Manhattan
    for (i=1;i<taille;i++){
        res=abs(vec1[i]-vec1[i-1])+abs(vec2[i]-vec2[i-1]);
        printf("La valeur de la %d-ieme distance de Manhattan est : %f \n",i,res);
    }

    //Calcul des distances Euclidienne
    for (i=1;i<taille;i++){
        res=sqrt(pow(vec1[i]-vec1[i-1],2)+pow(vec2[i]-vec2[i-1],2));
        printf("La valeur de la %d-ieme distance Euclidienne est : %f \n",i,res);
    }

    //Calcul des distances de Minkowski
    for (i=1;i<taille;i++){
        res=pow(pow(vec1[i]-vec1[i-1],taille)+pow(vec2[i]-vec2[i-1],taille),1.0/taille);
        printf("La valeur de la %d-ieme distance de Minkowski est : %f \n",i,res);
    }
    
    //On n'a pas compris le dernier

    free(vec1);
    free(vec2);
}