package animalerie2;
public class AOiseau extends AAnimal{
	public static final int nbPattesDefaut=2;
	public static final int nbAilesDefaut=2;

	//contructeur par initialisation
	public AOiseau(String n){
		super(n, nbPattesDefaut, nbAilesDefaut);
	}
	//constructeur par defaut
	public AOiseau(){
		super("Bidule", nbPattesDefaut, nbAilesDefaut);
	}
	//methodes
	/**
	 * Fait crier l'oiseau
	 */
	public abstract void crier();
	/**
	 * @return chaine de carctere decrivant le mammifere
	 */
	public String toString(){
		return (getNom()+", oiseau a "+getNbPattes()+" patte(s) et "+getNnbAiles()+" aile(s)");
	}
}
