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
    private MessageEchangeListe messageEchangeListe;

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

        
    }
}