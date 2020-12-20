/*
 * comilation : javac *.java
 * execution serveur : java Serveur
 * generation javadoc : javadoc *.java -d Doc
 */



import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;

import java.net.DatagramSocket;
import java.net.DatagramPacket;
import java.net.SocketException;
import java.net.InetAddress;
import java.net.InetSocketAddress;
import java.net.Socket;
import java.net.UnknownHostException;

import java.util.Scanner;
/**
 * cette classe représente le serveur qui permet de lier 2 clients ensemble pour faire une partie de tennis, par exemple
 * @author Nathan TONNELLE & Sofiane MEDDOURI
 */
public class Serveur {

    public static int portEcoute = 9876;
    public static int portEnvoie = -1;
    public static String addressEnvoie = "";

    private static final String nomFichier = "config_serveur.json";
    private static String addressServeur = "";
    private static int portServeur = -1;

    public static void main(String[] args) {
        Scanner clavier = new Scanner(System.in);
        String receptionClientMsg = "";
        String portClient1 = "";
        String portClient2 = "";
        String addressClient1 = "";
        String addressClient2 = "";
        String portOk = "ok";
        int cptClient = 1;

        //configation du serveur
        if(fichierExiste(Serveur.nomFichier)) charger();
        else {
            System.err.println("[ERREUR SERVEUR] Impossible d'ouvrir de fichier de configuration, \nImpossible d'allumer le serveur.");
            System.exit(0);
        }

        // Création de la socket
        DatagramSocket socket = null;
        try {
            socket = new DatagramSocket(Serveur.portServeur, InetAddress.getByName(Serveur.addressServeur));
            System.out.println("\nETAT serveur : on " + 
                "\n\t\tport Ecoute : " + socket.getLocalPort() + 
                "\n\t\t@ip : " + socket.getLocalAddress().toString().replace("/","")
            );
        } catch(SocketException e) {
            System.err.println("Erreur lors de la création de la socket : " + e);
            System.exit(0);
        } catch(UnknownHostException e){
            System.err.println("Erreur lors de la création de la socket : " + e);
            System.exit(0);
        }


        while(true){
            receptionClientMsg = "";
            portClient1 = "";
            portClient2 = "";
            addressClient1 = "";
            addressClient2 = "";

            // Lecture du message du Client-1
            byte[] tampon = new byte[1024];
            DatagramPacket msg = new DatagramPacket(tampon, tampon.length);
            try {
                socket.receive(msg);
                receptionClientMsg = new String(msg.getData(), 0, msg.getLength());

                addressClient1 = receptionClientMsg.split(":")[0].replace("/", "");
                portClient1 = receptionClientMsg.split(":")[1];
                System.out.println("Client " + cptClient + " : " + "\n\t @ip : " + addressClient1 + "\n\t port : " + portClient1);

                Serveur.portEnvoie = Integer.parseInt(portClient1);

                cptClient ++;
            } catch(IOException e) {
                System.err.println("Erreur lors de la réception du message : " + e);
                System.exit(0);
            }

            // Envoi du message Serveur d'enregistrement à Client-1
            msg = null;
            try {
                InetAddress adresse = InetAddress.getByName(addressClient1);
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

            receptionClientMsg = "";

            // Lecture du message du Client-2
            byte[] tamponClient2 = new byte[1024];
            DatagramPacket msgClient2 = new DatagramPacket(tamponClient2, tamponClient2.length);
            try {
                socket.receive(msgClient2);
                receptionClientMsg = new String(msgClient2.getData(), 0, msgClient2.getLength());

                addressClient2 = receptionClientMsg.split(":")[0].replace("/", "");
                portClient2 = receptionClientMsg.split(":")[1];
                System.out.println("Client " + cptClient + " : " + "\n\t @ip : " + addressClient2 + "\n\t port : " + portClient2);

                Serveur.portEnvoie = Integer.parseInt(portClient2);

                cptClient ++;
            } catch(IOException e) {
                System.err.println("Erreur lors de la réception du message : " + e);
                System.exit(0);
            }

            // Envoi du port Client-1 à Client-2
            msgClient2 = null;
            try {
                InetAddress adresseClient2 = InetAddress.getByName(addressClient2);
                byte[] tampon2Client2 = (addressClient1 + ":" + portClient1).getBytes();
                msgClient2 = new DatagramPacket(tampon2Client2, tampon2Client2.length, adresseClient2, portEnvoie);   
                socket.send(msgClient2);         
            } catch(UnknownHostException e) {
                System.err.println("Erreur lors de la création du message : " + e);
                System.exit(0);
            } catch(IOException e) {
                System.err.println("Erreur lors de l'envoi du message : " + e);
                System.exit(0);
            }

            System.out.println("\nPartie en cours : Client " + (cptClient-2) + " VS Client " + (cptClient-1) + "\n");
        }

        // Fermeture de la socket
        //System.out.println("\nETAT serveur : off");
        //clavier.close();
        //socket.close();
    }

    /**
    * Indique si un fichier existe.
    * @param nomFichier le nom du fichier
    * @return 'true' s'il existe
    */
    public static boolean fichierExiste(String nomFichier) {
        File f = new File(nomFichier);
        return f.exists();       
    }

    /**
    * Charge un fichier de configuration en mémoire.
    */
    private static void charger() {
        String allFichierCongif = "";
        // Ouverture du fichier
        try {
            File f = new File(Serveur.nomFichier);
            Scanner sc = new Scanner(f);

            while (sc.hasNext()) {
                String line = sc.nextLine();
                allFichierCongif += line;
            }
            allFichierCongif = allFichierCongif.replace("\"", "").replace(" ", "").replace("{", "").replace("}", "");
            String[] totalStringSplit = allFichierCongif.split(",");
            String[] addressServeurTotal = totalStringSplit[0].split(":");
            String[] portServeurTotal = totalStringSplit[1].split(":");
            Serveur.addressServeur = addressServeurTotal[1];
            Serveur.portServeur = Integer.parseInt(portServeurTotal[1]);

            sc.close();
        } catch (FileNotFoundException e) {
            System.out.println("Echec de l'ouverture et de la récupération des données des fichiers.\n");
            e.printStackTrace();
        }
    }
}