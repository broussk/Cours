package nathan.constructeur.usines;

import nathan.constructeur.Voiture.Voiture;

public class PlaceParking {
	private char rangee;
	private int numero;
	private boolean occupee;
	private Voiture voiture;
	
	public PlaceParking(Voiture v, char rangee, int num) {
		this.voiture = v;
		this.rangee = rangee;
		this.numero = num;
		this.occupee = true;
	}
	
	public char getRangee() {
		return rangee;
	}
	
	public void setRangee(char rangee) {
		this.rangee = rangee;
	}
	
	public int getNumero() {
		return numero;
	}
	
	public void setNumero(int numero) {
		this.numero = numero;
	}
	
	public boolean isOccupee() {
		return occupee;
	}
	
	public void setOccupee(boolean occupee) {
		this.occupee = occupee;
	}
	
	public Voiture getVoiture() {
		return this.voiture;
	}
	
	public void setVoiture(Voiture v) {
		this.voiture = v;
	}
	
	public String toString() {
		return ("La voiture : " + this.voiture.toString() + " est à l'emplacement :\n  rangée : " + this.rangee + "\n  numéro : " + this.numero);
	}
	
	public void ajouterVoitureByID(Parking p, int idVoiture, char rangee, int num) {
		p.ajouterVoiture(new PlaceParking(this.getVoiture(), rangee, num));
	}
	
	public void rechercherVoitureByID(Parking p, int idVoiture) {
		
	}
	
	public void deplacerVoitureByID(Parking p, int idVoiture, char rangee, int numero) {
		
	}
	
	public void supprimerVoitureByID(Parking p, int idVoiture) {
		
	}
}
