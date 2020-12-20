import java.util.*;

public class GestionnaireUsine{
    private String nomUsine;
    private Parking parking;
    static ArrayList<Voiture> Catalogue = new ArrayList<Voiture>();

    public GestionnaireUsine(){
        nomUsine = "";
        parking = null;
    }
    public GestionnaireUsine(String nomUsine, Parking parking){
        this.nomUsine = nomUsine;
        this.parking = parking;
    }

    public String getNomUsine(){return this.nomUsine;}
    public Parking getParking(){return this.parking;}

    public void setNomUsine(String nomUsine){this.nomUsine = nomUsine;}
    public void setParking(Parking parking){this.parking = parking;}

    public String toString(){
        return "Nom Usine : " + getNomUsine() + "\tparking : " + getParking();
    }

    public void ajouterVoiture(Voiture v){
        Catalogue.add(v);
    }

    public void afficherVoiture(){
        for(int i = 0; i < Catalogue.size(); i++ ){
            System.out.println(Catalogue.get(i).toString());
        }
    }

    public void supprimerVoiture(Voiture v){
        for(int i = 0; i < Catalogue.size(); i++){
            if(Catalogue.contains(v)){
                Catalogue.remove(v);
            }
        }
        afficherVoiture();
    }

    public boolean rechercherVoiture(Voiture v){
        boolean resultat = false;
        for(int i = 0; i < Catalogue.size(); i++){
            if(Catalogue.contains(v)){resultat = true;}
            else{resultat = false;}
        }
        return resultat;
    }
}