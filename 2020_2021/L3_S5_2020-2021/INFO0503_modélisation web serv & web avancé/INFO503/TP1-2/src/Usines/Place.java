package Usines;

import Voiture.Voiture;

public class Place {
	private char rangee;
	private int num;
	private boolean occupation;
	private Voiture voiture;
	
	
	public Place(char rangee, int num) {
		this.rangee = rangee;
		this.num = num;
		this.occupation = false;
		this.voiture = null;
	}

	public Place(char rangee, int num, Voiture voiture) {
		this.rangee = rangee;
		this.num = num;
		this.voiture = voiture;
		this.occupation = true;
	}
	
	public Place(Place pl) {
		this.rangee = pl.rangee;
		this.num = pl.num;
		this.occupation = pl.occupation;
		this.voiture = pl.voiture;
	}
	
	public char getRangee() {
		return rangee;
	}
	public int getNum() {
		return num;
	}
	public boolean isOccupation() {
		return occupation;
	}
	public Voiture getVoiture() {
		return voiture;
	}
	
	public void setVoiture(Voiture voiture) {
		this.voiture = voiture;
		this.occupation = true;
	}
	
	/*
	public void setOccupation(boolean occupation) {
		this.occupation = occupation;
	}
	*/
	
	public Voiture enleverVoiture() {
		if(!this.occupation) return null;
		Voiture voiture = this.getVoiture();
		this.voiture = null;
		this.occupation = false;
		return voiture;
	}
	
	@Override
	public String toString() {
		return "Place [rangee=" + rangee + ", num=" + num + ", occupation=" + (this.occupation?(this.occupation+ " ; Voiture : " + this.voiture.toString() + "]"):(this.occupation + "]"));
	}
	
}
