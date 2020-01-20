import java.io.ObjectInputStream;
import java.io.FileInputStream;

public class ReadSecretMessage
{
    public static void main(String[] args)
    {
	if(args.length!=1)
	    {
		System.out.println("Usage : readSecretMessage fileName ");
		System.out.println("        fileName must contain the message encoded by WriteSecretMessage");
		System.exit(10);
	    }

	ObjectInputStream in=null;
	
	try
	    {
		in=new ObjectInputStream(new FileInputStream(args[0]));
		SecretMessage message=(SecretMessage)in.readObject();
		System.out.println(message);

	    }
	catch(Exception e)
	    {
		System.out.println(e);
		System.exit(20);
	    }
	finally
	    {
		if(in != null)
		    {
			try
			    {
				in.close();
			    }
			catch(java.io.IOException ioe)
			    {
				System.out.println(ioe);
				System.exit(20);
			    }
		    }
	    }
    }
}
