#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
  char **Dict;
  int nbMots;
  char mot[27];
  do{
    printf("Combien de mots ? ");
    scanf("%d",&nbMots);
  }while(nbMots<=0);
  Dict = (char **)malloc(sizeof(char*)*nbMots);
  for(int i=0 ; i<nbMots ; i++){
    printf("Donnez un mot : ");
    scanf("%s",mot);
    Dict[i] = (char*)malloc(sizeof(char)*strlen(mot)+1);
    strcpy(Dict[i],mot);
  }
  printf("Mon dictionnaire comporte les mots : \n");
  for(int i=0 ; i<nbMots ; i++){
    printf("%s\n",Dict[i]);
  }
  for(int i=0 ; i<nbMots ; i++){
    free(Dict[i]);
    Dict[i] = NULL;
  }
  return 0;
}
