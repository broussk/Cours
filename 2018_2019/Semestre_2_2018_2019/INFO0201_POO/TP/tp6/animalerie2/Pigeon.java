package animalerie2;
public class Pigeon extends AOiseau{

	//constructeur par initialisation
	public Pigeon(String n){
		super(n);
	}
	//constructeur par defaut
	public Pigeon(){
		super();
	}
	//methodes
	/**
	 * Fait crier le pigeon
	 */
	public void crier(){
		System.out.println("rou,rou");
	}
		
	/**
	*@return chaine de caractere decrivant le chat
	*/
	public String toString(){
		return ("Pigeon "+super.toString());
	}
}
