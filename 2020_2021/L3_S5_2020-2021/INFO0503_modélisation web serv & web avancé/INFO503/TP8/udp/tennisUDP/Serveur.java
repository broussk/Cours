/*
 * comilation : javac *.java
 * execution serveur : java Serveur
 * execution client : java Client
 * generation javadoc : javadoc *.java -d Doc
 */



import java.io.IOException;

import java.net.DatagramSocket;
import java.net.DatagramPacket;
import java.net.SocketException;
import java.net.InetAddress;
import java.net.UnknownHostException;

import java.util.Scanner;

public class Serveur {

    public static int portEcoute = 9876;
    public static int portEnvoie = 9877;

    public static void main(String[] args) {
        Scanner clavier = new Scanner(System.in);

        // Création de la socket
        DatagramSocket socket = null;
        try {        
            System.out.println("\nETAT serveur : on \n\t\tport Ecoute : " + portEcoute + "\n\t\tport Envoie : " + portEnvoie);
            socket = new DatagramSocket(portEcoute);
        } catch(SocketException e) {
            System.err.println("Erreur lors de la création de la socket : " + e);
            System.exit(0);
        }

        while(true){
            String portClient1 = "";
            String portClient2 = "";
            String portOk = "ok";

            // Lecture du message du Client-1
            byte[] tampon = new byte[1024];
            DatagramPacket msg = new DatagramPacket(tampon, tampon.length);
            try {
                socket.receive(msg);
                portClient1 = new String(msg.getData(), 0, msg.getLength());
                System.out.println("\nMessage Client-1 : \n\tLu: " + portClient1);
                Serveur.portEnvoie = Integer.parseInt(portClient1);
            } catch(IOException e) {
                System.err.println("Erreur lors de la réception du message : " + e);
                System.exit(0);
            }

            // Envoi du message Serveur d'enregistrement à Client-1
            msg = null;
            try {
                InetAddress adresse = InetAddress.getByName(null);
                byte[] tampon2 = portOk.getBytes();
                msg = new DatagramPacket(tampon2, tampon2.length, adresse, portEnvoie);   
                socket.send(msg);         
            } catch(UnknownHostException e) {
                System.err.println("Erreur lors de la création du message : " + e);
                System.exit(0);
            } catch(IOException e) {
                System.err.println("Erreur lors de l'envoi du message : " + e);
                System.exit(0);
            }

            // Lecture du message du Client-2
            byte[] tamponClient2 = new byte[1024];
            DatagramPacket msgClient2 = new DatagramPacket(tamponClient2, tamponClient2.length);
            try {
                socket.receive(msgClient2);
                portClient2 = new String(msgClient2.getData(), 0, msgClient2.getLength());
                System.out.println("\nMessage Client-2 : \n\tLu: " + portClient2);
                Serveur.portEnvoie = Integer.parseInt(portClient2);
            } catch(IOException e) {
                System.err.println("Erreur lors de la réception du message : " + e);
                System.exit(0);
            }

            // Envoi du port Client-1 à Client-2
            msgClient2 = null;
            try {
                InetAddress adresseClient2 = InetAddress.getByName(null);
                byte[] tampon2Client2 = portClient1.getBytes();
                msgClient2 = new DatagramPacket(tampon2Client2, tampon2Client2.length, adresseClient2, portEnvoie);   
                socket.send(msgClient2);         
            } catch(UnknownHostException e) {
                System.err.println("Erreur lors de la création du message : " + e);
                System.exit(0);
            } catch(IOException e) {
                System.err.println("Erreur lors de l'envoi du message : " + e);
                System.exit(0);
            }
        }

        // Fermeture de la socket
        //System.out.println("\nETAT serveur : off");
        //clavier.close();
        //socket.close();
    }

}