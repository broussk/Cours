package animalerie;
import animalerie.Animal;
public class Mammifere{
	private String nom;
	private int nbPattes=4;
	
	//contructeur par initialisation
	public Mammifere(String n){
		nom=n;
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
	 * Fait crier le chat
	 */
	public void crier(){
		System.out.println("hum, hum");
		}
	/**
	 * @return chaine de carctere decrivant le mammifere
	 */
	public String toString(){
		return (nom+", mammifere a "+nbPattes+" patte(s)");
	}
/**
	 * affiche une chaine de caracteres
	 */
	public void afficher(){
		System.out.println(this.toString());
	}
}
