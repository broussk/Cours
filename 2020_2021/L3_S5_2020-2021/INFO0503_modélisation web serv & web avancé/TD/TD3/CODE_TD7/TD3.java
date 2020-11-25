//question 5
class MessageAgregation
class MessageEchange
class ServeurMessage
class ClientEmission
class ClientReception
class ThreadMessagerie

public class ThreadMessagerie extends Thread {
    private Socket s;
    private MessageAgregation msgA;
    private MessageAgregation msgB;
    private Vector<MessageEchangeListe> mg;
    private int token;
    public ThreadMessagerie(Socket s, MessageAgregation msgA){
        this.s = s;
        this.msgA = msgA;
    }

    @override
    public run(){
        InputStream is = new InputStream(s.getInputStream);
        ObjectInputStream ois = new ObjectInputStream(is);
        OutpuStream os = new OutpuStream(s.getOuputStream);
        ObjectOutputStream oos = new ObjectOutputStream(os);

        
        msgA = ( MessageAgregation ) oos.readObject();
        /*if(msgA.getlist()[0].getIdMsg() == 0){
            mg.add(msgA.getlist[0]);
            reponse.setID(1);
        }
        else{        
            for(int i=0; i<msg.lenght; i++){
                if(mg[i].getDestinataire() == msgA.getListe()[0].getExpediteur()){
                    reponse.add(mg[i]);
                }
                reponse.setId(1);
            }
            oos.writeObject(reponse);
        }*/
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
                oos.writeObject(msgB);
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
                oos.writeObject(msgB);  
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
                oos.writeObject(msgB);  
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
                oos.writeObject(msgB);
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
                oos.writeObject(msgB);
                break;
            default:    
                /*Traitement pour validé les infos
                    Si c'est ok compte tenu du contenu on va mettre 0 ou 200 
                    Si c'est pas ok + que 0 VOUS QUI VOYEZ*/
                remplireMessageReponse(101,0); 
                oos.writeObject(msgB);  
        }
        try {
            is.close();
            os.close();
            ois.close();
            oos.close();
            s.close();
        }catch(IOException e) {
            System.err.println("Erreur lors de la fermeture des flux et des sockets : " + e);
        }
    }
}
public void sendBDD(HttpExchange t, JSONObject object) {​​​​​​​
        String response = object.toString();
        try {​​​​​​​
            t.getResponseHeaders().set("Content-Type", "appication/json");
            t.sendResponseHeaders(200, response.length());
            OutputStream os = t.getResponseBody();
            os.write(response.getBytes());
            os.close();
        }​​​​​​​ catch(IOException e) {​​​​​​​
            System.err.println("Erreur lors de l'envoi du corps : " + e);
        }​​​​​​​
}​​​​​​​