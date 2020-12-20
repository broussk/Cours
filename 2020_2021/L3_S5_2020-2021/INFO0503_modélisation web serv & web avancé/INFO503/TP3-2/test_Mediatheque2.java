import javax.swing.JApplet;
import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

import mediatheque1.Auteur;

import java.nio.file.Files;
import java.nio.file.Paths;

import java.io.FileWriter;
import java.io.IOException;
import mediatheque2.*;

public class test_Mediatheque2 {
    public static void main(String[] args){
        Mediatheque mediatheque1 = new Mediatheque();

        Personne auteur1 = new Personne("Nathan TONNELLE", "28/11/2000");
        Personne realisateur1 = new Personne("RABAT Cyril", "19/10/1990");

        Livre livre1 = new Livre("Licence 2", auteur1);
        Livre livre2 = new Livre("Licence 3", auteur1);
        Livre livre3 = new Livre("Master 1", auteur1);
        Film film1 = new Film("La terrifiante Licence !", realisateur1, 120);

        mediatheque1.ajouterDocument(livre1);
        mediatheque1.ajouterDocument(livre2);
        mediatheque1.ajouterDocument(film1);
        mediatheque1.ajouterDocument(livre3);

        System.out.println("Mediatheque : " + 
            "\n\tLivre 1 : " + livre1.toString() + 
            "\n\tLivre 2 : " + livre2.toString() + 
            "\n\tLivre 3 : " + livre3.toString() +
            "\n\tFilm 1 : " + film1.toString() + "\n");
        
        JSONObject objet = new JSONObject();
        
        // Ajout du tableau
        try {
            objet.put("mediatheque", mediatheque1.toJSON());
        } catch(JSONException e) {
            System.err.println("Erreur lors de l'insertion du tableau.");
            System.err.println(e);
            System.exit(0);
        }

        System.out.println("Format json : " + objet.toString() + "\n");
        
        // Création du fichier de sortie
        FileWriter fs = null;
        try {
            fs = new FileWriter(args[0]);
        } catch(IOException e) {
            System.err.println("Erreur lors de l'ouverture du fichier '" + args[0] + "'.");
            System.err.println(e);
            System.exit(0);
        }
        catch(ArrayIndexOutOfBoundsException e) {
            System.err.println("Erreur le fichier n'est pas spécifié .");
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
        System.out.println("Contenu JSON : " + json + "\n");

        // Affichage à l'écran
        String iS = "";
        JSONObject recupObjects = objetRecup.getJSONObject("mediatheque");
        System.out.println("Mediathèque :");
        for(int i = 0; i < recupObjects.length(); i++) {
            iS = i + "";
            JSONObject elementRecup = recupObjects.getJSONObject(iS);
            if(elementRecup.has("auteur")){
                System.out.println("\tLivre : ");
                System.out.print("\t\ttitre : " + elementRecup.getString("titre") + "\n\t\t");
                System.out.print("auteur : \n\t\t\t");
                JSONObject elementOfelementRecup = elementRecup.getJSONObject("auteur");
                System.out.print("date de naissance : " + elementOfelementRecup.getString("dateNaissance") + "\n\t\t\t");
                System.out.println("nom : " + elementOfelementRecup.getString("nom"));
            }
            else if(elementRecup.has("realisateur")){
                System.out.println("\tFilm : ");
                System.out.print("\t\ttitre : " + elementRecup.getString("titre") + "\n\t\t");
                System.out.print("\t\tduree : " + elementRecup.getInt("duree") + " min\n\t\t");
                System.out.print("realisateur : \n\t\t\t");
                JSONObject elementOfelementRecup = elementRecup.getJSONObject("realisateur");
                System.out.print("date de naissance : " + elementOfelementRecup.getString("dateNaissance") + "\n\t\t\t");
                System.out.println("nom : " + elementOfelementRecup.getString("nom"));
            }
            
        }
    }
}
