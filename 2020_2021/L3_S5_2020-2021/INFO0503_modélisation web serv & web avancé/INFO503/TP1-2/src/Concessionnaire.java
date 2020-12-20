import constructeurAuto.Catalogue;

public class Concessionnaire {
	private String nom;
	private static int id = 0;
	private int idConcessionnaire;
	private Catalogue catalogue;
	
	public Concessionnaire(String nom, Catalogue catalogue) {
		this.idConcessionnaire = id;
		Concessionnaire.id ++;
		this.nom = nom;
		this.catalogue = catalogue;
	}
	
	public Concessionnaire(Catalogue catalogue){
		this.idConcessionnaire = id;
		Concessionnaire.id ++;
		this.nom = "VoitureVendeur";
		this.catalogue = catalogue;
	}

	public String getNom() {
		return nom;
	}

	public void setNom(String nom) {
		this.nom = nom;
	}

	public int getIdConcessionnaire() {
		return idConcessionnaire;
	}
	
	public Catalogue getCatalogue() {
		return this.catalogue;
	}
	
	public void setCatalogue(Catalogue catalogue) {
		this.catalogue = catalogue;
	}

	@Override
	public String toString() {
		return "Concessionnaire [nom=" + nom + ", idConcessionnaire=" + idConcessionnaire + ", catalogue=" + catalogue + "]";
	}
}
