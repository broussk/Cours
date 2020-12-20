import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.PrintWriter;

import java.net.Socket;

import java.util.Random;

/**
 * Se programme est le Thread qui est démarré par le serveur pour envoier les éléments de connexion des clients aux clients adverses
 * @author Nathan TONNELLE & Sofiane MEDDOURI
 */
public class Thread_serv extends Thread {

    private static BufferedReader inputClient1;
    private static PrintWriter outputClient1;
    private Socket socketClient1;
    private static BufferedReader inputClient2;
    private static PrintWriter outputClient2;
    private Socket socketClient2;

    public Thread_serv(Socket socketClient1, Socket socketClient2) {
        this.socketClient1 = socketClient1;
        this.socketClient2 = socketClient2;

        // Association d'un flux d'entrée et de sortie
        try {
            inputClient1 = new BufferedReader(new InputStreamReader(socketClient1.getInputStream()));
            outputClient1 = new PrintWriter(new BufferedWriter(new OutputStreamWriter(socketClient1.getOutputStream())), true);
            inputClient2 = new BufferedReader(new InputStreamReader(socketClient2.getInputStream()));
            outputClient2 = new PrintWriter(new BufferedWriter(new OutputStreamWriter(socketClient2.getOutputStream())), true);
        } catch(IOException e) {
            System.err.println("Association des flux impossible : " + e);
            System.exit(0);
        }
    }

    @Override
    public void run() {
        String pseudoClient1 = receptionMessageClient1().replace("{", "").replace("}", "").split(":")[1];
        System.out.println("pseudoClient1 : " + pseudoClient1);
        String pseudoClient2 = receptionMessageClient2().replace("{", "").replace("}", "").split(":")[1];
        System.out.println("pseudoClient2 : " + pseudoClient2);

        String infosClient1 = "{\"address\":" + socketClient1.getInetAddress().getHostAddress() + ",\"port\":" + socketClient1.getPort() + ",\"pseudo\":" + pseudoClient1 + "}";
        String infosClient2 = "{\"address\":" + socketClient2.getInetAddress().getHostAddress() + ",\"port\":" + socketClient2.getPort() + ",\"pseudo\":" + pseudoClient2 + "}";

        envoieMessageClient1(infosClient2);
        envoieMessageClient2(infosClient1);

        envoieMessageClient1("Joueur 1 connecté");
        envoieMessageClient2("Joueur 2 connecté");

        // Fermeture des flux et des sockets
        try {
            Thread_serv.inputClient1.close();
            Thread_serv.inputClient2.close();
            Thread_serv.outputClient1.close();
            Thread_serv.outputClient2.close();
            socketClient1.close();
            socketClient2.close();
        } catch(IOException e) {
            System.err.println("Erreur lors de la fermeture des flux et des sockets : " + e);
            System.exit(0);
        }
    }

    /**
     * envoie les packets
     * @param messageEnvoie le message a envoyer
     */
    public static void envoieMessageClient1(String messageEnvoie){
        Thread_serv.outputClient1.println(messageEnvoie);
    }
    /**
     * envoie les packets
     * @param messageEnvoie le message a envoyer
     */
    public static void envoieMessageClient1(int messageEnvoie){
        Thread_serv.outputClient1.println(messageEnvoie);
    }
    /**
     * envoie les packets
     * @param messageEnvoie le message a envoyer
     */
    public static void envoieMessageClient1(boolean messageEnvoie){
        Thread_serv.outputClient1.println(messageEnvoie);
    }

    /**
     * receptionne les packets
     * @return la chaine de caractere recu.
     */
    public static String receptionMessageClient1(){
        String message = "";

        try{
            message = Thread_serv.inputClient1.readLine();
        } catch(IOException e){
            System.err.println("Erreur lors de la lecture : " + e);
            System.exit(0);
        }
        System.out.println("[CLIENT] Lu : " + message);

        return message;
    }

    /**
     * envoie les packets
     * @param messageEnvoie le message a envoyer
     */
    public static void envoieMessageClient2(String messageEnvoie){
        Thread_serv.outputClient2.println(messageEnvoie);
    }
    /**
     * envoie les packets
     * @param messageEnvoie le message a envoyer
     */
    public static void envoieMessageClient2(int messageEnvoie){
        Thread_serv.outputClient2.println(messageEnvoie);
    }
    /**
     * envoie les packets
     * @param messageEnvoie le message a envoyer
     */
    public static void envoieMessageClient2(boolean messageEnvoie){
        Thread_serv.outputClient2.println(messageEnvoie);
    }

    /**
     * receptionne les packets
     * @return la chaine de caractere recu.
     */
    public static String receptionMessageClient2(){
        String message = "";

        try{
            message = Thread_serv.inputClient2.readLine();
        } catch(IOException e){
            System.err.println("Erreur lors de la lecture : " + e);
            System.exit(0);
        }
        System.out.println("[CLIENT] Lu : " + message);

        return message;
    }
}