#include <stdio.h>

#define tailleMax 100

int main(){

    int tab[tailleMax], duppli[tailleMax];
    int size,i,j,k,l,exist,occ;

    do{
        printf("Entrez la taille de votre tableau : ");
        scanf("%d",&size);
    }while(size <= 0 || size > tailleMax);


    printf("Entrez %d valeur(s) : ", size);
    for(i=0; i < size; i++){
        scanf("%d",&tab[i]);
    }

    k=0;
    occ=0;

    for(i=0; i < size; i++){
        for(j=i+1; j < size; j++){
            if(tab[i] == tab[j]){
                if(k==0){
                    duppli[k]=tab[i];
                    occ++;
                }
                else{
                    l=0;
                    exist=0;
                    while(l<k && exist == 0){
                        if(tab[i] == duppli[l]){
                            exist=1;
                        }
                        l++;
                    }
                    if(exist == 0){
                        duppli[k]=tab[i];
                        occ++;
                    }
                }
                k++;
            }
        }
    }

    printf("\nIl y a %d element(s) duplique(s)", occ);

    return 0;

}

