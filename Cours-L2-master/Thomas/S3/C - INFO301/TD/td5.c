#include <stdio.h>
#include <string.h>
#define TAILLE 50

void p5ex1(){
  char phrase[100] = "Le chat attrape la pelote";
  char voy;
  // char voyTab[] = {'a','A','e','E','i','I','o','O','u','U','y','Y'};
  char listVoy[] = "aeiouyAEIOUY";
  int i=0;

  do{
    printf("Insérer une voyelle : ");
    scanf("%c%*c",&voy);
  }while(strchr(listVoy,voy)==NULL);
  // v!='a'&&v!='e'&&v!='i'&&v!='o'&&v!='u'&&v!='y'&&v!='A'&&v!='E'&&v!='I'&&v!='O'&&v!='U'&&v!='Y');
  while(phrase[i]!='\0'){
    switch(phrase[i]){
      case 'a' :
      phrase[i] = voy;
      break;
      case 'e' :
      phrase[i] = voy;
      break;
      case 'i' :
      phrase[i] = voy;
      break;
      case 'o' :
      phrase[i] = voy;
      break;
      case 'u' :
      phrase[i] = voy;
      break;
      case 'y' :
      phrase[i] = voy;
      break;
      case 'A' :
      phrase[i] = voy;
      break;
      case 'E' :
      phrase[i] = voy;
      break;
      case 'I' :
      phrase[i] = voy;
      break;
      case 'O' :
      phrase[i] = voy;
      break;
      case 'U' :
      phrase[i] = voy;
      break;
      case 'Y' :
      phrase[i] = voy;
      break;
    }
    i++;
  }
  printf("%s",phrase);
}

void p7ex1(){
  /*Solution Juliet
  char phrase[100];
  int i,cpt=0,min=100,max=0;
  int iCpt;
  printf("Entrez une phrase : ");
  scanf("%[^\n]s",phrase);
  for(i=0 ; phrase[i] != '\0' ; i++){
    cpt = 0;
    while(i==0 || phrase[i-1]!=' '){
      cpt++;
    }
    if(cpt<min){
      min = cpt;
      iCpt = i;
    }
  }
  printf("La taille du mot : %d",cpt);
  printf("L'indice du mot : %d",iCPt);
  printf("Le mot : ");
  for(i=iCpt; phrase[i]!=' '; i++){
    printf("%c",phrase[i]);
  }
  printf("\n");
  */
  /*Solution Andy*/
  char chaine[100] = "Une phrase quelconque";
  int i=0,count=0,min=100,max=0;
  for(i=0 ; chaine[i]!='\n' ; i++){
    if(chaine[i]==' '){
      count++;
    }
    else{
      if(count > max){
        max = count;
      }
      if(count < min){
        min = count;
      }
      count = 0;
    }
  }
  printf("Le mot le plus long = %d caractères\nLe mot le moins long = %d caractères",max,min);
  /**/
}

void afficherMatriceCarree(int n, int m[n][n]){
  for(int i=0 ; i<n ; i++){
    for(int j=0 ; j<n ; j++){
      printf("[%d] ",m[i][j]);
    }
    printf("\n");
  }
}
void p1ex2(){
  int M1[TAILLE][TAILLE],M2[TAILLE][TAILLE],M3[TAILLE][TAILLE],M4[TAILLE][TAILLE],M5[TAILLE][TAILLE];
  int nLines=0,lin,col;
  do{
    printf("Entrez le nombre de lignes : ");
    scanf("%d",&nLines);
  }while((nLines<=0)||(nLines>TAILLE));
  for(int lin=0 ; lin<nLines ; lin++){ //Toutes les M
    for(int col=0 ; col<nLines ; col++){
      if(lin==col){
        M1[lin][col] = 0;
        M2[lin][col] = 1;
        M3[lin][col] = 1;
        M4[lin][col] = 1;
        M5[lin][col] = 0;
      }
      if(col>lin){
        M1[lin][col] = 1;
        M2[lin][col] = 0;
        M3[lin][col] = 0;
        M4[lin][col] = 1;
        M5[lin][col] = 0;
      }
      if(col<lin){
        M1[lin][col] =-1;
        M2[lin][col] = 0;
        M3[lin][col] = 0;
        M4[lin][col] = 0;
        M5[lin][col] = 1;
      }
      if(lin+col==TAILLE-1){
        M3[lin][col] = 1;
      }
    }
  }
  printf("M1 : \n");
  afficherMatriceCarree(nLines,M1);
}

void p2ex2(){

}

int main(){
  p1ex2();
  return 0;
}
