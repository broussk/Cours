package animalerie2;
public class AInsecte extends AAnimal{
	public static final int nbPattesDefaut=6;
	
	//contructeur par initialisation
	public AInsecte(String n, int nbA){
		super(n, nbPattesDefaut, nbA);
	}
	//constructeur par defaut
	public AInsecte(){
		super("Bidule", nbPattesDefaut, 4);
	}
	//methodes
	/**
	 * Fait crier l'insecte
	 */
	public abstract void crier();
	/**
	 * @return chaine de carctere decrivant le mammifere
	 */
	public String toString(){
		return (getNom()+", insecte a "+getNbPattes()+" patte(s) et "+getNnbAiles()+" aile(s)");
	}
}
