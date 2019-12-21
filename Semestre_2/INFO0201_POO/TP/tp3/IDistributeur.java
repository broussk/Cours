/**
 * Interface <b>IDistribteur</b> qui doit &ecirc;tre impl&eacute;ment&eacute;e
 * par la classe <b>Distributeur</b>.
 * @author Cyril Rabat
 * @version 23/02/2016
 */
public interface IDistributeur {

    /**
     * Permet de boire un caf&eacute; court.
     * @param montant le montant ins&eacute;r&eacute; par l'utilisateur
     * @return la monnaie rendue
     */
    public double boireCafeCourt(double montant);

   /**
     * Permet de boire un caf&eacute; long.
     * @param montant le montant ins&eacute;r&eacute; par l'utilisateur
     * @return la monnaie rendue
     */
    public double boireCafeLong(double montant);

    /**
     * Ajoute des dosettes dans le distributeur.
     * @param nbDosettes le nombre de dosettes &agrave; ajouter
     */
    public void ajouterDosettes(int nbDosettes);

    /**
     * Rempli le r&eacute;servoir d'eau du distributeur
     * @param quantite la quantit&eacute; d'eau &agrave; ajouter
     */
    public void remplirReservoir(double quantite);

}
