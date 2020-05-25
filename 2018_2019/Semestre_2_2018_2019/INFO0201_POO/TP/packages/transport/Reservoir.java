/**
 * La classe <b>Reservoir</b> correspond &agrave; un r&eacute;servoir d'un
 *   v&eacute;hicule
 * @author Cyril Rabat
 * @version 10/02/2019
 */
package transport;
public class Reservoir implements IReservoir {

    // Attributs
    
    private double capacite;
    private double contenu;

    /**
     * Construit un r&eacute;servoir de 50L.
     */
    public Reservoir() {
	capacite = 50;
	contenu = 0;
    }


    /**
     * Constructeur par initialisation
     * @param capacite la capacit&eacute; du reservoir
     */
    public Reservoir(double capacite) {
	this.capacite = capacite;
	contenu = 0;
    }

    /**
     * Constructeur par copie
     * @param r le r&eacute;servoir &agrave; recopier
     */
    public Reservoir(Reservoir r) {
	capacite = r.capacite;
	contenu = 0;
    }

    /**
     * Retourne la capacit&eacute; du r&eacute;servoir
     * @return la capacit&eacute;
     */
    public double getCapacite() {
	return capacite;
    }

    /**
     * Retourne le contenu du r&eacute;servoir
     * @return le contenu
     */
    public double getContenu() {
	return contenu;
    }

    /**
     * Remplit le r&eacute;servoir d'une certaine quantit&eacute;
     * @param quantite la quantit&eacute; &agrave; remplir
     */
    public void remplir(double quantite) {
	contenu += quantite;
	if(contenu > capacite)
	    contenu = capacite;
    }

    /**
     * Vide le r&eacute;servoir d'une certaine quantit&eacute;
     * @param quantite la quantit&eacute; &agrave; vider
     */
    public void vider(double quantite) {
	if(contenu > quantite)
	    contenu -= quantite;
	else
	    contenu = 0;
    }

    /**
     * Affiche le r&eacute;servoir &agrave; l'&eacute;cran
     */
    public void afficher() {
	System.out.println(toString());
    }

    /**
     * Retourne un r&eacute;servoir sous forme de chaine de caract&egrave;res
     * @return une chaine de caract&egrave;res
     */
    public String toString() {
	return contenu + "/" + capacite;
    }

}
