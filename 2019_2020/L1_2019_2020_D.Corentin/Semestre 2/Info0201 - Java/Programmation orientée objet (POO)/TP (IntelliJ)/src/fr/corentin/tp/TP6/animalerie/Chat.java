package fr.corentin.tp.TP6.animalerie;

/**
 * Classe Chat qui hérite de AMammifere.
 * @author DUPONT Corentin et LACROIX Owen
 * @version 11/03/2020
 */

public class Chat extends AMammifere{

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
    super(nom, 4, 0, 14);
  }


  /**
   * Fait crier le chat
   */
  public void crier(){
    System.out.println("miaou, miaou");
  }

  /**
   * Retourne une chaine de caractères décrivant un chat
   * @return la chaine de caractères
   */
  public String toString(){
    return "Chat " + super.toString();
  }
}
