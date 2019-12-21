package animalerie2;
import java.lang.Math;
public class Zoo implements IZoo{
	private Animal [] cage;
	private static final int minimum = 10;
	private static final int maximum = 20;
	
	//constructeur par initialisation
	public Zoo(int nbCage){
		if (nbCage<minimum) throw new ArithmeticException("Nombre de cage superieur au maximum !");
		else if (nbCage>maximum) throw new ArithmeticException("Nombre de cage inferieur au minimum !");  
		else cage = new Animal[nbCage];
	}
	//constructeur par defaut
	public Zoo(){
		cage = new Animal[(int)(Math.random()*(maximum*minimum))+minimum];
	}
	//methodes
	/**
	 * Ajoute un animal dans une cage du zoo
	 * @param a l'animal a ajouter
	 * @param i le numero de la cage
	 */
	public void ajouterAnimal(Animal a, int i){
		cage[i]=a;
	}
	/**
	 * Recupere un animal dans une des cages du zoo
	 * @param i le numero de la cage
	 * @return l'animal present dans la cage
	 */
	public Animal getAnimal(int i){
		return cage[i];
	}
	/**
	 * Supprime l'animal situe dans une cage
	 * @param i le numero de la cage
	 */
	public void supprimerAnimal(int i){
		cage[i]=null;
	}
	/**
	 * Fait crier tous les animaux du zoo
	 */
	public void faireCrier(){
		for(int j=0;j<cage.length;j++){
			cage[j].crier();
		}
	}
	/**
	 * Convertit tout le zoo en chaine de caracteres
	 * @return une chaine de caracteres
	 */
	public String toString(){
		String description="";
		for(int j=0;j<cage.length;j++){
			description+=cage[j].toString();
		}
		return description;
	}
}
