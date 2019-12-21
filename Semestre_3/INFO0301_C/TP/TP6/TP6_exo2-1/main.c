#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int plusGrand(int a, int b, int c){
    if(a>b && a>c)
        return a;
    else if(b>a && b>c)
        return b;
    else
        return c;
}
char toByTo(int a, int b, int c){
    if(a==b||a==c||b==c)
        return ('v');
    else
        return ('f');
}
int puissance2(int n){
    int res=n,i=0;
    do{
        i++;
        res/=2;
    }while(res!=0);
    return i;
}
int premierChiffre(int x){
    if(x>=0&&x<10)
        return x;
    else if(x>=10&&x<100)
        return x/10;
    else if(x>=100&&x<1000)
        return x/100;
    else if(x>=1000&&x<10000)
        return x/1000;
    else if(x>=10000&&x<100000)
        return x/10000;
    else if(x>=100000&&x<1000000)
        return x/100000;
    else
        return x;
}
int main()
{
    int a=2345678,b=0,c=2, resultat, resul,re;
    char res;
    resultat=plusGrand(a,b,c);
    printf("C'est %d le plus grand ", resultat);
    res=toByTo(a,b,c);
    printf("\nUn nombre est tape 2 fois: %c",res);
    resul=puissance2(a);
    printf("\nLa plus grande puissande de 2 de A est %d",resul);
    re=premierChiffre(a);
    printf("\nLe premier chiffre de A est %d",re);
    return 0;
}
