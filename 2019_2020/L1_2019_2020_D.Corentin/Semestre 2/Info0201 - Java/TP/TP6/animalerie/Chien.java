package fr.corentin.tp.TP6.animalerie;

/**
 * Classe Chien qui hérite de AMammifere.
 * @author DUPONT Corentin et LACROIX Owen
 * @version 11/03/2020
 */

public class Chien extends AMammifere{

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
    super(nom, 4, 0, 15);
  }


  /**
   * Fait crier le chien
   */
  public void crier(){
    System.out.println("ouaf, ouaf");
  }

  /**
   * Retourne une chaine de caractères décrivant un chien
   * @return la chaine de caractères
   */
  public String toString(){
    return "Chien " + super.toString();
  }
}
