package animalerie;
/**
* Interface IZoo devant etre implementee par la classe Zoo
* @author Cyril Rabat
* @version 03/03/2011
*/
public interface IZoo {
	/**
	* Ajoute un animal dans une cage du zoo
	* @param a l'animal a ajouter
	* @param i le numero de la cage
	*/
	public void ajouterAnimal(Animal a, int i);
	/**
	* Recupere un animal dans une des cages du zoo
	* @param i le numero de la cage
	* @return l'animal present dans la cage
	*/
	public Animal getAnimal(int i);
	/**
	* Supprime l'animal situe dans une cage
	* @param i le numero de la cage
	*/
	public void supprimerAnimal(int i);
	/**
	* Fait crier tous les animaux du zoo
	*/
	public void faireCrier();
	/**
	* Convertit tout le zoo en chaine de caracteres
	* @return une chaine de caracteres
	*/
	public String toString();
}
