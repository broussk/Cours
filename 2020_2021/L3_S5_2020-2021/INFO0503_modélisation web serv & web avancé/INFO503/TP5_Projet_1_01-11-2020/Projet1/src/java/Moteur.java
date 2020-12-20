public class Moteur extends Voiture{
    static final int PUISSDEF = 50;
    static int id = 0;
    private Carburation carburation;
    private int puissance;
    private int idMoteur;
  
    public Moteur(){
        super();
        Moteur.id++;
        this.idMoteur = Moteur.id;
        carburation = Carburation.DIESEL;
        puissance = PUISSDEF;
    }
    public Moteur(Carburation carbu, int puissance){
        Moteur.id++;
        this.idMoteur = Moteur.id;
        carburation = carbu;
  
        if(puissance<1){this.puissance = PUISSDEF;}
        else{this.puissance = puissance;}
    }

    public static int getPuissDef(){return PUISSDEF;}
    public static int getId(){return Moteur.id;}
    public int getIdMoteur(){return this.idMoteur;}
    public Carburation getCarburation(){return this.carburation;}
    public int getPuissance(){return this.puissance;}

    public void setCarburation(Carburation carburation){this.carburation = carburation;}
    public void setPuissance(int puissance){this.puissance = puissance;}

    public String toString(){
        return " PuissDef : " + getPuissDef() + " id : " + getId() + " carburation : " + getCarburation() + " puissance : " + getPuissance();
    }
}