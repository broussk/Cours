package fr.corentin.tp.TP3.Senseo;

import fr.corentin.tp.TP3.IDistributeur;

/**
 * Classe Senseo qui implémente l'interface IDistributeur.
 * @author DUPONT Corentin et LACROIX Owen
 * @version 06/02/2020
 */

public class Senseo implements IDistributeur {

    /**
     * Attributs de la classe
     */
    private final int capaciteDosette = 1;
    private int nombreDosette;
    private final double reservoirEau = 1.0;
    private double quantiteEau = 1.0;
    private static final double prixLong = 1.30;
    private static final double prixCourt = 0.90;
    public static final double volCafeCourt = 0.10;
    public static final double volCafeLong = 0.25;

    /**
     * Constructeur par initialisation
     * @param nombreDosette nombre de dosette
     */
    public Senseo(int nombreDosette){
        if(nombreDosette > capaciteDosette){
            this.nombreDosette = 1;
        } else {
            this.nombreDosette = nombreDosette;
        }
        this.quantiteEau = reservoirEau;
    }

    /**
     * Constructeur par défaut
     */
    public Senseo(){
        this(1);
    }

    /**
     * Constructeur par copie
     * @param ref Senseo qui sera copié
     */
    public Senseo(Senseo ref){
        this.nombreDosette = ref.nombreDosette;
    }

    /**
     * Retourne le nombre max de dosettes
     * @return capaciteDosette
     */
    public int getcapaciteDosette() {
        return this.capaciteDosette;
    }

    /**
     * Retourne le nombre de dosettes présentent dans la Senseo
     * @return nombreDosette
     */
    public int getNombreDosette() {
        return this.nombreDosette;
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
     * Retourne la qantité d'eau restante dans la Senseo
     * @return quantiteEau
     */
    public double getQuantiteEau() {
        return this.quantiteEau;
    }

    /**
     * Retourne la qantité maximale d'eau de la Senseo
     * @return quantiteEau
     */
    public double getReservoirEau() {
        return this.reservoirEau;
    }

    /**
     * Permet de boire un café court
     * @param montant le montant donné par l'utilisateur
     * @return la monnaie
     */
    public double boireCafeCourt(double montant){
        if (this.quantiteEau >= volCafeCourt && this.nombreDosette == 1){
            this.quantiteEau = this.quantiteEau-10;
            this.nombreDosette--;
            return montant;
        }
        else {
            System.out.println("Pas assez de dosette ou pas assez d'eau !");
            return montant;
        }
    }

    /**
     * Permet de boire un café long
     * @param montant le montant donné par l'utilisateur
     * @return la monnaie
     */
    public double boireCafeLong(double montant){
        if (this.quantiteEau >= volCafeLong && this.nombreDosette == 1){
            this.quantiteEau = this.quantiteEau-25;
            this.nombreDosette--;
            return montant;
        }
        else {
            System.out.println("Pas assez de dosette ou pas assez d'eau !");
            return montant;
        }
    }

    /**
     * Ajoute un nombre de dosettes à la Senseo
     * @param nbDosettes le nombre de dosettes à ajouter
     */
    public void ajouterDosettes(int nbDosettes){
        if(nbDosettes==1 && this.capaciteDosette == 0){
            this.nombreDosette++;
        } else {
            System.out.println("Vous ne povez mettre qu'une dosette a la fois !");
        }
    }

    /**
     * Ajoute une quantité d'eau à la Senseo
     * @param quantite la qantité d'eau à ajouter
     */
    public void remplirReservoir(double quantite){
        if (quantite <= quantite + quantiteEau){
            this.quantiteEau+=quantite;
        } else {
            System.out.println("Vous ne povez mettre plus d'eau que la senseo peut en contenir (1L) !");
        }
    }

    /**
     * Chaîne de caractères décrivant une Senseo
     * @return la description
     */
    public String toString(){
        return "Senseo: " +
                "\n -Dosettes: " + nombreDosette + "/" + capaciteDosette +
                "\n -Reservoir: " + quantiteEau+ "/" + reservoirEau + "L";
    }

    /**
     * Affiche la description de la Senseo
     */
    public void afficher(){
        System.out.println(this.toString());
    }

}
