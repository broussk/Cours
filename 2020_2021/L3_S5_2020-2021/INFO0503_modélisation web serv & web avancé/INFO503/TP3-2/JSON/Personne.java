/**
 * Classe représentant une personne.
 * @author Cyril Rabat
 */
public class Personne {

    private String nom;
    private String prenom;
    private int age;

    /**
     * Constructeur par initialisation.
     * @param nom le nom de la personne
     * @param prenom le prénom de la personne
     * @param age l'âge de la personne
     */
    public Personne(String nom, String prenom, int age) {
        this.nom = nom;
        this.prenom = prenom;
        this.age = age;
    }

    /**
     * Récupère le nom de la personne.
     * @return le nom de la personne
     */
    public String getNom() {
        return nom;
    }

    /**
     * Récupère le prénom de la personne.
     * @return le prénom de la personne
     */
    public String getPrenom() {
        return prenom;
    }

    /**
     * Récupère l'âge de la personne.
     * @return l'âge de la personne
     */
    public int getAge() {
        return age;
    }

    /**
     * Convertit l'objet courant en chaîne de caractères.
     * @return la chaîne de caractères
     */
    public String toString() {
        return nom + " " + prenom + " (" + age + "an(s))";
    }

}