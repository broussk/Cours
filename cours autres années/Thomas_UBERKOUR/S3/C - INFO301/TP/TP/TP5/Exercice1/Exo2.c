#include <stdlib.h>
#include <stdio.h>

int main(){
  char chaine[50]="";
  printf("Entrez une suite de chiffre : ");
  scanf("%s",chaine);
  // printf("%s\n",chaine);
  int i=0;
  int count0=0, count1=0, count2=0, count3=0, count4=0, count5=0, count6=0, count7=0, count8=0, count9=0;
  while(chaine[i]!=0){
    switch(chaine[i]){
      case '0':
      count0++;
      break;
      case '1':
      count1++;
      break;
      case '2':
      count2++;
      break;
      case '3':
      count3++;
      break;
      case '4':
      count4++;
      break;
      case '5':
      count5++;
      break;
      case '6':
      count6++;
      break;
      case '7':
      count7++;
      break;
      case '8':
      count8++;
      break;
      case '9':
      count9++;
      break;
    }
    i++;
  }
  printf("Chaine : %s\nCaractère\tOccurence\n0\t%d\n1\t%d\n2\t%d\n3\t%d\n4\t%d\n5\t%d\n6\t%d\n7\t%d\n8\t%d\n9\t%d\n",chaine,count0,count1,count2,count3,count4,count5,count6,count7,count8,count9);
}
