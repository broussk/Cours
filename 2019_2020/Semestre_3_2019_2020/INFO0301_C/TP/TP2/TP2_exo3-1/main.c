#include <stdio.h>
#include <stdlib.h>

int main()
{
    char c;
    printf("Entrez un caractere :");
    scanf("%c",&c);
    if(c>='0'&&c<='9'){
        printf("C'est un chiffre !\n");
    }
    else if(c>='A'&&c<='Z'){
        printf("C'est une lettre majuscule ");
        if(c=='A'||c=='E'||c=='Y'||c=='U'||c=='I'||c=='O'){
            printf("et c'est une voyelle !\n");
        }
        else{
            printf("et c'est une consonne !\n");
        }
    }
    else if(c>='a'&&c<='z'){
        printf("C'est une minuscule ");
        if(c=='a'||c=='e'||c=='y'||c=='u'||c=='i'||c=='o'){
            printf("et c'est une voyelle !\n");
        }
        else{
            printf("et c'est une consonne !\n");
        }
    }
    else{
        printf("C'est un caractère !\n");
    }
    return 0;
}
