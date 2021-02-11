package fr.corentin.tp.TP3.Toutou;

/**
 * Classe Toutou.
 * @author DUPONT Corentin et LACROIX Owen
 * @version 06/02/2020
 */
public class Toutou {
  /**
   * Attributs de la classe
   */
  private int puce;
  private String nom;

  /**
   * Constructeur par défaut
   */
  public Toutou() {
    nom = "Meddor";
    puce = 1;
  }

  /**
   * Constructeur par initialistaion
   * @param nom nom du toutou
   * @param puce nombre de puce du Toutou
   */
  public Toutou(String nom, int puce) {
    if (nom == null || nom.equals("")) {
      throw new IllegalArgumentException("Le nom ne doit pas être null ou vide");
    } else {
      this.nom = nom;
    }
    if (puce < 0) {
      throw new IllegalArgumentException("Le nombre de puces ne doit pas être negatif");
    } else {
      this.puce = puce;
    }
  }

  /**
   * Retourne le nom du Toutou
   * @return nom
   */
  public String getNom() {
    return nom;
  }

  /**
   * Retourne le nombre de puce du Toutou
   * @return puce
   */
  public int getPuce() {
    return puce;
  }

  /**
   * Modifie le nombre de puce du Toutou
   * @param p nombre de puce
   */
  public void setPuce(int p) {
    if (p < 0) {
      throw new IllegalArgumentException("Le nombre de puces ne doit pas être negatif");
    } else {
      this.puce = p;
    }
  }

  /**
   * Chaîne de caractères décrivant un Toutou
   * @return la description
   */
  public String toString() {
    return ("Le chien " + nom + " a " + puce + " puce(s)");
  }

  /**
   * Compare si deux Toutou sont égaux
   * @param ref Toutou qui sera comparé
   * @return boolean
   */
  public boolean egalA(Toutou ref) {
    return nom.equals(ref.nom);
  }
}
