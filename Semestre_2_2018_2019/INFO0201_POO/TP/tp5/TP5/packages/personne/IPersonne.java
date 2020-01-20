/**
 * L'interface <b>IPersonne</b> est impl&eacute;ment&eacute;e par la classe
 *   <b>Personne</b>
 * @author Cyril Rabat
 * @version 10/02/2019
 */
package personne;
public interface IPersonne {

    /**
     * Retourne le nom de la personne
     * @return le nom de la personne
     */
    public String getNom();

    /**
     * Retourne le pr&eacute;nom de la personne
     * @return le pr&eacute;nom de la personne
     */
    public String getPrenom();

    /**
     * Retourne l'&acirc;ge de la personne
     * @return l'&acirc;ge de la personne
     */
    public int getAge();
    
    /**
     * Affiche une personne &agrave; l'&eacute;cran
     */
    public void afficher();

    /**
     * Retourne une personne sous forme de chaine de caract&egrave;res
     * @return une chaine de caract&egrave;res
     */
    public String toString();

}
