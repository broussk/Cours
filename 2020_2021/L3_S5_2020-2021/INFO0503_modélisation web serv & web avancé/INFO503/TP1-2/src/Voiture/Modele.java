package Voiture;

public class Modele {
	private String nom;
	
	public Modele(String nom) {
		this.nom = nom;
	}
	
	public String getModele() {
		return this.nom;
	}
	
	public String toString() {
		return (this.nom);
	}
}
