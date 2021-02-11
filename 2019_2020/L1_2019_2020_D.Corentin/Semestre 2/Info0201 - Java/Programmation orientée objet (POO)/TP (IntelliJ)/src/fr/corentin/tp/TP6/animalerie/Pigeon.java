package fr.corentin.tp.TP6.animalerie;

/**
 * Classe Pigeon qui hérite de AOiseau.
 * @author DUPONT Corentin et LACROIX Owen
 * @version 11/03/2020
 */

public class Pigeon extends AOiseau{

  /**
   * Constructeur par défaut
   */
  public Pigeon(){
    super();
  }

  /**
   * Constructeur par initilaistion
   * @param nom le nom du pigeon
   */
  public Pigeon(String nom){
    super(nom, 2, 2, 6);
  }


  /**
   * Fait crier le pigeon
   */
  public void crier(){
    System.out.println("rourou, rourou");
  }

  /**
   * Retourne une chaine de caractères décrivant un pigeon
   * @return la chaine de caractères
   */
  public String toString(){
    return "Pigeon " + super.toString();
  }
}
