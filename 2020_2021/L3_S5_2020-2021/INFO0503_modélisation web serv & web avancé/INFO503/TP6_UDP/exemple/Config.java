import java.util.Scanner;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;

import org.json.JSONException;
import org.json.JSONObject;

/**
 * Classe permettant de créer/gérer un fichier de configuration.
 * @author Cyril Rabat
 */
public class Config {

    private String nomFichier;      // Nom du fichier de configuration
    private JSONObject config;      // La configuration 

    /**
     * Ouverture d'un fichier de configuration.
     * @param nomFichier le nom du fichier de configuration
     */
    public Config(String nomFichier) {
        this.nomFichier = nomFichier;
        charger();
    }

    /**
     * Ouverture/création d'un fichier de configuration.
     * @param nomFichier le nom du fichier de configuration
     * @param creation si 'true', crée un nouveau fichier vide
     */
    public Config(String nomFichier, boolean creation) {
        if(!creation) {
            this.nomFichier = nomFichier;
            charger();
        }
        else {
            this.nomFichier = nomFichier;
            config = new JSONObject();
        }
    }

    /**
    * Indique si un fichier existe.
    * @param nomFichier le nom du fichier
    * @return 'true' s'il existe
    */
    public static boolean fichierExiste(String nomFichier) {
        File f = new File(nomFichier);
        return f.exists();       
    }

    /**
    * Retourne la valeur associée à une clef.
    * @param clef le nom de la clef
    * @return la valeur de la clef
    */
    public String getString(String clef) {
        /**
        * #TODO#
        * Récupère la donnée dont la clef est spécifiée dans l'objet
        * JSON (attribut 'config').
        */
        return this.config.getString(clef);       
    }

    /**
    * Retourne la valeur associée à une clef.
    * @param clef le nom de la clef
    * @return la valeur de la clef
    */
    public int getInt(String clef) {
        /**
        * #TODO#
        * Récupère la donnée dont la clef est spécifiée dans l'objet
        * JSON (attribut 'config').
        */
        return this.config.getInt(clef);
    }

    /**
    * Ajoute une valeur de type entier dans la configuration.
    * @param clef le nom de la clef
    * @param valeur la valeur de la clef
    */
    public void ajouterValeur(String clef, int valeur) {
        /**
        * #TODO#
        * Ajouter les données dans l'objet JSON (attribut 'config')
        */
        this.config.put(clef, valeur);
    }

    /**
    * Ajoute une valeur de type chaîne de caractères dans la configuration.
    * @param clef le nom de la clef
    * @param valeur la valeur de la clef
    */
    public void ajouterValeur(String clef, String valeur) {
        /**
        * #TODO#
        * Ajouter les données dans l'objet JSON (attribut 'config')
        */
        this.config.put(clef, valeur);
    }

    /**
    * Charge un fichier de configuration en mémoire.
    */
    private void charger() {
        // Ouverture du fichier

        /**
        * #TODO#
        * Charger le fichier JSON dont le nom correspond à l'attribut
        * 'nomFichier' dans l'attribut 'config' (un objet JSONObject).
        */
        this.config = new JSONObject();
        try {
            File f = new File(this.nomFichier);
            Scanner sc = new Scanner(f);
            System.out.println("charger : " + this.nomFichier);

            while (sc.hasNext()) {
                String line = sc.nextLine();
                String[] lignes = line.split(",");

                lignes[0] = lignes[0].replaceAll(" ", "").replaceAll("\"", "").replaceAll(",", "");
                int port = Integer.parseInt(lignes[0].split(":")[1]);
                System.out.println("port : " + port);
                this.ajouterValeur("port", port);

                lignes[1] = lignes[1].replaceAll(" ", "").replaceAll("\"", "").replaceAll(",", "").replaceAll("}", "");
                String adresse = lignes[1].split(":")[1];
                System.out.println("adresse : " + adresse);
                this.ajouterValeur("adresse", adresse);
            }
            sc.close();
        } catch (FileNotFoundException e) {
            System.out.println("Echec de l'ouverture et de la récupération des données des fichiers.\n");
            e.printStackTrace();
        }
    }

    /**
    * Sauvegarde la configuration dans le fichier.
    */
    public void sauvegarder() {
        // Création du fichier de sortie

        /**
        * #TODO#
        * Sauvegarder le fichier JSON dans le fichier dont le nom
        * correspond à l'attribut 'nomFichier'.
        */

        // Création du fichier voiture.json
        FileWriter fs = null;
        try {
            fs = new FileWriter(this.nomFichier);
            System.out.println("Récupération du fichier\n");
        } catch(IOException e) {
            System.err.println("Erreur lors de l'ouverture du fichier '" + this.nomFichier + "'.");
            System.err.println(e);
            System.exit(0);
        }

        // Ecriture du fichier
        try {
        this.config.write(fs);
            fs.flush();
            System.out.println("Ecriture du fichier\n");
        } catch(IOException e) {
            System.err.println("Erreur lors de l'écriture dans le fichier.");
            System.err.println(e);
            System.exit(0);
        }

        // Fermeture du fichier
        try {
            fs.close();
            System.out.println("Fermeture du fichier\n");
        } catch(IOException e) {
            System.err.println("Erreur lors de la fermeture du fichier.");
            System.err.println(e);
            System.exit(0);
        }
    }
}