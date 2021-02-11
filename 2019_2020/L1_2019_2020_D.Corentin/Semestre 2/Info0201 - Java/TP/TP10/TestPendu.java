import java.io.File;
import java.util.Scanner;
import pendu.*;

/**
 * Classe de test du pendu.
 * @author Jessica Jonquet modifié par DUPONT Corentin
 * @version 09/04/2020
 */

public class TestPendu {

    /**
     * Attributs de classe
     */
      static Scanner clavier = new Scanner(System.in);
      static String mot = null;
      static Pendu p = null;
      static ListeMots lm = null;
      static boolean addWord = false;

    /**
     * Méthode principale.
     *
     * @param args les arguments
     */
    public static void main(String[] args) throws PenduException {
        char lettre;
        boolean fini = true;
        File file = new File("dicoPendu.txt");

          if(file.canRead()) {
              lm = new ListeMots("dicoPendu.txt");
              System.out.println("Voulez vous :\n1-Tirer un mot alatoire\n2-Entrer un mot vous meme");
              int c1 = clavier.nextInt();
              clavier.nextLine();
              switch(c1){
                  case 1:
                      mot = lm.motAleatoire();
                      System.out.println(mot);
                      p = new Pendu(mot);
                      break;
                  case 2:
                    addWord = true;
                    mot = entrerMot();
                      break;
                  default: System.out.println("Choix inconnu !");
              }
          } else {
              mot = entrerMot();
          }

        do{
            p.afficherEssais();
            System.out.print("\nEntrez une lettre : ");
            lettre = clavier.nextLine().charAt(0);
        }while(p.jouer(lettre) && !p.estFini());
            p.afficherEssais();
          if(p.estFini()){
            if(addWord){
              System.out.println("Gagne !!!!! Le mot " + mot + " a ete ajouter a la liste existante (" +lm.getNomFichier() +")");
              lm.ajouterMot(mot.toUpperCase());
            } else {
              System.out.println("Gagne !!!!!");
            }

          } else{
            System.out.println("Perdu :-(");
            System.out.print("\nLa solution est : "+p.getMot());
        }
    }

    private static String entrerMot(){
      String mot = null;
      System.out.print("Entrer un mot d'au moins 4 lettres: ");
      while(mot == null){
          mot = clavier.nextLine();
          try{
              p = new Pendu(mot);
          }  catch (PenduException ex){
              ex.getMessage();
              mot = null;
              System.out.println("Re-entrer un mot: ");
          }
      }
      return mot;
    }
}
