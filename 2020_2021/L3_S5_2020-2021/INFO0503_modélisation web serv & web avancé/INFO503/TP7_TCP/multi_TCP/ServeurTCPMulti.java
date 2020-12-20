import java.io.IOException;

import java.net.ServerSocket;
import java.net.Socket;

/**
 * Classe correspondant à un serveur TCP multithreadé.
 * Le client envoie la chaine 'Bonjour' et lit une réponse de la part du serveur.
 * Le client envoie ensuite la chaine 'Au revoir' et lit une réponse.
 * Le numéro de port du serveur est spécifié dans la classe ServeurTCP.
 * @author Cyril Rabat
 */
public class ServeurTCPMulti {

    public static int portEcoute = 5101;

    public static void main(String[] args) {
        if(args.length == 1) ServeurTCPMulti.portEcoute = Integer.parseInt(args[0]);
        // Création de la socket serveur
        ServerSocket socketServeur = null;
        try {    
            socketServeur = new ServerSocket(portEcoute);
            System.out.println("Serveur : on\n\t\tport Ecoute : " + portEcoute);
        } catch(IOException e) {
            System.err.println("Création de la socket impossible : " + e);
            System.exit(0);
        }

        int i=0;
        // Attente des connexions des clients
        try {
            Socket socketClient;
            while(i<5) {
                socketClient = socketServeur.accept();
                ThreadConnexion t = new ThreadConnexion(socketClient);
                t.start();
                System.out.println("n°" + i + " : En attente d'une connexion...");
                i++;
            }
        } catch(IOException e) {
            System.err.println("Erreur lors de l'attente d'une connexion : " + e);
            System.exit(0);
        }
    
        // Fermeture de la socket
        try {
            socketServeur.close();
            System.out.println("Serveur : off");
        } catch(IOException e) {
            System.err.println("Erreur lors de la fermeture de la socket : " + e);
            System.exit(0);
        }
    }

}