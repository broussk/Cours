package animalerie2;
public abstract class AMammifere extends AAnimal{
	public static final int nbPattesDefaut=4;
	//contructeur par initialisation
	public AMammifere(String n){
		super(n, nbPattesDefaut, 0);
	}
	//constructeur par defaut
	public AMammifere(){
		super("Bidule", nbPattesDefaut,0);
	}
	
	//methodes
	/**
	 * Fait crier le mammifere
	 */
	public abstract void crier();
	/**
	 * @return chaine de carctere decrivant le mammifere
	 */
	public String toString(){
		return (nom+", mammifere a "+nbPattes+" patte(s) et "+nbAiles+" aile(s)");
	}
}
