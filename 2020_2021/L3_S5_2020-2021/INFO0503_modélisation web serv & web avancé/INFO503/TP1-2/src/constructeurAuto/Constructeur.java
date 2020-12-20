package constructeurAuto;

import Usines.Usine;

public class Constructeur {

	private static int id = 0;
	private int idConstructeur;
	private String nom;
	private Usine[] usines;
	private Stock[] stocks;
	
	public Constructeur(String nom, Usine usine, Stock stock) {
		this.idConstructeur = id;
		Constructeur.id ++;
		this.nom = nom;
		this.usines = new Usine[1];
		this.usines[0] = usine;
		this.stocks = new Stock[1];
		this.stocks[0] = stock;
	}
	
	public Constructeur(String nom, Usine[] usines, Stock stock) {
		this.idConstructeur = id;
		Constructeur.id ++;
		this.nom = nom;
		this.usines = usines;
		this.stocks = new Stock[1];
		this.stocks[0] = stock;
	}
	
	public Constructeur(String nom, Usine usine, Stock[] stocks) {
		this.idConstructeur = id;
		Constructeur.id ++;
		this.nom = nom;
		this.usines = new Usine[1];
		this.usines[0] = usine;
		this.stocks = stocks;
	}
	
	public Constructeur(String nom, Usine[] usines, Stock[] stocks) {
		this.idConstructeur = id;
		Constructeur.id ++;
		this.nom = nom;
		this.usines = usines;
		this.stocks = stocks;
	}
	
	public Constructeur(Constructeur constructeur) {
		this.idConstructeur = id;
		Constructeur.id ++;
		this.nom = constructeur.nom;
		this.usines = constructeur.usines;
		this.stocks = null;
	}

	public String getNom() {
		return nom;
	}

	public void setNom(String nom) {
		this.nom = nom;
	}

	public Usine[] getUsines() {
		return usines;
	}
	
	public void setUsines(Usine usine) {
		this.usines = new Usine[1];
		this.usines[0] = usine;
	}

	public void setUsines(Usine[] usines) {
		this.usines = usines;
	}

	public Stock[] getStocks() {
		return stocks;
	}
	
	public void setStocks(Stock stock) {
		this.stocks = new Stock[1];
		this.stocks[0] = stock;
	}

	public void setStocks(Stock[] stocks) {
		this.stocks = stocks;
	}

	public int getIdConstructeur() {
		return idConstructeur;
	}
	
	public String usinesString() {
		String stringListe = "";
		for(int i=0; i<this.usines.length; i++) {
			stringListe = this.usines[i].toString() + "\n";
		}
		return stringListe;
	}
	
	public String stocksString() {
		String stringListe = "";
		for(int i=0; i<this.stocks.length; i++) {
			stringListe = this.stocks[i].toString() + "\n";
		}
		return stringListe;
	}

	@Override
	public String toString() {
		return "Constructeur [idConstructeur=" + idConstructeur + ", nom=" + nom + ", usines=" + this.usinesString() + ", stocks=" + this.stocksString() + "]";
	}
	
}
