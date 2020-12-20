package nathan.constructeur.usines;

import java.util.ArrayList;


public class Parking {
	private static int id = 0;
	private int idParking;
	private ArrayList<PlaceParking> park;
	private int maxPlaces;
	private int nbPlaceOccupe;
	private int nbPlaceLibre;
	private int nbRangeeMax;
	private int nbNumeroMax;
	
	public Parking(ArrayList<PlaceParking> pp, int nbRangeeMax, int nbNumeroMax) {
		this.idParking = id;
		Parking.id++;
		this.park = pp;
		this.maxPlaces = nbRangeeMax * nbNumeroMax;
		this.nbPlaceLibre = 0;
		this.nbPlaceOccupe = this.maxPlaces;
		this.nbRangeeMax = nbRangeeMax;
		this.nbNumeroMax = nbNumeroMax;
	}
	
	public int getNbRangeeMax() {
		return this.nbRangeeMax;
	}
	
	public int getNbNumeroMax() {
		return this.nbNumeroMax;
	}

	public int getIdParking() {
		return idParking;
	}
	
	public ArrayList<PlaceParking> getPark(){
		return this.park;
	}
	
	public void supprimerPark() {
		this.maxPlaces = 0;
		this.nbRangeeMax = 0;
		this.nbNumeroMax = 0;
		this.nbPlaceLibre = 0;
		this.nbPlaceOccupe = 0;
		this.park.clear();
	}
	
	public int getMaxPlaces() {
		return this.maxPlaces;
	}
	
	public int getNbPlaceOccupe() {
		return this.nbPlaceOccupe;
	}
	
	public int getNbPlaceLibre() {
		return this.nbPlaceLibre;
	}
	
	protected void retirerPlaceLibre() {
		this.nbPlaceLibre --;
	}
	
	protected void ajouterPlaceLibre() {
		this.nbPlaceLibre ++;
	}
	
	protected void retirerPlaceOccupe() {
		this.nbPlaceOccupe -- ;
	}
	
	protected void ajouterPlaceOccupe() {
		this.nbPlaceOccupe ++;
	}
	
	/*public char getRangeeByNumber(int nb) {
		return ((('A' + nb) <= 'Z') && (('A' + nb) >= 'A')) ? (char)('A' + nb) : ('@'); 
	}
	
	public int getNumeroByNumber(int nb) {
		int rep = -1;
		if(nb >= 0 && nb <= this.nbNumeroMax) {
			
		}
		return rep;
	}*/
	
	public void ajouterVoiture(PlaceParking pp) {
		this.park.add(pp);
	}
	
	public boolean rechercherVoiture(PlaceParking p) {
		return this.park.contains(p);
	}
	
	public void deplacerVoiture(PlaceParking p, int emplacement) {
		this.park.set(emplacement, p);
	}
	
	public void supprimerVoiture(PlaceParking p) {
		this.park.remove(p);
	}
	
	public String toString() {
		return (" id : " + this.idParking + "\n nb Place Maximum : " + this.maxPlaces + "\n Places Occupées : " + this.nbPlaceOccupe 
				+ "\n Places Libres : " + this.nbPlaceLibre + "\n nombre Rangées : " + this.nbRangeeMax + "\n nombre de Voiture par Rangées : " + this.nbNumeroMax 
				+ "\n Park : " + this.park.toString());
	}
}
