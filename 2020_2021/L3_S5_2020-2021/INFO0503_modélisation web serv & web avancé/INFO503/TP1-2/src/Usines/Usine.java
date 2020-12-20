package Usines;

public class Usine {
	private static int id = 0;
	private int idUsine;
	private String nom;
	private Parking[] parkings;
	
	public Usine(String nom, Parking parking) {
		this.nom = nom;
		this.parkings = new Parking[1];
		Place[] places = new Place[parking.getPlaces().length];
		for(int i=0; i<places.length; i++) {
			places[i] = new Place(parking.getPlaces()[i]);
		}
		this.parkings[0] = new Parking(places);
	}
	
	public Usine(String nom, Parking[] parkings) {
		this.idUsine = id;
		Usine.id ++;
		this.nom = nom;
		this.parkings = parkings;
	}
	
	public Usine(Usine us) {
		this.idUsine = id;
		Usine.id ++;
		this.nom = us.nom;
	}

	public String getNom() {
		return nom;
	}

	public void setNom(String nom) {
		this.nom = nom;
	}

	public Parking[] getParkings() {
		return parkings;
	}

	public void setParkings(Parking[] parkings) {
		this.parkings = parkings;
	}
	
	public void addParkings(Parking park) {
		Parking[] parks = new Parking[this.parkings.length +1];
		for(int i=0; i<this.parkings.length; i++) {
			parks[i] = new Parking(this.parkings[i]);
		}
		parks[parks.length -1] = new Parking(park);
		this.parkings = parks;
	}

	public String parkingString() {
		String stringListe = "";
			for(int i=0; i<this.parkings.length; i++) {
				stringListe += this.parkings[i].toString() + "\n";
			}
		return stringListe;
	}
	
	@Override
	public String toString() {
		return "Usine [idUsine=" + idUsine + ", nom=" + nom + ", parkings=" + this.parkingString() + "]";
	}
}
