package fr.corentin.tp.TP6.animalerie;

/**
 * Classe Animal qui implémente l'interface IAnimal.
 * @author DUPONT Corentin et LACROIX Owen
 * @version 21/02/2020
 */

public abstract class AAnimal implements IAnimal {

  /**
   * Attributs de la classe
   */
  private String nom;
  private int nbPattes;
  private int nbAiles;
  private static int age = 0;
  private int esperance;



  /**
   * Constructeur par défaut
   */
  public AAnimal(){
    this("LaBéte", 4, 0, 10);
  }


  /**
   * Constructeur par initialisation
   * @param nom nom de l'animal
   * @param nbPattes nombre de pattes de l'animal
   * @param nbAiles nombre d'ailes de l'animal
   * @param esperance esperance de vie de l'animal
   */
  public AAnimal(String nom, int nbPattes, int nbAiles, int esperance){
    if(nom == null || nom.equals("")){
      System.out.println("Nom invalide !");
    } else {
      this.nom = nom;
    }

     if(nbPattes < 0) {
      System.out.println("Nombre de pattes invalide !");
     } else {
       this.nbPattes = nbPattes;
     }

     if(nbAiles < 0) {
      System.out.println("Nombre d'ailes invalide !");
     } else {
       this.nbAiles = nbAiles;
     }

      if(esperance < 0) {
          System.out.println("esperance de vie invalide !");
      } else {
          this.esperance = esperance;
      }
  }

    /**
     * Récupere l'age de l'animal
     * @return  age
     */

    public int getAge() {
        return age;
    }

    /**
     * Récupere l'esperance de vie de l'animale'
     * @return  esperance
     */

    public int getEsperance() {
        return esperance;
    }

    /**
     * Permet de viellir l'animal de 1 an
     */

    public static void vieillir() {
        age = age + 1;
    }
    /**
   * Retourne le nom de l'animal
   * @return nom
   */
  public String getNom(){return nom;}


  /**
   * Retourne le nombre de pattes de l'animal
   * @return nbPattes
   */
  public int getNbPattes(){return nbPattes;}


  /**
   * Retourne le nombre d'ailes l'animal
   * @return nbAiles
   */
  public int getNbAiles(){return nbAiles;}


  /**
   * Arrache 1 patte d'un animal
   * @param animal l'animal en question
   */
  public void arrachePatte(AAnimal animal) {
      if (animal.getNbPattes() >= 1) {
          animal.nbPattes -= 1;
      animal.crier();
      }
  }


  /**
   * Arrache 1 aile d'un animal
   * @param animal l'animal en question
   */
  public void arracheAiles(AAnimal animal) {
      if (animal.getNbAiles() >= 1) {
          animal.nbAiles -= 1;
      animal.crier();
      }
  }


  /**
   * Fait crier l'animal
   */
  public abstract void crier();


  /**
   * Retourne une chaine de caractères décrivant un animal
   * @return la chaine de caractères
   */
  public String toString(){
    return nom + ", animal à " + nbPattes + " patte(s) et " + nbAiles + " aile(s).";
  }


  /**
   * Affiche la description de l'animal
   */
  public void afficher() {
    System.out.println(this);
  }
}
