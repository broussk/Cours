/*
 *  compilation :       javac -cp "json.jar:." *.java
 *  execution Client :  java -cp "json.jar:." ClientTennis
 *  execution Serveur : java -cp "json.jar:." ServeurTennis
 */

import java.net.DatagramSocket;
import java.net.DatagramPacket;
import java.net.SocketException;
import java.io.IOException;
import java.net.InetAddress;
import java.io.ByteArrayInputStream;
import java.io.ObjectInputStream;
import java.net.UnknownHostException;

import java.util.Scanner;

/**
 * Serveur UDP permettant de faire un tennis avec un Client
 * @author Nathan TONNELLE
 */
public class ServeurTennis {

    public static int portEcoute = 3031;
    public static int portEnvoie = 3032;
    private static final String endWord = "end";
            /*  améliorations possibles :   */
    //private static final String newParty = "again";
    //private static int nbEchange = 0;

    public static void main(String[] args) {
        // Création de la socket
        Scanner clavier = new Scanner(System.in);
        DatagramSocket socket = null;
        try {        
            System.out.println("\nETAT socket : on \n\t\tport Ecoute : " + portEcoute + "\n\t\tport Envoie : " + portEnvoie);
            System.out.println("\n\n\t\tVous êtes : \t Joueur 1 (J1)\n\n");
            socket = new DatagramSocket(portEcoute);
        } catch(SocketException e) {
            System.err.println("Erreur lors de la création du socket : " + e);
            System.exit(0);
        }

        //PARTIE : lancement jeu
            //création de l'echange, on vide le fichier echange.json
        Echange echange = new Echange("echange.json", true);
            //vérification du reset du fichier
        System.out.println(echange.toString());

        //PARTIE : envoie/reception des messages et jeu
        String message = "blabla";
        String texte = "blabla";
        int coupAdversaire = 1;
        int coupJoueur = 1;
        int infosCoupIntJoueur = 2;
        String requestCommentaireQuestion = "non";
        String commentaireJoueur = "aucun";
        boolean partieFini = false;

        while(!message.equals(endWord)){
            //quel choix à fait l'adversaire celon vous ?
            do{
                System.out.println("Marquez le coup que vous pensez que votre adversaire à envoyé \n\t1 = gauche\n\t2 = milieu\n\t3 = droite");
                coupAdversaire = clavier.nextInt();
            }while(coupAdversaire < 1 || coupAdversaire > 3);
            echange.coupAdverseDevine(0, coupAdversaire);

            partieFini = echange.partieFini();

            if(!partieFini){
                //Echanges construction
                    //endroit du coup
                do{
                    System.out.println("Marquez le coup que vous voulez \n\t1 = gauche\n\t2 = milieu\n\t3 = droite");
                    coupJoueur = clavier.nextInt();
                }while(coupJoueur < 1 || coupJoueur > 3);
                    //type
                do{
                    System.out.println("Marquez l'information sur le type de coup que vous voulez \n\t1 = service\n\t2 = envoie\n\t3 = renvoie");
                    infosCoupIntJoueur = clavier.nextInt();
                }while(coupJoueur < 1 || coupJoueur > 3);
                String infosCoupJoueur = infosChoice(infosCoupIntJoueur);
                    //commentaire
                System.out.println("Voulez-vous mêttre un commentaire (oui ou non): ");
                requestCommentaireQuestion = clavier.nextLine();
                requestCommentaireQuestion = clavier.nextLine();
                if(requestCommentaireQuestion.equals("oui")){
                    System.out.println("Entrez votre commentaire : ");
                    commentaireJoueur = clavier.nextLine();
                }else{commentaireJoueur = "aucun";}
                
                echange.nouvelEchange(0, coupJoueur, infosCoupJoueur, commentaireJoueur);
                System.out.println(echange.toString());
                echange.sauvegarder();
                
                System.out.println("\nEnvoie de l'échange");
                message = "send";
            }
            else{
                message = "end";
            }

            // Création du message Serveur
            DatagramPacket msg = null;
            try {
                InetAddress adresse = InetAddress.getByName(null);
                byte[] tampon2 = message.getBytes();
                msg = new DatagramPacket(tampon2, tampon2.length, adresse, portEnvoie);            
            } catch(UnknownHostException e) {
                System.err.println("Erreur lors de la création du message : " + e);
                System.exit(0);
            }

            // Envoi du message Serveur
            try {
                socket.send(msg);
            } catch(IOException e) {
                System.err.println("Erreur lors de l'envoi du message : " + e);
                System.exit(0);
            }

            if(!message.equals(endWord)){
                // Création du message Client
                byte[] tampon = new byte[1024];
                msg = new DatagramPacket(tampon, tampon.length);

                // Lecture du message du Client
                try {
                    socket.receive(msg);
                    texte = new String(msg.getData(), 0, msg.getLength());
                    echange.recharge();
                    System.out.println(echange.toStringCoupMasquer());
                    if(texte.equals(endWord)){
                        break;
                    }
                } catch(IOException e) {
                    System.err.println("Erreur lors de la réception du message : " + e);
                    System.exit(0);
                }
            }            
        }
        //System.out.println("message Client : " + texte);
        if(texte.equals(endWord)){
            partieFini = echange.partieFini();
        }
            
        System.out.println("\nETAT serveur : off");
        clavier.close();
        socket.close();
    }

    /**
     * retourne la chaine de caractère correspondant au coup choisi
     * @param x le numéro du coup choisi
     * @return le type de coup choisi
     */
    private static String infosChoice(int x){
        String returned = "";
        switch (x) {
            case 1:
                returned = "service";
                break;        
            case 2 : 
                returned = "envoie";
                break;
            case 3 :
                returned = "renvoie";
                break;
            default:
                returned = "renvoie";
                break;
        }
        return returned;
    }
}