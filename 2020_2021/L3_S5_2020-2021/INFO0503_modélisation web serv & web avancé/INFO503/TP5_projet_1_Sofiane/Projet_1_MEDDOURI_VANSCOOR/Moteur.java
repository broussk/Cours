public class Moteur extends Voiture{
    //Constantes
    static final int PUISSDEF = 110;
  
    //Attributs
    static int id = 0;
  
    protected Carburation carburation;
    protected int puissance;
  
    //Constucteur
    public Moteur(){
    super();
    id++;
    this.id = id;
    carburation = Carburation.DIESEL;
    puissance = PUISSDEF;
    }
  
    public Moteur(Carburation carbu, int puissance){
        id++;
        this.id = id;
        carburation = carbu;
  
        if(puissance<1){
            this.puissance = PUISSDEF;
        }
        else{
            this.puissance = puissance;
        }
    }

    // getter

    public static int getPuissDef(){
        return PUISSDEF;
    }

    public static int getId(){
        return id;
    }

    public Carburation getCarburation(){
        return carburation;
    }

    public int getPuissance(){
        return puissance;
    }

    // setter

    public void setCarburation(Carburation carburation){
        this.carburation = carburation;
    }

    public void setPuissance(int puissance){
        this.puissance = puissance;
    }

    // méthode toString

    public String toString(){
        return " PuissDef : " + getPuissDef() + " id : " + getId() + " carburation : " + getCarburation() + " puissance : " + getPuissance();
    }
}