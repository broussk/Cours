import java.util.Scanner;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.OutputStreamWriter;
import java.io.UnsupportedEncodingException;
import java.net.URLConnection;
import java.net.URL;
import java.net.URLEncoder;
import java.net.MalformedURLException;

/**
 * Classe correspondant à un client Http.
 * L'utilisateur doit saisir des données à envoyer puis celles-ci sont envoyées au serveur Http.
 * La réponse du serveur est ensuite affichée.
 * @author Cyril Rabat
 */
public class ClientHttp {

    public static void main(String[] args) {
        Scanner clavier = new Scanner(System.in);
        String listeDonnees = "", titre, donnees;
        int choix;
        
        // Menu pour saisir les données à envoyer en POST
        do {
            System.out.println("1) Pour ajouter des données en POST");
            System.out.println("2) Pour envoyer la requête");
            System.out.print("Votre choix : ");
            choix = clavier.nextInt();clavier.nextLine();
            
            if(choix == 1) {
                System.out.print("Nom du champ : ");
                titre = clavier.nextLine();
                System.out.print("Données      : ");
                donnees = clavier.nextLine();
                if(listeDonnees != "")
                    listeDonnees += "&";
                
                // Encodage des données
                try {
                    listeDonnees += URLEncoder.encode(titre, "UTF-8") + "=" + URLEncoder.encode(donnees, "UTF-8");
                } catch(UnsupportedEncodingException e) {
                    System.err.println("Erreur lors de l'encodage : " + e);
                    System.exit(0);                    
                }
            }            
        } while(choix != 2);
        
        // Mise en forme de l'URL
        URL url = null;
        try { 
            url = new URL("http://localhost:8080/index"); 
        } catch(MalformedURLException e) { 
            System.err.println("URL incorrect : " + e);
            System.exit(0);
        }
        
        // Etablissement de la connexion
        URLConnection connexion = null; 
        try { 
            connexion = url.openConnection(); 
            connexion.setDoOutput(true);
        } catch(IOException e) { 
            System.err.println("Connexion impossible : " + e);
            System.exit(0);
        } 
        
        // Envoi de la requête
        try {
            OutputStreamWriter writer = new OutputStreamWriter(connexion.getOutputStream());
            writer.write(listeDonnees);
            writer.flush();
            writer.close();
        } catch(IOException e) {
            System.err.println("Erreur lors de l'envoi de la requete : " + e);
            System.exit(0);            
        }        
        
        // Réception des données depuis le serveur
        donnees = ""; 
        try { 
            BufferedReader reader = new BufferedReader(new InputStreamReader( connexion.getInputStream())); 
            String tmp; 
            while((tmp = reader.readLine()) != null) 
                donnees += tmp; 
            reader.close(); 
        } catch(Exception e) { 
            System.err.println("Erreur lors de la lecture de la réponse : " + e);
            System.exit(0);
        }
        
        // Affichage des données reçues
        System.out.println("Réponse du serveur : ");
        System.out.println(donnees);
    }
   
}