import java.io.IOException;

import java.net.DatagramSocket;
import java.net.DatagramPacket;
import java.net.SocketException;
import java.net.InetAddress;
import java.net.InetSocketAddress;
import java.net.UnknownHostException;

import java.util.Scanner;

public class Client {

    public static int portEcoute = 0;
    public static int portEnvoie = 9876;
    
    public static void main(String[] args) {
        Scanner clavier = new Scanner(System.in);

        // Création de la socket
        DatagramSocket socket = null;
        try {        
            socket = new DatagramSocket();  //portEcoute automatique, récup avec : socket.getLocalPort()
            Client.portEcoute = socket.getLocalPort();
            System.out.println("\nETAT client : on \n\t\tport Ecoute : " + portEcoute + "\n\t\tport Envoie : " + portEnvoie);
        } catch(SocketException e) {
            System.err.println("Erreur lors de la création de la socket : " + e);
            System.exit(0);
        }

        String message = "";
        String message2 = "";
        String portClientAdversaire = "";

        //envoie du message avec le portEcoute au serveur
        DatagramPacket msg = null;
        message = socket.getLocalPort() + "";   //envoie portEcoute

        try {
            InetAddress adresse = InetAddress.getByName(null);
            byte[] tampon = message.getBytes();
            msg = new DatagramPacket(tampon, tampon.length, adresse, portEnvoie);   
            socket.send(msg);         
        } catch(UnknownHostException e) {
            System.err.println("[ERREUR_CLIENT] Erreur lors de la création du message : " + e);
            System.exit(0);
        } catch(IOException e) {
            System.err.println("[ERREUR_CLIENT] Erreur lors de l'envoi du message : " + e);
            System.exit(0);
        }

        //lecture du message du serveur
        byte[] tampon2 = new byte[1024];
        DatagramPacket msg2 = new DatagramPacket(tampon2, tampon2.length);

        try {
            socket.receive(msg2);
            message2 = new String(msg2.getData(), 0, msg2.getLength());
            System.out.println("\n[CLIENT] Lu : " + message2 + "");
        } catch(IOException e) {
            System.err.println("[ERREUR_CLIENT] Erreur lors de la réception du message : " + e);
            System.exit(0);
        }  

        
        if(message2.equals("ok")){      //Client-1
            //récupération du portEcoute de l'adversaire (Client-2)
            byte[] tampon3 = new byte[1024];
            DatagramPacket msg3 = new DatagramPacket(tampon3, tampon3.length);

            try {
                socket.receive(msg3);
                portClientAdversaire = new String(msg3.getData(), 0, msg3.getLength());
                System.out.println("\n[CLIENT] Lu : " + portClientAdversaire + "");
                Client.portEnvoie = Integer.parseInt(portClientAdversaire);
            } catch(IOException e) {
                System.err.println("[ERREUR_CLIENT] Erreur lors de la réception du message : " + e);
                System.exit(0);
            }
            System.out.println("\nClient :\n\t\tport Ecoute : " + portEcoute + "\n\t\tport Envoie : " + portEnvoie);

            //jeu
        }
        else{                           //Client-2
            Client.portEnvoie = Integer.parseInt(message2);

            //envoie du portEcoute (Client-2)
            DatagramPacket envoiePortEcoute = null;
            String messagePortEcoute = socket.getLocalPort() + "";   //envoie portEcoute

            try {
                InetAddress adresse = InetAddress.getByName(null);
                byte[] tamponEnvoiePortEcoute = messagePortEcoute.getBytes();
                envoiePortEcoute = new DatagramPacket(tamponEnvoiePortEcoute, tamponEnvoiePortEcoute.length, adresse, portEnvoie);   
                socket.send(envoiePortEcoute);         
            } catch(UnknownHostException e) {
                System.err.println("[ERREUR_CLIENT] Erreur lors de la création du message : " + e);
                System.exit(0);
            } catch(IOException e) {
                System.err.println("[ERREUR_CLIENT] Erreur lors de l'envoi du message : " + e);
                System.exit(0);
            }
            System.out.println("\nClient :\n\t\tport Ecoute : " + portEcoute + "\n\t\tport Envoie : " + portEnvoie);

            //jeu
        }
        
        
        // Fermeture de la socket
        System.out.println("\nETAT client : off");
        clavier.close();
        socket.close();
    }

}