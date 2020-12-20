public class Parking {
	private static int id = 0;
	private int numParking;
	private Place[] places;
	
	public Parking(Place[] places) {
		this.numParking = id;
		Parking.id ++;
		this.places = places;
	}
	
	public Parking(Parking park) {
		this.numParking = id;
		Parking.id ++;
		this.places = new Place[park.places.length];
		for (int i=0; i<park.places.length; i++) {
			this.places[i] = new Place(park.places[i].getRangee(), park.places[i].getNumPlace());
		}
	}

	public int getNumParking() {
		return numParking;
	}

	public Place[] getPlaces() {
		return places;
	}

	public void setPlaces(Place[] places) {
		this.places = places;
	}
	
	public void addPlace(Place place) {
		Place[] pls = new Place[this.places.length +1];
		for(int i=0; i<this.places.length; i++) {
			pls[i] = new Place(this.places[i]);
		}
		pls[pls.length -1] = new Place(place);
		this.places = pls;
	}
	
	public String placesString() {
		String stringListe = "";
			for(int i=0; i<this.places.length; i++) {
				stringListe += this.places[i].toString() + "\n";
			}
		return stringListe;
	}

	@Override
	public String toString() {
		return "Parking [numParking=" + numParking + ", places=" + this.placesString() + "]";
	}
}