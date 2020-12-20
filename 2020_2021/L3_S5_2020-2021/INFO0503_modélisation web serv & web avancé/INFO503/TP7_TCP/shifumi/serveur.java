import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Random;

/**
 * Classe correspondant à un serveur TCP.
 * Le client envoie le coup de son choix et lit le résutlat du match de la part du serveur.
 * Le numéro de port du serveur est spécifié dans la classe serveur.
 * @author Nathan TONNELLE
 */
public class serveur {

    public static int portEcoute = 9876;

    public static void main(String[] args) {
        if(args.length == 1) serveur.portEcoute = Integer.parseInt(args[0]);

        // Création de la socket serveur
        ServerSocket socketServeur = null;
        try {    
            socketServeur = new ServerSocket(portEcoute);
            System.out.println("Serveur : on\n\t\tport Ecoute : " + portEcoute);
        } catch(IOException e) {
            System.err.println("Création de la socket impossible : " + e);
            System.exit(0);
        }

        // Attente d'une connexion d'un client
        Socket socketClient = null;
        try {
            socketClient = socketServeur.accept();
        } catch(IOException e) {
            System.err.println("Erreur lors de l'attente d'une connexion : " + e);
            System.exit(0);
        }

        // Association d'un flux d'entrée et de sortie
        BufferedReader input = null;
        PrintWriter output = null;
        try {
            input = new BufferedReader(new InputStreamReader(socketClient.getInputStream()));
            output = new PrintWriter(new BufferedWriter(new OutputStreamWriter(socketClient.getOutputStream())), true);
        } catch(IOException e) {
            System.err.println("Association des flux impossible : " + e);
            System.exit(0);
        }

        //lecture du nombre envoyé
        int numberAdverssaire = -1;
        try{
            numberAdverssaire = Integer.parseInt(input.readLine());
        } catch(IOException e){
            System.err.println("Erreur lors de la lecture : " + e);
            System.exit(0);
        }
        System.out.println("[CLIENT] Lu : " + numberAdverssaire + " = " + coupString(numberAdverssaire));

        String matchJsonString = matchToJson(numberAdverssaire);
        System.out.println("[SERVEUR] Envoie : " + matchJsonString);
        output.println(matchJsonString);
        

        // Fermeture des flux et des sockets
        try {
            input.close();
            output.close();
            socketClient.close();
            socketServeur.close();
            System.out.println("Serveur : off");
        } catch(IOException e) {
            System.err.println("Erreur lors de la fermeture des flux et des sockets : " + e);
            System.exit(0);
        }
    }

    /**
     * retourne un aléatoire numéro du coup
     * @return le numéro du coup
     */
    public static int numAleatoire(){
        Random rand = new Random(); 
        return (rand.nextInt(3) + 1);
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
     * retourne le résultat du match sous forme de chaine de caractère
     * @param coupAdversaire numéro du coup de l'adversaire
     * @param coupDonnee numéro du coup du Serveur
     * @return résultat du match
     */
    public static String resultatMatch(int coupAdversaire, int coupDonnee){
        String resultat = "";
        if(coupDonnee == coupAdversaire){
            resultat = "égalité";
        }
        else if((coupDonnee == 1 && coupAdversaire == 3 ) 
            || (coupDonnee == 2 && coupAdversaire == 1) 
            || (coupDonnee == 3 && coupAdversaire == 2)){
                resultat = "gagné";
        }
        else if((coupDonnee == 1 && coupAdversaire == 2) 
            || (coupDonnee == 2 && coupAdversaire == 3) 
            || (coupDonnee == 3 && coupAdversaire == 1)){
                resultat = "perdu";
        }
        else{ resultat = "[ERREUR]";}
        return resultat;
    }

    /**
     * construit un objet json du match
     * @param coupAdversaire numéro du coup de l'adversaire
     * @return la chaine de caractère du match
     */
    public static String matchToJson(int coupAdversaire){
        String rep = "";
        int coupServeur = numAleatoire();
        String etat = "";
        if(numeroCorrect(coupAdversaire) && numeroCorrect(coupServeur)) etat = "OK";
        else etat = "ERREUR";
        String result = resultatMatch(coupAdversaire, coupServeur);

        rep = "{etat:" + etat + ",coup:" + coupServeur + ",result:" + result + "}";

        return rep;
    }
}