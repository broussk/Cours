package fr.corentin.tp.TP6.animalerie;
/**
 * Classe AInsecte qui hérite de AAnimal.
 * @author DUPONT Corentin et LACROIX Owen
 * @version 11/03/2020
 */

public abstract class AInsecte extends AAnimal{

  /**
   * Constructeur par défaut
   */
  public AInsecte(){
    super();
  }


  /**
   * Constructeur par initilaistion
   * @param nom le nom de l'insecte
   * @param nbPattes le nombre de pattes de l'insecte
   * @param nbAiles le nombre d'ailes de l'insecte
   * @param esperance esperance de vie de l'insecte
   */
  public AInsecte (String nom, int nbPattes, int nbAiles, int esperance){
    super(nom, 6, nbAiles, esperance);
  }


  /**
   * Retourne une chaine de caractères décrivant un insecte
   * @return la chaine de caractères
   */
  public String toString(){
    return getNom() + ", insecte possèdant " + getNbPattes() + " patte(s) et " + getNbAiles() + " aile(s)";
  }
}
