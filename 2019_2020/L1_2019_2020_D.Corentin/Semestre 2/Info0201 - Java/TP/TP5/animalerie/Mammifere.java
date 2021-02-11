package fr.corentin.tp.TP5.animalerie;

/**
 * Classe Mammifere qui hérite de Animal.
 * @author DUPONT Corentin et LACROIX Owen
 * @version 21/02/2020
 */

public class Mammifere extends Animal{

  /**
   * Constructeur par défaut
   */
  public Mammifere(){
    super();
  }

  /**
   * Constructeur par initilaistion
   * @param nom le nom du mammifere
   * @param nbPattes son nombre de pattes qui est ficé à 4.
   */
  public Mammifere (String nom, int nbPattes){
    super(nom, 4);
  }

  /**
   * Retourne une chaine de caractéres décrivant un mammifere
   * @return la chaine de caractére
   */
  public String toString(){
    return getNom() + ", mammifrère à "+ getNbPattes() +" pattes.";
  }
}
