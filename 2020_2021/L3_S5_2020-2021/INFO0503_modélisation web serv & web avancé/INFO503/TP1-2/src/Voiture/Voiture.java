package Voiture;

import java.util.Date;

import Moteur.Moteur;

public class Voiture {
	private static int id = 0;
	private int idVoiture;
	private Modele modele;
	private Moteur moteur;
	private Date dateFab;
	private COULEUR couleur;
	private Option[] options;
	
	public Voiture(Modele mod, COULEUR couleur, Moteur mot, Option options[]) {
		this.idVoiture = id;
		Voiture.id ++;
		this.dateFab = new Date();
		this.modele = mod;
		this.couleur = couleur;
		this.moteur = mot;
		this.options = options;
	}
	
	public Voiture(Voiture v) {
		this.idVoiture = id;
		Voiture.id ++;
		this.dateFab = new Date();
		this.modele = v.getModele();
		this.moteur = new Moteur(v.getMoteur());
		this.couleur = v.getCouleur();
		this.options = new Option[v.getOptions().length];
		for(int i=0; i<v.options.length; i++) {
			this.options[i] = new Option(v.getOptions()[i].getNomOption(),v.getOptions()[i].getContainOption());
		}
	}
	
	public int getIdVoiture() {
		return this.idVoiture;
	}
	
	public Modele getModele() {
		return this.modele;
	}
	
	public Moteur getMoteur() {
		return this.moteur;
	}
	
	public Date getDateFab() {
		return this.dateFab;
	}
	
	public COULEUR getCouleur() {
		return this.couleur;
	}
	
	public Option[] getOptions() {
		return this.options;
	}
	
	public String getStringOptions() {
		String s = "";
		for(int i=0; i<this.options.length; i++) {
			s += this.options[i].getNomOption() + ", ";
		}
		return s;
	}
	
	public void setCouleur(COULEUR c) {
		this.couleur = c;
	}
	
	public String toString() {
		return ("Voiture : \n id : " + this.idVoiture + " ;\n Modele : " + this.modele.toString() + " ;\n Couleur : " + this.couleur 
				+ " ;\n Date Fabrication : " + this.dateFab.toString() + " ;\n Moteur : " + this.moteur.toString() 
				+ " ;\n Options : " + this.getStringOptions());
	}
}
