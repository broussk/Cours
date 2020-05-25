#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main(){
  //EXO 3 a)


  // EXO 2 c)
  // char c = 0;
  // int a = 0;
  // printf("Entrez un caractère : ");
  // scanf("%c",&c);
  // printf("Entrez une hauteur : ");
  // scanf("%d",&a);
  // for(int i=1;i<=a;i++)
  // {
  //     for(int j=1;j<=i;j++)
  //     {
  //         printf("%c",c);
  //     }
  //     printf("\n");
  // }


  //EXO 2 b)
  // char compteur = 'A';
  // while(compteur<='Z'){
  //   printf("Caractère %c      Code ASCII = %d      Code Hexa = %x\n",compteur,compteur,compteur);
  //   compteur++;
  // }
  // printf("\n************      ***************      **************\n\n");
  // compteur = '0';
  // while(compteur<='9'){
  //   printf("Caractère %c      Code ASCII = %d      Code Hexa = %x\n",compteur,compteur,compteur);
  //   compteur++;
  // }
  // printf("\n************      ***************      **************\n\n");
  // compteur = 'a';
  // while(compteur<='z'){
  //   printf("Caractère %c      Code ASCII = %d      Code Hexa = %x\n",compteur,compteur,compteur);
  //   compteur++;
  // }


  //EXO 2 a)
  // double c=0,f=-40;
  // printf("Farenheit to Celsius\n\n");
  // do {
  //   c = (f-32)*5/9;
  //   printf("%.1f°F > %.1f°C\n",f,c);
  //   f += 5;
  // } while(f>=-40 && f<=40);
  // c = -40; f=0;
  // printf("\nCelsius to Farenheit\n\n");
  // do {
  //   f = (c*9/5)+32;
  //   printf("%.1f°C > %.1f°F\n",c,f);
  //   c+=5;
  // } while(c>=-40 && c<=40);


  //EXO 1 c)
  // int a=0,compt=0,tmp=0;
  // srand(time(NULL));
  // do {
  //   /* code */
  //   printf("Entrez un nombre en 100 et 999 : ");
  //   scanf("%d",&a);
  // } while(a<100 || a>999);
  // do {
  //   compt++;
  //   printf("%d\n",compt);
  // } while(a!=(rand()%(999-100)+100));
  // printf("Compteur = %d",compt);

  //EXO 1 b)
  // int r1,r2,r3;
  // do {
  //   v1=rand();
  //   v2=rand();
  //   v3=rand();
  // } while(r1%2==1 || r2%2==0 || r3%2==0);
  // printf("%d %d %d",v1,v2,v3);
  // return 0;

  //Exo 1 a)
  // int a=0, b=0;
  // do{
  //   printf("Entrez une valeur positive : ");
  //   scanf("%d",&a);
  // }while(a<=0);
  // do{
  //   printf("Entrez une valeur paire et multiple de 3 : ");
  //   scanf("%d",&b);
  // }while((b%3!=0) || (b%2==1));
  // if(a > b){
  //   printf("Le max est x = %d",a);
  // }
  // else{
  //   printf("Le max est y = %d",b);
  // }
}
