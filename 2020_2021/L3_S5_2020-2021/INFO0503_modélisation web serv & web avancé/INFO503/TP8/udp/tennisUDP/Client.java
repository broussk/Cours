
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
import java.net.InetSocketAddress;
import java.net.SocketAddress;
import java.net.UnknownHostException;

import java.util.Scanner;
import java.util.Random;

public class Client {

    public static int portEcoute = 0;
    public static int portEnvoie = 9876;

    private static String nomJoueur = "";
    private static String nomJoueur1 = "";
    private static String nomJoueur2 = "";
    private static DatagramSocket socket = null;
    private static final int tamponEchange = 4096;
    private static final int tamponNormal = 1024;
    
    public static void main(String[] args) {
        Scanner clavier = new Scanner(System.in);
        Echange matchEchange = new Echange();

        // Création de la socket
        Client.socket = null;
        try {
            Client.socket = new DatagramSocket();  //portEcoute automatique, récup avec : Client.socket.getLocalPort()
            Client.portEcoute = Client.socket.getLocalPort();
            //System.out.println("\nETAT client : on \n\t\tport Ecoute : " + Client.portEcoute + "\n\t\tport Envoie : " + Client.portEnvoie);
            System.out.println("\nETAT client : on\n");
        } catch(SocketException e) {
            System.err.println("Connexion impossible au Serveur.");
            System.err.println("Erreur lors de la création de la socket : " + e);
            System.exit(0);
        }

        System.out.println("Entrez votre nom : ");
        nomJoueur = clavier.nextLine();

        System.out.println("\nBienvenu " + nomJoueur + "! \nVous allez être mis en relation avec un autre Joueur d'ici peu de temps.");
        System.out.println(rulesString());

        System.out.println("Avez-vous bien compris les règles ? Ecrire : \"oui\" ou \"non\" ou \"o\" ou \"n\"");
        String repRegles = clavier.nextLine();

        if(repRegles.equals("oui") || repRegles.equals("o")){
            String message = "";
            String message2 = "";

            //envoie du message avec le portEcoute au serveur
            message = Client.socket.getLocalPort() + "";   //envoie portEcoute
            envoieMessage(message);

            //lecture du message du serveur
            message2 = receptionMessage(Client.tamponNormal);

            
            if(message2.equals("ok")){      //Client-1
                final int entityJoueur = 1;

                afficherMsgAttenteAdv();

                //récupération du portEcoute de l'adversaire (Client-2)
                Client.portEnvoie = Integer.parseInt(receptionMessage(Client.tamponNormal));

                System.out.println("\n~~~~\t Connecté \t~~~~\n");
                //System.out.println("\nClient :\n\t\tport Ecoute : " + Client.portEcoute + "\n\t\tport Envoie : " + Client.portEnvoie);

                //envoie du pseudo Joueur 1
                envoieMessage(nomJoueur);

                //reception du pseudo Joueur 2
                Client.nomJoueur2 = receptionMessage(Client.tamponNormal);
                Client.nomJoueur1 = nomJoueur;

                System.out.println("\nLes joueurs sont : (vous) \"" + Client.nomJoueur1 +  "\" (J1) - (J2) \"" + Client.nomJoueur2 + "\".");

                //jeu
                    //choix du joueur qui va servir
                //int randPlayer = nbAleatoire(); //0: J1     1: J2
//choix test
                int randPlayer = 0; 

                    //envoie du joueur qui sert en premier
                envoieMessage(randPlayer + "");

                if(randPlayer == 0){
                    System.out.println("\nLe Joueur 1 commence.");

                    System.out.println(matchEchange.scoreToString());

                //service
                        //saisie du premier service du match
                    int serviceMatch = 0;
                    do{
                        System.out.println("Où voulez-vous tirer pour servir ? Ecrire une zone, dans les zones de 1 à 5 \n\t" + emplacementString());
                        serviceMatch = clavier.nextInt();
                    }while(serviceMatch < 1 || serviceMatch > 5);

                        //construction du premier échange
                    matchEchange.nouvelEchange(entityJoueur, serviceMatch);
                    matchEchange.construireChaineEnvoie(entityJoueur);

                    //System.out.println("\n\nchaine d'envoie de l'échange : " + matchEchange.getEchangeString(entityJoueur) + "\n\n");

                        //envoie du premier echange
                    envoieMessage(matchEchange.getEchangeString(entityJoueur));

                        //affichage echange en cours
                    System.out.println(matchEchange.toString(entityJoueur));

                //reception et envoie du prochain echange tant que un point n'est pas marqué
                    boolean continuerEchange = true;
                    do{
                        afficherMsgAttenteAdv();

                        //reception result attrapé ?
                        String client2attrape_String = receptionMessage(Client.tamponNormal);
                        boolean client2attrape_ = (client2attrape_String.equals("true"))? true : false;
                        //System.out.println("\n\nclient2attrape_String : " + client2attrape_String + "\n\n");
                        if(client2attrape_) System.out.println("\nLe Joueur 2 a réussi à rattraper votre tir !\n");
                        else System.out.println("\nLe Joueur 2 n'a pas réussi à rattraper votre tir, BRAVO !\n");

                        afficherMsgAttenteAdv();

                        //attente/reception de reception echange
                        //affichage score
                        //System.out.println(matchEchange.scoreToString());
            
                        
                        if(client2attrape_){
                            //si client-2 a attrapé

                            //reception
                            String receptionEchange = receptionMessage(Client.tamponEchange);
                            //System.out.println("\n\nreceptionEchange : " + receptionEchange + "\n\n");

                            matchEchange.recharge(entityJoueur, receptionEchange);
                            System.out.println(matchEchange.toString(entityJoueur));

                            //System.out.println("\nLe Joueur 2 a réussi à rattraper votre tir !\n");

                            //prochain echange : 
                                //choix position + attrapé ?
                            int repChoixNouvellePostion = 0;
                            do{
                                System.out.println("\nVoulez-vous monter (1) , descendre (-1) ou rester a la même position (0) pour essayer d'attraper le tir de votre adversaire ? Ecrire : \"1\" ou \"-1\" ou \"0\"" + 
                                    "\n\tterrain : " + emplacementString() +
                                    "\n\tVous êtes à la position : " + matchEchange.tir_position_ToString(matchEchange.getPosition(entityJoueur)) 
                                    + "(" + matchEchange.getPosition(entityJoueur) + ")."
                                );
                                repChoixNouvellePostion = clavier.nextInt();
                            }while(repChoixNouvellePostion < -1 && repChoixNouvellePostion > 1);
                            //}while(repChoixNouvellePostion != 1 || repChoixNouvellePostion != -1 || repChoixNouvellePostion != 0);
                            int nouvellePosition = matchEchange.getPosition(entityJoueur) + repChoixNouvellePostion;
                            matchEchange.setPosition(entityJoueur, nouvellePosition);
                            System.out.println("\n\tVous êtes à la position : " + matchEchange.tir_position_ToString(matchEchange.getPosition(entityJoueur)) + "(" + matchEchange.getPosition(entityJoueur) + ").");

                                //regarde si le client-1 a attrapé le tir de client-2
                            boolean client1attrape_ = matchEchange.positionTirAdverseDevine(entityJoueur, matchEchange.getPosition(entityJoueur));
                            envoieMessage(client1attrape_ +"");
                            //System.out.println("client1attrape_ : " + client1attrape_);
                                
                            if(client1attrape_){
                                //si client-1 a attrapé
                                    //rejoue (nouvel echange)
                                int echangeMatch = 0;
                                do{
                                    System.out.println("Où voulez-vous tirer ? Ecrire une zone, dans les zones de 1 à 5 \n\t" + emplacementString());
                                    echangeMatch = clavier.nextInt();
                                }while(echangeMatch < 1 || echangeMatch > 5);
            
                                    //construction de l'échange
                                matchEchange.nouvelEchange(entityJoueur, echangeMatch);
                                matchEchange.construireChaineEnvoie(entityJoueur);
            
                                //System.out.println("\n\nchaine d'envoie de l'échange : " + matchEchange.getEchangeString(entityJoueur) + "\n\n");
            
                                    //envoie de l'echange
                                envoieMessage(matchEchange.getEchangeString(entityJoueur));
            
                                    //affichage echange en cours
                                //System.out.println(matchEchange.toString(entityJoueur));

                                //retourner début boucle pour savoir si client-2 a attrapé ou pas 
                            }
                            else if(!client1attrape_){
                                //si client-1 a pas attrapé
                                envoieMessage(matchEchange.getEchangeString(entityJoueur));
                                //affichage du score final : 
                                System.out.println(matchEchange.afficherScoreFinal());
                                //stop (temporaire)
                                continuerEchange = true;
                            }
                            else{
                                System.out.println("\n[ERREUR] on ne sait pas si le client-1 à attrapé la balle ou pas.");
                            }
                              
                        }
                        else if(!client2attrape_){
                            System.out.println("\nLe Joueur 2 n'a pas réussi à rattraper votre tir, bravo !\n");
                            //si client-2 a pas attrapé
                            System.out.println(matchEchange.afficherScoreFinal());
                            //stop (temporaire)
                            continuerEchange = true;
                        }
                        else{
                            System.out.println("\n[ERREUR] on ne sait pas si le client-2 à attrapé la balle ou pas.");
                        }
                    }while(continuerEchange);















































                














                
                } 
                else if(randPlayer == 1){
                    System.out.println("\nLe Joueur 2 commence.");

                    System.out.println(matchEchange.scoreToString());
                    
                //service reception
                    String receptionService = receptionMessage(Client.tamponEchange);
                    //System.out.println("\n\nreceptionService : " + receptionService + "\n\n");

                    matchEchange.recharge(entityJoueur, receptionService);
                    System.out.println(matchEchange.toString(entityJoueur));
                
                //envoie et reception des echange tant que l'echange n'est pas fini (tant qu'il n'y a pas de gagnant à l'echange (point marqué))
                } 
                
            }
            else{                           //Client-2
                final int entityJoueur = 2;
                Client.portEnvoie = Integer.parseInt(message2);

                afficherMsgAttenteAdv();

                //envoie du portEcoute (Client-2)
                String messagePortEcoute = Client.socket.getLocalPort() + "";   //envoie portEcoute
                envoieMessage(messagePortEcoute);

                System.out.println("\n~~~~\t Connecté \t~~~~\n");
                //System.out.println("\nClient :\n\t\tport Ecoute : " + Client.portEcoute + "\n\t\tport Envoie : " + Client.portEnvoie);

                //reception du pseudo Joueur 1
                Client.nomJoueur1 = receptionMessage(Client.tamponNormal);
                Client.nomJoueur2 = nomJoueur;

                System.out.println("\nLes joueurs sont : \"" + Client.nomJoueur1 +  "\" (J1) - (J2) \"" + Client.nomJoueur2 + "\" (vous).");

                //envoie du pseudo Joueur 2
                envoieMessage(nomJoueur);

                //jeu
                    //reception du joueur servant en premier
                int transmissionInt = -1;
                transmissionInt = Integer.parseInt(receptionMessage(Client.tamponNormal));

                if(transmissionInt == 0){
                    System.out.println("\nLe Joueur 1 commence.");

                    System.out.println(matchEchange.scoreToString());

                

                //envoie et reception des echange tant que l'echange n'est pas fini (tant qu'il n'y a pas de gagnant à l'echange (point marqué))
                    
                    boolean continuerEchange = true;
                    do{
                        afficherMsgAttenteAdv();

                        //reception de l'echange
                        String receptionService = receptionMessage(Client.tamponEchange);
                        //System.out.println("\n\nreceptionService : " + receptionService + "\n\n");

                        matchEchange.recharge(entityJoueur, receptionService);

    //masquer le tir adv apres les tests
                        System.out.println(matchEchange.toString(entityJoueur));

                        //choix position + attrapé ?
                        int repChoixNouvellePostion = 0;
                        do{
                            System.out.println("\nVoulez-vous monter (1) , descendre (-1) ou rester a la même position (0) pour essayer d'attraper le tir de votre adversaire ? Ecrire : \"1\" ou \"-1\" ou \"0\"" + 
                                "\n\tterrain : " + emplacementString() +
                                "\n\tVous êtes à la position : " + matchEchange.tir_position_ToString(matchEchange.getPosition(entityJoueur)) 
                                + "(" + matchEchange.getPosition(entityJoueur) + ")."
                            );
                            repChoixNouvellePostion = clavier.nextInt();
                        }while(repChoixNouvellePostion < -1 && repChoixNouvellePostion > 1);
                        //}while(repChoixNouvellePostion != 1 || repChoixNouvellePostion != -1 || repChoixNouvellePostion != 0);
                        int nouvellePosition = matchEchange.getPosition(entityJoueur) + repChoixNouvellePostion;
                        matchEchange.setPosition(entityJoueur, nouvellePosition);
                        System.out.println("\n\tVous êtes à la position : " + matchEchange.tir_position_ToString(matchEchange.getPosition(entityJoueur)) + "(" + matchEchange.getPosition(entityJoueur) + ").");

                            //regarde si le client-2 a attrapé le tir de client-1
                        boolean client2attrape_ = matchEchange.positionTirAdverseDevine(entityJoueur, matchEchange.getPosition(entityJoueur));
                            
                            //envoie result attrapé :
                        envoieMessage(client2attrape_ + "");

                        if(client2attrape_){
                            //si client-2 a attrapé

                            //rejoue (nouvel echange)
                            int echangeMatch = 0;
                            do{
                                System.out.println("Où voulez-vous tirer ? Ecrire une zone, dans les zones de 1 à 5 \n\t" + emplacementString());
                                echangeMatch = clavier.nextInt();
                            }while(echangeMatch < 1 || echangeMatch > 5);
        
                                //construction de l'échange
                            matchEchange.nouvelEchange(entityJoueur, echangeMatch);
                            matchEchange.construireChaineEnvoie(entityJoueur);
        
                            //System.out.println("\n\nchaine d'envoie de l'échange : " + matchEchange.getEchangeString(entityJoueur) + "\n\n");
        
                                //envoie de l'echange
                            envoieMessage(matchEchange.getEchangeString(entityJoueur));
        
                                //affichage echange en cours
                            System.out.println(matchEchange.toString(entityJoueur));

                            afficherMsgAttenteAdv();

                            //reception result attrapé ?
                            String client1attrape_String = receptionMessage(Client.tamponNormal);
                            boolean client1attrape_ = (client1attrape_String.equals("true"))? true : false;
                            //System.out.println("\n\nclient1attrape_String : " + client1attrape_String + "\n\n");
                            if(client1attrape_) System.out.println("\nLe Joueur 1 a réussi à rattraper votre tir !\n");
                            else System.out.println("\nLe Joueur 1 n'a pas réussi à rattraper votre tir, BRAVO !\n");
                            
                            if(!client1attrape_){
                                //si client-1 a pas attrapé
                                matchEchange.recharge(entityJoueur, receptionMessage(Client.tamponEchange));
                                //affichage du score final : 
                                System.out.println(matchEchange.afficherScoreFinal());
                                //stop (temporaire)
                                continuerEchange = true;
                            }  
                        }
                        else if(!client2attrape_){
                            //System.out.println("\nLe Joueur 1 n'a pas réussi à rattraper votre tir, bravo !\n");
                            //si client-2 a pas attrapé
                            System.out.println(matchEchange.afficherScoreFinal());
                            //stop (temporaire)
                            envoieMessage(matchEchange.getEchangeString(entityJoueur));
                            continuerEchange = true;
                        }
                        else{
                            System.out.println("\n[ERREUR] on ne sait pas si le client-1 à attrapé la balle ou pas.");
                        }
                    }while(continuerEchange);





















































































                } 
                else if(transmissionInt == 1){
                    System.out.println("\nLe Joueur 2 commence.");

                    System.out.println(matchEchange.scoreToString());

                //service
                    //saisie du premier service du match
                    int serviceMatch = 0;
                    do{
                        System.out.println("Où voulez-vous tirer pour servir ? (dans les zones de 1 à 5) \n\t" + emplacementString());
                        serviceMatch = clavier.nextInt();
                    }while(serviceMatch < 1 || serviceMatch > 5);

                    //construction du premier échange
                    matchEchange.nouvelEchange(entityJoueur, serviceMatch);
                    matchEchange.construireChaineEnvoie(entityJoueur);

                    //System.out.println("\n\nchaine d'envoie de l'échange : " + matchEchange.getEchangeString(entityJoueur) + "\n\n");

                    //envoie du premier echange
                    envoieMessage(matchEchange.getEchangeString(entityJoueur));

                    //affichage echange en cours
                    System.out.println(matchEchange.toString(entityJoueur));
                
                //reception du prochain echange tant que un point n'est pas marqué
                } 
            }
        }
        else{
            System.out.println("Le Client s'éteint.\n Au revoir " + nomJoueur + ".");
        }
        
        // Fermeture de la socket
        System.out.println("\nETAT client : off");
        clavier.close();
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
    public static void envoieMessage(String messageEnvoie){
        DatagramPacket msg = null;
        InetAddress adresse;
        byte[] tampon;
        try {
            adresse = InetAddress.getByName(null);
            tampon = messageEnvoie.getBytes();
            msg = new DatagramPacket(tampon, tampon.length, adresse, Client.portEnvoie);   
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
}