import java.io.IOException;

import java.net.DatagramSocket;
import java.net.DatagramPacket;
import java.net.SocketException;
import java.net.InetAddress;
import java.net.UnknownHostException;

import java.util.Scanner;

/**
 * Classe correspondant à un client UDP.
 * La chaine de caractères "Bonjour" est envoyée au serveur.
 * Le port d'écoute du serveur est indiqué dans la classe ServeurUDP.
 * @author TONNELLE Nathan
 */
public class ClientUDP {

    public static int portEcoute = 9877;
    public static int portEnvoie = 9876;

    private static String nomFichierClePriv = "priveeClient.bin";
    private static String nomFichierClePubl = "publiqueClient.bin";
    private static String message = "blabla";
    private static DatagramSocket socket = null;
    private static DatagramPacket msg = null;
    
    public static void main(String[] args) {
        Scanner clavier = new Scanner(System.in);

        // Création de la socket
        socket = null;
        try {        
            System.out.println("\nETAT socket : on \n\t\tport Ecoute : " + portEcoute + "\n\t\tport Envoie : " + portEnvoie);
            socket = new DatagramSocket(portEcoute);
        } catch(SocketException e) {
            System.err.println("Erreur lors de la création de la socket : " + e);
            System.exit(0);
        }
        
        RSA rsaClient = new RSA(nomFichierClePriv, nomFichierClePubl);

        //envoie clé publique au serveur
        message = rsaClient.lectureClePublique(nomFichierClePubl).toString();
        envoie(message);

        //reception clé publique du serveur


        while(!message.equals("end")){
            System.out.print("\nMessage à envoyer au serveur : ");
            message = clavier.nextLine();

            //envoie au serveur
            envoie(message);

            //retour Serveur
            String retour = reception(1024);
        }
        
        clavier.close();

        // Fermeture de la socket
        System.out.println("\nETAT socket : off");
        socket.close();
    }

    /**
     * envoie un message au serveur
     * @param messageString message à envoyer
     */
    public static void envoie(String messageString){
        msg = null;
        try {
            InetAddress adresse = InetAddress.getByName(null);
            byte[] tampon = messageString.getBytes();
            msg = new DatagramPacket(tampon, tampon.length, adresse, portEnvoie);    
            //System.out.println("\nEnvoie du message au serveur : " + messageString);
            socket.send(msg);        
        } catch(UnknownHostException e) {
            System.err.println("Erreur lors de la création du message : " + e);
            System.exit(0);
        } catch(IOException e) {
            System.err.println("Erreur lors de l'envoi du message : " + e);
            System.exit(0);
        }
    }

    /**
     * Receptionne un message serveur
     * @param nbBytes nombre de bytes pour le tampon
     * @return le message du serveur
     */
    public static String reception(int nbBytes){
        String receptionString = "";
        byte[] tamponReception = new byte[nbBytes];
        msg = new DatagramPacket(tamponReception, tamponReception.length);

        // Lecture du message du Serveur
        try {
            socket.receive(msg);
            receptionString = new String(msg.getData(), 0, msg.getLength());
            System.out.println("\nMessage Serveur : \n\tLu: " + receptionString);
        } catch(IOException e) {
            System.err.println("Erreur lors de la réception du message : " + e);
            System.exit(0);
        }

        return receptionString;
    }

}