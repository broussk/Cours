import java.io.BufferedReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.UnsupportedEncodingException;
import java.net.URI;
import java.net.URLDecoder;
import java.util.ArrayList;
import java.util.Date;

import com.sun.net.httpserver.Headers;
import com.sun.net.httpserver.HttpExchange;
import com.sun.net.httpserver.HttpHandler;

import org.json.*;

class AjoutVoitureHandler implements HttpHandler{

    @Deprecated
    public void handle(HttpExchange t) {
        String reponse = "<h1>Bienvenue sur la page de connexion</h1>";
        
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
        }
        else{
            reponse += "<b>" + "La voiture a bien été crée" + "</b></p>";
            reponse += "<a href='http://localhost:9876/login'><button>Cliquez ici pour retourner a la page d'accueil</button></a>";

            try {
                //génération de tout les objets lié au formulaire pour la création du json
                query = URLDecoder.decode(query, "UTF-8");

                String[] decoupQuery = query.split("&");

                String[] decoupQuery_2 = decoupQuery[2].split("=");

                String[] decoupQuery_2_1_Moteur = decoupQuery_2[1].split(",");

                String puissanceString = decoupQuery_2_1_Moteur[3];
                String carburationString = decoupQuery_2_1_Moteur[2];
                Moteur moteur = new Moteur(carburationMoteurByQuery(carburationString), puissanceMoteurByQuery(puissanceString));
                System.out.println("Création moteur ... Terminé \n");

                String nomModele = decoupQuery[1].split("=")[1];
                Modele modele = new Modele(nomModele);
                System.out.println("Création modele ... Terminé \n");

                String[] decoupDateFabrication = decoupQuery[3].split("=")[1].split("-");
                int annee = pieceOfDate(decoupDateFabrication[0]);
                int mois = pieceOfDate(decoupDateFabrication[1]);
                int jour = pieceOfDate(decoupDateFabrication[2]);
                Date dateFabriation = new Date(annee, mois, jour);
                System.out.println("Création date de Fabrication ... Terminé \n");

                String couleurString = decoupQuery[4].split("=")[1];
                Couleur couleur = couleurByQuery(couleurString);
                System.out.println("Création Couleur ... Terminé \n");

                Options[] options = optionsByQuery(query);
                System.out.println("Création Options ... Terminé \n");

                String numeroIdentification = decoupQuery[0].split("=")[1];
                System.out.println("Création numéro d'Identification ... Terminé \n");
                
                Voiture voiture = new Voiture(numeroIdentification, modele, moteur, dateFabriation, couleur, options);
                System.out.println("Création Voiture ... Terminé \n");

                ArrayList<Voiture> catalogue = new ArrayList<Voiture>();
                catalogue.add(voiture);

                Place placeA1 = new Place('A', 1);
                Place placeA2 = new Place('A', 2);
                Place placeA3 = new Place('A', 3);
                Place placeA4 = new Place('A', 4);
                Place placeA5 = new Place('A', 5);
                Place placeB1 = new Place('B', 1);
                Place placeB2 = new Place('B', 2);
                Place placeB3 = new Place('B', 3);
                Place placeB4 = new Place('B', 4);
                Place placeB5 = new Place('B', 5);
                Place[] placesRangeeAB = new Place[] {placeA1, placeA2, placeA3, placeA4, placeA5, placeB1, placeB2, placeB3, placeB4, placeB5};
                Parking parking = new Parking(placesRangeeAB);
                System.out.println("Création Parking, places, Catalogue ... Terminé \n");

                GestionnaireUsine gestionnaireUsineVoitureVacances = new GestionnaireUsine("Voiture Vacances", parking);

                gestionnaireUsineVoitureVacances.ajouterVoiture(voiture);

                System.out.println("Création et remplissage du Gestionnaire d'usine ... Terminé \n");

                System.out.println("Erreur avec la création  de l'object JsonArray et JsonObject\n");
                JSONArray voitureJsonArray = new JSONArray();
                JSONObject voitureJsonObject = new JSONObject();

                System.out.println("Création variable JsonObject et JsonArray \n");

                voitureJsonObject.put("numeroIdentification", voiture.getNumeroIdentification());
                voitureJsonObject.put("modele", voiture.getModele());
                voitureJsonObject.put("moteur", voiture.getMoteur());
                voitureJsonObject.put("dateFabrication", voiture.getDateFabrication());
                voitureJsonObject.put("couleur", voiture.getCouleur());
                voitureJsonObject.put("options", voiture.getStringOptions());

                System.out.println("Création JsonObject() de Voiture ... Terminé \n\t " + voitureJsonObject.toString());
                voitureJsonArray.put(voitureJsonArray.length(), voitureJsonObject);
                System.out.println("Insertion du JsonObject dans le JsonArray ... Terminé\n");

                // Création du fichier voiture.json
                FileWriter fs = null;
                try {
                    fs = new FileWriter("../../misc/json/voiture.json");
                    System.out.println("Récupération du fichier\n");
                } catch(IOException e) {
                    System.err.println("Erreur lors de l'ouverture du fichier '" + "/misc/json/voiture.json" + "'.");
                    System.err.println(e);
                    System.exit(0);
                }

                // Ecriture du fichier
                try {
                    voitureJsonObject.write(fs, 3, 0);
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
                
                System.out.println("Le fichier '" + "/misc/json/voiture.json" + "' a été généré.");

             //System.out.println(query);
            } catch (UnsupportedEncodingException io) {
                System.out.println("Erreur query");
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

    private Carburation carburationMoteurByQuery(String carburationString){
        Carburation carburation = null;

        if(carburationString.equalsIgnoreCase("diesel")){           carburation = Carburation.DIESEL;}
        else if(carburationString.equalsIgnoreCase("hybride")){     carburation = Carburation.HYBRIDE;}
        else if(carburationString.equalsIgnoreCase("essence")){     carburation = Carburation.ESSENCE;}
        else if(carburationString.equalsIgnoreCase("GPL")){         carburation = Carburation.GPL;}
        else if(carburationString.equalsIgnoreCase("Electrique")){  carburation = Carburation.ELECTRIQUE;}

        return carburation;
    }

    private int puissanceMoteurByQuery(String puissanceString){
        int puissance = 0;

        try{
            puissance = Integer.parseInt(puissanceString.trim());
        }catch (NumberFormatException nfe){
            System.out.println("NumberFormatException: " + nfe.getMessage());
        }

        return puissance;
    }

    private int pieceOfDate(String pieceString){
        int piece = 0;

        try{
            piece = Integer.parseInt(pieceString.trim());
        }catch (NumberFormatException nfe){
            System.out.println("NumberFormatException: " + nfe.getMessage());
        }

        return piece;
    }

    private Couleur couleurByQuery(String couleurString){
        Couleur couleur = null;
                
        if(couleurString.equalsIgnoreCase("rouge")){         couleur = Couleur.ROUGE;}
        else if(couleurString.equalsIgnoreCase("bleu")){     couleur = Couleur.BLEU;}
        else if(couleurString.equalsIgnoreCase("jaune")){    couleur = Couleur.JAUNE;}
        else if(couleurString.equalsIgnoreCase("blanc")){    couleur = Couleur.BLANC;}
        else if(couleurString.equalsIgnoreCase("noir")){     couleur = Couleur.NOIR;}
        else if(couleurString.equalsIgnoreCase("vert")){     couleur = Couleur.VERT;}
        else if(couleurString.equalsIgnoreCase("rose")){     couleur = Couleur.ROSE;}
        else if(couleurString.equalsIgnoreCase("marron")){   couleur = Couleur.MARRON;}
        else if(couleurString.equalsIgnoreCase("orange")){   couleur = Couleur.ORANGE;}
        else if(couleurString.equalsIgnoreCase("cyan")){     couleur = Couleur.CYAN;}
        else if(couleurString.equalsIgnoreCase("beige")){    couleur = Couleur.BEIGE;}
        else if(couleurString.equalsIgnoreCase("violet")){   couleur = Couleur.VIOLET;}
        else if(couleurString.equalsIgnoreCase("bleu_nuit")){couleur = Couleur.BLEU_NUIT;}
        else if(couleurString.equalsIgnoreCase("gris")){     couleur = Couleur.GRIS;}

        return couleur;
    }

    private Options[] optionsByQuery(String query) {
        Options opt1 = new Options("Camera De Recul", true);
        Options opt2 = new Options("Vitre Electriques", true);
        Options opt3 = new Options("GPS", true);
        Options opt4 = new Options();
        Options[] options = null;

        String opt1String = "options1";
        String opt2String = "options2";
        String opt3String = "options3";
        String opt4String = "options4";

        //arbre des options
        if(query.indexOf(opt1String) != -1 ){
            if(query.indexOf(opt2String) != -1){
                if(query.indexOf(opt3String) != -1){
                    if(query.indexOf(opt4String) != -1){
                        options = new Options[] {opt1, opt2, opt3, opt4};
                    }
                }
                else if(query.indexOf(opt4String) != -1){
                    options = new Options[] {opt1, opt2, opt4};
                }
            }
            else if(query.indexOf(opt3String) != -1){
                if(query.indexOf(opt4String) != -1){
                    options = new Options[] {opt1, opt3, opt4};
                }
            }
            else if(query.indexOf(opt4String) != -1){
                options = new Options[] {opt1, opt4};
            }

        }
        else if(query.indexOf(opt2String) != -1){
            if(query.indexOf(opt3String) != -1){
                if(query.indexOf(opt4String) != -1){
                    options = new Options[] {opt2, opt3, opt4};
                }
            }
            else if(query.indexOf(opt4String) != -1){
                options = new Options[] {opt2, opt4};
            }
        }
        else if(query.indexOf(opt3String) != -1){
            if(query.indexOf(opt4String) != -1){
                options = new Options[] {opt3, opt4};
            }
        }
        else if(query.indexOf(opt4String) != -1){
            options = new Options[] {opt4};
        }
        else{
            options = new Options[] {opt4};
        }   

        return options;
    }
}