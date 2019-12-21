#include <stdio.h>
int main (){
char c1,c2;
printf("Merci de saisir le caractere 1:");
scanf("%c%*c",&c1);
printf("Le caractere 1=%c(code ascii=%d)\n",c1,c1);
printf("Merci de saisir le caractere 2:");
scanf("%c%*c",&c2);
printf("Le caractere 1=%c(code ascii=%d)\n",c2,c2);
return(0);
}