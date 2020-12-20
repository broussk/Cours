/*
 * TONNELLE Nathan
 * 16-10-2020
*/

#include <stdio.h>
#include <stdlib.h>
#include "kruskal.h"
#include "arete.h"
#define MAX 100;

arete** generer_acpm_kruskal_tableau(arete** t){
  arete**tab = malloc(sizeof(arete)*23);
  int tabint[24];
  int temp = 2;
  int val = 2;
  int bool = 0;
  int j = 0;

  tab[0] = t[0];
  tabint[0] = t[0]->sommetCelluleOrigine->sommet;
  tabint[0] = t[0]->sommetCelluleExtremite->sommet;

  for (int i=1; i<23; i++){
    printf("%d/",t[i]->sommetCelluleOrigine->sommet);
    printf("%d\n", tabint[temp]);
    printf("[%i] [%i]", i, j);
    bool = 0;
    j = 0;
    while(bool != 1 && j < 24){
      printf("|%d|", j);
      if((t[i]->sommetCelluleOrigine->sommet != tabint[j] && t[i]->sommetCelluleExtremite->sommet != tabint[j]) && (val < 24)){
        printf("%d/", t[i]->sommetCelluleOrigine->sommet);
        printf("%d::", t[i]->sommetCelluleExtremite->sommet);
        tabint[val] = t[i]->sommetCelluleOrigine->sommet;
        val++;
        tabint[val] = t[i]->sommetCelluleExtremite->sommet;
        val++;
        printf("@%d/@", tabint[j]);
        //printf("passer\n");
        tab[temp-1] = t[i];
        temp++;
        bool = 1;
        printf("%d ",tab[temp]->poids);
      }
      else{
        bool = 0;
      }
      j++;
      printf("%d\n",val);
    }
    printf("\n");
  }
  return tab;
}