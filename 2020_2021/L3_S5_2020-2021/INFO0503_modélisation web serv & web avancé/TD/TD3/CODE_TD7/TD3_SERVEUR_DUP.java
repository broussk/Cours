class MessageAgregation
class MessageEchange
class ServeurMessage
class ClientEmission
class ClientReception

 private MessageAgregation msgA;
   private MessageAgregation msgB;

public class ServeurUDP{

	public static int port = 666;
 	private MessageAgregation msgA;

	public static void main(String[] args){
		// Création de la socket
        DatagramSocket socket = null;
         try {        
            socket = new DatagramSocket(port);
        } catch(SocketException e) {
            System.err.println("Erreur lors de la création de la socket : " + e);
            System.exit(0);
        }
        // Création du message
       	byte[] tampon = new byte[1024];
        DatagramPacket msg = new DatagramPacket(tampon, tampon.length);


        // Lecture du message du client
        try {
            socket.receive(msg);
            msgA = new msgA(msg.getData(), 0, msg.getLength());
            System.out.println(texte);
        } catch(IOException e) {
            System.err.println("Erreur lors de la réception du message : " + e);
            System.exit(0);
        }

        int id_msg_received= msgA.getlist()[0].getIdMsg();

        switch(id_msg_received){
            case 0:
                //conection
                /*haché du couple envoyé par l'utilisateur */
                String hash = msgA.getlist()[0].getContenu();
                // Requete à la BDD 
                HttpExchange t;
                sendBDD(t,objet);
                readPost(t);
                //reception + traitement 
                //Reponse de la bdd
                    if(reponse.getCode()){ 
                        generateToken();
                        remplireMessageReponse(reponse.getId(),0,msgB);
                    }else{
                        remplireMessageReponse(reponse.getId(),1,msgB);
                    }
                socket.send(msgB);
                break;
            case 1:
                //envoi
                /*Traitement pour validé les infos
                    Si c'est ok compte tenu du contenu on va mettre 0 ou 200 
                    Si c'est pas ok + que 0 VOUS QUI VOYEZ*/

                remplireMessageReponse(id_msg_received,0); 
                /*
                    Accès à la mémoire partagée 
                    -ecrire le méssage dans cette mémoire / stack / tmtc 
                    -BDD
                    -variable partagée genre des mutex /!\/!\/!\ pas important ici 
                */
                socket.send(msgB);  
                break;
            case 2:
                //reception
                /*Traitement pour validé les infos
                    Si c'est ok compte tenu du contenu on va mettre 0 ou 200 
                    Si c'est pas ok + que 0 VOUS QUI VOYEZ*/
                remplireMessageReponse(id_msg_received,0); 
                /*
                    Accès à la mémoire partagée 
                    -ecrire le méssage dans cette mémoire / stack / tmtc 
                    -BDD
                    -variable partagée genre des mutex /!\/!\/!\ pas important ici 
                */
                socket.send(msgB);  
                break;
            case 3:
                //archivage
                //Requete à la BDD 
                HttpExchange t;
                sendBDD(t,objet);
                readPost(t);
                //reception + traitement 
                //Reponse de la bdd
                    if(reponse.getCode()){ 
                        //archivage ok 
                        remplireMessageReponse(reponse.getId(),0,msgB);
                    }else{
                        //archivage pas ok 
                        remplireMessageReponse(reponse.getId(),1,msgB);
                    }
                socket.send(msgB);
                break;
            case 4:
                //effacement
                //Requete à la BDD 
                HttpExchange t;
                sendBDD(t,objet);
                readPost(t);
                //reception + traitement 
                //Reponse de la bdd
                    if(reponse.getCode()){ 
                        //archivage ok 
                        remplireMessageReponse(reponse.getId(),0,msgB);
                    }else{
                        //archivage pas ok 
                        remplireMessageReponse(reponse.getId(),1,msgB);
                    }
                socket.send(msgB);
                break;
            default:    
                /*Traitement pour validé les infos
                    Si c'est ok compte tenu du contenu on va mettre 0 ou 200 
                    Si c'est pas ok + que 0 VOUS QUI VOYEZ*/
                remplireMessageReponse(101,0); 
                socket.send(msgB);  
        }
        // Fermeture de la socket
        socket.close();
    }
}