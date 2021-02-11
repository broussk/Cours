#include <stdio.h>

int main(){

    int a, b;
    char c;

    printf("Faite une saisie de type: \"2 + 2\" (+,-,/,x)\n");
    scanf("%d %c %d", &a, &c, &b);

    switch (c) {
        case '+': printf("%d %c %d = %d", a,c,b , (a+b));
            break;
        case '-': printf("%d %c %d = %d", a,c,b , (a-b));
            break;
        case '/': printf("%d %c %d = %d", a,c,b , (a/b));
            break;
        case 'x': printf("%d %c %d = %d", a,c,b , (a*b));
            break;
        default: printf("Operateur inconnu !");

    }


    return 0;

}