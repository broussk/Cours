package animalerie2;
public class Chat extends AMammifere{
	private String nom;
	private int nbPattes=4;
	private int nbAiles=0;

	//constructeur par initialisation
	public Chat(String n){
		super(n);
	}
	//constructeur par defaut
	public Chat(){
		super();
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
		return ("Chat "+super.toString());
	}
}
