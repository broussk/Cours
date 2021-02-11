#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TMAX 5
#define TMAX2 7
int main(){
int tab[TMAX],tab2[TMAX2];
int i;
if (TMAX<TMAX2){
srand(time(NULL));
for (i=0; i<TMAX; i++){
tab[i] = rand();
tab2[i] = tab[i];
printf("T1: i[%d]: %d | T2: i[%d]: %d \n", i , tab[i], i , tab2[i]);
}
}
else
{
printf("Le deuxieme tableau est trop petit ! \n");
}
return 0;
}