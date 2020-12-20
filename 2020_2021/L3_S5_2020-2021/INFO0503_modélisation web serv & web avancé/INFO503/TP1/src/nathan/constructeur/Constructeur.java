package nathan.constructeur;

import nathan.constructeur.Voiture.Modele;

public class Constructeur {

	private String nom;
	private Modele[] modeles;
	
	public String getNom() {
		return nom;
	}
	public void setNom(String nom) {
		this.nom = nom;
	}
	public Modele[] getModeles() {
		return modeles;
	}
	public void setModeles(Modele[] modeles) {
		this.modeles = modeles;
	}
	
}
