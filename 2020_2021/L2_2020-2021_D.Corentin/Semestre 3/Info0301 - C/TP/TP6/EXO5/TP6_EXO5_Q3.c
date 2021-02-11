#include <stdio.h>
#include <string.h>

int pal(char *tab, int i, int j){
    if (j == i) return 1;
    if(tab[i] == tab[j])
        return pal(tab, i++, j--);
    else
        return 0;
}


int main(){
    char tab[100] = "eve";
    if(pal(tab, 0, strlen(tab) - 1)){
        printf("C'est un pal");
    } else {
        printf("Ce n'est pas un pal");
    }
    return 0;
}