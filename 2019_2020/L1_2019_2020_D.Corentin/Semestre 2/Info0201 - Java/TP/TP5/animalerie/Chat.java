package fr.corentin.tp.TP5.animalerie;

/**
 * Classe Chat qui hérite de Mammifere.
 * @author DUPONT Corentin et LACROIX Owen
 * @version 21/02/2020
 */

public class Chat extends Mammifere{

  /**
   * Constructeur par défaut
   */
  public Chat(){
    super();
  }

  /**
   * Constructeur par initilaistion
   * @param nom le nom du chat
   */
  public Chat(String nom){
    super(nom, 4);
  }


  /**
   * Fait crieer le chat
   */
  public void crier(){
    System.out.println("miaou, miaou");
  }

  /**
   * Retourne une chaine de caractéres décrivant un chat
   * @return la chaine de caractére
   */
  public String toString(){
    return "Chat " + getNom() + ", mammifère à "+ getNbPattes() +" pattes.";
  }
}
