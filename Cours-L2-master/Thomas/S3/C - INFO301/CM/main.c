#include "fonctions.h"
#include <string.h>
#include <stdio.h>
/**/
int main(){
  char **parag;
  int nbMots;
  int i;


}
/*
strcoll <=> strcmp
*/

/*
void main(){
  char *mot1 = NULL;
  char *mot2 = NULL;
  saisie();
  saisie2();
  return 0;
}

char* saisie(){
  char chaine[100];
  scanf("%s",chaine);
  tmp = (char*)malloc(sizeof(char)*(strlen(chaine)+1))
  strcpy(tmp,chaine);
  return tmp;
}

void saisie2(char* m){
  char chaine[100];
  scanf("%s",chaine);
  *m=(char*)malloc(sizeof(char)*strlen(chaine)+1);
  strcpy(*m,chaine);
  return;
}
*/

/*
  //Exemple 1
  #include <string.h>
  #include <stdio.h>
  int main(){
    char strtest[] = "129th";
    char cset[] = "1234567890";
    int i = strspm(strtest,cset);
    printf("Le nombre de début comporte %d chiffres\n",i);
    return 0;
  }

  //Exemple 2
  #include <string.h>
  #include <stdio.h>
  int main(){
    char str[] = "lcba3";
    char key[] = "1234567890";
    int i=strcspn(str,key);
    printf("LA position du premier caractère de la deuxième chain dans la première estt %d\n",i);
    return 0;
  }

  //Exemple 3
  #include <string.h>
  #include <stdio.h>
  int main(){
    char str[] = "This is a sample string";
    char key = "aeiouy";
    char *pch;
    pch =  strpbrk(str,key)
    while(pch!=NULL){
      printf("%c",*pch);
      pch = strpbrk(str,key);
    }
    return 0;
  }
*/

/*
      Autres méthodes beaucoup utilisées dans string.h :
      strcat()
      strchr()
*/

/*
  char *mot1 = malloc(sizeof(char)*20);
  char *mot2 = malloc(sizeof(char)*30);
  strcpy(mot1,"Bonjour");
  strcpy(mot2,"Coucou");
  if(mot1==mot2){                 //} strcmp() si 0=>identique | si -=>1ère chaine inférieure | si +=>1ère chaine supérieure
                                  //} ou
  }                               //} strncmp() compare n premiers caractères
*/

/*
  char mot1[30] = "Bonjour";
  char *mot2 = NULL;
  int compt = 0;

  while(mot1[cmpt]!='\0'){      //}
    compt++;                    //}=====> strlen(mot1);
  }                             //}
  mot2=(char*)malloc(sizeof(char)+(compt+1));

  OU

  i = 1;
  while(mot1[i]!='\0'){
      mot2 = realloc(mot2, sizeof(char)*(i+1));
      mot1[i] = mot2[i];
    }
    MAIS PLUS LONG DONC MOI EFFICACE

    for(i=0 ; i<=compt ; i++){                    //}
      mot2[i] = mot1[i];                          //}=====> strcpy(dst,src);
    }                                             //}
*/

/*
  int tab[] = {0,1,2,3,4};
  affichage(tab,3);
*/
