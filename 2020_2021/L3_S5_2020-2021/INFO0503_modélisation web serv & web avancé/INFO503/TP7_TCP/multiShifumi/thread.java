import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.PrintWriter;

import java.net.Socket;

import java.util.Random;

/**
 * Classe correspondant au thread associe à chaque connexion d'un client.
 * @author Nathan TONNELLE
 */
public class thread extends Thread {

    private BufferedReader input;
    private PrintWriter output;
    private Socket socketClient;

    public thread(Socket socketClient) {
        this.socketClient = socketClient;

        // Association d'un flux d'entrée et de sortie
        try {
            input = new BufferedReader(new InputStreamReader(socketClient.getInputStream()));
            output = new PrintWriter(new BufferedWriter(new OutputStreamWriter(socketClient.getOutputStream())), true);
        } catch(IOException e) {
            System.err.println("Association des flux impossible : " + e);
            System.exit(0);
        }
    }

    @Override
    public void run() {
        //lecture du nombre envoyé
        String clientNumber = this.getName().split("-")[1];
        int numberAdverssaire = -10;
        do{
            try{
                numberAdverssaire = Integer.parseInt(input.readLine());
            } catch(IOException e){
                System.err.println("Erreur lors de la lecture : " + e);
                System.exit(0);
            }
            if(numberAdverssaire != -1){
                System.out.println("[CLIENT-" + clientNumber + "] Lu : " + numberAdverssaire + " = " + coupString(numberAdverssaire));

                String matchJsonString = matchToJson(numberAdverssaire);
                System.out.println("[SERVEUR] Envoie : " + matchJsonString);
                output.println(matchJsonString);
            }
            else{System.out.println("[SERVEUR] Client-" + clientNumber + " Arreté");}
                
        }while(numberAdverssaire != -1);
            

        // Fermeture des flux et des sockets
        try {
            input.close();
            output.close();
            socketClient.close();
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
            case -1 :
                coup = "Arret Client";
                break;
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