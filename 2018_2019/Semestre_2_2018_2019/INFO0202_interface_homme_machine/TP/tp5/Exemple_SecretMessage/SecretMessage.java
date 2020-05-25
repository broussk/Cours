import java.io.Serializable;
import java.util.Vector;
import java.util.Iterator;

public class SecretMessage implements Serializable
{
    private static final long serialVersionUID = 11111111L;

    private int specialValue;
    private Vector<String> messages;
    private transient int oddValue; 
	
    public SecretMessage()
    {
	messages = new Vector<String>();
	specialValue=(int)(Math.random()*1024);
	oddValue=(int)(Math.random()*1024);
    }

    public void addMessage(String message)
    {
	messages.add(message);
    }

    public String toString()
    {
	String secretMessage="=============================";
	secretMessage+="\nThe special value is "+specialValue;
	secretMessage+="\nThe odd value is "+oddValue;
	secretMessage+="\nThe secret message is ";

	Iterator<String> it=messages.iterator();
	while(it.hasNext())
	    {
		secretMessage+="\n\t"+it.next();
	    }

	secretMessage+="\n=============================";

	return secretMessage;
    }
}
