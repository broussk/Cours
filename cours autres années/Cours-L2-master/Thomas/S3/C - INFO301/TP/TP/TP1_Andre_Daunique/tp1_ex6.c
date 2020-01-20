#include <stdio.h>

void main(){
    int a,b,res,reste;
    printf ("saisir 2 nombre\n");
    fflush(stdin);
    scanf("%d,%d\n",&a,&b);
    if (a>b){
        res=a/b;
        reste=a%b;
    }else if (b>a){
        res=b/a;
        reste=b%a;
    }
    printf("résultat = %d et reste = %d",res,reste);

}