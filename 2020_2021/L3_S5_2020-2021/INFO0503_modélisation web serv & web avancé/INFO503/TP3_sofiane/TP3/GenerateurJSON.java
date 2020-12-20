import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;
import java.io.FileWriter;
import java.io.IOException;
import mediatheque1.*;

public class GenerateurJSON{
    public static void main(String[] args){

        // Vérification des arguments
        if(args.length != 1) {
            System.err.println("Erreur : vous devez spécifier le nom du fichier JSON.");
            System.err.println();
            System.err.println("Usage : java GenerateurJSON fichier.json");
            System.err.println("\toù 'fichier.json' est le nom du fichier dans lequel sauvegarder");
            System.exit(0);
        }

        // Génération du JSON depuis un tableau d'objets
        Auteur a1 = new Auteur("Eichiro Oda","01/01/1975");
        Auteur a2 = new Auteur("Masashi Kishimoto","08/11/1974");
        Livre l1[] = {
            new Livre("One piece",a1),
            new Livre("Naruto",a2)
        };
        Mediatheque m1[] ={
            new Mediatheque(),
        };
        
        JSONObject objet1 = new JSONObject();
        JSONObject objet2 = new JSONObject();
        // Ajout du tableau
        try{
            objet1.put("contacts",new JSONArray(l1));
            objet2.put("media",new JSONArray(m1));
        }catch(JSONException e){
            System.out.println("Erreur lors de l'insertion du tableau");
            System.out.println(e);
            System.exit(-1);
        }
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
            objet1.write(fs, 3, 0);
            objet2.write(fs, 3, 0);
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
        }
    }