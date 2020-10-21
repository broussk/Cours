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

        while{
            msgA = oos.read(Object());
            if(msgA.getlist()[0].getIdMsg() == 0){
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
            }
        }
        s.close();
    }
}