/*
 * comilation : javac *.java
 * execution client : java Client
 * generation javadoc : javadoc *.java -d Doc
 */



import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;

import java.net.DatagramSocket;
import java.net.DatagramPacket;
import java.net.SocketException;
import java.net.SocketTimeoutException;
import java.net.InetAddress;
import java.net.InetSocketAddress;
import java.net.SocketAddress;
import java.net.UnknownHostException;

import java.util.Scanner;
import java.util.concurrent.TimeoutException;
import java.util.Random;

public class Client {

    public static int portEcoute = -1;

    private static final String nomFichier = "config_client.json";
    private static String addressClient = "";
    private static int portClient = -1;
    private static String addressServeur = "";
    private static int portServeur = -1;
    private static String addressClientAdversaire = "";
    private static int portClientAdversaire = -1;

    private static String nomJoueur = "";
    private static String nomJoueur1 = "";
    private static String nomJoueur2 = "";
    private static DatagramSocket socket = null;
    private static Echange matchEchange = new Echange();
    private static Scanner clavier = new Scanner(System.in);

    private static final int tamponEchange = 4096;
    private static final int tamponNormal = 1024;
    private static final String timeOutReceive = "TimeOutException";
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

        // Création de la socket
        Client.socket = null;
        try {
            Client.socket = new DatagramSocket();  //portEcoute automatique, récup avec : Client.socket.getLocalPort()
            Client.portEcoute = Client.socket.getLocalPort();
            socket = new DatagramSocket(Client.portClient, InetAddress.getByName(Client.addressClient));
            /*
            System.out.println("\nETAT Client : on " + 
                "\n\t\tport Ecoute : " + socket.getLocalPort() + 
                "\n\t\tport Envoie : " + Client.portServeur +
                "\n\t\t@ip : " + socket.getLocalAddress().toString().replace("/","") +
                "\n\t\t Identifiants Serveur : " +
                "\n\t\tport Ecoute : " + Client.portServeur + 
                "\n\t\t@ip : " + Client.addressServeur
            );
            */
            //System.out.println("\nETAT client : on \n\t\tport Ecoute : " + Client.portEcoute + "\n\t\tport Envoie : " + Client.portServeur);
            System.out.println("\nETAT client : on\n");
            Client.socket.setSoTimeout(Client.timeOutTime);
        } catch(SocketException e) {
            System.err.println("Connexion impossible au Serveur.");
            System.err.println("Erreur lors de la création de la socket : " + e);
            System.exit(0);
        } catch(UnknownHostException e){
            System.err.println("Erreur lors de la création de la socket : " + e);
            System.exit(0);
        }

        System.out.println("Entrez votre nom : ");
        nomJoueur = Client.clavier.nextLine();

        System.out.println("\nBienvenu " + nomJoueur + "! \nVous allez être mis en relation avec un autre Joueur d'ici peu de temps.");
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
            

            //envoie du message avec le portEcoute au serveur
            //message = Client.socket.getLocalPort() + Client.addressClient;   //envoie portEcoute + address
            message = Client.socket.getLocalSocketAddress().toString();
            envoieMessage(message, Client.addressServeur, Client.portServeur);

            //lecture du message du serveur
            message2 = receptionMessage(Client.tamponNormal);
            if(message2.equals(Client.timeOutReceive)) closeBy_TimeOutException_EndOfMatch();

            
            if(message2.equals("ok")){      //Client-1
                final int entityJoueur = 1;

                afficherMsgAttenteAdv();

                //récupération du portEcoute de l'adversaire (Client-2)
                message = receptionMessage(Client.tamponNormal);
                if(message.equals(Client.timeOutReceive)) closeBy_TimeOutException_EndOfMatch();
                Client.addressClientAdversaire = message.split(":")[0];
                Client.portClientAdversaire = Integer.parseInt(message.split(":")[1]);

                System.out.println("\n~~~~\t Connecté \t~~~~\n");
                //System.out.println("\nClient :\n\t\tport Ecoute : " + Client.portEcoute + "\n\t\tport Envoie : " + Client.portServeur);

                //envoie du pseudo Joueur 1
                envoieMessage(nomJoueur, Client.addressClientAdversaire, Client.portClientAdversaire);

                //reception du pseudo Joueur 2
                Client.nomJoueur2 = receptionMessage(Client.tamponNormal);
                if(nomJoueur2.equals(Client.timeOutReceive)) closeBy_TimeOutException_EndOfMatch();
                Client.nomJoueur1 = nomJoueur;

                System.out.println("\nLes joueurs sont : (vous) \"" + Client.nomJoueur1 +  "\" (J1) - (J2) \"" + Client.nomJoueur2 + "\".");

                //jeu
                    //choix du joueur qui va servir
                int randPlayer = nbAleatoire(); //0: J1     1: J2 

                    //envoie du joueur qui sert en premier
                envoieMessage(randPlayer + "", Client.addressClientAdversaire, Client.portClientAdversaire);

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
                        envoieMessage(Client.matchEchange.getEchangeString(entityJoueur), Client.addressClientAdversaire, Client.portClientAdversaire);

//System.out.println("\n\nLe joueur 1 construit et envoie l'échange : " + Client.matchEchange.getEchangeString(entityJoueur) + "\n\n");

                        afficherMsgAttenteAdv();

                        //reception result attrapé ? de C2
                        resultAttrapC2_boolean_String = receptionMessage(Client.tamponNormal);
                        if(resultAttrapC2_boolean_String.equals(Client.timeOutReceive)) closeBy_TimeOutException_EndOfMatch();
                        resultAttrapC2_boolean = (resultAttrapC2_boolean_String.equals("true"))? true : false;

//System.out.println("\n\nresultAttrapC2_boolean_String : " + resultAttrapC2_boolean_String + "\n" + "resultAttrapC2_boolean : " + resultAttrapC2_boolean + "\n");

                        if(resultAttrapC2_boolean) System.out.println("\nLe Joueur 2 a réussi à rattraper votre tir !\n");
                        else System.out.println("\nLe Joueur 2 n'a pas réussi à rattraper votre tir, BRAVO !\n");

                        //reception echange de C2
                        receptionEchange = receptionMessage(Client.tamponEchange);
                        if(receptionEchange.equals(Client.timeOutReceive)) closeBy_TimeOutException_EndOfMatch();
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
                                receptionEchange = receptionMessage(Client.tamponEchange);
                                if(receptionEchange.equals(Client.timeOutReceive)) closeBy_TimeOutException_EndOfMatch();
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
                                envoieMessage(resultAttrapC1_boolean +"", Client.addressClientAdversaire, Client.portClientAdversaire);
//System.out.println("\n\nresultAttrapC1_boolean : " + resultAttrapC1_boolean + "\n\n");

                                Client.matchEchange.construireChaineEnvoie(entityJoueur);
                                envoieMessage(Client.matchEchange.getEchangeString(entityJoueur), Client.addressClientAdversaire, Client.portClientAdversaire);
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
                        receptionEchange = receptionMessage(Client.tamponEchange);
                        if(receptionEchange.equals(Client.timeOutReceive)) closeBy_TimeOutException_EndOfMatch();
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
                        envoieMessage(resultAttrapC1_boolean +"", Client.addressClientAdversaire, Client.portClientAdversaire);
//System.out.println("\n\nresultAttrapC1_boolean : " + resultAttrapC1_boolean + "\n\n");

                        Client.matchEchange.construireChaineEnvoie(entityJoueur);
                        envoieMessage(Client.matchEchange.getEchangeString(entityJoueur), Client.addressClientAdversaire, Client.portClientAdversaire);
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
                                envoieMessage(Client.matchEchange.getEchangeString(entityJoueur), Client.addressClientAdversaire, Client.portClientAdversaire);

//System.out.println("\n\nLe joueur 1 construit et envoie l'échange : " + Client.matchEchange.getEchangeString(entityJoueur) + "\n\n");

                                afficherMsgAttenteAdv();

                                //reception result attrapé ? de C1
                                resultAttrapC2_boolean_String = receptionMessage(Client.tamponNormal);
                                if(resultAttrapC2_boolean_String.equals(Client.timeOutReceive)) closeBy_TimeOutException_EndOfMatch();
                                resultAttrapC2_boolean = (resultAttrapC2_boolean_String.equals("true"))? true : false;

//System.out.println("\n\nresultAttrapC2_boolean_String : " + resultAttrapC2_boolean_String + "\n" + "resultAttrapC2_boolean : " + resultAttrapC2_boolean + "\n");
                                
                                if(resultAttrapC2_boolean) System.out.println("\nLe Joueur 2 a réussi à rattraper votre tir !\n");
                                else System.out.println("\nLe Joueur 2 n'a pas réussi à rattraper votre tir, BRAVO !\n");

                                //reception echange de C2
                                receptionEchange = receptionMessage(Client.tamponEchange);
                                if(receptionEchange.equals(Client.timeOutReceive)) closeBy_TimeOutException_EndOfMatch();
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
            else if(message2.equals("timeOutException")){System.out.println("[TIME OUT]");}
            else{                           //Client-2
                final int entityJoueur = 2;
                Client.addressClientAdversaire = message2.split(":")[0];
                Client.portClientAdversaire = Integer.parseInt(message2.split(":")[1]);

                afficherMsgAttenteAdv();

                //envoie du portEcoute + address (Client-2)
                String messagePortEcoute = Client.addressClient + ":" + Client.portClient ;   //envoie portEcoute + address
                envoieMessage(messagePortEcoute, Client.addressClientAdversaire, Client.portClientAdversaire);

                System.out.println("\n~~~~\t Connecté \t~~~~\n");
                //System.out.println("\nClient :\n\t\tport Ecoute : " + Client.portEcoute + "\n\t\tport Envoie : " + Client.portServeur);

                //reception du pseudo Joueur 1
                Client.nomJoueur1 = receptionMessage(Client.tamponNormal);
                if(nomJoueur1.equals(Client.timeOutReceive)) closeBy_TimeOutException_EndOfMatch();
                Client.nomJoueur2 = nomJoueur;

                System.out.println("\nLes joueurs sont : \"" + Client.nomJoueur1 +  "\" (J1) - (J2) \"" + Client.nomJoueur2 + "\" (vous).");

                //envoie du pseudo Joueur 2
                envoieMessage(nomJoueur, Client.addressClientAdversaire, Client.portClientAdversaire);

                //jeu
                    //reception du joueur servant en premier
                int transmissionInt = -1;
                String transmissionString = receptionMessage(Client.tamponNormal);
                if(transmissionString.equals(Client.timeOutReceive)) closeBy_TimeOutException_EndOfMatch();
                transmissionInt = Integer.parseInt(transmissionString);

                if(transmissionInt == 0){
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
                        receptionEchange = receptionMessage(Client.tamponEchange);
                        if(receptionEchange.equals(Client.timeOutReceive)) closeBy_TimeOutException_EndOfMatch();
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
                        envoieMessage(resultAttrapC2_boolean +"", Client.addressClientAdversaire, Client.portClientAdversaire);
//System.out.println("\n\nresultAttrapC2_boolean : " + resultAttrapC2_boolean + "\n\n");

                        Client.matchEchange.construireChaineEnvoie(entityJoueur);
                        envoieMessage(Client.matchEchange.getEchangeString(entityJoueur), Client.addressClientAdversaire, Client.portClientAdversaire);
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
                                envoieMessage(Client.matchEchange.getEchangeString(entityJoueur), Client.addressClientAdversaire, Client.portClientAdversaire);

//System.out.println("\n\nLe joueur 2 construit et envoie l'échange : " + Client.matchEchange.getEchangeString(entityJoueur) + "\n\n");

                                afficherMsgAttenteAdv();

                                //reception result attrapé ? de C2
                                resultAttrapC1_boolean_String = receptionMessage(Client.tamponNormal);
                                if(resultAttrapC1_boolean_String.equals(Client.timeOutReceive)) closeBy_TimeOutException_EndOfMatch();
                                resultAttrapC1_boolean = (resultAttrapC1_boolean_String.equals("true"))? true : false;

//System.out.println("\n\nresultAttrapC1_boolean_String : " + resultAttrapC1_boolean_String + "\n" + "resultAttrapC1_boolean : " + resultAttrapC1_boolean + "\n");
                                
                                if(resultAttrapC1_boolean) System.out.println("\nLe Joueur 1 a réussi à rattraper votre tir !\n");
                                else System.out.println("\nLe Joueur 1 n'a pas réussi à rattraper votre tir, BRAVO !\n");

                                //reception echange de C1
                                receptionEchange = receptionMessage(Client.tamponEchange);
                                if(receptionEchange.equals(Client.timeOutReceive)) closeBy_TimeOutException_EndOfMatch();
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
                else if(transmissionInt == 1){
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
                        envoieMessage(Client.matchEchange.getEchangeString(entityJoueur), Client.addressClientAdversaire, Client.portClientAdversaire);

//System.out.println("\n\nLe joueur 2 construit et envoie l'échange : " + Client.matchEchange.getEchangeString(entityJoueur) + "\n\n");

                        afficherMsgAttenteAdv();

                        //reception result attrapé ? de C1
                        resultAttrapC1_boolean_String = receptionMessage(Client.tamponNormal);
                        if(resultAttrapC1_boolean_String.equals(Client.timeOutReceive)) closeBy_TimeOutException_EndOfMatch();
                        resultAttrapC1_boolean = (resultAttrapC1_boolean_String.equals("true"))? true : false;

//System.out.println("\n\nresultAttrapC1_boolean_String : " + resultAttrapC1_boolean_String + "\n" + "resultAttrapC1_boolean : " + resultAttrapC1_boolean + "\n");

                        if(resultAttrapC1_boolean) System.out.println("\nLe Joueur 1 a réussi à rattraper votre tir !\n");
                        else System.out.println("\nLe Joueur 1 n'a pas réussi à rattraper votre tir, BRAVO !\n");

                        //reception echange de C1
                        receptionEchange = receptionMessage(Client.tamponEchange);
                        if(receptionEchange.equals(Client.timeOutReceive)) closeBy_TimeOutException_EndOfMatch();
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
                                receptionEchange = receptionMessage(Client.tamponEchange);
                                if(receptionEchange.equals(Client.timeOutReceive)) closeBy_TimeOutException_EndOfMatch();
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
                                envoieMessage(resultAttrapC2_boolean +"", Client.addressClientAdversaire, Client.portClientAdversaire);
//System.out.println("\n\nresultAttrapC2_boolean : " + resultAttrapC2_boolean + "\n\n");

                                Client.matchEchange.construireChaineEnvoie(entityJoueur);
                                envoieMessage(Client.matchEchange.getEchangeString(entityJoueur), Client.addressClientAdversaire, Client.portClientAdversaire);
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
        
        
        // Fermeture de la socket
        System.out.println("\nETAT client : off");
        Client.clavier.close();
        Client.socket.close();
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
     * envoie les packets
     * @param messageEnvoie le message a envoyer
     */
    public static void envoieMessage(String messageEnvoie, String addressEnvoie, int portEnvoie){
        DatagramPacket msg = null;
        InetAddress adresse;
        byte[] tampon;
        try {
            adresse = InetAddress.getByName(addressEnvoie);
            tampon = messageEnvoie.getBytes();
            msg = new DatagramPacket(tampon, tampon.length, adresse, portEnvoie);   
            Client.socket.send(msg);         
        } catch(UnknownHostException e) {
            System.err.println("[ERREUR_CLIENT] Erreur lors de la création du message : " + e);
            System.exit(0);
        } catch(IOException e) {
            System.err.println("[ERREUR_CLIENT] Erreur lors de l'envoi du message : " + e);
            System.exit(0);
        }
    }

    /**
     * receptionne les packets
     * @param nbBytes le nombre de bytes pour le tampon
     * @return la chaine de caractere recu.
     */
    public static String receptionMessage(int nbBytes){
        byte[] tampon = new byte[nbBytes];
        DatagramPacket msg = new DatagramPacket(tampon, tampon.length);
        String message = "";

        try {
            Client.socket.receive(msg);
            message = new String(msg.getData(), 0, msg.getLength());
            if(message.equals(Client.timeOutReceive)) closeBy_receive_TimeOutException_EndOfMatch();
        } catch(SocketTimeoutException e){
            System.err.println("[ERREUR_CLIENT] Time out : " + e);
            message = Client.timeOutReceive;
        } catch(IOException e) {
            System.err.println("[ERREUR_CLIENT] Erreur lors de la réception du message : " + e);
            System.exit(0);
        }

        return message;
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
     * met fin au match, accordant la victoire 
     */
     public static void closeBy_TimeOutException_EndOfMatch(){
        System.out.println("\nNous somme désolé, mais nous avons détecté un TIME OUT du joueur adverse.");
        System.out.println("Vous avez donc gagné par forfait ! BRAVO !\n");
        envoieMessage(Client.timeOutReceive, Client.addressClientAdversaire, Client.portClientAdversaire);

        // Fermeture de la socket
        System.out.println("\nETAT client : off");
        //Client.clavier.close();
        Client.socket.close();
        System.exit(0);
    }

    /**
     * met fin au match, accordant la victoire 
     */
    public static void closeBy_receive_TimeOutException_EndOfMatch(){
        System.out.println("\nNous somme désolé, mais nous avons détecté un TIME OUT de votre côté.");
        System.out.println("Vous avez donc perdu par forfait \n");

        // Fermeture de la socket
        System.out.println("\nETAT client : off");
        //Client.clavier.close();
        Client.socket.close();
        System.exit(0);
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
            //System.out.println("charger : " + Client.nomFichier);

            while (sc.hasNext()) {
                String line = sc.nextLine();
                allFichierCongif += line;
            }
            allFichierCongif = allFichierCongif.replace("\"", "").replace(" ", "").replace("{", "").replace("}", "");
            //System.out.println("allFichierConfig : " + allFichierCongif);
            String[] totalStringSplit = allFichierCongif.split(",");

            String[] addressServeurTotal = totalStringSplit[0].split(":");
            String[] portServeurTotal = totalStringSplit[1].split(":");
            
            String[] addressClientTotal = totalStringSplit[2].split(":");
            String[] portClientTotal = totalStringSplit[3].split(":");

                //serveur identifiants
            //System.out.println("addressServeur : " + addressServeurTotal[1]);
            Client.addressServeur = addressServeurTotal[1];
            //System.out.println("portServeur : " + portServeurTotal[1]);
            Client.portServeur = Integer.parseInt(portServeurTotal[1]);

                //client identifiants
            //System.out.println("addressClient : " + addressClientTotal[1]);
            Client.addressClient = addressClientTotal[1];
            //System.out.println("portClient : " + portClientTotal[1]);
            Client.portClient = Integer.parseInt(portClientTotal[1]);

            sc.close();
        } catch (FileNotFoundException e) {
            System.out.println("Echec de l'ouverture et de la récupération des données des fichiers.\n");
            e.printStackTrace();
        }
    }
}