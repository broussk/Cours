public class Modele{
    private String modele;

    public Modele(String modele){
        this.modele=modele;
    }

    public String getModele(){return modele;}
    
    public void setModele(String modele){this.modele=modele;}

    public String toString(){
        return "nom : " + getModele();
    }
}
