public class Decorateur {
    private Codeur codeur = new Codeur();
    //non optimisé
    /*
    public String encode(String messageACode){
        String s = "", sEnvers = (new StringBuffer(messageACode)).reverse().toString();
        s = sEnvers + messageACode + sEnvers + messageACode;
        return s;
    }

    public String decode(String messageCode){
        String s = "";
        int count = messageCode.length()/4;
        s = messageCode.substring(count, count*2);
        return s;
    }
    */

    //optimisation : 
    /*
    public String encode(String messageACode){
        String s = (new StringBuffer(messageACode)).reverse().toString();
        s += messageACode;
        s += s;        
        return s;
    }

    public String decode(String messageCode){
        int count = messageCode.length()/4;
        messageCode = messageCode.substring(count, count*2);
        return messageCode;
    }
    */

    //decorateur + codeur :
    public String encode(String messageACode){
        String s = (new StringBuffer(messageACode)).reverse().toString();
        s += messageACode;
        s += s;
        try {
            s = codeur.encode(s);    
        } catch (Exception e) {
            System.out.println("erreur encode Codeur dans decorateur\n "+ e.toString());
        } 
        return s;
    }

    public String decode(String messageCode){
        int count = messageCode.length()/4;
        try {
            messageCode = codeur.decode(messageCode);    
        } catch (Exception e) {
            System.out.println("erreur decode Codeur dans decorateur \n " + e.toString());
        }
        messageCode = messageCode.substring(count, count*2);
        return messageCode;
    }
    
}
