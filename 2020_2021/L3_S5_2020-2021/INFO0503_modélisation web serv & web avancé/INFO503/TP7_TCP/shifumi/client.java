import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.PrintWriter;

import java.net.Socket;
import java.net.UnknownHostException;

import java.util.Random;
import java.util.Scanner;

/**
 * Classe correspondant à un client TCP.
 * Le client envoie le coup de son choix et lit le résutlat du match de la part du serveur.
 * Le numéro de port du serveur est spécifié dans la classe serveur.
 * @author Nathan TONNELLE
 */
public class client {

    public static int portEcoute = 9876;

    public static void main(String[] args) {
        Scanner clavier = new Scanner(System.in);
        if(args.length == 1) client.portEcoute = Integer.parseInt(args[0]);

        // Création de la socket
        Socket socket = null;
        try {
            socket = new Socket("localhost", portEcoute);
            System.out.println("Client : on\n\t\tport Ecoute: " + portEcoute);
        } catch(UnknownHostException e) {
            System.err.println("Erreur sur l'hôte : " + e);
            System.exit(0);
        } catch(IOException e) {
            //System.err.println("Création de la socket impossible : " + e);
            System.out.println("Le serveur est éteins, impossible de créer un lien avec lui.");
            System.exit(0);
        }
    
        // Association d'un flux d'entrée et de sortie
        BufferedReader input = null;
        PrintWriter output = null;
        try {
            input = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            output = new PrintWriter(new BufferedWriter(new OutputStreamWriter(socket.getOutputStream())), true);
        } catch(IOException e) {
            System.err.println("Association des flux impossible : " + e);
            System.exit(0);
        }
    
        //envoie d'entier
        int number = -1;
        do{
            System.out.println("Saisir un nombre à envoyer au serveur (1 ou 2 ou 3):");
            number = clavier.nextInt();
        }while(!numeroCorrect(number));
        System.out.println("[CLIENT] Envoie : " + number + " = " + coupString(number));
        output.println(number);

        //lecture entier serveur
        String retourServeur = "";
        try{
            retourServeur = input.readLine();
        }catch(IOException e){
            System.err.println("Erreur lors de la lecture : " + e);
            System.exit(0);
        }
        System.out.println("[SERVEUR] Lu : " + retourServeur);
        System.out.println("Récupération à partir de la chaine envoyée :" 
            + "\n\tetat : " + recupEtat(retourServeur) 
            + "\n\tcoup Client : " + number + " = " + coupString(number)
            + "\n\tcoup Serveur : " + recupCoup(retourServeur) + " = " + coupString(recupCoup(retourServeur)) 
            + "\n\tresultat : " + recupResult(retourServeur)
        );

        // Fermeture des flux et de la socket
        try {
            input.close();
            output.close();
            socket.close();
            clavier.close();
            System.out.println("Client : off");
        } catch (IOException e) {
            System.err.println("Erreur lors de la fermeture des flux et de la socket : " + e);
            System.exit(0);
        }
    }

    /**
     * retourne la correspondace entre le numéro et coup
     * @param num entier correspondant au numéro du coup
     * @return chaine de caractère décrivant le coup
     */
    public static String coupString(int num){
        String coup = "";
        switch(num){
            case 1 :
                coup = "Pierre";
                break;
            case 2 :
                coup = "Feuille";
                break;
            case 3 :
                coup = "Ciseaux";
                break;
            default : 
                coup = "pierre";
                break;
        }
        return coup;
    }

    /**
     * verification que le numéro du cop est correcte
     * @param num entier correspondant au numéro du coup
     * @return boolean de la vérification
     */
    public static boolean numeroCorrect(int num){
        boolean correct = false;
        if(num >= 1 && num <= 3) correct = true;
        return correct;
    }

    /**
     * retourne  l'état du match
     * @param objJSON correspond au retour du serveur sur le match en cours, en format JSON
     * @return retourne l'état du match 
     */
    public static String recupEtat(String objJSON){
        String etat = "false";
        if(verifChaineJson(objJSON)){
            objJSON = objJSON.replace("{", "").replace("}", "");
            String[] parseObjet = objJSON.split(",");

            String[] recupEtats = parseObjet[0].split(":");

            etat = recupEtats[1];
            //System.out.println("[FONCTION RECUP ETAT] etat : " + etat);
        }
        else{System.out.println("[ERREUR : fonction recupResult] La chaine de caractère transmise ne possède pas le format JSON.");}

        return etat;
    }

    /**
     * retourne  le coup du serveur
     * @param objJSON correspond au retour du serveur sur le match en cours, en format JSON
     * @return retourne le coup du serveur 
     */
    public static int recupCoup(String objJSON){
        if(verifChaineJson(objJSON)){
            objJSON = objJSON.replace("{", "").replace("}", "");
            String[] parseObjet = objJSON.split(",");

            String[] recupCoups = parseObjet[1].split(":");

            String coup = recupCoups[1];
            //System.out.println("[FONCTION RECUP COUP] etat : " + coup);

            return Integer.parseInt(coup);
        }
        else{
            System.out.println("[ERREUR : fonction recupResult] La chaine de caractère transmise ne possède pas le format JSON.");
            return -1;
        }
    }

    /**
     * retourne  le résultat du match
     * @param objJSON correspond au retour du serveur sur le match en cours, en format JSONs
     * @return retourne le résultat du match 
     */
    public static String recupResult(String objJSON){
        String result = "false";
        if(verifChaineJson(objJSON)){
            objJSON = objJSON.replace("{", "").replace("}", "");
            String[] parseObjet = objJSON.split(",");

            String[] recupResults = parseObjet[2].split(":");

            result = recupResults[1];
            //System.out.println("[FONCTION RECUP RESULT] etat : " + result);
        }
        else{System.out.println("[ERREUR : fonction recupResult] La chaine de caractère transmise ne possède pas le format JSON.");}

        return result;
    }

    /**
     * vérifie le format de la chaine de caractère transmise, si c'est du JSON, alors c'est correcte, sinon non
     * @param chaineJson chaine à vérifier
     * @return retourne le résultat de la vérification
     */
    public static boolean verifChaineJson(String chaineJson){
        boolean verif = false;
        if(chaineJson.contains("{") && chaineJson.contains("}")) verif = true;
        return verif;
    }

}