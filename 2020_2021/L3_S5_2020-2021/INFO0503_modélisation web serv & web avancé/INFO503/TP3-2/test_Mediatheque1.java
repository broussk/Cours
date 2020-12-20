import javax.swing.JApplet;

import java.io.FileWriter;
import java.io.IOException;

import java.nio.file.Files;
import java.nio.file.Paths;

import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

import mediatheque1.*;
public class test_Mediatheque1 {
    public static void main(String[] args){
        Auteur auteur1 = new Auteur("Cyril RABAT", "18/09/1990");
        Auteur auteur2 = new Auteur("Nathan TONNELLE", "28/11/2000");
        Auteur[] auteurs = {auteur1, auteur2};

        Livre livre1 = new Livre("Licence", auteur1);
        Livre livre2 = new Livre("Licence le retour ! ", auteur2);
        Livre[] livres = {livre1, livre2};

        Mediatheque mediatheque1 = new Mediatheque();

        mediatheque1.ajouterLivre(livre1);
        mediatheque1.ajouterLivre(livre2);

        System.out.println("Livre 1 : " + livre1.toString() + "\nLivre 2 : " + livre2.toString());
        
        JSONObject objet = new JSONObject();

        // Ajout du tableau
        try {
            //objet.put("auteurs", new JSONArray(auteurs));
            //objet.put("livres", new JSONArray(livres));
            objet.put("mediatheque", mediatheque1.toJSON());
        } catch(JSONException e) {
            System.err.println("Erreur lors de l'insertion du tableau.");
            System.err.println(e);
            System.exit(0);
        }

        System.out.println("Format json : " + objet.toString());
        
        // Création du fichier de sortie
        FileWriter fs = null;
        try {
            fs = new FileWriter(args[0]);
        } catch(IOException e) {
            System.err.println("Erreur lors de l'ouverture du fichier '" + args[0] + "'.");
            System.err.println(e);
            System.exit(0);
        }
	
        // Sauvegarde dans le fichier
        try {
            objet.write(fs, 3, 0);
            fs.flush();
        } catch(IOException e) {
            System.err.println("Erreur lors de l'écriture dans le fichier.");
            System.err.println(e);
            System.exit(0);
        }
        
        // Fermeture du fichier
        try {
            fs.close();
        } catch(IOException e) {
            System.err.println("Erreur lors de la fermeture du fichier.");
            System.err.println(e);
            System.exit(0);
        }
        
        System.out.println("Le fichier '" + args[0] + "' a été généré.");

        System.out.println("\n\n\n\tDeserialisation du fichier cree : \n\n");

        // Vérification des arguments
        if(args.length != 1) {
            System.err.println("Erreur : vous devez spécifier le nom du fichier JSON.");
            System.err.println();            
            System.err.println("Usage : java LecteurJSON fichier.json");
            System.err.println("\toù 'fichier.json' est le nom du fichier à ouvrir");
            System.exit(0);
        }
        
        // Récupération de la chaîne JSON depuis le fichier
        String json = "";
        try {
          byte[] contenu = Files.readAllBytes(Paths.get(args[0]));
          json = new String(contenu);        
        } catch(IOException e) {
            System.err.println("Erreur lors de la lecture du fichier '" + args[0] + "'");
            System.exit(0);
        } 
        
        // Création d'un objet JSON
        JSONObject objetRecup = new JSONObject(json);
        System.out.println("Contenu JSON : ");
        System.out.println(json);

        // Affichage à l'écran
        String iS = "";
        JSONObject recupObjects = objetRecup.getJSONObject("mediatheque");
        System.out.println("Mediathèque :");
        for(int i = 0; i < recupObjects.length(); i++) {
            iS = i + "";
            JSONObject elementRecup = recupObjects.getJSONObject(iS);
            System.out.print("\ttitre : " + elementRecup.getString("titre") + "\n\t");
            System.out.print("auteur : \n\t\t");
            JSONObject elementOfelementRecup = elementRecup.getJSONObject("auteur");
            System.out.print("date de naissance : " + elementOfelementRecup.getString("dateNaissance") + "\n\t\t");
            System.out.println("nom : " + elementOfelementRecup.getString("nom"));
        }
    }
}
