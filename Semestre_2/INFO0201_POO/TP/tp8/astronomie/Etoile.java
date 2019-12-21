package astronomie;
public class Etoile extends AAstre implements IEtoile{
	private int age;
	//constructeur
	public Etoile(String n, double m, double d, double vR, int a){
		super(n, m, d, vR);
		age=a;
	}

	//methodes
	/**
     * Retourne l'age de l'etoile
     * @return l'age de l'etoile
     */
    public double getAge(){return age;}

    /**
     * Convertion en chaine de caracteres
     * Exemple d'affichage : Soleil, etoile
     * @return une chaine de caracteres
     */
    public String toString(){
    	return (this.getNom()+", etoile");
	}
}
