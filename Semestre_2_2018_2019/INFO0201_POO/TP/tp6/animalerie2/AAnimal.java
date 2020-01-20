package animalerie2;
public abstract class AAnimal implements IAnimal{
	private String nom;
	private int nbPattes=4;
	private int nbAiles=0;
	
	//contructeur par initialisation
	public AAnimal(String n, int nbP, int nbA){
		nom=n;
		if(nbP>0){nbPattes=nbP;}
		if(nbA>0){nbAiles=nbA;}
	}
	
	//getters
	public String getNom(){return nom;}
	public int getNbPattes(){return nbPattes;}
	public int getNbAiles(){return nbAiles;}
	
	//setters
	public void setNbPattes(int nbP){
		if(nbP>0 && nbP<=nbPattes){nbPattes=nbP;}
	}
	public void setNbAiles(int nbA){
		if(nbA>0 && nbA<=nbPattes){nbPattes=nbA;}
	}
	
	//methodes
	/**
	 * @return chaine de carctere decrivant le mammifere
	 */
	public String toString(){
		return (nom+", animal a "+nbPattes+" patte(s) et "+nbAiles+" aile(s).");
	}
	/**
	 * affiche une chaine de caracteres
	 */
	public void afficher(){
		System.out.println(this.toString());
	}
	/**
	 * Fait crier l'animal
	 */
	public abstract void crier();
}
