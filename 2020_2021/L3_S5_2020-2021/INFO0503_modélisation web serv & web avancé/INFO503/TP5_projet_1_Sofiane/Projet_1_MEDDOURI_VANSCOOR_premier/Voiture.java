import java.util.Date;

public class Voiture{
    
    // attributs

    private String numeroIdentification;
    protected Modele modele;
    protected Moteur moteur;
    private Date dateFabrication;
    private Couleur couleur;
    private Options[] options;
   

    // constructeur par défaut

    public Voiture(){
        this.numeroIdentification = "";
        this.modele = null;
        this.moteur = null;
        this.couleur = Couleur.BLEU;
        this.options = null;
        
    }

    // constructeur par initialisation

	public Voiture(String numeroIdentification, Modele modele, Moteur moteur, Date dateFabrication, Couleur couleur,Options options[]){
		this.numeroIdentification = numeroIdentification;
		this.modele = modele;
		this.moteur = moteur;
		this.dateFabrication = dateFabrication;
        this.couleur = couleur;
        this.options = options;
    }
    
    // constructeur par copie

    public Voiture(Voiture v){
        this.numeroIdentification = v.numeroIdentification;
        this.modele = v.modele;
        this.moteur = v.moteur;
        this.dateFabrication = v.dateFabrication;
        this.couleur = v.couleur;
        this.options = v.options;

    }

    // getters

    public String getNumeroIdentification(){
        return this.numeroIdentification;
    }

    public Moteur getMoteur(){
        return this.moteur;
    }

    public Modele getModele(){
        return this.modele;
    }

    public Date getDateFabrication(){
        return this.dateFabrication;
    }

    public Couleur getCouleur(){
        return this.couleur;
    }

    public Options[] getOptions(){
        return this.options;
    }

    public String getStringOptions(){
        String o = "";
        for(int i = 0; i < this.options.length;i++){
            o += this.options[i].getNomOptions() + ", ";
        }
        return o;
    }

    public String toString(){
        return "numeroIdentification : " + getNumeroIdentification() + "\nmoteur :" + getMoteur() + " modele : " + getModele() +  "\ndateFabrication : " + getDateFabrication() + "\ncouleur : " + getCouleur() + "\noptions : " + getStringOptions();
    }





}