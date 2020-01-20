#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lire(char *chaine, int longueur)
{
    char *positionEntree = NULL;

    // On lit le texte saisi au clavier
    if (fgets(chaine, longueur, stdin) != NULL)  // Pas d'erreur de saisie ?
    {
        positionEntree = strchr(chaine, '\n'); // On recherche l'"Entrée"
        if (positionEntree != NULL) // Si on a trouvé le retour à la ligne
        {
            *positionEntree = '\0'; // On remplace ce caractère par \0
        }
        return 1; // On renvoie 1 si la fonction s'est déroulée sans erreur
    }
    else
    {
        return 0; // On renvoie 0 s'il y a eu une erreur
    }
}

int main(int argc, char *argv[])
{

char *prenom = malloc (sizeof (*prenom) * 256);
char *nom = malloc (sizeof (*nom) * 256);
int date = 0;
printf("Donnez votre prenom :" );
lire(prenom, 20);
rewind(stdin);
printf("Donnez votre nom : " );
lire(nom, 20);
rewind(stdin);
printf("Donnez votre année de naissance : " );
scanf("%d", &date );
rewind(stdin);

printf("Vous vous appelez %s %s et êtes né en %d\n",prenom,nom,date );

    return 0;
}
