package animalerie2;
public class Abeille extends AInsecte{
	public static final int nbAilesDefaut=4;

	//constructeur par initialisation
	public Abeille(String n){
		super(n, nbAilesDefaut);
	}
	//constructeur par defaut
	public Abeille(){
		super();
	}
	//methodes
	/**
	 * Fait crier l'abeille
	 */
	public void crier(){
		System.out.println("biz,biz");
	}
		
	/**
	*@return chaine de caractere decrivant le chat
	*/
	public String toString(){
		return ("Abeille "+super.toString());
	}
}
