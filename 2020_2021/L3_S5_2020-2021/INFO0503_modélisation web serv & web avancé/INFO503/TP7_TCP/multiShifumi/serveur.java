import java.io.IOException;

import java.net.ServerSocket;
import java.net.Socket;

/**
 * Classe correspondant à un serveur TCP multithreadé.
 * Le client joue au shifumi avec le serveur, il envoie sa réponse en premier.
 * Le Serveur lui répond et affiche le résutlat.
 * Le numéro de port du serveur est spécifié dans la classe ServeurTCP.
 * @author Nathan TONNELLE
 */
public class serveur {

    public static int portEcoute = 5101;

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

        System.out.println("[SERVEUR] Serveur : " 
            + "\n\t@ip Serveur: " + socketServeur.getInetAddress().getHostAddress()
            + "\n\tlocal port (Ecoute) : " + socketServeur.getLocalPort()
        );

        int i = 0;
        // Attente des connexions des clients
        try {
            Socket socketClient;
            //while(i <= 5) {
            while(true){
                socketClient = socketServeur.accept();
                thread_serv t = new thread_serv(socketClient);
                t.start();
                System.out.println("[SERVEUR] Client-" + i + " : "
                    + "\n\t@ip Client : " + socketClient.getInetAddress().getHostAddress()
                    + "\n\tlocal port (Ecriture) : " + socketClient.getLocalPort()
                    + "\n\tport (connecté au serveur avec) : " + socketClient.getPort()
                    + "\n\ten attente ..."
                );
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