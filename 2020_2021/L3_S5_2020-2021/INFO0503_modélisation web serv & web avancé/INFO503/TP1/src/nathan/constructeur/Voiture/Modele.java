package nathan.constructeur.Voiture;

import java.util.ArrayList;

public class Modele {
	private String nom;
	private ArrayList<Couleur> couleurs;
	
	public Modele(String nom, ArrayList<Couleur> couleurs) {
		this.nom = nom;
		this.couleurs = couleurs;
	}
	
	public Modele(String nom) {
		this.nom = nom;
		this.couleurs.clear();
	}
	
	public String getNom() {
		return nom;
	}
	
	public ArrayList<Couleur> getCouleur() {
		return couleurs;
	}
	
	public void setCouleur(Couleur[] couleurs) {
		this.couleurs.clear();
		for(int i=0; i<couleurs.length; i++) this.ajouterCouleur(couleurs[i]);;
	}
	
	public void ajouterCouleur(Couleur couleur) {
		this.couleurs.add(couleur);		
	}
	
	public void retirerCouleur(Couleur couleur) {
		this.couleurs.remove(couleur);
	}
	
	public void supprimerToutesCouleurs() {
		this.couleurs.clear();
	}
	
	public void supprimerModele() {
		this.nom = null;
		this.supprimerToutesCouleurs();
	}
	
	public String toString() {
		return (" Nom Modèle : " + this.nom + "\n Couleurs : " + this.couleurs.toString());
	}
}
