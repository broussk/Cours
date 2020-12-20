package Voiture;

public class Option {
	private String option;
	private boolean contain;
	
	public Option(String nom) {
		this.option = nom;
		this.contain = false;
	}
	
	public Option(String nom, boolean contain) {
		this.option = nom;
		this.contain = contain;
	}
	
	public Option(Option opt) {
		this.option = opt.option;
		this.contain = opt.contain;
	}
	
	public String getNomOption() {
		return this.option;
	}
	
	public boolean getContainOption() {
		return this.contain;
	}
	
	public String toString() {
		return (this.option + " : " + this.contain);
	}
}
