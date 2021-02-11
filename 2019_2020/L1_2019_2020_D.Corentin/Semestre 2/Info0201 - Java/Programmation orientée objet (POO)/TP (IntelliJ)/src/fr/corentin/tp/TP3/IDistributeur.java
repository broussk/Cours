package fr.corentin.tp.TP3;

/**
 * Interface <b>IDistribteur</b> qui doit &ecirc;tre impl&eacute;ment&eacute;e * par la classe <b>Distributeur</b>.
 * @author Cyril Rabat
 * @version 23/01/2020
 */
public interface IDistributeur {

	/**
	 * Permet de boire un café court
	 * @param montant le montant donné par l'utilisateur
	 * @return rendu la monnaies
	 */

	public double boireCafeCourt(double montant);

	/**
	 * Permet de boire un café long
	 * @param montant le montant donné par l'utilisateur
	 * @return rendu la monnaies
	 */
	public double boireCafeLong(double montant);

	/**
	 * Ajoute des dosettes dans le distributeur.
	 * @param nbDosettes le nombre de dosettes à ajouter
	 */
	public void ajouterDosettes(int nbDosettes);

	/**
	 * Rempli le réservoir d'eau du distributeur
	 * @param quantite la quantité d'eau à ajouter
	 */
	public void remplirReservoir(double quantite);
}
