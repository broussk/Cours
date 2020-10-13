
//question 8
Public class Film extends Media{
    private String realisateur;
    private int annee;

    public Film(String _realisateur, int _annee, StringBuffer cote, int note, String titre){
        super(titre, cote, note);
        this.realisateur = _realisateur;
        this.annee = _annee;
    }

    public Film(){
        super();
        this.realisateur = "Jojo";
        this.annee = 1995;
    }

    public Film(Film f){
        super(f.getTitre(), f.getCote(), f.getNote()); //OU super(f.titre, f.cote, f.getNote())
        this.realisateur = f.realisateur;
        this.annee = f.annee;
    }

    //getteur-setter
    public String getRealisateur(){
        return this.realisateur;
    }
    public int getAnnee(){
        return this.annee;
    }

    public void setRealisateur(String realisateur){
        this.realisateur = realisateur;
    }
    public void setAnnee(int annee){
        this.annee = annee;
    }

    @override 
    public String tpString(){
        return ("Le realisateur : "+ realisateur +", année de réalisation : " + annee + " " + super.toString());
    }

    public boolean equals(Film f){
        return ((f.titre == this.titre) && (f.cote == this.cote) && (f.getNote() == this.getNote()) && (f.realisateur == this.realisateur) && (f.annee == this.annee)); 
    }
    
    public Film clone(){
        return new Film(this);
        //OU return Film(this.realisateur, this.annee, this.cote, this.getNote(), this.titre;
    }
} 

//question 9

public static void main(String[] args){
    Film f1 = new Film();
    Film f2 = new Film("Kubrik", 1969, "Z9T4", 19, "2001");
    
    if(f1.equals(f2)){
        System.out.println("film identiques");
    }
    else{
        System.out.println("film différents");
    }

    Film f3 = f2.clone();
    if(f2.equals(f3)){
        System.out.println("film identiques");
    }
    else{
        System.out.println("film différents");
    }
    System.out.println(f2.toString());
}

//question 10
public class Mediatheque{
    private String nom;
    private Vector<Media> medias;

    public Mediatheque(){
        nom="";
        medias=NULL;
    }

    public Mediatheque (Mediatheque c){
        this.nom = c.nom;
        this.medias = new Vector<Media>(c.medias); //OU this.medias = c.medias.clone();
    }

    public void add(Media m){
        if(m != NULL) this.medias.add(m);
    }

    public String toString(){
        String s = "nom : " + this.nom + " Vector : " + this.medias.toString();
        return s;
    }
}

//question 11
public static void main(String[] args){
    Mediatheque m1 = new Mediatheque();
    Mediatheque m2 = new Mediatheque(m1);
    Media m = new Media();
    m1.add(m);
    m1.toString();
}