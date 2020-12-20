public class Modele{

    //attributs
    
    private String modele;
    
    //constructeur

    public Modele(String modele){
        this.modele=modele;
    }
    //méthodes
    public String getModele(){
        return modele;
    }
    public void setModele(String modele){
        this.modele=modele;
    }

    public String toString(){
        return "nom : " + getModele();
    }
}
