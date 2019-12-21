package animalerie;
public class Animal{
	private String nom;
	private int nbPattes=0;
	
	//contructeur par initialisation
	public Animal(String n, int nb){
		nom=n;
		if(nb>0){nbPattes=nb;}
	}
	
	//getters
	public String getNom(){return nom;}
	public int getNbPattes(){return nbPattes;}
	
	//setters
	public void setNbPattes(int nb){
		if(nb>1 && nb<=nbPattes){nbPattes=nb;}
	}
	
	//methodes
	/**
	 * @return chaine de carctere decrivant le mammifere
	 */
	public String toString(){
		return (nom+", animal a "+nbPattes+" patte(s)");
	}
	/**
	 * affiche une chaine de caracteres
	 */
	public void afficher(){
		System.out.println(this.toString());
	}
	/**
	 * Fait crier l'animal
	 */
	public void crier(){
		System.out.println("hum, hum");
	}
}
