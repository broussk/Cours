package etoilecraft;
public class Flammeur extends AUniteTerran{
	public Flammeur(double ptVie,double ptArmure,double pTir){
		super(ptVie,ptArmure,pTir,0);
	}
	public Flammeur(){
		super(150,2,90,0);
	}
	/**
     * Indique si l'unite est volante ou non
     * @return vrai si l'unite est volante
     */
	public boolean estVolante(){return false;}
	/**
     * @return chaine de caractere decrivatn l'objet
     */
   	public String toString(){
   		return ("L'unite Flammeur : Point de Vie = "+this.getPointsDeVie()+" Points d'armure = "+this.getPointsArmure()+" Point degat Sol = "+this.getPuissanceTirSol()+" Point degat Air = "+this.getPuissanceTirAir());
   	}
}
