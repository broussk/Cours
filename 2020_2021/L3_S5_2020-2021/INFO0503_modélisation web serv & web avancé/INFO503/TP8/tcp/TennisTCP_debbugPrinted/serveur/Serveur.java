/*
 *  Compilation : javac *.java
 *  Exécution : java Serveur
 *  JavaDoc : javadoc *.java -d Doc
 */




import java.io.IOException;
import java.io.File;
import java.io.FileNotFoundException;

import java.net.ServerSocket;
import java.net.Socket;
import java.net.InetAddress;

import java.util.Scanner;

/**
 * Cette classe représente le serveur permettant d'acceuillir 2 Client et les mettant en relation via un thread
 * Ces 2 Clients, une fois mis en relation, peuvent jouer au Tennis l'un contre l'autre
 * @author Nathan TONNELLE & Sofiane MEDDOURI
 */
public class Serveur {

    //public static int portEcoute = 5101;
    public static int portEcoute = 9876;
    public static int portEnvoie = -1;
    public static String addressEnvoie = "";

    public static final String nomFichier = "config_serveur.json";
    public static String addressServeur = "";
    public static int portServeur = -1;
    public static ServerSocket socketServeur = null;

    public static void main(String[] args) {
        //configation du serveur
        if(fichierExiste(Serveur.nomFichier)) charger();
        else {
            System.err.println("[ERREUR SERVEUR] Impossible d'ouvrir de fichier de configuration, \nImpossible d'allumer le serveur.");
            System.exit(0);
        }

        //création de la socket serveur
        socketServeur = null;
        try{
            Serveur.socketServeur = new ServerSocket(portServeur, 50, InetAddress.getByName(Serveur.addressServeur));
            System.out.println("Serveur : on\n\tport Ecoute : " + Serveur.portServeur);
        } catch(IOException e){
            System.err.println("Création de la socket impossible : " + e);
            System.exit(0);
        }
        System.out.println("[SERVEUR] Serveur : " 
            + "\n\t@ip Serveur: " + Serveur.socketServeur.getInetAddress().getHostAddress()
            + "\n\tlocal port (Ecoute) : " + Serveur.socketServeur.getLocalPort()
        );

        int i = 1;
        // Attente des connexions des clients
        try {
            Socket socketClient1;
            Socket socketClient2;
            //while(i <= 5) {
            while(true){
                socketClient1 = socketServeur.accept();
                System.out.println("[SERVEUR] Client-" + i + " : "
                    + "\n\t@ip Client : " + socketClient1.getInetAddress().getHostAddress()
                    + "\n\tlocal port (Ecriture) : " + socketClient1.getLocalPort()
                    + "\n\tport (connecté au serveur avec) : " + socketClient1.getPort()
                    + "\n\ten attente ..."
                );
                i++;
                socketClient2 = socketServeur.accept();
                System.out.println("[SERVEUR] Client-" + i + " : "
                    + "\n\t@ip Client : " + socketClient2.getInetAddress().getHostAddress()
                    + "\n\tlocal port (Ecriture) : " + socketClient2.getLocalPort()
                    + "\n\tport (connecté au serveur avec) : " + socketClient2.getPort()
                    + "\n\ten attente ..."
                );
                if(i%2 == 0){
                    Thread_serv t = new Thread_serv(socketClient1, socketClient2);
                    t.start();
                }
                i++;
            }
        } catch(IOException e) {
            System.err.println("Erreur lors de l'attente d'une connexion : " + e);
            System.exit(0);
        }

        //femeture serveur
        try{
            Serveur.socketServeur.close();
            System.out.println("Serveur : off");
        } catch (IOException e) {
            System.err.println("Erreur lors de la fermeture de la socket : " + e);
            System.exit(0);
        }
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