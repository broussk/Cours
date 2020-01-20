#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void viderBuffer(){
  int c;
  while ((c = getchar()) != '\n' && c != EOF);
}

int main(){

  // int h,m,s =0;
  // printf("Entrez l'heure sous la forme HH:MM:SS > ");
  // scanf("%d:%d:%d",&h,&m,&s);
  // printf("Il est %d heures %d minutes et %d secondes\n",h,m,s);

  // double a,b=0;
  // char c=0;
  // printf("Entrez l'opération que vous souhaitez sous la forme nombre1 opérateur(+/-/*) nombre2 : ");
  // scanf("%lf %c %lf",&a,&c,&b);
  // if(c == '+'){
  //   printf("%lf + %lf = %lf\n",a,b,a+b);
  // }
  // else if(c == '-'){
  //   printf("%lf - %lf = %lf\n",a,b,a-b);
  // }
  // else if(c == '*'){
  //   printf("%lf * %lf = %lf\n",a,b,a*b);
  // }
  // else{
  //   printf("Nous n'avons pas compris, opération par défaut +\n%lf + %lf = %lf",a,b,a+b);
  // }

  // double a,b,c = 0;
  // printf("Entrez 3 valeurs séparées par une virgule : ");
  // scanf("%lf,%lf,%lf",&a,&b,&c);
  // printf("La somme des 3 valeurs : %lf\n",a+b+c);

  // char prenom[25] = "";
  // char nom[25] = "";
  // int anneeNaissance = 0;
  // printf("Entrez votre prénom : ");
  // scanf("%s",prenom);
  // viderBuffer();
  // printf("Entrez votre nom : ");
  // scanf("%s",nom);
  // viderBuffer();
  // printf("Entrez votre année de naissance : ");
  // scanf("%d",&anneeNaissance);
  // printf("%s %s né(e) en %d\n",prenom,nom,anneeNaissance);

  // char a,b;
  // printf("Merci de saisir un premier caractère : ");
  // scanf("%c",&a);
  // viderBuffer();
  // printf("Le caractère saisi est '%c' et son code ascii est %d\n",a,a);
  // printf("Merci de saisir un deuxième caractère : ");
  // scanf("%c",&b);
  // printf("Le caractère saisi est '%c' et son code ascii est %d\n",b,b);

  // char a;
  // printf("Merci de saisir un premier caractère : ");
  // scanf("%c",&a);
  // printf("Le caractère saisi est '%c' et son code ascii est %d\n",a,a);

  // printf("1- Saisie des données\n2- Lecture des données à partir d'un fichier\n3- Traitement des données\n4- Affichage des résultats\n5- Sauvegarde des résultats dans un fichier\n6- Quitter\n");

  // int fstVal, sndVal, thdVal = 0;
  //
  // printf("Merci d'entrer la première valeur : ");
  // scanf("%d",&fstVal);
  // printf("La première valeur saisie : %d\n",fstVal);
  // printf("Merci d'entrer la deuxième valeur : ");
  // scanf("%d",&sndVal);
  // printf("La deuxième valeur saisie : %d\n",sndVal);
  // printf("Merci d'entrer la troisième valeur : ");
  // scanf("%d",&thdVal);
  // printf("La troisième valeur saisie : %d\n/*** \"C'est fini\" ***/\n",thdVal);


  // printf("*************\n\n*   Test    *\n\n*************");
  return 0;
}
