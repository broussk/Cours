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

    public ThreadMessagerie(Socket s, MessageAgregation msgA){
        this.s = s;
        this.msgA = msgA;
    }

    @override
    public run(){
        InputStream in = new InputStream(s.getInputStream);
        ObjectInputStream ois = new ObjectInputStream(in);
        OutpuStream os = new OutpuStream(s.getOuputStream);
        ObjectOutputStream oos = new ObjectOutputStream(os);

        Vector<MessageEchange> reponse;

        while(1){
            msgA = oos.readObject();



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
            short id_msg_received = msgA.getlist()[0].getIdMsg();
            switch(id_msg_received){
                case 0:
                    //conection 
                    //haché du couple envoyé par l'utilisateur
                    String hash = msgA.getlist()[0].getContenu();
                    //requete a la bdd
                    reponse = ;
                    //reponse de la bdd
                        if(reponse.getCode()){
                            remplirMessageReponse(reponse.getId(),0);
                        }
                        else{
                            remplirMessageReponse(reponse.getId(),1);
                        }
                        oos.writeObject(msgB);
                        //ok -> ok + tocken du clien
                        //pas ok -> pas ok
                    break;
                case 1:
                    //envoi
                    break;
                case 2:
                    //reception
                    break;
                case 3:
                    //archivage
                    break;
                case 4:
                    //effacement
                    break;
                default : 
            }
        }
        s.close();
    }
}