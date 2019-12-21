package astronomie;

/**
 * Interface decrivant le fonctionnement d'une etoile
 * @author Cyril Rabat
 * @version 23/03/2011
 */
public interface IEtoile {

    /**
     * Retourne l'age de l'etoile
     * @return l'age de l'etoile
     */
    public double getAge();

    /**
     * Convertion en chaine de caracteres
     * Exemple d'affichage : Soleil, etoile
     * @return une chaine de caracteres
     */
    public String toString();
}
