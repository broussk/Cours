package nathan.constructeur.usines;

import java.util.ArrayList;

public class Usines {
	private String nom;
	private ArrayList<Parking> parkings;
	
	public Usines(String nom) {
		this.nom = nom;
	}
	
	public Usines(String nom, Parking[] p) {
		this.nom = nom;
		this.setParking(p);
	}
	
	public Usines(String nom, ArrayList<Parking> p) {
		this.nom = nom; 
		this.parkings = p;
	}
	
	public String getNom() {
		return nom;
	}
	
	public void setNom(String nom) {
		this.nom = nom;
	}
	
	public ArrayList<Parking> getParking() {
		return parkings;
	}
	
	public void ajouterParking(Parking p) {
		this.parkings.add(p);
	}
	
	public void retirerParking(Parking p) {
		this.parkings.remove(p);
	}
	
	public void setParking(Parking[] p) {
		this.parkings.clear();
		for(int i=0; i<p.length; i++) this.ajouterParking(p[i]);
	}
	
	public void supprimerParkings() {
		this.parkings.clear();
	}
	
	public void detruireUsine() {
		this.nom = null;
		this.supprimerParkings();
	}
	
	public String toString() {
		return (" Nom Usine : " + this.nom + "\n Parkings : " + this.parkings.toString());
	}
	
}
