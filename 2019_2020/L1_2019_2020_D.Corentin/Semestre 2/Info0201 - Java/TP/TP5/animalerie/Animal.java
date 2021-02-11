package fr.corentin.tp.TP5.animalerie;

/**
 * Classe Animal qui implémente l'interface IAnimal.
 * @author DUPONT Corentin et LACROIX Owen
 * @version 21/02/2020
 */

public class Animal implements IAnimal {

  /**
   * Attributs de la classe
   */
  private String nom;
  private int nbPattes;

  /**
   *COnstructeur par défaut
   */
  public Animal(){
    this("LaBéte", 12);
  }

  /**
   * Constructeur par initialisation
   * @param nom nom de l'animal
   * @param nbPattes nombre de pattes de l'animal
   */
  public Animal(String nom, int nbPattes){
    if(nom == null || nom.equals("")){
      System.out.println("Nom invalide !");
    } else {
      this.nom = nom;
    }

     if(nbPattes < 0) {
      System.out.println("Nombre de pattes invalide !");
     } else {
       this.nbPattes = nbPattes;
     }
  }

  /**
   * Retourne le nom de l'animal
   * @return nom
   */
  public String getNom(){return nom;}

  /**
   * Retourne le nombre de pattes de l'animal
   * @return nbPattes
   */
  public int getNbPattes(){return nbPattes;}

  /**
   * Fait crier l'animal
   */
  public void crier(){
    System.out.println("hum, hum");
  }

  /**
   * Retourne une chaine de caractéres décrivant un animal
   * @return la chaine de caractére
   */
  public String toString(){
    return nom + ", animal à " + nbPattes + " pattes.";
  }

  /**
   * Affiche la description de l'animal
   */
  public void afficher() {
    System.out.println(this);
  }
}
