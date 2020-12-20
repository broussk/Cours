/*import com.sun.net.httpserver.HttpExchange;
import com.sun.net.httpserver.HttpHandler;
import com.sun.net.httpserver.Headers;
import java.io.IOException;
import java.io.UnsupportedEncodingException;
import java.io.OutputStream;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.net.URI;

class LoginHandler implements HttpHandler{

    public void handle(HttpExchange t) {
        String reponse = "<h1>Bienvenue sur la page de connexion</h1>";

        // Récupération des données en GET
        URI requestedUri = t.getRequestURI();
        String query = requestedUri.getRawQuery();
        /*
        reponse += "<p>Données en GET : ";
        if(query == null)
            reponse += "<b>Aucune</b></p>";
        else
            reponse += "<b>" + query + "</b></p>";
*/
        // Utilisation d'un flux pour lire les données du message Http
        /*
        BufferedReader br = null;
        try {
            br = new BufferedReader(new InputStreamReader(t.getRequestBody(),"utf-8"));
            System.out.println(br);
        } catch(UnsupportedEncodingException e) {
            System.err.println("Erreur lors de la récupération du flux " + e);
            System.exit(0);
        }
	
        // Récupération des données en POST
        try {
            query = br.readLine();
        } catch(IOException e) {
            System.err.println("Erreur lors de la lecture d'une ligne " + e);
            System.exit(0);
        }

        //reponse += "<p>Données en POST : ";
        if(query == null)
        reponse += "<form method='POST'action='http://localhost/Projet_1_MEDDOURI_VANSCOOR/ServeurVoiture/FormulaireAjoutVoiture.php'><button>Cliquez ici pour ajouter une voiture</button></form>";
        else
            reponse += "<form method='POST'action='http://localhost/Projet_1_MEDDOURI_VANSCOOR/ServeurVoiture/FormulaireAjoutVoiture.php'><button>Cliquez ici pour ajouter une voiture</button></form>";
            //reponse += "<b>" + query + "</b></p>";

        // Envoi de l'en-tête Http
        try {
            Headers h = t.getResponseHeaders();
            h.set("Content-Type", "text/html; charset=utf-8");
            t.sendResponseHeaders(200, reponse.getBytes().length);
        } catch(IOException e) {
            System.err.println("Erreur lors de l'envoi de l'en-tête : " + e);
            System.exit(0);
        }

        // Envoi du corps (données HTML)
        try {
            OutputStream os = t.getResponseBody();
            os.write(reponse.getBytes());
            os.close();
        } catch(IOException e) {
            System.err.println("Erreur lors de l'envoi du corps : " + e);
        }
    }

}
*/

import com.sun.net.httpserver.HttpExchange;
import com.sun.net.httpserver.HttpHandler;
import com.sun.net.httpserver.Headers;
import java.io.IOException;
import java.io.UnsupportedEncodingException;
import java.io.OutputStream;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.net.URI;

class LoginHandler implements HttpHandler{

    public void handle(HttpExchange t) {
        
        String reponse = "<h1>Bienvenue sur la page de connexion</h1>";
        String URL = "http://localhost:8080/index";
        reponse += "<form method=\"POST\" action="+URL+"><label>Login : </label><input type=\"text\" name=\"login\"><label>Mot de passe : </label><input type=\\\"text\\\" name=\\\"mdp\\\"><button>Valider</button>";
        URI requestedUri = t.getRequestURI();
        String query = requestedUri.getRawQuery();
        BufferedReader br = null;
        try {
            br = new BufferedReader(new InputStreamReader(t.getRequestBody(),"utf-8"));
        } catch(UnsupportedEncodingException e) {
            System.err.println("Erreur lors de la récupération du flux " + e);
            System.exit(0);
        }
	
        try {
            query = br.readLine();
        } catch(IOException e) {
            System.err.println("Erreur lors de la lecture d'une ligne " + e);
            System.exit(0);
        }

        /*reponse += "<p>Données en POST : ";
        if(query == null)
            reponse += "<b>Aucune</b></p>";
        else
            reponse += "<b>" + query + "</b></p>";
		*/
        try {
            Headers h = t.getResponseHeaders();
            h.set("Content-Type", "text/html; charset=utf-8");
            t.sendResponseHeaders(200, reponse.getBytes().length);
        } catch(IOException e) {
            System.err.println("Erreur lors de l'envoi de l'en-tête : " + e);
            System.exit(0);
        }
        
        try {
            OutputStream os = t.getResponseBody();
            os.write(reponse.getBytes());
            os.close();
        } catch(IOException e) {
            System.err.println("Erreur lors de l'envoi du corps : " + e);
        }
    }

}