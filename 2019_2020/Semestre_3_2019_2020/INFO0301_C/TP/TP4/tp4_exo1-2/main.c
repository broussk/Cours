#include <stdio.h>
#include <stdlib.h>
#define TAILLE 999

int main()
{
    int i, j, min, max, cpt, tmp;
    int tab[TAILLE];
    printf("Notez 20 chiffres :\n");
    for(i=0;i<20;i++){
        printf("coucou %d:",i);
        scanf("%d",&tab[i]);
    }
    for(i=0;i<20;i++){
        if(i==0){
            min=tab[i];
            max=tab[i];
        }
        else{
            if(tab[i]<min){
                min=tab[i];
            }
            else if (tab[i]>max){
                max=tab[i];
            }
        }
    }
    printf("max= %d min= %d",max,min);
    for(i=0;i<20;i++){
        tmp=tab[i];
        for(j=0;j<20;j++){
            if(tab[j]==tmp && tab[j]>min-1){
                cpt++;
                tab[j]=min-1;
            }
            if(j==19&&tmp!=min-1){
                printf("Le nombre d'occurence de %d est de %d\n",tmp,cpt);
            }
        }
    }
    return 0;
/*prof*/
int main(){
char chaine[100];
int nb_occ[10];
int i;
printf("merci de saisir la chaine");
scanf("%s",chaine);
for(i=0;chaine[i]!='\0';i++){
    if(chaine[i]>='0' && chaine[i]<='9'){
        nb_occ[chaine[i]-'0']++;
    }
}
affichage du tableau nb_occ
}
