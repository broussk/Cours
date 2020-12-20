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

        String absolutePathProject = (new File("IndexHandler.java").getAbsolutePath()).substring(0,new File("IndexHandler.java").getAbsolutePath().lastIndexOf(File.separator));
        absolutePathProject = absolutePathProject.substring(0, absolutePathProject.lastIndexOf('/'));

    	GestionnaireUtilisateurs gestionnaireUtilisateur = new GestionnaireUtilisateurs(absolutePathProject + "/misc/json/login.json", absolutePathProject + "/misc/json/metier.json");
    	ArrayList<String> logins = gestionnaireUtilisateur.getLogin();
    	ArrayList<String> mdp = gestionnaireUtilisateur.getMdp();
    	ArrayList<String> professions = gestionnaireUtilisateur.getProfession();

    	String reponse = "<h1>Bienvenue sur votre page d'accueil</h1>";
        
        // Récupération des données en GET
        URI requestedUri = t.getRequestURI();
        String query = requestedUri.getRawQuery();
        
        // Buffer pour lire les données du message Http
        BufferedReader br = null;
        try {
            br = new BufferedReader(new InputStreamReader(t.getRequestBody(), "utf-8"));
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

        if(query == null){
            reponse += "<b>Aucune</b></p>";
            reponse += "<a href='http://localhost:9876/login'><button>Cliquez ici pour retourner a la page d'accueil</button></a>";
        }
        else {
        	String[] lignes = query.split("&");
        	lignes[1] = lignes[1].replaceAll("%5C%22", "");
        	String[] log = lignes[0].split("=");
        	String[] password = lignes[1].split("=");
        	int compteur = 0;
            String connected = "false";

            reponse = "<h1>Bienvenue sur le Home</h1>";

        	for(String e : logins) {
        		if(e.equals(log[1])) {
                    if(gestionnaireUtilisateur.log(e, password[1])){
                        connected = "true";
                        reponse += "<br/> <h3>Pseudo : </h3>" + log[1] + " <h3>de Profession :</h3> " + professions.get(compteur) + ".<br/>";
                        reponse += "<p>vous pouvez utiliser votre portail d'accueil.</p>\n";
                        if(professions.get(compteur).equalsIgnoreCase("Directeurgenerald'usine")){
                            reponse += "<br><br/>";
                            reponse += "<a href='http://localhost/Projet1/src/php/FormulaireAjoutVoiture.php'><button>Cliquez ici pour ajouter une voiture</button></a><br>";
                            reponse += "<a href='http://localhost/Projet1/src/php/ListeVoitures.php'><button>Cliquez ici pour voir la liste des Voitures</button></a><br>";
                            reponse += "<a href='http://localhost/Projet1/src/php/ListeModeles.php'><button>Cliquez ici pour voir la liste des Modèles</button></a><br>";
                            reponse += "<a href='http://localhost/Projet1/src/php/ListeMoteurs.php'><button>Cliquez ici pour voir la liste des Moteurs</button></a><br>";
                            reponse += "<a href='http://localhost/Projet1/src/php/ListeCouleurs.php'><button>Cliquez ici pour voir la liste des Couleurs</button></a><br>";
                        }
                        reponse += "<a href='http://localhost:9876/login'><button>Deconnexion</button></a><br>";
                    }
        		}
        		compteur++;
        	}
        	if(connected == "false") {
        		reponse += "<h2>Vos identifiants ne correspondent pas ou alors ne sont pas present dans le site.<br/>";
                reponse += "<a href='http://localhost:9876/login'><button>Cliquez ici pour retourner a la page d'accueil</button></a>";
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