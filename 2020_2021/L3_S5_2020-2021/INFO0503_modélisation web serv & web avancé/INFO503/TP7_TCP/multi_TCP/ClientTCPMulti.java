import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.PrintWriter;

import java.net.Socket;
import java.net.UnknownHostException;

/**
 * Classe correspondant à un client TCP.
 * Le client envoie la chaine 'Bonjour' et lit une réponse de la part du serveur.
 * Le client envoie ensuite la chaine 'Au revoir' et lit une réponse.
 * Le numéro de port du serveur est spécifié dans la classe ServeurTCPMulti.
 * @author Cyril Rabat
 */
public class ClientTCPMulti {
    
    public static int portEcoute = 5101;

    public static void main(String[] args) {
        if(args.length == 1) ClientTCPMulti.portEcoute = Integer.parseInt(args[0]);
        // Création de la socket
        Socket socket = null;
        try {
            socket = new Socket("localhost", portEcoute);
            System.out.println("Serveur : on\n\t\tport Ecoute : " + portEcoute);
        } catch(UnknownHostException e) {
            System.err.println("Erreur sur l'hôte : " + e);
            System.exit(0);
        } catch(IOException e) {
            System.err.println("Création de la socket impossible : " + e);
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

        // Envoi de 'Bonjour'
        String message = "Bonjour";
        System.out.println("Envoi: " + message);
        output.println(message);

        // Lecture de 'Bonjour'
        try {
            message = input.readLine();
        } catch(IOException e) {
            System.err.println("Erreur lors de la lecture : " + e);
            System.exit(0);
        }
        System.out.println("Lu: " + message);
        
        // Envoi de 'Au revoir'
        message = "Au revoir";
        System.out.println("Envoi: " + message);
        output.println(message);

        // Lecture de 'Au revoir'
        try {
            message = input.readLine();
        } catch(IOException e) {
            System.err.println("Erreur lors de la lecture : " + e);
            System.exit(0);
        }
        System.out.println("Lu: " + message);
        
        int chiffre = -1;
        //envoie d'un message écris
        System.out.println("Saisir un chiffre");
        chiffre = clavier.nextInt();
        //envoie
        System.out.println("chiffre : " + chiffre);
        output.println(chiffre);

        //boucle avec stop = -1
        System.out.println("[BOUCLE] stop = -1");
        while(chiffre != -1){
            //envoie d'un message écris
            System.out.println("Saisir un chiffre");
            chiffre = clavier.nextInt();
            //envoie
            System.out.println("chiffre : " + chiffre);
            output.println(chiffre);
        }

        // Fermeture des flux et de la socket
        try {
            input.close();
            output.close();
            socket.close();
            System.out.println("Client : off");
        } catch(IOException e) {
            System.err.println("Erreur lors de la fermeture des flux et de la socket : " + e);
            System.exit(0);
        }
    }

}