#include <stdio.h>

int main(){
    int b100,b50,b20,b10,b5,p2,p1,argent;
    printf("Veuillez entrer la somme d'argent\n");
    scanf("%d", &argent);

    b100 = argent / 100;
    argent = argent % 100;
    b50 = argent / 50;
    argent = argent % 50;
    b20 = argent / 20;
    argent = argent % 20;
    b10 = argent / 10;
    argent = argent % 10;
    b5 = argent / 5;
    argent = argent % 5;
    p2 = argent / 2;
    argent = argent % 2;
    p1 = argent;

    printf("%d euros donnera:\n- %d billet(s) de 100e\n- %d billet(s) de 50e\n- %d billet(s) de 20e\n- %d billet(s) de 10e\n- %d billet(s) de 5e\n- %d piece(s) de 2e\n- %d piece(s) de 1e.", argent, b100, b50, b20, b10, b5, p2, p1);


    return 0;
}