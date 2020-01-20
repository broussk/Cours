package etoilecraft;
import java.lang.Math;
public abstract class AUniteTerran implements IUnite{
	private double ptVie;
	private double ptArmure;
	private double pTirSol;
	private double pTirAir;
	
	public AUniteTerran(double ptV,double ptA,double pTS, double pTA){
		ptVie=ptV;
		ptArmure=ptA;
		pTirSol=pTS;
		pTirAir=pTA;
	}
	public AUniteTerran(){
		ptVie=100;
		ptArmure=5;
		pTirSol=5;
		pTirAir=5;
	}
	//methodes
	/**
     * Retourne le nombre de points de vie de l'unite
     * @return le nombre de points de vie
     */
    public double getPointsDeVie(){return ptVie;}

    /**
     * Retourne les points d'armure de l'unite
     * @return les points d'armure
     */
    public double getPointsArmure(){return ptArmure;}

    /**
     * Retourne la puissance de tir au sol de l'unite
     * @return la puissance de tir au sol
     */
    public double getPuissanceTirSol(){return pTirSol;}

    /**
     * Retourne la puissance de tir en l'air de l'unite
     * @return la puissance de tir en l'air
     */
    public double getPuissanceTirAir(){return pTirAir;}
	/**
     * Indique si l'unite est volante ou non
     * @return vrai si l'unite est volante
     */
	public abstract boolean estVolante();
	/**
     * Subit une attaque d'un ennemi
     * @param degats les degats infliges
     * @return vrai si l'unite est tuee, faux sinon
     */
	public boolean subirAttaque(double degats){
		boolean rep=false;
		ptVie=ptVie-(degats/ptArmure);
		if(ptVie<=0) rep=true;
		return rep;
	}
	/**
     * Attaque une unite
     * @param u l'unite a attaquer
     * @return true si l'unite attaquee est tuee
     */
    public boolean attaquer(IUnite u){
    	boolean rep2=false;
    	double attaque;
    	if(u.estVolante()) attaque=Math.random()*pTirAir;
    	else attaque=Math.random()*pTirSol;
    	if(subirAttaque(attaque)) rep2=true;
    	return rep2;
    }

    /**
     * @return chaine de caractere decrivatn l'objet
     */
   	public String toString(){
   		return ("L'unite : Point de Vie = "+ptVie+" Points d'armure = "+ptArmure+" Point degat Sol = "+pTirSol+" Point degat Air = "+pTirAir);
   	}
}
