package animalerie;
import animalerie.Mammifere;
public class Chat{
private String nom;
	private int nbPattes=4;

	//constructeur par initialisation
	public Chat(String n){
		nom=n;
	}
	//methodes
	/**
	 * Fait crier le chat
	 */
	public void crier(){
		System.out.println("miaou, miaou");
		}
		
	/**
	*@return chaine de caractere decrivant le chat
	*/
	public String toString(){
		return ("Chat "+nom+", mammifere a "+nbPattes+" patte(s)");
		}
}
