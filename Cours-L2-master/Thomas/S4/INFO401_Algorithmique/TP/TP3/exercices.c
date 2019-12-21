#include <stdio.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>

#include "exercices.h"

#define NMAX 100
#define TEN 10
/*
Ex 1 : NE FONCTIONNE PAS
calculer la longueur d'une chaine de caractères grâce aux pointeurs

*/
void ex1(){
  char *CH = "teste";
  int *P=CH;
  for(int i=0 ; i!=EOF ; i++){
    P++;
  }
  int n = P-CH;
  printf("Longueur : %d",n);
}

/*
Ex 2 : demander la longueur de deux tableau et les coller l'un derrière l'autre dans un troisième tableau grâce aux pointeurs.
        Le tableau final (le 3ème) ne doit pas dépasser NMAX

tableau d'entiers : A, B (initialisés à 0, de longueur NMAX de 100)
pointeurs sur des entiers : PA, PB
entiers : N,M (initialisés à 0)

afficher("Entrez N")
Lire(N)
Faire
  Si M > NMAX-N
    afficher("Dépassement de tableau")
  FinSi
  afficher("Entrez M")
  Lire(M)
TantQue M>NMAX-N

Pour i allant de 0 à N Faire
  A[i] = aléatoire[0-50]
FinPour
Pour i allant de 0 à M Faire
  B[i] = aléatoire[0-50]
FinPour

afficher(tableau A)
afficher(tableau B)
ajouter à l'adresse de A les valeurs de B
afficher(tableau A) //qui contient au final A+B grâce aux pointeurs
*/
void ex2(){
  int A[NMAX]={0}, B[NMAX]={0},N=0, M=0;
  srand(time(NULL));

  printf("Entrez N : ");
  scanf("%d",&N);
  do{
    if(M>NMAX-N){
      printf("Depassement de tableau\n");
    }
    printf("Entrez M : ");
    scanf("%d",&M);
  }while(M>NMAX-N);
  for(int i=0 ; i<N ; i++){
    A[i] = rand()%51;
  }
  for(int i=0 ; i<M ; i++){
    B[i] = rand()%51;
  }
  printf("Tableau A : \n");
  for(int i=0 ; i<N; i++){
    printf("%d.[%d]\n",(i+1),A[i]);
  }
  printf("Tableau B : \n");
  for(int i=0 ; i<M ; i++){
    printf("%d.[%d]\n",(i+1),B[i]);
  }
  for(int i=0 ; i<M ; i++){
    *(A+N+i) = *(B+i);
  }
  printf("Tableau A + B : \n");
  for(int i=0 ; i<N+M ; i++){
    printf("%d.[%d]\n",(i+1),A[i]);
  }
}

/*
Ex 3 : Créer un tableau de longueur fixe, le remplir aléatoirement.
       Puis, choisir une valeur aléatoire x et l'enlever du tableau précédemment créé et initialisé.
       Le tableau se verra réduit autant de fois que l'on aura retirer x du tableau. Tous les éléments seront collés le plus à gauche possible.

Initialisation
  tableau d'entiers : A (initialisé à 0 de longueur 10)
  entiers : x (aléatoire[0-10]), i(0), j(0)
  pointeurs : P1 (adresse de A), P2 (adresse de A)

Début
  Pour i allant de 0 à TEN faire
    A[i] <- aléatoire[0-10]
  FinPour
  afficher(x)
  afficher(A)

  //
  Dans la boucle pour à venir, nous remettons à chaque tour de boucle la valeur à l'adresse de P2 dans l'adresse de P1
  Ensuite, si la valeur présente à l'adresse de P2 est différente de x, on augmente P1 de 1.
  On augmente ensuite P2 dans tous les cas.
  Cela aura pour effet de passer outre les valeurs égales à x et de ne pas les copier d'un pointeur à l'autre. De ce fait, les prochaines itérations remplacement les valeurs de x qu'on a "sauté" pour mettre les valeur de droite à sa place
  //

  Pour i allant de 0 à TEN faire
    *P1 <- *P2
    Si(*P2 != x)
      P1++
    FinSi
    P2++
  FinPour

  /!\ FAIRE EXEMPLE D'EXECUTION /!\
  Pour i allant de 1 à P1-A faire //On utilise les adresses pour connaitre la longueur du tableau après avoir supprimer les valeurs qui correspondaient à x
    afficher(A[i])
  FinPour
Fin
*/
void ex3(){
  srand(time(NULL));
  int A[TEN]={0}, x=rand()%10, *P1=A, *P2=A, i=0, j=0;
  for(int i=0 ; i<TEN ; i++){
    A[i] = rand()%10;
  }
  printf("x = %d\nTableau A : \n",x);
  for(int i=0 ; i<TEN ; i++){
    printf("[%d] | ",A[i]);
  }

  for(int i=0 ; i<TEN ; i++){
    *P1=*P2;
    if(*P2!=x){
      P1++;
    }
    P2++;
  }
  printf("\nTableau A sans %d : \n",x);
  for(int i=0 ; i<(P1-A) ; i++){
    printf("[%d] | ",A[i]);
  }
}

/*
Ex 4 : Inverser les valeurs d'UN SEUL tableau à l'aide de pointeurs

Initialisation
  tableau d'entiers : A (de taille 10)
  entier : AIDE
  pointeur : P1 (pointe sur A[0], la première case), P2 (pointe sur A[0+10]-1 soit A[9], la dernière case)

  Pour i allant de 0 à 10 faire
    A[i] = aléatoire[0-10]
  FinPour
  afficher(A)
  Pour i allant de 0 à TEN/2 (soit 5) faire
    AIDE <- valeur à l'adresse de P1 (A[0])
    *P1 <- valeur à l'adresse de P2 (A[9] se retrouve dans A[0])
    *P2 <- AIDE (anciennement A[0])
    P1++
    P2--
  FinPour
  afficher(A) (après inversion)
*/
void ex4(){
  int A[TEN], AIDE, *P1=A, *P2=(A+TEN)-1;
  srand(time(NULL));
  for(int i=0 ; i<TEN ; i++){
    A[i] = rand()%10;
  }
  printf("Tableau A : \n");
  for(int i=0 ; i<TEN ; i++){
    printf("[%d] | ",A[i]);
  }
  for(int i=0 ; i<(TEN/2) ; i++){
    AIDE = *P1;
    *P1 = *P2;
    *P2 = AIDE;
    P1++;
    P2--;
  }
  printf("\nTableau A inverse : \n");
  for(int i=0 ; i<TEN ; i++){
    printf("[%d] | ",A[i]);
  }
}
