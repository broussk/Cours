package fr.corentin.tp.TP3.Kawa;

import fr.corentin.tp.TP3.IDistributeur;

/**
 * Classe Distributeur qui implémente l'interface IDistributeur.
 * @author DUPONT Corentin et LACROIX Owen
 * @version 06/02/2020
 */

public class Distributeur implements IDistributeur {

  /**
   * Attributs de la classe
   */
  private int capaDose;
  private int nbrDose;
  private static double prixLong = 1.30;
  private static double prixCourt = 0.90;
  private double cagnotte;
  private double reservoir;
  private double reservMax;

  /**
   * Constructeur par initialistaion
   * @param capaDose nombre max de dosettes
   * @param reservMax capacité max du réservoir
   */
  public Distributeur(int capaDose, double reservMax) {
    if (capaDose < 0) {
      capaDose = 10;
    } else {
      this.capaDose = capaDose;
    }
    this.nbrDose = capaDose;
    this.cagnotte = 0;
    if (reservMax < 0) {
      reservMax = 2.0;
    } else {
      this.reservMax = reservMax;
    }
    this.reservoir = reservMax;
  }

  /**
   * Constructeur par défaut
   */
  public Distributeur() {
    this(10, 2.0);
  }

  /**
   * Constructeur par copie
   * @param ref Distributeur qui sera copié
   */
  public Distributeur(Distributeur ref) {
    this.capaDose = ref.capaDose;
    this.nbrDose = ref.nbrDose;
    this.cagnotte = 0;
    this.reservoir = ref.reservoir;
    this.reservMax = ref.reservMax;
  }

  /**
   * Retourne le nombre max de dosettes
   * @return capaDose
   */
  public int getCapaDose() {
    return this.capaDose;
  }

  /**
   * Retourne le nombre de dosettes présentent dans le Distributeur
   * @return nbrDose
   */
  public int getNbrDose() {
    return this.nbrDose;
  }

  /**
   * Retourne le prix d'un café long
   * @return prixLong
   */
  public static double getPrixLong() {
    return prixLong;
  }

  /**
   * Retourne le prix d'un café court
   * @return prixCourt
   */
  public static double getPrixCourt() {
    return prixCourt;
  }

  /**
   * Retourne la cagnotte du Distributeur
   * @return cagnotte
   */
  public double getCagnotte() {
    return this.cagnotte;
  }

  /**
   * Retourne la qantité d'eau restante dans le Distributeur
   * @return reservoir
   */
  public double getReservoir() {
    return this.reservoir;
  }

  /**
   * Retourne la qantité maximale du Distributeur
   * @return reservoir
   */
  public double getReservMax() {
    return this.reservMax;
  }

  /**
   * Modifie le prix du café court
   * @param pc nouveau prix
   */
  public static void setPrixCourt(double pc) {
    if (pc > 0) {
      prixCourt = pc;
    }
  }

  /**
   * Modifie le prix du café long
   * @param pl nouveau prix
   */
  public static void setPrixLong(double pl) {
    if (pl > 0) {
      prixLong = pl;
    }
  }

  /**
   * Augmente le prix des deux cafés d'un certain pourcentage
   * @param pourcentage l'augmentation
   */
  public static void augmenter(double pourcentage) {
    double pourcentagecafecourt = (prixCourt * pourcentage) / 100;
    double pourcentagecafelong = (prixLong * pourcentage) / 100;

    prixCourt += pourcentagecafecourt;
    prixLong += pourcentagecafelong;
  }


  /**
   * Ajoute un nombre de dosettes au Distributeur
   * @param nbDosettes le nombre de dosettes à ajouter
   */
  public void ajouterDosettes(int nbDosettes) {
    if (nbDosettes >= 0 && (this.nbrDose + nbDosettes) <= this.capaDose) {
      this.nbrDose += nbDosettes;
    } else {
      System.out.println("Le nombre de dosette est invlide.");
    }
  }

  /**
   * Ajoute une quantité d'eau au Distributeur
   * @param quantite la quatité d'au à ajouter
   */
  public void remplirReservoir(double quantite) {
    if (quantite >= 0 && (this.reservoir + quantite) <= this.reservMax) {
      this.reservoir += quantite;
    } else {
      System.out.println("La quantite d'eau est invalide.");
    }
  }

  /**
   * Permet de boire un café court
   * @param montant le montant donné par l'utilisateur
   * @return la monnaie
   */
  public double boireCafeCourt(double montant) {
    double rendu = 0;
    if (montant >= prixCourt && reservoir >= 0.10 && nbrDose > 0) {
      this.nbrDose--;
      this.reservoir -= 0.10;
      this.cagnotte += this.prixCourt;
      rendu = Math.abs(((cagnotte*100)-(montant*100))/100);
      System.out.println("Transaction reussi ! Attention c'est CHAUD !! ");
      System.out.println("La machine vous as rendu " + rendu + " euros");
      return rendu;
    }
    else {
      System.out.println("Transaction echouer ! ");
      System.out.println("La machine vous as rendu " + montant + " euros");
      return montant;
    }
  }

  /**
   * Permet de boire un café long
   * @param montant le montant donné par l'utilisateur
   * @return la monnaie
   */
  public double boireCafeLong(double montant) {
    double rendu = 0;
    if (montant >= prixLong && reservoir >= 0.25 && nbrDose > 0) {
      this.nbrDose--;
      this.reservoir -= 0.25;
      this.cagnotte += this.prixLong;
      rendu = Math.abs(((cagnotte*100)-(montant*100))/100);
      System.out.println("Transaction reussi ! Attention c'est CHAUD !! ");
      System.out.println("La machine vous as rendu " + rendu + " euros");
      return  rendu;
    }
    else {
      System.out.println("Transaction echouer ! ");
      System.out.println("La machine vous as rendu " + montant + " euros");
      return montant;
    }
  }


  /**
   * Chaîne de caractères décrivant un Distributeur
   * @return la description
   */
  public String toString() {
    return "Distributeur: " +
            "\n -Dosettes: " + this.nbrDose + "/" + this.capaDose +
            "\n -Prix cafe long: " + this.prixLong + " euros" +
            "\n -Prix cafe court: " + this.prixCourt + " euros" +
            "\n -Reservoir: " + this.reservoir + "L/" + this.reservMax + "L" +
            "\n -Cagnotte: " + this.cagnotte + " euros";
  }

  /**
   * Affiche la description du Distributeur
   */
  public void afficher() {
    System.out.println(this);
  }
}
