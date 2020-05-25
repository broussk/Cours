#include <stdio.h>
#include <math.h>
void main(){
int heure1=1,minute1=20,seconde1=30,heure2=2,minute2=24,seconde2=55,tot1,tot2,totall;
tot1=(heure1*3600)+(minute1*60)+seconde1;
tot2=(heure2*3600)+(minute2*60)+seconde2;
if (tot1>tot2){
    totall=tot1-tot2;
}else{
    totall=tot2-tot1;
}
printf("%d\n",totall);

}