/*
 *  Compilation : javac *.java
 *  Exécution : java Client
 *  JavaDoc : javadoc *.java -d Doc
 */




import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.PrintWriter;
import java.io.File;
import java.io.FileNotFoundException;

import java.net.ServerSocket;
import java.net.Socket;
import java.net.UnknownHostException;
import java.net.InetAddress;

import java.util.Scanner;
import java.util.Random;


/**
 * cette classe représente le Client et sa connexion en TCP au serveur et au Client adverse
 * @author Nathan TONNELLE & Sofiane MEDDOURI
 */
public class Client {

    //public static int portEcoute = -1;

    private static final String nomFichier = "config_client.json";
        //Client
    private static String addressClient = "";
    private static int portClient = -1;
    private static int portClient2 = -1;

        //Client adverse
    private static String addressClientAdversaire = "";
    private static int portClientAdversaire = -1;
    private static int portClientAdversaire2 = -1;

        //Serveur Socket permettant la connexion du Client Adverse
    private static ServerSocket serveurSocket_ConenxionTo_ClientAdversaire = null;
    //private static BufferedReader inputServeur_ConenxionTo_ClientAdversaire = null;
    //private static PrintWriter outputServeur_ConenxionTo_ClientAdversaire = null;

        //Socket permettant la communication avec le Serveur Socket du Client Adverse
    private static Socket socket_CommunicationWith_ClientAdversaire = null;
    private static BufferedReader inputServeur_CommunicationWith_ClientAdversaire = null;
    private static PrintWriter outputServeur_CommunicationWith_ClientAdversaire = null;

        //Serveur
    private static String addressServeur = "";
    private static int portServeur = -1;

        //Serveur communications
    private static Socket socketCommServeur = null;
    private static BufferedReader inputServeur = null;
    private static PrintWriter outputServeur = null;

        //Pseudos Joueurs
    private static String nomJoueur = "";
    private static String nomJoueur1 = "";
    private static String nomJoueur2 = "";

    private static Echange matchEchange = new Echange();
    private static Scanner clavier = new Scanner(System.in);

    //private static BufferedReader input_ServerSocket_ClientAdversaire = null;
    //private static PrintWriter output_ServerSocket_ClientAdversaire = null;
    
    private static final int timeOutTime = 300000; //300000 = 5 min  15000 = 15 sec
    

    public static void main(String[] args) {
        String repRegles = "";
        boolean repRegles_boolean = false;
        String message = "";
        String message2 = "";

        //configation du client
        if(fichierExiste(Client.nomFichier)) charger();
        else {
            System.err.println("[ERREUR CLIENT] Impossible d'ouvrir de fichier de configuration, \nImpossible d'allumer le client.");
            System.exit(0);
        }

        // Création de la socketCommServeur
        Client.socketCommServeur = null;
        try {
            Client.socketCommServeur = new Socket(Client.addressServeur, Client.portServeur, InetAddress.getByName(Client.addressClient), Client.portClient);
            Client.socketCommServeur.setSoTimeout(Client.timeOutTime);
            System.out.println("Client : on" + 
                "\n\tport Ecoute : " + Client.socketCommServeur.getLocalPort() + 
                "\n\tLocal Address, host name" + Client.socketCommServeur.getLocalAddress().getHostAddress()
                
            );
        } catch(UnknownHostException e) {
            System.err.println("Erreur sur l'hôte : " + e);
            System.exit(0);
        } catch(IOException e) {
            System.err.println("Création de la socketCommServeur impossible : " + e);
            System.exit(0);
        }

        // Association d'un flux d'entrée et de sortie
        Client.inputServeur = null;
        Client.outputServeur = null;
        try {
            Client.inputServeur = new BufferedReader(new InputStreamReader(Client.socketCommServeur.getInputStream()));
            Client.outputServeur = new PrintWriter(new BufferedWriter(new OutputStreamWriter(Client.socketCommServeur.getOutputStream())), true);
        } catch(IOException e) {
            System.err.println("Association des flux impossible : " + e);
            System.exit(0);
        }

        System.out.println("Entrez votre nom : ");
        Client.nomJoueur = Client.clavier.nextLine();
        Client.nomJoueur1 = Client.nomJoueur;

        System.out.println("\nBienvenue " + nomJoueur + "! \nVous allez être mis en relation avec un autre Joueur d'ici peu de temps.");
        System.out.println(rulesString());

        do{
            System.out.println("\nVous devez accepter et comprendre les règles pour pouvoir jouer.\n");
            System.out.println("Avez-vous bien compris les règles ? Ecrire : \"oui\" ou \"non\" ou \"o\" ou \"n\" ou \"exit\" (si vous voulez fermer le client).");
            repRegles = Client.clavier.nextLine();
            if(repRegles.equalsIgnoreCase("exit")) break;
            else if(repRegles.equalsIgnoreCase("oui")) repRegles_boolean = true;
            else if(repRegles.equalsIgnoreCase("o")) repRegles_boolean = true;
        }while(repRegles_boolean != true);

        if(repRegles.equalsIgnoreCase("oui") || repRegles.equals("o")){
            
            //envoyer "pseudo" au serveur
            String infosClient = "{\"pseudo\":" + Client.nomJoueur1 + "}";
            envoieMessage_Serveur(infosClient);

            //receptionne "@ipAdversaire:portClientAdversaire:pseudoAdversaire" du serveur
            recupInfo_Adversaire();

            String retourServeur = receptionMessage_Serveur();

            if(retourServeur.equals("Joueur 1 connecté")){     //Client 1
                final int entityJoueur = 1;

                //connexion à l'adversaire
                System.out.println("\nEn attente de connexion au joueur 2\n");
                System.out.println("Infos adversaire :" + 
                    "\n\t@ 1 = " + Client.addressClientAdversaire + ":" + Client.portClientAdversaire +
                    "\n\t@ 2 = " + Client.addressClientAdversaire + ":" + Client.portClientAdversaire2
                );

                createConnexionWith_ClientAdversaire();
                
                System.out.println("\n~~~~\t Connecté \t~~~~\n");
                System.out.println("\nLes joueurs sont : (vous) \"" + Client.nomJoueur1 +  "\" (J1) - (J2) \"" + Client.nomJoueur2 + "\".");
                
                //la suite du programme correspond à ce qui aurait été le jeu si la connexion entre les 2 clients s'était éffectué
                
                
                //jeu
                    //choix du joueur qui va servir
                int randPlayer = nbAleatoire(); //0: J1     1: J2 

                envoieMessage_Adversaire(randPlayer);

                if(randPlayer == 0){
                    boolean resultAttrapC1_boolean = false;
                    boolean resultAttrapC2_boolean = false;
                    //String resultAttrapC1_boolean_String = "";
                    String resultAttrapC2_boolean_String = "";

                    String receptionEchange = "";
                    int repChoixNouvellePostion = 0;
                    int nouvellePosition = 0;
                    boolean checkIfHaveWinner = false;

                    System.out.println("\nLe Joueur 1 commence.");

                    System.out.println(Client.matchEchange.scoreToString());

                    do{
                        //choix du tir
                        int echangeMatch = 0;
                        do{
                            System.out.println("Où voulez-vous tirer ? Ecrire une zone, dans les zones de 1 à 5 \n\t" + emplacementString());
                            echangeMatch = Client.clavier.nextInt();
                        }while(echangeMatch < 1 || echangeMatch > 5);

//System.out.println("\n\nLe joueur 1 souhaite tirer en : " + echangeMatch + " = " + Client.matchEchange.tir_position_ToString(echangeMatch) + "\n\n");
    
                        //construction/envoie de l'échange
                        Client.matchEchange.nouvelEchange(entityJoueur, echangeMatch);
                        Client.matchEchange.construireChaineEnvoie(entityJoueur);
                        envoieMessage_Adversaire(Client.matchEchange.getEchangeString(entityJoueur));

//System.out.println("\n\nLe joueur 1 construit et envoie l'échange : " + Client.matchEchange.getEchangeString(entityJoueur) + "\n\n");

                        afficherMsgAttenteAdv();

                        //reception result attrapé ? de C2
                        resultAttrapC2_boolean_String = receptionMessage_Adversaire();
                        resultAttrapC2_boolean = (resultAttrapC2_boolean_String.equals("true"))? true : false;

//System.out.println("\n\nresultAttrapC2_boolean_String : " + resultAttrapC2_boolean_String + "\n" + "resultAttrapC2_boolean : " + resultAttrapC2_boolean + "\n");

                        if(resultAttrapC2_boolean) System.out.println("\nLe Joueur 2 a réussi à rattraper votre tir !\n");
                        else System.out.println("\nLe Joueur 2 n'a pas réussi à rattraper votre tir, BRAVO !\n");

                        //reception echange de C2
                        receptionEchange = receptionMessage_Adversaire();
//System.out.println("\n\nreceptionEchange de C2 : " + receptionEchange + "\n\n");

                        Client.matchEchange.recharge(entityJoueur, receptionEchange);
                        System.out.println(Client.matchEchange.scoreToString());

                        //si il y a un winner
                        if(Client.matchEchange.scoreGagnant(Client.matchEchange.getScore(1), Client.matchEchange.getScore(2)) == true) checkIfHaveWinner = true;
//System.out.println("\n\n TEST 1 : check If Have Winner = " + checkIfHaveWinner); 
                        if(Client.matchEchange.scoreGagnant(Client.matchEchange.getScore(2), Client.matchEchange.getScore(1)) == true) checkIfHaveWinner = true;
//System.out.println(" TEST 2 : check If Have Winner = " + checkIfHaveWinner + "\n\n"); 
                        if(checkIfHaveWinner) break;

                        afficherMsgAttenteAdv();
                        //si C2 a attrapé 
                        if(resultAttrapC2_boolean){
                            do{
                               

                                //reception echange de C2
                                receptionEchange = receptionMessage_Adversaire();

//System.out.println("\n\nreceptionEchange : " + receptionEchange + "\n\n");

                                Client.matchEchange.recharge(entityJoueur, receptionEchange);
                                System.out.println(Client.matchEchange.scoreToString());

                                //si il y a un winner
                                if(Client.matchEchange.scoreGagnant(Client.matchEchange.getScore(1), Client.matchEchange.getScore(2)) == true) checkIfHaveWinner = true;
//System.out.println("\n\n TEST 1 : check If Have Winner = " + checkIfHaveWinner); 
                                if(Client.matchEchange.scoreGagnant(Client.matchEchange.getScore(2), Client.matchEchange.getScore(1)) == true) checkIfHaveWinner = true;
//System.out.println(" TEST 2 : check If Have Winner = " + checkIfHaveWinner + "\n\n"); 
                                if(checkIfHaveWinner) break;

                                    //choix position + attrapé ?
                                repChoixNouvellePostion = 0;
                                do{
                                    System.out.println("\nVoulez-vous monter (1) , descendre (-1) ou rester a la même position (0) pour essayer d'attraper le tir de votre adversaire ? Ecrire : \"1\" ou \"-1\" ou \"0\"" + 
                                        "\n\tterrain : " + emplacementString() +
                                        "\n\tVous êtes à la position : " + Client.matchEchange.tir_position_ToString(Client.matchEchange.getPosition(entityJoueur)) 
                                        + "(" + Client.matchEchange.getPosition(entityJoueur) + ")."
                                    );
                                    repChoixNouvellePostion = Client.clavier.nextInt();
                                }while(repChoixNouvellePostion < -1 && repChoixNouvellePostion > 1);
//System.out.println("\n\nLe joueur 1 souhaite ête en position : " + (Client.matchEchange.getPosition(entityJoueur) + repChoixNouvellePostion) + " = " + Client.matchEchange.tir_position_ToString(Client.matchEchange.getPosition(entityJoueur) + repChoixNouvellePostion) + "\n\n");

                                nouvellePosition = Client.matchEchange.getPosition(entityJoueur) + repChoixNouvellePostion;
                                Client.matchEchange.setPosition(entityJoueur, nouvellePosition);
                                System.out.println("\n\nVous êtes à la position : " + Client.matchEchange.tir_position_ToString(Client.matchEchange.getPosition(entityJoueur)) + "(" + Client.matchEchange.getPosition(entityJoueur) + ").\n\n");

                                    //envoie si le client-1 a attrapé le tir de client-2
                                resultAttrapC1_boolean = Client.matchEchange.positionTirAdverseDevine(entityJoueur, Client.matchEchange.getPosition(entityJoueur));
                                envoieMessage_Adversaire(resultAttrapC1_boolean);
//System.out.println("\n\nresultAttrapC1_boolean : " + resultAttrapC1_boolean + "\n\n");

                                Client.matchEchange.construireChaineEnvoie(entityJoueur);
                                envoieMessage_Adversaire(Client.matchEchange.getEchangeString(entityJoueur));
//System.out.println("\n\nLe joueur 1 envoie l'echange : " + Client.matchEchange.getEchangeString(entityJoueur) + "\n\n");

                                System.out.println(Client.matchEchange.scoreToString());
                                
                                afficherMsgAttenteAdv();
                                
                                //si il y a un winner
                                if(Client.matchEchange.scoreGagnant(Client.matchEchange.getScore(1), Client.matchEchange.getScore(2)) == true) checkIfHaveWinner = true;
//System.out.println("\n\n TEST 1 : check If Have Winner = " + checkIfHaveWinner); 
                                if(Client.matchEchange.scoreGagnant(Client.matchEchange.getScore(2), Client.matchEchange.getScore(1)) == true) checkIfHaveWinner = true;
//System.out.println(" TEST 2 : check If Have Winner = " + checkIfHaveWinner + "\n\n"); 
                                if(checkIfHaveWinner) break;

                            }while(!resultAttrapC1_boolean);
                        }
                        //si il y a un winner
                        if(Client.matchEchange.scoreGagnant(Client.matchEchange.getScore(1), Client.matchEchange.getScore(2)) == true) checkIfHaveWinner = true;
//System.out.println("\n\n TEST 1 : check If Have Winner = " + checkIfHaveWinner); 
                        if(Client.matchEchange.scoreGagnant(Client.matchEchange.getScore(2), Client.matchEchange.getScore(1)) == true) checkIfHaveWinner = true;
//System.out.println(" TEST 2 : check If Have Winner = " + checkIfHaveWinner + "\n\n"); 
                        if(checkIfHaveWinner) break;
                    }while(Client.matchEchange.scoreGagnant(Client.matchEchange.getScore(1), Client.matchEchange.getScore(2)) != true || Client.matchEchange.scoreGagnant(Client.matchEchange.getScore(2), Client.matchEchange.getScore(1)) != true);
                } 
                else if(randPlayer == 1){
                    boolean resultAttrapC2_boolean = false;
                    boolean resultAttrapC1_boolean = false;
                    String resultAttrapC2_boolean_String = "";
                    //String resultAttrapC1_boolean_String = "";

                    String receptionEchange = "";
                    int repChoixNouvellePostion = 0;
                    int nouvellePosition = 0;
                    boolean checkIfHaveWinner = false;

                    System.out.println("\nLe Joueur 2 commence.");

                    System.out.println(Client.matchEchange.scoreToString());
                    do{
                        afficherMsgAttenteAdv();

                        //reception echange de C2
                        receptionEchange = receptionMessage_Adversaire();
//System.out.println("\n\nreceptionEchange de C2 : " + receptionEchange + "\n\n");

                        Client.matchEchange.recharge(entityJoueur, receptionEchange);
                        System.out.println(Client.matchEchange.scoreToString());

                        //si il y a un winner
                        if(Client.matchEchange.scoreGagnant(Client.matchEchange.getScore(1), Client.matchEchange.getScore(2)) == true) checkIfHaveWinner = true;
//System.out.println("\n\n TEST 1 : check If Have Winner = " + checkIfHaveWinner); 
                        if(Client.matchEchange.scoreGagnant(Client.matchEchange.getScore(2), Client.matchEchange.getScore(1)) == true) checkIfHaveWinner = true;
//System.out.println(" TEST 2 : check If Have Winner = " + checkIfHaveWinner + "\n\n"); 
                        if(checkIfHaveWinner) break;

                        //choix position + attrapé ?
                        repChoixNouvellePostion = 0;
                        do{
                            System.out.println("\nVoulez-vous monter (1) , descendre (-1) ou rester a la même position (0) pour essayer d'attraper le tir de votre adversaire ? Ecrire : \"1\" ou \"-1\" ou \"0\"" + 
                                "\n\tterrain : " + emplacementString() +
                                "\n\tVous êtes à la position : " + Client.matchEchange.tir_position_ToString(Client.matchEchange.getPosition(entityJoueur)) 
                                + "(" + Client.matchEchange.getPosition(entityJoueur) + ")."
                            );
                            repChoixNouvellePostion = Client.clavier.nextInt();
                        }while(repChoixNouvellePostion < -1 || repChoixNouvellePostion > 1);
//System.out.println("\n\nLe joueur 1 souhaite ête en position : " + (Client.matchEchange.getPosition(entityJoueur) + repChoixNouvellePostion) + " = " + Client.matchEchange.tir_position_ToString(Client.matchEchange.getPosition(entityJoueur) + repChoixNouvellePostion) + "\n\n");

                        nouvellePosition = Client.matchEchange.getPosition(entityJoueur) + repChoixNouvellePostion;
                        Client.matchEchange.setPosition(entityJoueur, nouvellePosition);
                        System.out.println("\n\nVous êtes à la position : " + Client.matchEchange.tir_position_ToString(Client.matchEchange.getPosition(entityJoueur)) + "(" + Client.matchEchange.getPosition(entityJoueur) + ").\n\n");

                            //envoie si le client-1 a attrapé le tir de client-2
                        resultAttrapC1_boolean = Client.matchEchange.positionTirAdverseDevine(entityJoueur, Client.matchEchange.getPosition(entityJoueur));
                        envoieMessage_Adversaire(resultAttrapC1_boolean);
//System.out.println("\n\nresultAttrapC1_boolean : " + resultAttrapC1_boolean + "\n\n");

                        Client.matchEchange.construireChaineEnvoie(entityJoueur);
                        envoieMessage_Adversaire(Client.matchEchange.getEchangeString(entityJoueur));
//System.out.println("\n\nLe joueur 1 envoie l'échange suivant : " + Client.matchEchange.getEchangeString(entityJoueur) + "\n\n");

                        System.out.println(Client.matchEchange.scoreToString());

                        //si C1 a attrapé le tir de C2
                        if(resultAttrapC1_boolean){
                            do{
                                //choix du tir
                                int echangeMatch = 0;
                                do{
                                    System.out.println("Où voulez-vous tirer ? Ecrire une zone, dans les zones de 1 à 5 \n\t" + emplacementString());
                                    echangeMatch = Client.clavier.nextInt();
                                }while(echangeMatch < 1 || echangeMatch > 5);

//System.out.println("\n\nLe joueur 1 souhaite tirer en : " + echangeMatch + " = " + Client.matchEchange.tir_position_ToString(echangeMatch) + "\n\n");
            
                                //construction/envoie de l'échange
                                Client.matchEchange.nouvelEchange(entityJoueur, echangeMatch);
                                Client.matchEchange.construireChaineEnvoie(entityJoueur);
                                envoieMessage_Adversaire(Client.matchEchange.getEchangeString(entityJoueur));
//System.out.println("\n\nLe joueur 1 construit et envoie l'échange : " + Client.matchEchange.getEchangeString(entityJoueur) + "\n\n");

                                afficherMsgAttenteAdv();

                                //reception result attrapé ? de C1
                                resultAttrapC2_boolean_String = receptionMessage_Adversaire();
                                resultAttrapC2_boolean = (resultAttrapC2_boolean_String.equals("true"))? true : false;

//System.out.println("\n\nresultAttrapC2_boolean_String : " + resultAttrapC2_boolean_String + "\n" + "resultAttrapC2_boolean : " + resultAttrapC2_boolean + "\n");
                                
                                if(resultAttrapC2_boolean) System.out.println("\nLe Joueur 2 a réussi à rattraper votre tir !\n");
                                else System.out.println("\nLe Joueur 2 n'a pas réussi à rattraper votre tir, BRAVO !\n");

                                //reception echange de C2
                                receptionEchange = receptionMessage_Adversaire();
//System.out.println("\n\nreceptionEchange : " + receptionEchange + "\n\n");

                                Client.matchEchange.recharge(entityJoueur, receptionEchange);
                                System.out.println(Client.matchEchange.scoreToString());

                                //si il y a un winner
                                if(Client.matchEchange.scoreGagnant(Client.matchEchange.getScore(1), Client.matchEchange.getScore(2)) == true) checkIfHaveWinner = true;
//System.out.println("\n\n TEST 1 : check If Have Winner = " + checkIfHaveWinner); 
                                if(Client.matchEchange.scoreGagnant(Client.matchEchange.getScore(2), Client.matchEchange.getScore(1)) == true) checkIfHaveWinner = true;
//System.out.println(" TEST 2 : check If Have Winner = " + checkIfHaveWinner + "\n\n"); 
                                if(checkIfHaveWinner) break;

                            }while(!resultAttrapC2_boolean);
                        }
                        //si il y a un winner
                        if(Client.matchEchange.scoreGagnant(Client.matchEchange.getScore(1), Client.matchEchange.getScore(2)) == true) checkIfHaveWinner = true;
//System.out.println("\n\n TEST 1 : check If Have Winner = " + checkIfHaveWinner); 
                        if(Client.matchEchange.scoreGagnant(Client.matchEchange.getScore(2), Client.matchEchange.getScore(1)) == true) checkIfHaveWinner = true;
//System.out.println(" TEST 2 : check If Have Winner = " + checkIfHaveWinner + "\n\n"); 
                        if(checkIfHaveWinner) break;
                    }while(Client.matchEchange.scoreGagnant(Client.matchEchange.getScore(1), Client.matchEchange.getScore(2)) != true || Client.matchEchange.scoreGagnant(Client.matchEchange.getScore(2), Client.matchEchange.getScore(1)) != true);
                }
                
            }










            
            else if(retourServeur.equals("Joueur 2 connecté")){       //Client 2
                final int entityJoueur = 2;
                
                //connexion au joueur 1
                System.out.println("\nEn attente de connexion au joueur 1\n");
                System.out.println("Infos adversaire :" + 
                    "\n\t@ 1 = " + Client.addressClientAdversaire + ":" + Client.portClientAdversaire +
                    "\n\t@ 2 = " + Client.addressClientAdversaire + ":" + Client.portClientAdversaire2
                );
                createConnexionWith_ClientAdversaire();

                System.out.println("\n~~~~\t Connecté \t~~~~\n");
                System.out.println("\nLes joueurs sont : \"" + Client.nomJoueur1 +  "\" (J1) - (J2) \"" + Client.nomJoueur2 + "\" (vous).");
                
                //la suite du programme correspond à ce qui aurait été le jeu si la connexion entre les 2 clients s'était éffectué
                
                int randPlayer = Integer.parseInt(receptionMessage_Adversaire());

                if(randPlayer == 0){
                    boolean resultAttrapC1_boolean = false;
                    boolean resultAttrapC2_boolean = false;
                    String resultAttrapC1_boolean_String = "";
                    //String resultAttrapC2_boolean_String = "";

                    String receptionEchange = "";
                    int repChoixNouvellePostion = 0;
                    int nouvellePosition = 0;
                    boolean checkIfHaveWinner = false;

                    System.out.println("\nLe Joueur 1 commence.");

                    System.out.println(Client.matchEchange.scoreToString());
                    do{
                        afficherMsgAttenteAdv();

                        //reception echange de C1
                        receptionEchange = receptionMessage_Adversaire();
//System.out.println("\n\nreceptionEchange de C1 : " + receptionEchange + "\n\n");

                        Client.matchEchange.recharge(entityJoueur, receptionEchange);
                        System.out.println(Client.matchEchange.scoreToString());

                        //si il y a un winner
                        if(Client.matchEchange.scoreGagnant(Client.matchEchange.getScore(1), Client.matchEchange.getScore(2)) == true) checkIfHaveWinner = true;
//System.out.println("\n\n TEST 1 : check If Have Winner = " + checkIfHaveWinner); 
                        if(Client.matchEchange.scoreGagnant(Client.matchEchange.getScore(2), Client.matchEchange.getScore(1)) == true) checkIfHaveWinner = true;
//System.out.println(" TEST 2 : check If Have Winner = " + checkIfHaveWinner + "\n\n"); 
                        if(checkIfHaveWinner) break;

                        //choix position + attrapé ?
                        repChoixNouvellePostion = 0;
                        do{
                            System.out.println("\nVoulez-vous monter (1) , descendre (-1) ou rester a la même position (0) pour essayer d'attraper le tir de votre adversaire ? Ecrire : \"1\" ou \"-1\" ou \"0\"" + 
                                "\n\tterrain : " + emplacementString() +
                                "\n\tVous êtes à la position : " + Client.matchEchange.tir_position_ToString(Client.matchEchange.getPosition(entityJoueur)) 
                                + "(" + Client.matchEchange.getPosition(entityJoueur) + ")."
                            );
                            repChoixNouvellePostion = Client.clavier.nextInt();
                        }while(repChoixNouvellePostion < -1 || repChoixNouvellePostion > 1);
//System.out.println("\n\nLe joueur 2 souhaite ête en position : " + (Client.matchEchange.getPosition(entityJoueur) + repChoixNouvellePostion) + " = " + Client.matchEchange.tir_position_ToString(Client.matchEchange.getPosition(entityJoueur) + repChoixNouvellePostion) + "\n\n");

                        nouvellePosition = Client.matchEchange.getPosition(entityJoueur) + repChoixNouvellePostion;
                        Client.matchEchange.setPosition(entityJoueur, nouvellePosition);
                        System.out.println("\n\nVous êtes à la position : " + Client.matchEchange.tir_position_ToString(Client.matchEchange.getPosition(entityJoueur)) + "(" + Client.matchEchange.getPosition(entityJoueur) + ").\n\n");

                            //envoie si le client-2 a attrapé le tir de client-1
                        resultAttrapC2_boolean = Client.matchEchange.positionTirAdverseDevine(entityJoueur, Client.matchEchange.getPosition(entityJoueur));
                        envoieMessage_Adversaire(resultAttrapC2_boolean);
//System.out.println("\n\nresultAttrapC2_boolean : " + resultAttrapC2_boolean + "\n\n");

                        Client.matchEchange.construireChaineEnvoie(entityJoueur);
                        envoieMessage_Adversaire(Client.matchEchange.getEchangeString(entityJoueur));
//System.out.println("\n\nLe joueur 2 envoie l'échange suivant : " + Client.matchEchange.getEchangeString(entityJoueur) + "\n\n");

                        System.out.println(Client.matchEchange.scoreToString());

                        //si C2 a attrapé le tir de C1
                        if(resultAttrapC2_boolean){
                            do{
                                //choix du tir
                                int echangeMatch = 0;
                                do{
                                    System.out.println("Où voulez-vous tirer ? Ecrire une zone, dans les zones de 1 à 5 \n\t" + emplacementString());
                                    echangeMatch = Client.clavier.nextInt();
                                }while(echangeMatch < 1 || echangeMatch > 5);

//System.out.println("\n\nLe joueur 2 souhaite tirer en : " + echangeMatch + " = " + Client.matchEchange.tir_position_ToString(echangeMatch) + "\n\n");
            
                                //construction/envoie de l'échange
                                Client.matchEchange.nouvelEchange(entityJoueur, echangeMatch);
                                Client.matchEchange.construireChaineEnvoie(entityJoueur);
                                envoieMessage_Adversaire(Client.matchEchange.getEchangeString(entityJoueur));
//System.out.println("\n\nLe joueur 2 construit et envoie l'échange : " + Client.matchEchange.getEchangeString(entityJoueur) + "\n\n");

                                afficherMsgAttenteAdv();

                                //reception result attrapé ? de C2
                                resultAttrapC1_boolean_String = receptionMessage_Adversaire();
                                resultAttrapC1_boolean = (resultAttrapC1_boolean_String.equals("true"))? true : false;

//System.out.println("\n\nresultAttrapC1_boolean_String : " + resultAttrapC1_boolean_String + "\n" + "resultAttrapC1_boolean : " + resultAttrapC1_boolean + "\n");
                                
                                if(resultAttrapC1_boolean) System.out.println("\nLe Joueur 1 a réussi à rattraper votre tir !\n");
                                else System.out.println("\nLe Joueur 1 n'a pas réussi à rattraper votre tir, BRAVO !\n");

                                //reception echange de C1
                                receptionEchange = receptionMessage_Adversaire();
//System.out.println("\n\nreceptionEchange : " + receptionEchange + "\n\n");

                                Client.matchEchange.recharge(entityJoueur, receptionEchange);
                                System.out.println(Client.matchEchange.scoreToString());

                                //si il y a un winner
                                if(Client.matchEchange.scoreGagnant(Client.matchEchange.getScore(1), Client.matchEchange.getScore(2)) == true) checkIfHaveWinner = true;
//System.out.println("\n\n TEST 1 : check If Have Winner = " + checkIfHaveWinner); 
                                if(Client.matchEchange.scoreGagnant(Client.matchEchange.getScore(2), Client.matchEchange.getScore(1)) == true) checkIfHaveWinner = true;
//System.out.println(" TEST 2 : check If Have Winner = " + checkIfHaveWinner + "\n\n"); 
                                if(checkIfHaveWinner) break;

                            }while(!resultAttrapC1_boolean);
                        }
                        //si il y a un winner
                        if(Client.matchEchange.scoreGagnant(Client.matchEchange.getScore(1), Client.matchEchange.getScore(2)) == true) checkIfHaveWinner = true;
//System.out.println("\n\n TEST 1 : check If Have Winner = " + checkIfHaveWinner); 
                        if(Client.matchEchange.scoreGagnant(Client.matchEchange.getScore(2), Client.matchEchange.getScore(1)) == true) checkIfHaveWinner = true;
//System.out.println(" TEST 2 : check If Have Winner = " + checkIfHaveWinner + "\n\n"); 
                        if(checkIfHaveWinner) break;
                    }while(Client.matchEchange.scoreGagnant(Client.matchEchange.getScore(1), Client.matchEchange.getScore(2)) != true || Client.matchEchange.scoreGagnant(Client.matchEchange.getScore(2), Client.matchEchange.getScore(1)) != true);
                } 
                else if(randPlayer == 1){
                    boolean resultAttrapC2_boolean = false;
                    boolean resultAttrapC1_boolean = false;
                    //String resultAttrapC2_boolean_String = "";
                    String resultAttrapC1_boolean_String = "";

                    String receptionEchange = "";
                    int repChoixNouvellePostion = 0;
                    int nouvellePosition = 0;
                    boolean checkIfHaveWinner = false;

                    System.out.println("\nLe Joueur 2 commence.");

                    System.out.println(Client.matchEchange.scoreToString());

                    do{
                        //choix du tir
                        int echangeMatch = 0;
                        do{
                            System.out.println("Où voulez-vous tirer ? Ecrire une zone, dans les zones de 1 à 5 \n\t" + emplacementString());
                            echangeMatch = Client.clavier.nextInt();
                        }while(echangeMatch < 1 || echangeMatch > 5);

//System.out.println("\n\nLe joueur 2 souhaite tirer en : " + echangeMatch + " = " + Client.matchEchange.tir_position_ToString(echangeMatch) + "\n\n");
    
                        //construction/envoie de l'échange
                        Client.matchEchange.nouvelEchange(entityJoueur, echangeMatch);
                        Client.matchEchange.construireChaineEnvoie(entityJoueur);
                        envoieMessage_Adversaire(Client.matchEchange.getEchangeString(entityJoueur));
//System.out.println("\n\nLe joueur 2 construit et envoie l'échange : " + Client.matchEchange.getEchangeString(entityJoueur) + "\n\n");

                        afficherMsgAttenteAdv();

                        //reception result attrapé ? de C1
                        resultAttrapC1_boolean_String = receptionMessage_Adversaire();
                        resultAttrapC1_boolean = (resultAttrapC1_boolean_String.equals("true"))? true : false;

//System.out.println("\n\nresultAttrapC1_boolean_String : " + resultAttrapC1_boolean_String + "\n" + "resultAttrapC1_boolean : " + resultAttrapC1_boolean + "\n");

                        if(resultAttrapC1_boolean) System.out.println("\nLe Joueur 1 a réussi à rattraper votre tir !\n");
                        else System.out.println("\nLe Joueur 1 n'a pas réussi à rattraper votre tir, BRAVO !\n");

                        //reception echange de C1
                        receptionEchange = receptionMessage_Adversaire();
//System.out.println("\n\nreceptionEchange de C1 : " + receptionEchange + "\n\n");

                        Client.matchEchange.recharge(entityJoueur, receptionEchange);
                        System.out.println(Client.matchEchange.scoreToString());

                        //si il y a un winner
                        if(Client.matchEchange.scoreGagnant(Client.matchEchange.getScore(1), Client.matchEchange.getScore(2)) == true) checkIfHaveWinner = true;
//System.out.println("\n\n TEST 1 : check If Have Winner = " + checkIfHaveWinner); 
                        if(Client.matchEchange.scoreGagnant(Client.matchEchange.getScore(2), Client.matchEchange.getScore(1)) == true) checkIfHaveWinner = true;
//System.out.println(" TEST 2 : check If Have Winner = " + checkIfHaveWinner + "\n\n"); 
                        if(checkIfHaveWinner) break;

                        //si C1 a attrapé 
                        if(resultAttrapC1_boolean){
                            do{
                                afficherMsgAttenteAdv();

                                //reception echange de C1
                                receptionEchange = receptionMessage_Adversaire();
//System.out.println("\n\nreceptionEchange : " + receptionEchange + "\n\n");

                                Client.matchEchange.recharge(entityJoueur, receptionEchange);
                                System.out.println(Client.matchEchange.scoreToString());

                                //si il y a un winner
                                if(Client.matchEchange.scoreGagnant(Client.matchEchange.getScore(1), Client.matchEchange.getScore(2)) == true) checkIfHaveWinner = true;
//System.out.println("\n\n TEST 1 : check If Have Winner = " + checkIfHaveWinner); 
                                if(Client.matchEchange.scoreGagnant(Client.matchEchange.getScore(2), Client.matchEchange.getScore(1)) == true) checkIfHaveWinner = true;
//System.out.println(" TEST 2 : check If Have Winner = " + checkIfHaveWinner + "\n\n"); 
                                if(checkIfHaveWinner) break;

                                    //choix position + attrapé ?
                                repChoixNouvellePostion = 0;
                                do{
                                    System.out.println("\nVoulez-vous monter (1) , descendre (-1) ou rester a la même position (0) pour essayer d'attraper le tir de votre adversaire ? Ecrire : \"1\" ou \"-1\" ou \"0\"" + 
                                        "\n\tterrain : " + emplacementString() +
                                        "\n\tVous êtes à la position : " + Client.matchEchange.tir_position_ToString(Client.matchEchange.getPosition(entityJoueur)) 
                                        + "(" + Client.matchEchange.getPosition(entityJoueur) + ")."
                                    );
                                    repChoixNouvellePostion = Client.clavier.nextInt();
                                }while(repChoixNouvellePostion < -1 && repChoixNouvellePostion > 1);
//System.out.println("\n\nLe joueur 2 souhaite ête en position : " + (Client.matchEchange.getPosition(entityJoueur) + repChoixNouvellePostion) + " = " + Client.matchEchange.tir_position_ToString(Client.matchEchange.getPosition(entityJoueur) + repChoixNouvellePostion) + "\n\n");

                                nouvellePosition = Client.matchEchange.getPosition(entityJoueur) + repChoixNouvellePostion;
                                Client.matchEchange.setPosition(entityJoueur, nouvellePosition);
                                System.out.println("\n\nVous êtes à la position : " + Client.matchEchange.tir_position_ToString(Client.matchEchange.getPosition(entityJoueur)) + "(" + Client.matchEchange.getPosition(entityJoueur) + ").\n\n");

                                    //envoie si le client-2 a attrapé le tir de client-1
                                resultAttrapC2_boolean = Client.matchEchange.positionTirAdverseDevine(entityJoueur, Client.matchEchange.getPosition(entityJoueur));
                                envoieMessage_Adversaire(resultAttrapC2_boolean);
//System.out.println("\n\nresultAttrapC2_boolean : " + resultAttrapC2_boolean + "\n\n");

                                Client.matchEchange.construireChaineEnvoie(entityJoueur);
                                envoieMessage_Adversaire(Client.matchEchange.getEchangeString(entityJoueur));
//System.out.println("\n\nLe joueur 2 envoie l'echange : " + Client.matchEchange.getEchangeString(entityJoueur) + "\n\n");

                                System.out.println(Client.matchEchange.scoreToString());
                                
                                //si il y a un winner
                                if(Client.matchEchange.scoreGagnant(Client.matchEchange.getScore(1), Client.matchEchange.getScore(2)) == true) checkIfHaveWinner = true;
//System.out.println("\n\n TEST 1 : check If Have Winner = " + checkIfHaveWinner); 
                                if(Client.matchEchange.scoreGagnant(Client.matchEchange.getScore(2), Client.matchEchange.getScore(1)) == true) checkIfHaveWinner = true;
//System.out.println(" TEST 2 : check If Have Winner = " + checkIfHaveWinner + "\n\n"); 
                                if(checkIfHaveWinner) break;

                            }while(!resultAttrapC2_boolean);
                        }
                        //si il y a un winner
                        if(Client.matchEchange.scoreGagnant(Client.matchEchange.getScore(1), Client.matchEchange.getScore(2)) == true) checkIfHaveWinner = true;
//System.out.println("\n\n TEST 1 : check If Have Winner = " + checkIfHaveWinner); 
                        if(Client.matchEchange.scoreGagnant(Client.matchEchange.getScore(2), Client.matchEchange.getScore(1)) == true) checkIfHaveWinner = true;
//System.out.println(" TEST 2 : check If Have Winner = " + checkIfHaveWinner + "\n\n"); 
                        if(checkIfHaveWinner) break;
                    }while(Client.matchEchange.scoreGagnant(Client.matchEchange.getScore(1), Client.matchEchange.getScore(2)) != true || Client.matchEchange.scoreGagnant(Client.matchEchange.getScore(2), Client.matchEchange.getScore(1)) != true);
                } 
                
            }
        }










        else{
            System.out.println("\nLe Client s'éteint.\n Au revoir " + nomJoueur + ".");
        }

        String joueurGagnantString = "";
        if(Client.matchEchange.scoreGagnant(Client.matchEchange.getScore(1), Client.matchEchange.getScore(2))){
            joueurGagnantString = "\"" + nomJoueur1 + "\" (J1)";
        } 
        else if(Client.matchEchange.scoreGagnant(Client.matchEchange.getScore(2), Client.matchEchange.getScore(1))){
            joueurGagnantString = "\"" + nomJoueur2 + "\" (J2)";
        } 
        System.out.println("\n\t Nous avons un GAGNANT !");
        System.out.println("\tC'est le Joueur : " + joueurGagnantString + " BRAVO à lui !!");
        System.out.println(Client.matchEchange.afficherScoreFinal().replace("(J1)", "\"" + nomJoueur1 + "\" (J1)").replace("(J2)", "(J2)\"" + nomJoueur2 + "\""));
        

            // Fermeture des flux et de la socket
            try {
                System.out.println("Fermeture du Client :");
                Client.clavier.close();

                Client.socketCommServeur.close();
                Client.inputServeur.close();
                Client.outputServeur.close();

                Client.socket_CommunicationWith_ClientAdversaire.close();
                Client.serveurSocket_ConenxionTo_ClientAdversaire.close();
                Client.inputServeur_CommunicationWith_ClientAdversaire.close();
                Client.outputServeur_CommunicationWith_ClientAdversaire.close();

                System.out.println("Client : off");
            } catch(IOException e) {
                System.err.println("Erreur lors de la fermeture des flux et de la socket : " + e);
                System.exit(0);
            }
    }

    /**
     * vérifie le format de la chaine de caractère transmise, si c'est du JSON, alors c'est correcte, sinon non
     * @param chaineJson chaine à vérifier
     * @return retourne le résultat de la vérification
     */
    public static boolean verifChaineJson(String chaineJson){
        boolean verif = false;
        if(chaineJson.contains("{") && chaineJson.contains("}")) verif = true;
        return verif;
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
            File f = new File(Client.nomFichier);
            Scanner sc = new Scanner(f);

            while (sc.hasNext()) {
                String line = sc.nextLine();
                allFichierCongif += line;
            }
            allFichierCongif = allFichierCongif.replace("\"", "").replace(" ", "").replace("{", "").replace("}", "");
            String[] totalStringSplit = allFichierCongif.split(",");

            String[] addressServeurTotal = totalStringSplit[0].split(":");
            String[] portServeurTotal = totalStringSplit[1].split(":");
            
            String[] addressClientTotal = totalStringSplit[2].split(":");
            String[] portClientTotal = totalStringSplit[3].split(":");

                //serveur identifiants
            Client.addressServeur = addressServeurTotal[1];
            Client.portServeur = Integer.parseInt(portServeurTotal[1]);
            System.out.println("Serveur : " + Client.addressServeur + ":" + Client.portServeur);

                //client identifiants
            Client.addressClient = addressClientTotal[1];
            Client.portClient = Integer.parseInt(portClientTotal[1]);
            Client.portClient2 = Client.portClient +10;
            System.out.println("Client : " + Client.addressClient + ":" + Client.portClient);

            sc.close();
        } catch (FileNotFoundException e) {
            System.out.println("Echec de l'ouverture et de la récupération des données des fichiers.\n");
            e.printStackTrace();
        }
    }
    
    /**
     * retourne un aléatoire
     * @return le nombre alétoire
     */
    public static int nbAleatoire(){
        Random rand = new Random(); 
        return  rand.nextInt(2);
    }

    /**
     * Retourne une chaine de caracteres contenant les regles de la partie
     * @return chaine de caracteres
     */
    public static String rulesString(){
        return (
            "\n" + 
            "\n~~~~\t Les Règles du Tennis : \t~~~~\n" + 
            "\n" +

            "\n A: COMPOSITION du plateau : " + 
            "\n\t 1. Le terrain de Tennis est composé de 5 cases." +
            "\n\t    (1)gauche / (2)milieu-gauche / (3)milieu / (4)milieu-droite / (5)droite" + 
            "\n" +

            "\n B: MOUVEMENTS possibles : " +
            "\n\t 1. Vous pouvez vous déplacer sur les 5 case du terrain, cependant, vous ne pouvez vous déplacer que d'une case à la fois." +
            "\n\t 2. Vous aurez le choix de tirer dans l'une des 5 cases de votre adversaire." + 
            "\n" +

            "\n C: DEROULEMENT d'une partie : " +
            "\n\t 1. La partie commence par le choix aléatoire du joueur qui servira en premier." +
            "\n\t 2. Ensuite ce joueur choisi un endroit où tirer, et tire." +
            "\n\t 3. Puis ca sera à son adversaire de choisir s'il désir bouger de +/- 1 case ou rester à la meme place. " +
            "\n\t 4. Soit l'adversaire arrive à attraper la balle et dans ce cas, il peut la relancer où il le souhaite." + 
            "\n\t    Soit il n'y arrive pas et dans ce cas le joueur gagne un point et c'est au joueur de relancer." +
            "\n" +

            "\n C: FIN d'une partie : " +
            "\n\t 1. La partie est fini lorsque un des 2 joueurs aie atteind le score limite (5 par défaut) et qu'il aie au moins 2 points de plus que sont adversaire." +
            "\n" +

            "\n" +
            "\n~~~~\t    Fin du Règlement    \t~~~~\n" + 
            "\n"
        );
    }

    /**
     * retourne String decrivant les emplacement possibles
     * @return chaine de caractere decrivant les emplacement possibles
     */
    public static String emplacementString(){
        return "(1)gauche / (2)milieu-gauche / (3)milieu / (4)milieu-droite / (5)droite";
    }

    /**
     * affiche un message d'attente : "(En attente du joueur adverse...)"
     */
    public static void afficherMsgAttenteAdv(){
        System.out.println("\n\n(En attente du joueur adverse...)\n\n");
    }

    /**
     * envoie les packets
     * @param messageEnvoie le message a envoyer
     */
    public static void envoieMessage_Serveur(String messageEnvoie){
        Client.outputServeur.println(messageEnvoie);
    }
    /**
     * envoie les packets
     * @param messageEnvoie le message a envoyer
     */
    public static void envoieMessage_Serveur(int messageEnvoie){
        Client.outputServeur.println(messageEnvoie);
    }
    /**
     * envoie les packets
     * @param messageEnvoie le message a envoyer
     */
    public static void envoieMessage_Serveur(boolean messageEnvoie){
        Client.outputServeur.println(messageEnvoie);
    }

    /**
     * receptionne les packets
     * @return la chaine de caractere recu.
     */
    public static String receptionMessage_Serveur(){
        String message = "";

        try{
            message = Client.inputServeur.readLine();
        }catch(IOException e){
            System.err.println("Erreur lors de la lecture : " + e);
            System.exit(0);
        }
        System.out.println("[SERVEUR] Lu : " + message);

        return message;
    }

    /**
     * envoie les packets
     * @param messageEnvoie le message a envoyer
     */
    public static void envoieMessage_Adversaire(String messageEnvoie){
        Client.outputServeur_CommunicationWith_ClientAdversaire.println(messageEnvoie);
    }
    /**
     * envoie les packets
     * @param messageEnvoie le message a envoyer
     */
    public static void envoieMessage_Adversaire(int messageEnvoie){
        Client.outputServeur_CommunicationWith_ClientAdversaire.println(messageEnvoie);
    }
    /**
     * envoie les packets
     * @param messageEnvoie le message a envoyer
     */
    public static void envoieMessage_Adversaire(boolean messageEnvoie){
        Client.outputServeur_CommunicationWith_ClientAdversaire.println(messageEnvoie);
    }

    /**
     * receptionne les packets
     * @return la chaine de caractere recu.
     */
    public static String receptionMessage_Adversaire(){
        String message = "";

        try{
            message = Client.inputServeur_CommunicationWith_ClientAdversaire.readLine();
        }catch(IOException e){
            System.err.println("Erreur lors de la lecture : " + e);
            System.exit(0);
        }
        System.out.println("[SERVEUR] Lu : " + message);

        return message;
    }
    
    /**
     * récupération des informations du client adverse
     */
    public static void recupInfo_Adversaire(){
        String[] infosClientAdverse = receptionMessage_Serveur().replace("{", "").replace("}", "").replace("\"", "").split(",");
        if(infosClientAdverse[0].split(":")[0].equals("address")) Client.addressClientAdversaire = infosClientAdverse[0].split(":")[1];
        if(infosClientAdverse[1].split(":")[0].equals("port")){
            Client.portClientAdversaire = Integer.parseInt(infosClientAdverse[1].split(":")[1]);
            Client.portClientAdversaire2 = Client.portClientAdversaire +10;
        }
        if(infosClientAdverse[2].split(":")[0].equals("pseudo")) Client.nomJoueur2 = infosClientAdverse[2].split(":")[1];
        
    }

    /**
     * créé une connexion avec le client adverse
     */
    public static void createConnexionWith_ClientAdversaire(){
        //close connexions to serveur
        try {
            Client.socketCommServeur.close();
            Client.inputServeur.close();
            Client.outputServeur.close();
            System.out.println("\n\t[CLIENT] fermeture de la communication avec le serveur\n");
        } catch(IOException e) {
            System.err.println("Erreur lors de la fermeture des flux et de la socket de communication avec le serveur : " + e);
            System.exit(0);
        }
        

        //create serveur socket                 accept connection
        try {
            Client.serveurSocket_ConenxionTo_ClientAdversaire = 
                new ServerSocket(Client.portClient2, 50, InetAddress.getByName(Client.addressClient));
            System.out.println("\n\t[CLIENT] création du Serveur Socket\n");
        } catch (UnknownHostException e) {
            System.err.println("[CLIENT] Erreur lors de la création de l'inetAddress pour la création du serveurSocket : " + e);
            //System.exit(0);
        } catch (IOException e){
            System.err.println("[CLIENT] Erreur lors de la création du serveurSocket : " + e);
            //System.exit(0);
        }

        System.out.println("\n\t[CLIENT] envoie d'un message pour la connexion\n");
        envoieMessage_Adversaire("test");
        
        //create socket                         traitement input/output
        try{
            Client.socket_CommunicationWith_ClientAdversaire = Client.serveurSocket_ConenxionTo_ClientAdversaire.accept();
            System.out.println("\n\t[CLIENT] Création de la Socket de communication\n");
        } catch (IOException e){
            System.err.println("[CLIENT] impossible d'accepter la connection au serveurSocket : " + e);
            //System.exit(0);
        }
        
        //create Buffers input/output socket
        try {
            Client.inputServeur_CommunicationWith_ClientAdversaire = 
                new BufferedReader(
                    new InputStreamReader(
                        Client.socket_CommunicationWith_ClientAdversaire.getInputStream()
                    )
                );
            Client.outputServeur_CommunicationWith_ClientAdversaire = 
                new PrintWriter(
                    new BufferedWriter(
                        new OutputStreamWriter(
                            Client.socket_CommunicationWith_ClientAdversaire.getOutputStream()
                        )
                    )
                );
            System.out.println("\n\t[CLIENT] Création des input/output de communication\n");
        } catch (Exception e) {
            System.err.println("[CLIENT] Impossible d'ouvrir les flux input/output : " + e);
            //System.exit(0);
        }
    }
}