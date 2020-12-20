import com.sun.net.httpserver.HttpExchange;
import com.sun.net.httpserver.HttpHandler;
import com.sun.net.httpserver.Headers;
import java.io.IOException;
import java.io.UnsupportedEncodingException;
import java.io.OutputStream;
import java.io.BufferedReader;
import java.io.File;
import java.io.InputStreamReader;
import java.net.URI;
import java.util.ArrayList;

class IndexHandler implements HttpHandler{

    public void handle(HttpExchange t) {
    	GestionnaireUtilisateurs gu = new GestionnaireUtilisateurs("../src/login.json","../src/metier.json");
    	ArrayList<String> id = gu.getLogin();
    	ArrayList<String> mdp = gu.getMdp();
    	ArrayList<String> metiers = gu.getMetier();
       
    	//String reponse = "<h1>Bienvenue sur la page de connexion</h1>"+ id.get(0);
    	String reponse = "<h1>Bienvenue sur votre page d'accueil</h1>";
    	
        
        // Récupération des données en GET
        URI requestedUri = t.getRequestURI();
        String query = requestedUri.getRawQuery();
        /*
        int compteur = 0;
    	for(String e : id) {
		  	reponse+="	" + gu.log(e,mdp.get(compteur));
		  	compteur++;
		}
		*/
        
        /*
        reponse += "<p>Données en GET : ";
        if(query == null)
            reponse += "<b>Aucune</b></p>";
        else
            reponse += "<b>" + query + "</b></p>";
*/
        // Utilisation d'un flux pour lire les données du message Http
        BufferedReader br = null;
        try {
            br = new BufferedReader(new InputStreamReader(t.getRequestBody(),"utf-8"));
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

        if(query == null)
            reponse += "<b>Aucune</b></p>";
        else {
        	String[] lignes = query.split("&");
        	lignes[1] = lignes[1].replaceAll("%5C%22", "");
        	String[] log = lignes[0].split("=");
        	String[] password = lignes[1].split("=");
        	int compteur2 = 0;
        	String connected = "false";
        	for(String e : id) {
        		if(e.equals(log[1])) {
        			if(mdp.get(compteur2).equals(password[1]))
        				if(gu.log(e,mdp.get(compteur2))==true) {
        					connected = "true";
        					reponse+="<br/> <h2>Pseudo : " + log[1] + " de Profession : " + metiers.get(compteur2)+".<br/>";
                            reponse+="<h2>vous pouvez utiliser votre portail d'accueil.\n";
                            if(metiers.get(compteur2).equalsIgnoreCase("Directeurgenerald'usine")){
                                reponse += "<br><br/>";
                                reponse += "<form method='POST'action='http://localhost/Projet_1_MEDDOURI_VANSCOOR/ServeurVoiture/FormulaireAjoutVoiture.php'><button>Cliquez ici pour ajouter une voiture</button></form>";
                            }
        				}
        		}
        		compteur2++;
        	}
        	if(connected=="false") {
        		reponse+="<h2>Vos identifiants ne correspondent pas ou alors ne sont pas present dans le site.<br/>";
        		String URL = "http://localhost:8080/login" ;
                reponse+="<a href="+URL+">Retourner au formulaire de connexion</a>";
        	}
        }
        
        
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