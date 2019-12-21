package etoilecraft;
public class Marine extends AUniteTerran{
	public Marine(double ptVie,double ptArmure,double pTir){
		super(ptVie, ptArmure, pTir,pTir);
	}
	public Marine(){
		super(200,4,10,10);
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
   		return ("L'unite Marine : Point de Vie = "+this.getPointsDeVie()+" Points d'armure = "+this.getPointsArmure()+" Point degat Sol = "+this.getPuissanceTirSol()+" Point degat Air = "+this.getPuissanceTirAir());
   	}
}
