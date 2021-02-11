import java.util.Scanner;
import pendu.*;

/**
 * Classe de test de liste de mots.
 * @author DUPONT Corentin
 * @version 09/04/2020
 */

public class TestListeMots {

    /**
     * Attirbus(s) de classe
     */
    static Scanner sc = new Scanner(System.in);

    /**
     * Méthode principale.
     *
     * @param args les arguments
     */
    public static void main(String [] args){

        System.out.println("Entrer un nom de fichier: ");
        String nomFichier = sc.nextLine();
        boolean quit = false;
        ListeMots lm = new ListeMots(nomFichier);

        while(!quit){
            System.out.print("\n");
            System.out.println("1-Ajouter un mot \n2-Afficher le contenu du fichier\n3-Tiré un mot aleatoirement\n4-Quitter");
            int choix = sc.nextInt();
            switch(choix){
                case 1:
                    System.out.println("Entrer un mot:");
                    sc.nextLine();
                    String mot = sc.nextLine().toUpperCase();
                    lm.ajouterMot(mot);
                  break;
                case 2:
                    //liste les mots présent dans le fichier
                    System.out.println("Le fichier " + lm.getNomFichier()+ " contient :");
                    for (int i = 0; i< lm.getListeMots().size(); i++){
                        System.out.println(" - " + lm.getListeMots().get(i));
                    }
                    break;
                case 3:
                    //Test de la méthode motAléatoire
                    System.out.println("Mot tire aleatoirement: " + lm.motAleatoire());
                    break;
                case 4: quit = true;
                    break;
                default: System.out.println("Choix inconnu");
            }
        }
    }
}
