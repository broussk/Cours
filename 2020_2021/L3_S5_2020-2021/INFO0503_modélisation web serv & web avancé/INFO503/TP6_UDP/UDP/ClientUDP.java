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
 * @author Cyril Rabat
 */
public class ClientUDP {

    public static int portEcoute = 9877;
    public static int portEnvoie = 9876;
    
    public static void main(String[] args) {
        Scanner clavier = new Scanner(System.in);

        // Création de la socket
        DatagramSocket socket = null;
        try {        
            System.out.println("\nETAT socket : on \n\t\tport Ecoute : " + portEcoute + "\n\t\tport Envoie : " + portEnvoie);
            socket = new DatagramSocket(portEcoute);
        } catch(SocketException e) {
            System.err.println("Erreur lors de la création de la socket : " + e);
            System.exit(0);
        }

        String message = "blabla";

        while(!message.equals("end")){
            // Création du message Client
            DatagramPacket msg = null;
            System.out.print("\nMessage à envoyer au serveur : ");
            message = clavier.nextLine();
            //System.out.println("Message : \"" + message + "\"");
            try {
                InetAddress adresse = InetAddress.getByName(null);
                byte[] tampon = message.getBytes();
                msg = new DatagramPacket(tampon, tampon.length, adresse, portEnvoie);            
            } catch(UnknownHostException e) {
                System.err.println("Erreur lors de la création du message : " + e);
                System.exit(0);
            }

            // Envoi du message Client
            try {
                //System.out.println("\nEnvoie du message au serveur : " + message);
                socket.send(msg);
            } catch(IOException e) {
                System.err.println("Erreur lors de l'envoi du message : " + e);
                System.exit(0);
            }

            // Création du message Serveur
            byte[] tampon2 = new byte[1024];
            msg = new DatagramPacket(tampon2, tampon2.length);

            // Lecture du message du Serveur
            try {
                socket.receive(msg);
                String texte = new String(msg.getData(), 0, msg.getLength());
                System.out.println("\nMessage Serveur : \n\tLu: " + texte);
            } catch(IOException e) {
                System.err.println("Erreur lors de la réception du message : " + e);
                System.exit(0);
            }
        }
        
        clavier.close();

        // Fermeture de la socket
        System.out.println("\nETAT socket : off");
        socket.close();
    }

}