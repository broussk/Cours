char *afficherDisque(char *chaine, int tailleTours, int valDisque) {
	int i;
	
	strcpy(chaine, "");
	for (i = 0; i < tailleTours - valDisque; i++)
		strcat(chaine, " ");
	for (i = 0; i < valDisque; i++)
		strcat(chaine, "*");
	strcat(chaine, " ");
	for (i = 0; i < valDisque; i++)
		strcat(chaine, "*");
	for (i = 0; i < tailleTours - valDisque; i++)
		strcat(chaine, " ");
		
	return chaine;
}

void afficherHanoi(hanoi_t *hanoi) {
	int i, j;
	char chaine[50];
	pile_t **toursTemp = (pile_t **) malloc(sizeof(pile_t *) * 3);
	
	for (i = 0; i < 3; i++) {
		toursTemp[i] = copierPile(&hanoi->tours[i]);
	}
		
	for (i = 0; i < 100; i++)
		printf("\n");
	for (i = 0; i < hanoi->tailleTours; i++) {
		for (j = 0; j < 3; j++) {
			if (i < hanoi->tailleTours - taillePile(hanoi->tours[j])) {
				printf("%s", afficherDisque(chaine, hanoi->tailleTours, 0));
			}
			else {
				printf("%s", afficherDisque(chaine, hanoi->tailleTours, depiler(toursTemp[j])));
			}
		}
		printf("\n");
	}
	for (i = 0; i < (hanoi->tailleTours * 2 + 1) * 3; i++);
		printf("\n");
	for (i = 0; i < 3; i++) {
		detruirePile(&toursTemp[i]);
	}
	free(toursTemp);
}
