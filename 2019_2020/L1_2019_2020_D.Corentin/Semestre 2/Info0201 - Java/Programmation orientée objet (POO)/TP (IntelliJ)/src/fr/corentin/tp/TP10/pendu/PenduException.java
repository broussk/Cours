package pendu;

/**
 * Classe traitant l'excep^tion du pendu.
 * @author DUPONT Corentin
 * @version 09/04/2020
 */

public class PenduException extends Exception {

    /**
     * Constructeur par défaut
     **/
    public PenduException(){
        super("Mot invalide !");
    }

    /**
     * Constructeur par initialisation
     * @param motInvalide mot qui déclenche l'exception
     **/
    public PenduException(String motInvalide){
        System.out.println("Mot invalide : " + motInvalide + ". Il doit contenir au moins 4 lettres.");
    }
}
