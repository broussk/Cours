package pendu;

import java.io.*;
import java.util.Vector;

/**
 * Classe représentant une liste de mot.
 * @author DUPONT Corentin
 * @version 09/04/2020
 */

public class ListeMots {

    /**
     * Attribut(s) de classe
     */
    private String nomFichier;
    private Vector <String> listeMots;

    /**
     * Constructeur par initailiasation
     * @param nom nom du fichier à partir du quel seront stockés / lu les mots
     */
    public ListeMots(String nom) {
        this.nomFichier = nom;
        listeMots = new Vector<>();
        checkFile();
    }

    /**
     * Regarde si le fichier existe. Si il n'existe pas il le crée
     */
    private void checkFile() {
        File f = new File(nomFichier);
        if (f.exists()) {
              ajoutMotExistant();
        } else{
            try {
                f.createNewFile();
                System.out.println("Le fichier " + nomFichier + " n'existant pas a éré crée !");
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }


    /**
     * Ajoute les mots déjà existant du fichier au vecteur
     */
    private void ajoutMotExistant() {
      String ligne;
      try {
          BufferedReader in = new BufferedReader(new FileReader(nomFichier));
          while ((ligne = in.readLine()) != null) {
              listeMots.add(ligne);
          }
      } catch (IOException e) {
          e.printStackTrace();
      }
    }

    /**
     * Tire un mot aléatoirement parmi les mots contenu dans le vecteur
     * @return un mot tiré aléatoirement
     */
    public String motAleatoire() {
        if (listeMots.size() != 0) {
            return listeMots.get((int)(Math.random() * (listeMots.size())));
        }
        return "Liste de mot vide !";
    }


    /**
     * Regarde si le mot que l'on veut ajouter n'existe déjà pas dans le vecteur et donc dans le fichier
     * @param newWord mot à ajouter
     * @return true si il exite / false si il existe pas
     */
    private boolean checkDoublon(String newWord) {
        for (int i = 0; i < listeMots.size(); i++) {
            if (listeMots.get(i).equals(newWord)) {
                return true;
            }
        }
        return false;
    }


    /**
     * Ajouter un mot au fichier et au vecteur
     * @param mot le mot à ajouter
     */
    public void ajouterMot(String mot) {
        if (!checkDoublon(mot)) {
            listeMots.add(mot);
            try {
                BufferedWriter out = new BufferedWriter(new FileWriter(nomFichier, true));
                out.write(mot);
                out.newLine();
                out.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
        } else {
            System.out.println("Le mot " + mot + " est deja dans la liste !");
        }
    }

    /**
     * Retoune la liste de mot
     * @return listeMots le vecteur de mots
     */
    public Vector <String> getListeMots() {
        return listeMots;
    }

    /**
     * Retoune le nom du fichier
     * @return nomFichier le nom du fichier
     */
    public String getNomFichier() {
        return nomFichier;
    }
}
