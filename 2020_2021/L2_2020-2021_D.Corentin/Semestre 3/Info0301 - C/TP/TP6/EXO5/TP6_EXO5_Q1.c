#include <stdio.h>

int maxtab(int * t, int size){
    int m;
    if (size == 1) return *t;
    m = maxtab(t+1, size - 1);
    if (*t >= m)
        return (*t);
    else
        return m;
}

int main(){
    int tab[5] = {1, 5, 4, 2, 8};
    printf("La plus grande valeur du tabeau est %d\n", maxtab(tab,5));
    return 0;
}