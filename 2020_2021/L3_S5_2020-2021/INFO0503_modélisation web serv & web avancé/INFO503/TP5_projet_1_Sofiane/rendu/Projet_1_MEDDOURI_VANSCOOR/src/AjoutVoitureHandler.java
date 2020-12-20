import com.sun.net.httpserver.HttpExchange;
import com.sun.net.httpserver.HttpHandler;
import com.sun.net.httpserver.Headers;
import java.io.IOException;
import java.io.UnsupportedEncodingException;
import java.io.OutputStream;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.net.URI;
import java.net.URLDecoder;
import java.io.IOException;
import java.lang.Integer;
import java.lang.Enum;
import java.util.Date;
import java.text.SimpleDateFormat;
import java.util.*;
import org.json.*;
import java.io.FileWriter;
import java.io.IOException;
class AjoutVoitureHandler implements HttpHandler{

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

        //reponse += "<p>Données en POST : ";
        if(query == null){
            reponse += "<b>Aucune</b></p>";
        }
        else{
            reponse += "<b>" + "La voiture a bien été crée" + "</b></p>";
            reponse += "<form method='POST'action='http://localhost:8080/login'><button>Cliquez ici pour retourner a la page d'accueil</button></form>";
            try {
             query = URLDecoder.decode(query, "UTF-8");
             String[] decoupage1;
             decoupage1 = query.split("&");
             for(int i = 0; i < decoupage1.length;i++){
              System.out.println(decoupage1[i]);
             }
            String[] decoupage2;
            decoupage2 = decoupage1[2].split("=");
            for(int i = 0; i < decoupage2.length;i++){
                //System.out.println(decoupage2[i]);
            }

            String[] decoupage3;
            decoupage3 = decoupage2[1].split(",");
            for(int i = 0; i < decoupage3.length;i++){
                //System.out.println(decoupage3[i]);
            }

            String puiss = decoupage3[3];

            int puissance = 0;

            try{
                puissance = Integer.parseInt(puiss.trim());
            }catch (NumberFormatException nfe){
                System.out.println("NumberFormatException: " + nfe.getMessage());
            }

            //System.out.println(puissance);

            String carb = decoupage3[2];

            Carburation carburation = null;

            if(carb.equalsIgnoreCase("diesel")){
                carburation = Carburation.DIESEL;
            }
            if(carb.equalsIgnoreCase("hybride")){
                carburation = Carburation.HYBRIDE;
            }
            if(carb.equalsIgnoreCase("essence")){
                carburation = Carburation.ESSENCE;
            }
            if(carb.equalsIgnoreCase("GPL")){
                carburation = Carburation.GPL;
            }
            
            Moteur moteur = new Moteur(carburation,puissance);

            String[] decoupage4 = decoupage1[1].split("=");
            
            String m = decoupage4[1];

            Modele modele = new Modele(m);

            String[] decoupage5 = decoupage1[3].split("=");

            String dateFabrication = decoupage5[1];

            String[] autreDecoupage = dateFabrication.split("-");

            String anneeTemp = autreDecoupage[0];
            String jourTemp = autreDecoupage[1];
            String moisTemp = autreDecoupage[2];

            int annee = 0;
            int mois = 0;
            int jour = 0;

            try{
                annee = Integer.parseInt(anneeTemp.trim());
                mois = Integer.parseInt(moisTemp.trim());
                jour = Integer.parseInt(jourTemp.trim());
            }catch (NumberFormatException nfe){
                System.out.println("NumberFormatException: " + nfe.getMessage());
            }
            //System.out.println("Hello tous le monde");
            //System.out.println(annee);
            //System.out.println(mois);
            //System.out.println(jour);

            Date date = new Date(annee,mois,jour);

            //System.out.println(dateFabrication);

            String[] decoupage6 = decoupage1[4].split("=");

            String coul = decoupage6[1];

            Couleur couleur = null;
            
            if(coul.equalsIgnoreCase("rouge")){
                couleur = Couleur.ROUGE;
            }
            
            if(coul.equalsIgnoreCase("bleu")){
                couleur = Couleur.BLEU;
            }
            if(coul.equalsIgnoreCase("jaune")){
                couleur = Couleur.JAUNE;
            }
            if(coul.equalsIgnoreCase("blanc")){
                couleur = Couleur.BLANC;
            }
            if(coul.equalsIgnoreCase("noir")){
                couleur = Couleur.NOIR;
            }
            if(coul.equalsIgnoreCase("vert")){
                couleur = Couleur.VERT;
            }
            if(coul.equalsIgnoreCase("rose")){
                couleur = Couleur.ROSE;
            }
            if(coul.equalsIgnoreCase("marron")){
                couleur = Couleur.MARRON;
            }
            if(coul.equalsIgnoreCase("orange")){
                couleur = Couleur.ORANGE;
            }
            if(coul.equalsIgnoreCase("cyan")){
                couleur = Couleur.CYAN;
            }
            if(coul.equalsIgnoreCase("beige")){
                couleur = Couleur.BEIGE;
            }
            if(coul.equalsIgnoreCase("violet")){
                couleur = Couleur.VIOLET;
            }
            if(coul.equalsIgnoreCase("bleu_nuit")){
                couleur = Couleur.BLEU_NUIT;
            }
            if(coul.equalsIgnoreCase("gris")){
                couleur = Couleur.GRIS;
            }

            System.out.println(couleur);
            Options opt5 = new Options();
            Options opt2 = new Options("vitres electriques", true);
            Options opt1 = new Options("camera de recul", true);
            Options opt3 = new Options("toit ouvrant", true);
            Options opt4 = new Options("alarme integree", true);
            Options[] options1 = null;

            String o = "options1";
            String p = "options2";
            String q = "options3";
            String r = "options4";
            String s = "options5";

            System.out.println(query);
            //marche
            if(query.indexOf(o) != -1){
                options1 = new Options[] {opt1};
            }
            //marche
            if(query.indexOf(p) != -1){
                options1 = new Options[] {opt2};
            }
            //marche
            if(query.indexOf(q) != -1){
                options1 = new Options[] {opt3};
            }
            //marche
            if(query.indexOf(r) != -1){
                options1 = new Options[] {opt4};
            }
            if(query.indexOf(s) != 1){
                options1 = new Options[]{opt5};
            }
            //marche
            if(query.indexOf(o) != -1 && query.indexOf(p) != -1){
                options1 = new Options[] {opt1,opt2};
            }
            //marche
            if(query.indexOf(o) != -1 && query.indexOf(q) != -1){
                options1 = new Options[] {opt1,opt3};
            }
            //marche
            if(query.indexOf(o) != -1 && query.indexOf(r) != -1){
                options1 = new Options[] {opt1,opt4};
            }
            //marche
            if(query.indexOf(p) != -1 && query.indexOf(q) != -1){
                options1 = new Options[] {opt2,opt3};
            }
            //marche
            if(query.indexOf(p) != -1 && query.indexOf(r) != -1){
                options1 = new Options[] {opt2,opt4};
            }
            //marche
            if(query.indexOf(q) != -1 && query.indexOf(r) != -1){
                options1 = new Options[] {opt3,opt4};
            }
            //marche
            if(query.indexOf(o) != -1 && query.indexOf(p) != -1 && query.indexOf(q) != -1){
                options1 = new Options[] {opt1,opt2,opt3};
            }
            //marche
            if(query.indexOf(o) != -1 && query.indexOf(q) != -1 && query.indexOf(r) != -1){
                options1 = new Options[] {opt1,opt3,opt4};
            }
            //ne marche pas
            if(query.indexOf(p) != -1 && query.indexOf(q) != -1 && query.indexOf(r) != -1){
                options1 = new Options[] {opt2,opt3,opt4};
            }
            //marche
            if(query.indexOf(q) != -1 && query.indexOf(r) != -1){
                options1 = new Options[] {opt3,opt4};
            }
            //marche
            if(query.indexOf(r) != -1 && query.indexOf(o) != -1 && query.indexOf(p) != -1){
                options1 = new Options[] {opt4,opt1,opt2};
            }
            //marche
            if(query.indexOf(o) != -1 && query.indexOf(p) != -1 && query.indexOf(q) != -1 && query.indexOf(r) != -1){
                options1 = new Options[] {opt1,opt2,opt3,opt4};
            }

            String[] decoupage7 = decoupage1[0].split("=");
            String numeroIdentification = decoupage7[1];
            
            Voiture v = new Voiture(numeroIdentification,modele,moteur,date,couleur,options1);
            
            List Catalogue = new ArrayList(10);

            Place p1 = new Place('A',1);
            Place p2 = new Place('A', 3);
            Place[] placesRangeeA = new Place[] {p1, p2};
            Parking pp = new Parking(placesRangeeA);

            GestionnaireUsine u = new GestionnaireUsine("Volkswagen",pp);

            u.ajouterVoiture(v);

            u.afficherVoiture();


            JSONObject tabVoiture = new JSONObject();

            tabVoiture.put("numeroIdentification",v.getNumeroIdentification());

            tabVoiture.put("modele",v.getModele());

            tabVoiture.put("moteur",v.getMoteur());

            tabVoiture.put("dateFabrication",v.getDateFabrication());

            tabVoiture.put("couleur",v.getCouleur());

            tabVoiture.put("options",v.getStringOptions());

            tabVoiture.toString();

        // Création du fichier de sortie
        FileWriter fs = null;
        try {
            fs = new FileWriter("../src/voiture.json");
        } catch(IOException e) {
            System.err.println("Erreur lors de l'ouverture du fichier '" + "voiture.json" + "'.");
            System.err.println(e);
            System.exit(0);
        }
        // Sauvegarde dans le fichier
        try {
            tabVoiture.write(fs, 3, 0);
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
        
        System.out.println("Le fichier '" + "voiture.json" + "' a été généré.");
            
            

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
   
}