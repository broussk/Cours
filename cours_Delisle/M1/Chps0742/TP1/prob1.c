#include <stdio.h>
#include <stdlib.h>
#include <glpk.h>									/*fichier d'entete de la bibliotheque GLPK*/
													
int main (void) {
	glp_prob *prob1;								/*pointeur sur un objet probleme*/
	int ia[1+4];									/*indices de lignes de la matrice des contraintes*/
	int ja[1+4];									/*indices de colonnes de la matrice des contraintes*/
	double ar[1+4];									/*valeurs des coefficients de la matrice des contraintes*/
	double z, x1, x2;

	prob1 = glp_create_prob();						/*creation d'un objet probleme*/
	glp_set_prob_name(prob1, "probCours1");			/*definition d'un nom symbolique pour le probleme*/

	glp_set_obj_dir(prob1, GLP_MAX);				/*definition du type d'optimisation, ici maximisation*/
	glp_add_rows(prob1, 2);							/*addition de 2 contraintes au probleme*/
	glp_set_row_name(prob1, 1, "machine1");			/*definition d'un nom symbolique pour la contrainte 1*/
	glp_set_row_bnds(prob1, 1, GLP_UP, 0.0, 6000.0);/*definition du type et des limites de la contrainte 1 :*/
													/*GLP_UP : borne superieure --> contrainte de type <= */
													/*0.0 : valeur de la borne inferieure (ignore ici)*/
													/*6000.0 : valeur de la borne supérieure (bi)*/
	glp_set_row_name(prob1, 2, "machine2");			/*definition d'un nom symbolique pour la contrainte 2*/
	glp_set_row_bnds(prob1, 2, GLP_UP, 0.0, 4000.0);/*definition du type et des limites de la contrainte 2*/

	glp_add_cols(prob1, 2);							/*addition de 2 variables au probleme*/
	glp_set_col_name(prob1, 1, "x1");				/*definition d'un nom symbolique pour la variable x1*/
	glp_set_col_bnds(prob1, 1, GLP_LO, 0.0, 0.0);	/*definition du type et des limites de la variable x1*/
													/*GLP_LO : borne inferieure --> x1 >= 0*/
													/*ici, le premier 0.0 est la borne, le 2e est ignore*/
	glp_set_obj_coef(prob1, 1, 400.0);				/*definition du coefficient de la variable x1 (cj)*/
	
	glp_set_col_name(prob1, 2, "x2");				/*definition d'un nom symbolique pour la variable x2*/
	glp_set_col_bnds(prob1, 2, GLP_LO, 0.0, 0.0);	/*definition du type et des limites de la variable x2*/
	glp_set_obj_coef(prob1, 2, 200.0);				/*definition du coefficient de la variable x2*/

	ia[1] = 1, ja[1] = 1, ar[1] = 30.0;				/*definition des elements non nuls de la matrice des*/		
	ia[2] = 1, ja[2] = 2, ar[2] = 20.0;				/*contraintes (coefficients aij)*/
	ia[3] = 2, ja[3] = 1, ar[3] = 40.0;				/*ia : indices de lignes*/
	ia[4] = 2, ja[4] = 2, ar[4] = 10.0;				/*ja : indices de colonnes*/
													/*ar : coefficients numeriques */
													/*ex : 30x1 de la contrainte 1 :*/
													/*ligne 1, colonne 1, valeur 30.0*/

	glp_load_matrix(prob1, 4, ia, ja, ar);			/*chargement de la matrice des contraintes definie par les
													/*indices de lignes, les indices de colonnes et les*/
													/*valeurs des coefficients. Le parametre 4 signifie qu'il*/
													/*y a 4 valeurs a entrer dans la matrice*/
													
	glp_simplex(prob1, NULL);						/*resolution du probleme par le simplexe. Le 2e parametre*/
													/*permet de definir des options de resolution. Ici on*/
													/*utilise la configuration par defaut*/
													/*Les resultats sont stockes dans l'objet probleme*/

	z = glp_get_obj_val(prob1);						/*Recuperation de la valeur de la fonction objectif*/
	x1 = glp_get_col_prim(prob1, 1);				/*Recuperation de la valeur de la 1ere colonne (x1)*/
	x2 = glp_get_col_prim(prob1, 2);				/*Recuperation de la valeur de la 2e colonne (x2)*/

	printf("\nz = %g; x1 = %g; x2 = %g;\n", z, x1, x2); /*affichage des resultats a l'ecran*/

	glp_delete_prob(prob1);							/*suppression de l'objet probleme*/

	return 0;
}
