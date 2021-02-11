package fr.corentin.tp.TP5.animalerie;

/**
 * Classe Chien qui hérite de Mammifere.
 * @author DUPONT Corentin et LACROIX Owen
 * @version 21/02/2020
 */

public class Chien extends Mammifere{

  /**
   * Constructeur par défaut
   */
  public Chien(){
    super();
  }

  /**
   * Constructeur par initilaistion
   * @param nom le nom du chien
   */
  public Chien(String nom){
    super(nom, 4);
  }


  /**
   * Fait crieer le chien
   */
  public void crier(){
    System.out.println("ouaf, ouaf");
  }

  /**
   * Retourne une chaine de caractéres décrivant un chien
   * @return la chaine de caractére
   */
  public String toString(){
    return "Chien " + getNom() + ", mammifère à "+ getNbPattes() +" pattes.";
  }
}