#include <stdio.h>
#include <stdlib.h>

void permutation(int *x, int *y){
    int tmp;
    tmp=*x;
    *x=*y;
    *y=tmp;
}
void additionPourCharline(int *x,int *y, int *res){
    *res=*x+*y;
}
void increment5(int *a,int *b, int *c){
    *a+=5;
    *b+=5;
    *c+=5;
}
int main()
{
    int x=2,y=10,*res=0;
    int a=1,b=2,c=3;
    permutation(&x,&y);
    printf("Permuation : x=%d et y=%d", x,y);
    additionPourCharline(&x,&y,&res);
    printf("\nAddition expliquee pour Charline : %d",res);
    increment5(&a,&b,&c);
    printf("\nIncremente a=%d, b=%d, c=%d",a,b,c);
    return 0;
}
