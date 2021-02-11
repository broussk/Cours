#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10

void deallocate(int*** tab, int m, int l){
    int i,j;
    for(i = 0; i < l;i++){
        for(j = 0; j < m;j++){
            free(tab[i][j]);
        }
        free(tab[i]);
    }
    free(tab);
}

void print_tab(int*** tab, int n, int m, int l){
    int i, j, k;
    printf("Tableau:\n");
    for(k = 0 ; k < m; k++){
        for(i = 0; i < n; i++){
            for(j = 0;j < l; j++){
                printf("%d", tab[i][j][k]);;
            }
            printf("\n");
        }
        printf("\n");
    }
}


void store(int*** tab, int n, int m, int l){
    int i, j, k;
    printf("Veuillez saisir les valeurs du tableau:\n");
    for(k = 0 ; k < m; k++){
        for(i = 0; i < n; i++){
            for(j = 0;j < l; j++){
                printf("[%d][%d][%d]: ", k, i, j);
                scanf("%d",  &tab[i][j][k]);
            }
        }
    }
    print_tab(tab, n, m, l);


}
int*** allocate(int*** tab, int n, int m, int l){
    int i,j;
    tab = malloc(n * sizeof(int**));
    for(i = 0; i < m; i++){
        tab[i]= (int **) malloc(m * sizeof(int *));
        for( j = 0; j < n; j++)
            tab[i][j]= (int *) malloc(l * sizeof(int));
    }

    printf("Vous avez allouer un tableau de 3 dimensions : [%d][%d][%d]\n", n, m, l);
    return tab;
}



int main(){
    int ***tab3D = NULL;
    int n, m, l;

    do {
        printf("Entre un n, m et l pour un tableau 3D: \n");
        scanf("%d %d %d", &n, &m, &l);
    } while (m <= 0 || n <= 0 || l <= 0);

    tab3D = allocate(tab3D, n, m, l);
    store(tab3D, n, m, l);
    print_tab(tab3D, n, m, l);
    deallocate(tab3D, m, l);

    return 0;
}