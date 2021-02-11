#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    int size, i, p, num_vec;
    float *tab1, *tab2, val, dist_manhattan, dist_euclide, dist_tchebychev, dist_minkowski;

    do{
        printf("=> Entrez une taille:\n");
        scanf("%d", &size);
    }while(size <= 0);

    do{
        printf("Saisir distance p Minkowski:\n");
        scanf("%d",&p);
    }while(p <= 0);

    tab1 = malloc(size * sizeof(float));
    tab2 = malloc(size * sizeof(float));
    dist_manhattan=0;
    dist_euclide=0;
    dist_tchebychev=0;
    dist_minkowski = 0;

    for(num_vec=0; num_vec < 2; num_vec++){
        if(num_vec == 0){
            printf("Vecteur 1:\n");
        } else {
            printf("Vecteur 2:\n");
        }
        for(i=0; i < size; i++){
            printf("=> [%d]:", i);
            scanf("%f", &val);
            if(num_vec == 0){
                tab1[i]=val;
            }
            else{
                tab2[i]=val;
            }
        }
    }

    for(i=0;i<size;i++){
        dist_manhattan += fabsf(tab1[i]-tab2[i]);
        dist_euclide += (tab1[i]-tab2[i])*(tab1[i]-tab2[i]);
        dist_minkowski += pow(fabsf(tab1[i]-tab2[i]),p);
        if(fabsf(tab1[i] - tab2[i]) >= dist_tchebychev) dist_tchebychev = fabsf(tab1[i] - tab2[i]);
    }
    dist_euclide=sqrtf(dist_euclide);
    dist_minkowski=pow(sqrtf(dist_minkowski),p);


    printf("La distance Manhattan entre les 2 vecteurs est de: %.2f \n", dist_manhattan);
    printf("La distance Euclidienne entre les 2 vecteurs est de: %.2f \n", dist_euclide);
    printf("La distance Minkowski entre les 2 vecteurs est de: %.2f \n", dist_minkowski);
    printf("La distance Tchebychev entre les 2 vecteurs est de: %.2f \n", dist_tchebychev);

    free(tab1);
    free(tab2);

    return 0;
}