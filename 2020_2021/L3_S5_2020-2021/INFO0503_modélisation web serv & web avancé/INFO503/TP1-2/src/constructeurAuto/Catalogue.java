package constructeurAuto;

import java.util.ArrayList;

import Voiture.Voiture;

public class Catalogue {
	private static int id = 0;
	private int idCatalogue;
	private Constructeur[] constructeurs;
	private ArrayList<Voiture> voituresList;
	
	public Catalogue(Constructeur[] constructeurs) {
		this.idCatalogue = id;
		Catalogue.id ++;
		this.voituresList = new ArrayList<Voiture>();
		this.constructeurs = constructeurs;
	}
	
	public Catalogue(Constructeur constructeur) {
		this.idCatalogue = id;
		Catalogue.id ++;
		this.voituresList = new ArrayList<Voiture>();
		this.constructeurs = new Constructeur[1];
		this.constructeurs[0] = constructeur;
	}
	
	public Catalogue(Constructeur[] constructeurs, Voiture voiture) {
		this.idCatalogue = id;
		Catalogue.id ++;
		this.voituresList = new ArrayList<Voiture>();
		this.voituresList.add(voiture);
		this.constructeurs = new Constructeur[constructeurs.length];
		for (int i=0; i<constructeurs.length; i++) {
			this.constructeurs[i] = constructeurs[i];
		}
	}
	
	public Catalogue(Constructeur constructeur, Voiture voiture) {
		this.idCatalogue = id;
		Catalogue.id ++;
		this.voituresList = new ArrayList<Voiture>();
		this.voituresList.add(voiture);
		this.constructeurs = new Constructeur[1];
		this.constructeurs[0] = constructeur;
	}
	
	public Catalogue(Constructeur[] constructeurs, Voiture[] voituresTab) {
		this.idCatalogue = id;
		Catalogue.id ++;
		this.voituresList = new ArrayList<Voiture>();
		for(int i=0; i<voituresTab.length; i++) {
			this.voituresList.add(voituresTab[i]);
		}
		this.constructeurs = new Constructeur[constructeurs.length];
		for(int i=0; i<constructeurs.length; i++) {
			this.constructeurs[i] = constructeurs[i];
		}
	}
	
	public Catalogue(Constructeur constructeur, Voiture[] voituresTab) {
		this.idCatalogue = id;
		Catalogue.id ++;
		this.voituresList = new ArrayList<Voiture>();
		for(int i=0; i<voituresTab.length; i++) {
			this.voituresList.add(voituresTab[i]);
		}
		this.constructeurs = new Constructeur[1];
		this.constructeurs[0] = constructeur;
	}
	
	public Catalogue(Constructeur[] constructeurs, ArrayList<Voiture> voituresList) {
		this.idCatalogue = id;
		Catalogue.id ++;
		this.voituresList = new ArrayList<Voiture>();
		this.voituresList = voituresList;
		this.constructeurs = new Constructeur[constructeurs.length];
		for(int i=0; i<constructeurs.length; i++) {
			this.constructeurs[i] = constructeurs[i];
		}
	}
	
	public Catalogue(Constructeur constructeur, ArrayList<Voiture> voituresList) {
		this.idCatalogue = id;
		Catalogue.id ++;
		this.voituresList = new ArrayList<Voiture>();
		this.voituresList = voituresList;
		this.constructeurs = new Constructeur[1];
		this.constructeurs[0] = constructeur;
	}
	
	public ArrayList<Voiture> getVoituresList(){
		return this.voituresList;
	}
	
	public Voiture[] getVoituresListInTabOfVoiture() {
		Voiture[] voitureTab = new Voiture[this.voituresList.size()];
		for(int i=0; i<voitureTab.length; i++) {
			voitureTab[i] = this.voituresList.get(i);
		}
		return voitureTab;
	}
	
	public Constructeur[] getConstructeur() {
		return this.constructeurs;
	}
	
	public int getId() {
		return this.idCatalogue;
	}
	
	public void addVoitureToList(Voiture voit) {
		this.voituresList.add(voit);
	}
	
	public void retirerVoitureToList(Voiture voit) {
		if(!this.voituresList.contains(voit)) return;
		this.voituresList.remove(voit);
	}
	
	public String voitureListToString() {
		String stringVoitureToString = "";
		Voiture[] voituresTab = this.getVoituresListInTabOfVoiture();
		for(int i=0; i<voituresTab.length; i++) {
			stringVoitureToString += voituresTab[i].toString();
		}
		return stringVoitureToString;
	}
	
	public String constructeurTabToString() {
		String stringConstructeurTab = "";
		for(int i=0; i<this.constructeurs.length; i++) {
			stringConstructeurTab += this.constructeurs[i].toString();
		}
		return stringConstructeurTab;
	}

	@Override
	public String toString() {
		return "Catalogue [idCatalogue=" + idCatalogue + ", constructeurs=" + this.constructeurTabToString() + ", voituresList=" + this.voitureListToString() + "]";
	}

	

}