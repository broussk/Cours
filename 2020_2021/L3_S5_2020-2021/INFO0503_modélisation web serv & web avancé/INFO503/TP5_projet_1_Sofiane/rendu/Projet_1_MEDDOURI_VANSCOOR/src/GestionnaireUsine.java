import java.util.*;


public class GestionnaireUsine{
 //attributs
 protected String nomUsine;
 protected Parking parking;
 private int i = 0;
 //constructeur
 public GestionnaireUsine(){
   nomUsine="";
   parking=null;
 }
 public GestionnaireUsine(String nomUsine,Parking parking){
   this.nomUsine=nomUsine;
   this.parking=parking;
 }
 //getter
public String getNomUsine(){
 return this.nomUsine;
 }
public Parking getParking(){
 return this.parking;
}

//setter

public void setNomUsine(String nomUsine){
 this.nomUsine=nomUsine;
}

public void setParking(Parking parking){
 this.parking = parking;
}

// methode toString

public String toString(){
 return "Nom Usine : " + getNomUsine() + "\tparking : " + getParking();
}

List Catalogue = new ArrayList(10);

  // methode ajouterVoiture

  public void ajouterVoiture(Voiture v){
    Catalogue.add(v);
  }
/*
  // methode commmander

  public void commander(Voiture v){
    Commande commande=new Commande(v);
  }
*/
  public void afficherVoiture(){
    for(int i = 0; i < Catalogue.size(); i++ ){
      //System.out.println(voiture[i]);
      System.out.println(Catalogue.get(i));
    }
  }

  public void supprimerVoiture(Voiture v/*,int taille*/){
    /*for(int i = 0; i < taille; i++){
        if(voiture[i] == v){
          voiture[i] = null;
        }
        */
        for(int i = 0; i < Catalogue.size(); i++){
          if(Catalogue.contains(v)){
            Catalogue.remove(v);
          }
        }
    afficherVoiture();
  }

  public boolean rechercherVoiture(Voiture v){
    /*boolean resultat = false;
    for(int i = 0; i < 10; i++){
      if(voiture[i] == v){
         resultat = true;
      }
    }
    return resultat;
    */
    boolean resultat = false;
    for(int i = 0; i < Catalogue.size();i++){
      if(Catalogue.contains(v)){
        resultat = true;
      }else{
        resultat = false;
      }
    }
    return resultat;
  }
}