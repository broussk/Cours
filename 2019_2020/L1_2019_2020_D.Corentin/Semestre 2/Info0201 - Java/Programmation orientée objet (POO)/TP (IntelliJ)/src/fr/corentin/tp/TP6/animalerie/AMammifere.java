package fr.corentin.tp.TP6.animalerie;

/**
 * Classe AMammifere qui hérite de AAnimal.
 * @author DUPONT Corentin et LACROIX Owen
 * @version 11/03/2020
 */

public abstract class AMammifere extends AAnimal{

  /**
   * Constructeur par défaut
   */
  public AMammifere(){
    super();
  }

  /**
   * Constructeur par initilaistion
   * @param nom le nom du mammifere
   * @param nbPattes le nombre de pattes du mammifère
   * @param nbAiles le nombre d'ailes du mammifère
   * @param esperance esperance du mammifère
   */
  public AMammifere (String nom, int nbPattes, int nbAiles, int esperance){
    super(nom, 4, 0, esperance);
  }


  /**
   * Retourne une chaine de caractères décrivant un mammifère
   * @return la chaine de caractères
   */
  public String toString(){
    return getNom() + ", mammifère possèdant " + getNbPattes() + " patte(s) et " + getNbAiles() + " aile(s)";
  }

}
