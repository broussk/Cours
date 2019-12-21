#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int taille, i,h,p;
    do{
        printf("entrez un taille : ");
        scanf("%d",&taille);
    }while(taille <= 0);
    do{
        printf("entrez un p pour la distance de Minkowski : ");
        scanf("%d",&p);
    }while(p <= 0);
    float tab1[taille],tab2[taille],val,resManh=0,tmp,resEuclid=0,resMink=0;
    for(h=1;h<=2;h++){
        for(i=0;i<taille;i++){
            printf("Tableau%d case %d :",h,i);
            scanf("%f",&val);
            //if(val<0){val*=-1;}
            if(h==1){
                tab1[i]=val;
            }
            else{
                tab2[i]=val;
            }
        }
    }
    for(i=0;i<taille;i++){
        tmp=tab1[i]-tab2[i];
        resEuclid+=tmp*tmp;
        if(tmp<0){tmp*=-1;}
        resManh+=tmp;
        for(h=0;h<p;h++){
            tmp*=tmp;//2 4 16
        }
        resMink+=tmp;
    }
    resEuclid=sqrt(resEuclid);
    printf("La distance Manhattan entre le 2 vecteurs est de : %f \n",resManh);
    printf("La distance Euclidienne entre les 2 vecteurs est de : %f \n",resEuclid);
    printf("La distance Minkowski entre les 2 vecteurs est de : %f \n",resMink);
    return 0;
}
