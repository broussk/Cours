package nathan.constructeur.Voiture;

import java.util.Date;

import nathan.constructeur.Voiture.moteur.Moteur;

public class Voiture {
	private static int id = 0;
	private int idVoiture;
	private Moteur moteur;
	private Date dateFab;
	private Couleur couleur;
	private String[] options;
	private Modele modele;
	
	public Voiture(Modele mod, Couleur c, Moteur m) {
		this.idVoiture = id;
		Voiture.id++;
		this.dateFab = new Date();
		this.moteur = new Moteur(m);
		this.couleur = c;
		this.options = new String[] {""};
		this.modele = mod;
	}
	
	public Voiture(Modele mod, Couleur c, Moteur m, String options[]) {
		this.idVoiture = id;
		Voiture.id++;
		this.dateFab = new Date();
		this.moteur = new Moteur(m);
		this.couleur = c;
		this.options = options;
		this.modele = mod;
	}
	
	public Voiture(Voiture v) {
		this.idVoiture = id;
		Voiture.id++;
		this.dateFab = new Date();
		this.moteur = new Moteur(v.getMoteur());
		this.couleur = v.getCouleur();
		this.options = v.getOptions();
		this.modele = v.getModele();
	}
	
	public int getIdVoiture() {
		return idVoiture;
	}
	
	public Voiture getVoitureByID(int idVoiture) {
		return null;
	}
	
	public Moteur getMoteur() {
		return moteur;
	}
	
	public void setMoteur(Moteur moteur) {
		this.moteur = moteur;
	}
	
	public Date getDateFab() {
		return dateFab;
	}
	
	public Couleur getCouleur() {
		return couleur;
	}
	
	public void setCouleur(Couleur couleur) {
		this.couleur = couleur;
	}
	
	public String[] getOptions() {
		return options;
	}
	
	public String getOptionsListString() {
		String s = "";
		for(int i=0; i<this.options.length; i++) s += this.options[i] + ", ";
		return s;
	}
	
	public void setOptions(String[] options) {
		this.options = options;
	}
	
	public Modele getModele() {
		return modele;
	}
	
	public String toString() {
		return (" id : " + this.idVoiture + "\n Créé le : " + this.dateFab.toString() + "\n Modèle : " + this.modele.toString() 
		+ "\n Couleur : " + this.couleur + "\n Moteur : " + this.moteur.toString() + "\n Options : " + this.getOptionsListString());
	}
	
}
