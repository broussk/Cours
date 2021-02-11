package fr.corentin.tp.TP6.animalerie;
/**
 * Classe Abeille qui hérite de AInsecte.
 * @author DUPONT Corentin et LACROIX Owen
 * @version 11/03/2020
 */

public class Abeille extends AInsecte{

  /**
   * Constructeur par défaut
   */
  public Abeille(){
    super();
  }

  /**
   * Constructeur par initilaistion
   * @param nom le nom de l'abeille
   */
  public Abeille(String nom){
    super(nom, 6, 4, 1);
  }


  /**
   * Fait crier l'abeille
   */
  public void crier(){
    System.out.println("bzz, bzz, bzzz");
  }

  /**
   * Retourne une chaine de caractères décrivant une abeille
   * @return la chaine de caractères
   */
  public String toString(){
    return "Abeille " + super.toString();
  }
}
