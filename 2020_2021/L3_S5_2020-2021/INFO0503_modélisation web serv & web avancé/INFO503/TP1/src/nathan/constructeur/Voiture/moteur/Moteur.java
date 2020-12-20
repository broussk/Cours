package nathan.constructeur.Voiture.moteur;

public class Moteur {
	private static int id = 0;
	private int idMoteur;
	private Carburation carburation;
	private int puissance;
	
	public Moteur(Carburation carburation, int puissance) {
		this.idMoteur = id;
		Moteur.id++;
		this.carburation = carburation;
		this.puissance = puissance;
	}
	
	public Moteur(Moteur m) {
		this.idMoteur = id;
		Moteur.id++;
		this.carburation = m.carburation;
		this.puissance = m.puissance;
	}
	
	public int getIdMoteur() {
		return idMoteur;
	}

	public Carburation getCarburation() {
		return carburation;
	}

	public void setCarburation(Carburation carburation) {
		this.carburation = carburation;
	}
	
	public int getPuissance() {
		return puissance;
	}
	
	public void setPuissance(int puissance) {
		this.puissance = puissance;
	}
	
	public String toString() {
		return ("id : " + this.idMoteur + " \n Carburation : " + this.carburation + " \n Puissance : " + this.puissance + " poney");
	}
}
