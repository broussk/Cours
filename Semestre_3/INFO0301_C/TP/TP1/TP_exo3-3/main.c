#include <stdio.h>
#include <stdlib.h>

int main()
{
    int conso,i;
    float som=0;
    printf("Entrez votre consommation electrique en unite : ");
    scanf("%d",conso);
    if(conso>=0){
        if(conso>=50){
            som=0.5*50;
            conso-=50;
            if(conso>=0){
                if(conso>=100){
                    som=0.75*100;
                    conso-=100;
                    if(conso>=0){
                        if(conso>=100){
                            som=1.2*100;
                            conso-=100;
                            if(conso>=0){
                                for(i=0;i<=conso;i++){
                                    som=som+i*0.5;
                                }
                            }
                        }
                        else{
                            for(i=0;i<=conso;i++){
                                som=som+i*1.2;
                            }
                        }
                    }
                }
                else{
                    for(i=0;i<=conso;i++){
                        som=som+i*0.75;
                    }
                }
            }
        }
        else{
            for(i=0;i<=conso;i++){
                som=som+i*0.5;
            }
        }
    }
    return 0;
}
