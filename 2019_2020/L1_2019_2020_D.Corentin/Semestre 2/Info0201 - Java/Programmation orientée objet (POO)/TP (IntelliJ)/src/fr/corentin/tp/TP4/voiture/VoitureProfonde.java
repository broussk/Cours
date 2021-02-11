package fr.corentin.tp.TP4.voiture;

import fr.corentin.tp.TP4.exceptions.AgeInvalidException;
import fr.corentin.tp.TP4.implement.IVoiture;



public class VoitureProfonde implements IVoiture {

  /**
   * Attributs de la classe
   */
  private Moteur moteur;
  private Reservoir reservoir;
  private Personne conducteur;

  /**
   * Constructeur par initialisation
   * @param moteur le moteur
   * @param reservoir le réservoir
   */
  public VoitureProfonde(Moteur moteur, Reservoir reservoir){
    this.moteur = new Moteur(moteur);
    this.reservoir = new Reservoir(reservoir);
    this.conducteur = null;
  }

  /**
   * Constructeur par copie (copie profonde)
   * @param vs la voiture qui sera copiée
   */
  public VoitureProfonde(VoitureProfonde vs){
    this.moteur = new Moteur(vs.moteur);
    this.reservoir = new Reservoir(vs.reservoir);
    this.conducteur = null;
  }

  /**
   * Retourne le moteur de la voiture
   * @return moteur
   */
  public Moteur getMoteur(){
    return moteur;
  }

  /**
   * Retourne le reservoir de la voiture
   * @return reservoir
   */
  public Reservoir getReservoir(){
    return reservoir;
  }

  /**
   * Retourne le conducteur de la voiture
   * @return conducteur
   */
  public Personne getConducteur(){
    return conducteur;
  }

  /**
   * Retourne le contenue du réservoir de la voiture
   * @return contenu du réservoir
   */
  public double getContenuReservoir(){
    return this.reservoir.getContenu();
  }

  /**
   * Attibut une persoone/conducteur à une voiture
   * @param conducteur une personne
   * @throws AgeInvalidException retourne une exception si l'âge est invalide
   */
  public void setConducteur(Personne conducteur) throws AgeInvalidException {
    if(!(conducteur.getAge() < 18)){
        this.conducteur = conducteur;
    }else {
      throw new AgeInvalidException("Cette personne ne peut pas conduire au vu de son age !");
    }
  }

  /**
   * Fait le plein du réservoir de la voiture
   * @return la quantité ajoutée au réservoire de la voiture
   */
  public double faireLePlein(){
    double qt = this.reservoir.getCapacite() - getContenuReservoir();
    this.reservoir.remplir(qt);
    return qt;
  }

  /**
   * Fait avancer la voiture de la distance spécifié en
   * paramétre et retourne le nombre de kilométres qui ont
   * été effectivement parcourus
   * @param distance la distance parcouru
   * @return le nombre de kilométres parcourus
   */
  public double avancer(double distance){
    double nbKmParcourus = 0;

    if(conducteur != null) {
      if (this.reservoir.getContenu() >= ((this.moteur.getConsommation() * distance) / 100)) {
        this.reservoir.vider((this.moteur.getConsommation() * distance) / 100);
        nbKmParcourus = distance;
      } else {
        this.reservoir.vider(this.reservoir.getContenu());
        nbKmParcourus = this.reservoir.getContenu() * this.moteur.getConsommation();
      }
    } else {
      System.out.println("La voiture ne possede pas de conducteur !");
    }
    return nbKmParcourus;
  }

  /**
   * Retorune une chaine de caractére décrivant une voiture
   * @return la description
   */
  public String toString(){
    return "\n-Moteur : " + moteur.toString()
            + "\n-Reservoir : " + reservoir.toString()
            + "\n-Conducteur : " + conducteur.toString();
  }

  /**
   * Affiche la description de la voiture
   */
  public void afficher(){
    System.out.println(this);
  }
}
