package animalerie;
import animalerie.Mammifere;
public class Chien{
private String nom;
	private int nbPattes=4;
	
	//constructeur par initialisation
	public Chien(String n){
		nom=n;
	}
	//methodes
	/**
	 * Fait crier le chien
	 */
	public void crier(){
		System.out.println("ouaf, ouaf");
		}
		
	/**
	*@return chaine de caractere decrivant le chien
	*/
	public String toString(){
		return ("Chien "+nom+", mammifere a "+nbPattes+" patte(s)");
	}
}
