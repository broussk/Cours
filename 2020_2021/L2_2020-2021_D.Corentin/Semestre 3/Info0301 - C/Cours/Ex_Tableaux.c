#include<stdio.h>
#include<stdlib.h>
#define nbl 2
#define nbc 3


int main()
{
  int Tab[5]={1,2,3,4,5};
  int Mat[nbl][nbc]={{1,2,3},{4,5,6}}; // = {1,2,3,4,5,6}
  int M[nbl][nbc]= {{0}}; // = {0}
  int * p;
  int i,j;

  /*
  for (i=0;i<nbl;i++){
      for(j=0;j<nbc;j++){
          printf("Donner M[%d][%d]: ",i,j);
          scanf("%d",&M[i][j]);
      }
  }
  */

  for (i=0;i<nbl;i++){
      for(j=0;j<nbc;j++{
	        M[i][j]=rand()%101;
      }
  }


 printf("\n\n");


  for (i=0;i<nbl;i++)  {
      for(j=0;j<nbc;j++){
          printf("%d ",M[i][j]);
      }
      printf("\n");
  }

  //  Tab=p; FAUX
  /*  p=Tab;

  printf("Tab = %d \n",Tab);
  printf("&Tab = %d \n",&Tab);
  printf("p = %d \n",p);
  printf("&p = %d \n",&p);
  printf("&Tab[0] = %d \n",&Tab[0]);
  printf("&p[0] = %d \n",&p[0]);
  printf("*Tab = %d \n",*Tab);
  printf("*p = %d \n",*p);
  printf("p[0] = %d \n",p[0]);
  printf("Tab[0] = %d \n",Tab[0]);
  */

  // Affichage du tableau Tab avec p
  /*  for (i = 0; i<5; i++)
    printf("p[%d]=*(p+i)=%d=%d\n",i, p[i],*(p+i));
  */

  //  Tab[i] <=> *(Tab+i)   et  &Tab[i] <=> &*(Tab+i)<=> (Tab+i)
  /*  printf("&Tab[3] =%d \n  &*(Tab+3) = %d \n (Tab+3)=%d \n",&Tab[3],&*(Tab+3),(Tab+3));
   */

  // Tab[3] <=> *(Tab+3) <=> *(3+Tab) <=> 3[Tab] ??
  /*
  printf("Tab[3] = %d  se trouve à l'adresse &Tab[3]=%d\n",Tab[3],&Tab[3]);
  printf("*(Tab+3) = %d  se trouve à l'adresse Tab+3=%d\n",*(Tab+3),Tab+3);
  printf("*(3+Tab) = %d  se trouve à l'adresse 3+Tab=%d\n",*(3+Tab),3+Tab);
  printf("3[Tab] = %d  se trouve à l'adresse &3[Tab]=%d\n",3[Tab],&3[Tab]);
  */

  /*
  printf("Tab = %d \n",Tab);
  printf("&Tab = %d \n",&Tab);
  printf("&Tab[0] = %d \n",&Tab[0]);
  printf("*Tab = %d \n",*Tab);
  printf("Tab[0] = %d \n",Tab[0]);

  for (i =0; i<5;i++){
      printf("&Tab[%d] = %d \n",i,&Tab[i]);
      printf("Tab+%d = %d \n",i,Tab+i);
      printf("Tab[%d] = %d \n",i,Tab[i]);
      printf("*(Tab+%d) = %d \n",i,*(Tab+i));
  }
  */
  return 0;
}
