package etoilecraft;
public class Cuirrasse extends AUniteTerran{
	public Cuirrasse(double ptVie,double ptArmure,double pTirSol, double pTirAir){
		super(ptVie,ptArmure,pTirSol,pTirAir);
	}
	public Cuirrasse(){
		super(400,6,80,60);
	}
	/**
     * Indique si l'unite est volante ou non
     * @return vrai si l'unite est volante
     */
	public boolean estVolante(){return true;}
	/**
     * @return chaine de caractere decrivatn l'objet
     */
   	public String toString(){
   		return ("L'unite Cuirrasse : Point de Vie = "+this.getPointsDeVie()+" Points d'armure = "+this.getPointsArmure()+" Point degat Sol = "+this.getPuissanceTirSol()+" Point degat Air = "+this.getPuissanceTirAir());
   	}
}
