#include <stdio.h>
#include <stdlib.h>
#include "Element.h"

struct Cellule* creerCellule(int valeur){
    struct Cellule* c;
    c=(struct Cellule*)malloc(sizeof(struct Cellule));
    c->nombre=valeur;
    c->suivant=NULL;
    return c;
}

struct Liste* creerListe(){
    struct Liste* l;
    l=(struct Liste*)malloc(sizeof(struct Liste));
    l->tete=NULL;
    l->queue=NULL;
    return l;
}

void afficherListe(struct Liste* l){
    
    struct Cellule* p;

    if(l->tete==NULL){
        printf("La liste est vide\n");
    }
    else{
        p=l->tete;
        while(p->suivant!=NULL){
            printf("%d\n",p->nombre);
            p=p->suivant;
        }
        printf("%d\n",p->nombre);       
    }
}

void ajouterFinListe(struct Liste* l, struct Cellule* c){
    if(l==0){
        printf("La liste n'existe pas\n");
    }
    else if(l->tete==NULL){
        printf("La liste etait vide \n");
        l->tete=c;
        l->queue=c;
    }
    else{
        l->queue->suivant=c;
        l->queue=c;
    }
}

struct Liste* fusionListes(struct Liste* l1, struct Liste* l2){
    struct Liste* l3;
    struct Cellule* p1;
    struct Cellule* p2;
    p1=l1->tete;
    p2=l2->tete;
    while((p1!=0)&&(p2!=0)){
        if(p1->nombre<p2->nombre){
            ajouterFinListe(l3,p1);
            p1=p1->suivant;
        }
        else{
            ajouterFinListe(l3,p2);
            p2=p2->suivant;
        }
    }
    if(!p2){
        while(p2!=NULL){
            ajouterFinListe(l3,p2);
            p2=p2->suivant;
        }
    }
    else{
        while(p1!=NULL){
            ajouterFinListe(l3,p1);
            p1=p1->suivant;
        }
    }
    return l3;
}


int main(){

    struct Liste* l;

    struct Cellule* c1;
    struct Cellule* c2;
    struct Cellule* c3;
    struct Cellule* c4;

    int nb1=18, nb2=23, nb3=11, nb4=4;

    c1=creerCellule(nb1);
    c2=creerCellule(nb2);
    c3=creerCellule(nb3);
    c4=creerCellule(nb4);

    printf("Cellule 1 = %d \n",c1->nombre);
    printf("Cellule 2 = %d \n",c3->nombre);
    printf("Cellule 3 = %d \n",c2->nombre);
    printf("Cellule 4 = %d \n",c4->nombre);


    l=creerListe();

    ajouterFinListe(l,c1);

    ajouterFinListe(l,c2);

    ajouterFinListe(l,c3);

    printf("Liste : \n");
    afficherListe(l);

    return(0);
}