/*
Programme qui permet de determiner si un circuit donne est satisfiable.  Le circuit est code
"a la dure" dans la fonction verifierCircuit.

A la fin du programme, le processeur 0 imprime le nombre total de solutions

Pierre Delisle
*/

#include <stdio.h>
#include <mpi.h>  /*bibliotheque MPI*/

/*Retourne 1 si le ieme bit de n est 1, retourne 0 sinon*/
#define EXTRAIRE_BIT(n,i) ((n&(1<<i))?1:0)


int verifierCircuit(int id, int z) {
/*Verifie si la combinaison entree en parametre satisfait le circuit et l'affiche le cas echeant
Retourne 1 si la combinaison satisfait le circuit, 0 sinon
id : Rang du processeur
z : Entier representant une combinaison sur 16 bits*/

	int v[16];	/*Chaque element est un bit de z*/
	int i;
	int trouve;

	for (i = 0; i < 16; i++)
		v[i] = EXTRAIRE_BIT(z,i);	/*Transformation de l'entier en une chaine de 16 bits*/

	trouve = 0;
	if ((v[0] || v[1]) && (!v[1] || !v[3]) && (v[2] || v[3]) /*Verification du circuit*/
		&& (!v[3] || !v[4]) && (v[4] || !v[5])
		&& (v[5] || !v[6]) && (v[5] || v[6])
		&& (v[6] || !v[15]) && (v[7] || !v[8])
		&& (!v[7] || !v[13]) && (v[8] || v[9])
		&& (v[8] || !v[9]) && (!v[9] || !v[10])
		&& (v[9] || v[11]) && (v[10] || v[11])
		&& (v[12] || v[13]) && (v[13] || !v[14])
		&& (v[14] || v[15])) {

		printf("Combinaison trouvee sur le processeur no. %d : %d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d\n",
				id,v[0],v[1],v[2],v[3],v[4],v[5],v[6],v[7],v[8], v[9],v[10],v[11],v[12],v[13],v[14],v[15]);
		fflush(stdout);
		trouve = 1;
	}
	return trouve;
}

int main(int argc, char *argv[]) {
	int i;
	int id;						/*Rang du Processeur*/
	int p;						/*Nombre de processeurs*/
	int nbSolutions;			/*Nombre de solutions trouvees par un processeur*/
	int nbTotalSolutions;	/*Nombre total de solutions trouvees par les processeurs*/

	MPI_Init(&argc, &argv);						/*Initialisation de l'environnement MPI*/
	MPI_Comm_rank(MPI_COMM_WORLD, &id);		/*Affecte a id le rang du processeur (entre 0 et p-1)*/
	MPI_Comm_size(MPI_COMM_WORLD, &p);		/*Affecte a p le nombre de processeurs*/

	nbSolutions = 0;
	for (i = id; i < 65536; i += p)
		nbSolutions += verifierCircuit(id,i);

	printf("Le processeur %d a trouve %d solutions\n", id, nbSolutions);
	MPI_Reduce(&nbSolutions, &nbTotalSolutions, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

	printf("Le processeur %d a termine son execution\n", id);
	fflush(stdout);
	MPI_Finalize();								/*Libere les ressources utilisees par MPI*/
	if (id == 0)
		printf("Un total de %d combinaisons ont satisfait le circuit\n", nbTotalSolutions);
	return 0;

}

