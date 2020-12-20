package nathan.constructeur;

import java.util.Date;

import nathan.constructeur.Voiture.Voiture;

public class Commandes{

	private Voiture[] voitures;
	private Date date;
	
	public Voiture[] getVoitures() {
		return voitures;
	}
	public void setVoitures(Voiture[] voitures) {
		this.voitures = voitures;
	}
	public Date getDate() {
		return date;
	}
	public void setDate(Date date) {
		this.date = date;
	}
	
}
