package Moteur;

public class Moteur {
	private static int id = 0;
	private int idMoteur;
	private CARBURATION carburation;
	private int puissance;
	
	public Moteur(CARBURATION carburation, int puiss) {
		this.idMoteur = id;
		Moteur.id ++;
		this.carburation = carburation;
		this.puissance = puiss;
	}
	
	public Moteur(Moteur m) {
		this.idMoteur = id;
		Moteur.id ++;
		this.carburation = m.getCarburation();
		this.puissance = m.getPuissance();
	}
	
	public int getIdMoteur() {
		return this.idMoteur;
	}
	
	public CARBURATION getCarburation() {
		return this.carburation;
	}
	
	public int getPuissance() {
		return this.puissance;
	}
	
	public String toString() {
		return ("id : " + this.idMoteur + " ; Carburation : " + this.carburation + " ; Puissance : " + this.puissance + " poneys");
	}
}
