#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){

    int a,r,j,i=0;
    int t[6];

    do{
        printf("Entrer un nombre positif : ");
        scanf("%d",&a);
    }while(a<0);

    do{
        r=a%2;
        t[i]=r;
        a=(a-r)/2;
        i++;
    }while (a!=0);

    for(i=7;i>=0;i--){
        printf("%d",t[i]);
    }
    return(0);
}
