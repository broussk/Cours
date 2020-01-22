#include <stdio.h>
#include <stdlib.h>

int main(){
    int * f;
    int i,n;
    printf("entrer valeure positive");
    scanf("%d",&n);

    f = malloc(n*__SIZEOF_INT__);

    f[0]=0;
    f[1]=1;

    printf("%d ",f[0]);
    printf("%d ",f[1]);

    for(i=2;i<n;i++){
        f[i]=f[i-1]+f[i-2];
        printf("%d ",f[i]);
    }

    printf("\n");

    return 0;
}