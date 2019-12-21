import java.io.ObjectOutputStream;
import java.io.FileOutputStream;

public class WriteSecretMessage
{
    public static void main(String[] args)
    {
	if(args.length<2)
	    {
		System.out.println("Usage : writeSecretMessage fileName value1 value2 ... ");
		System.out.println("        into the file fileName, save all the remaining ");
		System.out.println("        values of the command line");
		return;
	    }

	ObjectOutputStream out=null;

	try
	    {
		out=new ObjectOutputStream(new FileOutputStream(args[0]));
	    }
	catch(Exception e)
	    {
		System.out.println(e);
		System.exit(10);
	    }

	SecretMessage secret=new SecretMessage();
	
	
	for(int i=1;i<args.length;i++)
	    {
		secret.addMessage(args[i]);
	    }

	System.out.println(secret);
	
	try
	    {
		out.writeObject(secret);
	    }
	catch(Exception e)
	    {
		System.out.println(e);
		System.exit(20);
	    }
	finally
	    {
		try
		    {
			out.flush();
			out.close();
		    }
		catch(java.io.IOException ioe)
		    {
			System.out.println(ioe);
			System.exit(30);
		    }
		
	    }
    }
}
