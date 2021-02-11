#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>


void print_main_menu(){
    printf("\n\n-----------------------------Choix-----------------------------------\n");
    printf("1) Calculer le nombre de points se trouvant dans un octant.\n");
    printf("2) Calculer la moyenne des points se trouvant dans un octant.\n");
    printf("3) Copier les points se trouvant dans un octant dans une matrice appelee Points_Octant_i, i allant de 1 a 8.\n");
    printf("4) Calculer la distance euclidienne entre deux points.\n");
    printf("5) Verifier si trois points forment un triangle, dans le cas echeant, afficher son perimetre, et sa surface.\n");
    printf("-------------------------------------------------------------------------\n");
}

void print_octant_menu(){
    printf("\n\n-----------------------------Octants-----------------------------------\n");
    printf("1) (+ , +, +)\n");
    printf("2) (+, +, -)\n");
    printf("3) (+,-,+)\n");
    printf("4) (+,-,-)\n");
    printf("5) (-,+,+)\n");
    printf("6) (-,+,-)\n");
    printf("7) (- , - ,+)\n");
    printf("8) (-, -, -)\n");
    printf("-------------------------------------------------------------------------\n");
}

int main(){

    int **p;
    int i, j, k, nb_point, choice, choice_octant, nb_ptn_octant, pt1, pt2, pt3, dist_p1p2, dist_p2p3, dist_p1p3, perimetre;
    float dist_eucli, tmp, moyX, moyY, moyZ;

    //--------------------------------------Initialisation-----------------------------

    srand(time(NULL));
    k=3;
    nb_ptn_octant = 0;
    dist_eucli = 0;
    moyX = 0;
    moyY = 0;
    moyZ = 0;
    
    do{
        printf("=> Definissez le nombre de points pour le nuage: ");
        scanf("%d",&nb_point);
    } while (nb_point < 0);


    p = malloc(k * sizeof(int*));

    for (i=0;i<k;i++){
        p[i] = malloc(nb_point * sizeof(int));
    }


    for(i=0;i<k;i++){
        for(j=0; j < nb_point; j++){
            p[i][j]=(rand()%2001)-1001;
        }

    }
    for(i=0;i<k;i++){
        if(i==0){
            printf("\nx:\n");
        } else if (i==1){
            printf("\ny:\n");
        } else{
            printf("\nz:\n");
        }

        for(j=0; j < nb_point; j++){
            printf("%d ",p[i][j]);
        }
    }

    //--------------------------------------Choix utilisisateur-----------------------------

    print_main_menu();
    printf("=> Quel est votre choix:\n");
    scanf("%d", &choice);

    switch(choice){
        case 1:
            print_octant_menu();
            printf("=> Quel est votre choix:\n");
            scanf("%d", &choice_octant);

            for (i=0; i < nb_point; i++){
                switch (choice_octant) {
                    case 1:
                        if(p[0][i] >= 0 && p[1][i] >= 0 && p[2][i] >= 0) nb_ptn_octant++;
                        break;
                    case 2:
                        if(p[0][i] >= 0 && p[1][i] >= 0 && p[2][i] < 0) nb_ptn_octant++;
                        break;
                    case 3:
                        if(p[0][i] >= 0 && p[1][i] < 0 && p[2][i] >= 0) nb_ptn_octant++;
                        break;
                    case 4:
                        if(p[0][i] >= 0 && p[1][i] < 0 && p[2][i] < 0) nb_ptn_octant++;
                        break;
                    case 5:
                        if(p[0][i] < 0 && p[1][i] >= 0 && p[2][i] >= 0) nb_ptn_octant++;
                        break;
                    case 6:
                        if(p[0][i] < 0 && p[1][i] >= 0 && p[2][i] < 0) nb_ptn_octant++;
                        break;
                    case 7:
                        if(p[0][i] < 0 && p[1][i] < 0 && p[2][i] >= 0) nb_ptn_octant++;
                        break;
                    case 8:
                        if(p[0][i] < 0 && p[1][i] < 0 && p[2][i] < 0) nb_ptn_octant++;
                        break;
                }
            }

            printf("=> Le nombre de point dans cet octant est: %d", nb_ptn_octant);
            break;
        case 2:
            print_octant_menu();
            printf("=> Quel est votre choix:\n");
            scanf("%d", &choice_octant);

            for (i=0; i < nb_point; i++){
                switch (choice_octant) {
                    case 1:
                        if(p[0][i] >= 0 && p[1][i] >= 0 && p[2][i] >= 0){
                            nb_ptn_octant++;
                            moyX += p[0][i];
                            moyY = p[1][i];
                            moyZ = p[2][i];
                        }
                        break;
                    case 2:
                        if(p[0][i] >= 0 && p[1][i] >= 0 && p[2][i] < 0) {
                            nb_ptn_octant++;
                            moyX += p[0][i];
                            moyY = p[1][i];
                            moyZ = p[2][i];
                        }
                        break;
                    case 3:
                        if(p[0][i] >= 0 && p[1][i] < 0 && p[2][i] >= 0) {
                            nb_ptn_octant++;
                            moyX += p[0][i];
                            moyY = p[1][i];
                            moyZ = p[2][i];
                        }
                        break;
                    case 4:
                        if(p[0][i] >= 0 && p[1][i] < 0 && p[2][i] < 0) {
                            nb_ptn_octant++;
                            moyX += p[0][i];
                            moyY = p[1][i];
                            moyZ = p[2][i];
                        }
                        break;
                    case 5:
                        if(p[0][i] < 0 && p[1][i] >= 0 && p[2][i] >= 0) {
                            nb_ptn_octant++;
                            moyX += p[0][i];
                            moyY = p[1][i];
                            moyZ = p[2][i];
                        }
                        break;
                    case 6:
                        if(p[0][i] < 0 && p[1][i] >= 0 && p[2][i] < 0) {
                            nb_ptn_octant++;
                            moyX += p[0][i];
                            moyY = p[1][i];
                            moyZ = p[2][i];
                        }
                        break;
                    case 7:
                        if(p[0][i] < 0 && p[1][i] < 0 && p[2][i] >= 0) {
                            nb_ptn_octant++;
                            moyX += p[0][i];
                            moyY = p[1][i];
                            moyZ = p[2][i];
                        }
                        break;
                    case 8:
                        if(p[0][i] < 0 && p[1][i] < 0 && p[2][i] < 0) {
                            nb_ptn_octant++;
                            moyX += p[0][i];
                            moyY = p[1][i];
                            moyZ = p[2][i];
                        }
                        break;
                }
            }
            if(nb_ptn_octant == 0 ){
                printf("=> Il n'y a pas de points dans cet octant donc impossible d'en calculer sa moyenne.");
            } else {
                printf("=> La moyenne des points est: (x= %.2f, y= %.2f, z= %.2f)", moyX/nb_ptn_octant, moyY/nb_ptn_octant, moyZ/nb_ptn_octant);
            }
            break;

        case 3:

            break;

        case 4:
            do{
                printf("=> Donnez l'indice des deux points entre 0 et %d:\n", nb_point);
                scanf("%d %d", &pt1, &pt2);
            }while ((pt1 < 0 || pt1 > nb_point) || (pt2 < 0 || pt2 > nb_point));

            for(i = 0; i < k; i++){
                tmp= p[i][pt1] - p[i][pt2];
                dist_eucli+= tmp * tmp;
            }

            printf("=> La distance euclidienne esntre ces 2 points est: %.2f", sqrtf(dist_eucli));
            break;

        case 5:
            do{
                printf("=> Donnez l'indice des trois points entre 0 et %d:\n", nb_point);
                scanf("%d %d %d", &pt1, &pt2, &pt3);
            }while ((pt1 < 0 || pt1 > nb_point) || (pt2 < 0 || pt2 > nb_point)|| (pt3 < 0 || pt3 > nb_point));

            if((((p[0][pt2]-p[0][pt1])*(p[1][pt3]-p[1][pt1]))-((p[1][pt2]-p[1][pt1])*(p[0][pt3]-p[0][pt1])))== 0){
                printf("=> Ces trois points ne forment pas de triangle.");
            } else {
                for(i = 0; i < k; i++){
                    dist_p1p2+= (p[i][pt1] - p[i][pt2]) * (p[i][pt1] - p[i][pt2]);
                    dist_p2p3+= (p[i][pt2] - p[i][pt3])* (p[i][pt2] - p[i][pt3]);
                    dist_p1p3+= (p[i][pt1] - p[i][pt3]) * (p[i][pt1] - p[i][pt3]);
                }

                perimetre = sqrt(dist_p1p2) + sqrt(dist_p2p3)+ sqrt(dist_p1p3);


                printf("=> Ces trois points forment un triangle:\n-Perimetre: %d", perimetre);
            }
            break;
        default: printf("=> Choix inconnu !");
    }



    //--------------------------------------Vide mémoire allouées-----------------------------
    for (i=0;i<k;i++){
        free(p[i]);
    }
    free(p);



    return(0);
}