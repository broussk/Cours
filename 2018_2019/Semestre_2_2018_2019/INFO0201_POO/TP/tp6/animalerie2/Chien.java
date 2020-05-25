package animalerie2;
public class Chien extends AMammifere{
	private String nom;
	private int nbPattes=4;
	private int nbAiles=0;
	
	//constructeur par initialisation
	public Chien(String n){
		super(n);
	}
	//constructeur par defaut
	public Chien(){
		super();
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
		return ("Chien "+super.toString());
	}
}
