import java.util.Date;

import Voiture.Voiture;

public class Commande {
	private static int id = 0;
	private int idCommande;
	private Voiture[] voitures;
	private Date dateCommande;
	
	public Commande(Voiture[] voitures) {
		this.idCommande = id;
		Commande.id ++;
		this.voitures = voitures;
		this.dateCommande = new Date();
	}
	
	public Commande(Voiture voiture) {
		this.idCommande = id;
		Commande.id ++;
		this.voitures = new Voiture[1];
		this.voitures[0] = voiture;
		this.dateCommande = new Date();
	}
	
	public Commande() {
		this.idCommande = id;
		Commande.id ++;
		this.voitures = new Voiture[1];
		this.voitures[0] = null;
		this.dateCommande = new Date();
	}
	
	public Voiture[] getVoituresCommande() {
		return this.voitures;
	}
	
	public Date getDateCommande() {
		return this.dateCommande;
	}
	
	public void setVoituresCommande(Voiture[] voitures) {
		this.voitures = new Voiture[voitures.length];
		this.voitures = voitures;
	}
	
	public void setVoituresCommande(Voiture voiture) {
		this.voitures = new Voiture[1];
		this.voitures[0] = voiture;
	}
	
	public void addVoitureCommande(Voiture voiture) {
		Voiture[] addedVoitureTab = new Voiture[this.voitures.length +1];
		for (int i=0; i<this.voitures.length; i++) {
			/*if(this.voitures[i] != null)*/ addedVoitureTab[i] = this.voitures[i];
		}
		addedVoitureTab[addedVoitureTab.length -1] = voiture;
		this.voitures = addedVoitureTab;
	}
	
	public void addVoitureCommande(Voiture[] voitures) {
		Voiture[] addedVoitureTab = new Voiture[this.voitures.length + voitures.length+1];
		int i=0, j=0;
		for (i=0; i<this.voitures.length; i++) {
			addedVoitureTab[i] = this.voitures[i];
		}
		for (i=this.voitures.length; j<voitures.length; i++) {
			addedVoitureTab[i] = voitures[j];
			j++;
		}
		this.voitures = addedVoitureTab;
	}

	public String voituresTabToString() {
		String voituresTabString = "";
		if(this.voitures != null) {
			for(int i=0; i<this.voitures.length; i++) {
				if(this.voitures[i] != null) voituresTabString += this.voitures[i].toString();
			}
		}
		else if(this.voitures[0] == null && this.voitures[1] == null){
			voituresTabString = "aucune voiture";
		}
		
		return voituresTabString;
	}
	
	@Override
	public String toString() {
		return "Commande [idCommande=" + idCommande + " date=" + this.dateCommande.toString() + ", voitures=" + this.voituresTabToString() + "]";
	}
}
