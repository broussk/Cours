#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void FtoC();
void CtoF();
void affCubeNatuel(int max);
void affTriangle(int a);


int main(){
  // FtoC();

  // CtoF();

  // int max = 0;
  // while(max < 1){
  //   printf("Entrez une valeur pour le max au moins égale à 1 : ");
  //   scanf("%d",&max);
  // }
  // affCubeNatuel(max);
  affTriangle(7);


}

void FtoC(){
  printf("***Conversion Farenheit en Celsius***\n\n");
  for(int f=0 ; f<=300 ; f+=20){
    double c = (5.0/9.0)*(f-32.0);
    printf("%d°F****** %.1f°C\n",f,c);
  }
  printf("\n\n");
}

void CtoF(){
  printf("***Conversion Celsius en Farenheit***\n\n");
  for(int c=0 ; c<=300 ; c+=20){
    double f = (9.0/5.0*c)+32;
    printf("%d°C****** %.1f°F\n",c,f);
  }
  printf("\n\n");
}

void affCubeNatuel(int max){
    for(int i=1 ; i<=max ; i++){
      printf("Le cube de %d est : %d\n",i,i*i*i);
    }
}

void affTriangle(int a){
  for(int i=1;i<=a;i++)
  {
      for(int j=1;j<=i;j++)
      {
          printf("%d",j);
      }
      printf("\n");
  }
}
