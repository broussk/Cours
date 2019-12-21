/**
 * Classe <b>Personne</b> repr&eacute;sentant une personne
 * @author Cyril Rabat
 * @version 10/02/2019
 */
package personne;
public class Personne implements IPersonne {

    // Attribut(s)
    
    private String nom;
    private String prenom;
    private int age;

    /**
     * Constructeur par initialisation
     * @param nom le nom de la personne
     * @param prenom le pr&eacute;nom de la personne
     */
    public Personne(String nom, String prenom) {
	this.nom = nom;
	this.prenom = prenom;
    }

    /**
     * Constructeur par initialisation
     * @param nom le nom de la personne
     * @param prenom le pr&eacute;nom de la personne
     * @param age l'&acirc;ge de la personne
     */
    public Personne(String nom, String prenom, int age) {
	this.nom = nom;
	this.prenom = prenom;
	this.age = age;
    }

    /**
     * Retourne le nom de la personne
     * @return le nom de la personne
     */
    public String getNom() {
	return nom;
    }

    /**
     * Retourne le pr&eacute;nom de la personne
     * @return le pr&eacute;nom de la personne
     */
    public String getPrenom() {
	return prenom;
    }

    /**
     * Retourne l'&acirc;ge de la personne
     * @return l'&acirc;ge de la personne
     */
    public int getAge() {
	return age;
    }
    
    /**
     * Affiche une personne &agrave; l'&eacute;cran
     */
    public void afficher() {
	System.out.println(toString());
    }

    /**
     * Retourne une personne sous forme de chaine de caract&egrave;res
     * @return une chaine de caract&egrave;res
     */
    public String toString() {
	String retour = nom + " " + prenom + " (" + age + " an";
	if(age > 1) retour += "s";
	retour += ")";
	return retour;
    }

}
