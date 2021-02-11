package fr.corentin.tp.TP6.animalerie;

/**
 * Classe AOiseau qui hérite de AAnimal.
 * @author DUPONT Corentin et LACROIX Owen
 * @version 11/03/2020
 */

public abstract class AOiseau extends AAnimal{

  /**
   * Constructeur par défaut
   */
  public AOiseau(){
    super();
  }


  /**
   * Constructeur par initilaistion
   * @param nom le nom de l'oiseau
   * @param nbPattes le nombre de pattes de l'oiseau
   * @param nbAiles le nombre d'ailes de l'oiseau
   * @param esperance esperance de vie de l'oiseau
   */
  public AOiseau (String nom, int nbPattes, int nbAiles, int esperance){
    super(nom, 2, 2, esperance);
  }


  /**
   * Retourne une chaine de caractères décrivant un oiseau
   * @return la chaine de caractères
   */
  public String toString(){
    return getNom() + ", oiseau possèdant " + getNbPattes() + " patte(s) et " + getNbAiles() + " aile(s)";
  }
}
