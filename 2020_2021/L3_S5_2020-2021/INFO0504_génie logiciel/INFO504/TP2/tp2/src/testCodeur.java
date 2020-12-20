//compilation :  javac -d .\cls\ -cp .\misc\ -sourcepath .\src\ .\src\testCodeur.java
//execution : java -cp "cls;misc" testCodeur

import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;

public class testCodeur {

	public static void main(String[] args) {
		Codeur codeur = new Codeur();
		Decorateur deco = new Decorateur();
		Adaptateur adapt = new Adaptateur();
		String message = "coucou";
		String messageCode = "";
		String messageDecode = ""; 

		//Codeur :
		/*
		try{
			messageCode = codeur.encode(message);
			System.out.println(messageCode);
		}
		catch(Exception e){
			System.out.println("erreur1");
		}
		try{
			String messageDecode = codeur.decode(messageCode);
			System.out.println(messageDecode);
		}
		catch(Exception e){
			System.out.println("erreur2");
		}
		*/
		
		//Decorateur :
		System.out.println(message);
		messageCode = deco.encode(message);
		System.out.println(messageCode);
		System.out.println(deco.decode(messageCode));
		
		//Decorateur + Codeur :
		/*System.out.println(message);
		try{
			messageCode = deco.encode(message);
			messageCode = codeur.encode(messageCode);
			System.out.println(messageCode);
		}
		catch(Exception e){
			System.out.println("erreur1");
		}
		try{
			messageDecode = codeur.decode(messageCode);
			messageDecode = deco.decode(messageDecode);
			System.out.println(messageDecode);
		}
		catch(Exception e){
			System.out.println("erreur2");
		}*/

		//Adaptateur
		/*
		String absolutePathJava = new File("testCodeur.java").getAbsolutePath();
		String filePath = absolutePathJava.substring(0,absolutePathJava.lastIndexOf(File.separator));
		String filePathImage = filePath+"\\src\\chaton_mignon.jpg"; 
		=> concaténation : 
		*/
		String absolutePathImage = (new File("testCodeur.java").getAbsolutePath()).substring(0,new File("testCodeur.java").getAbsolutePath().lastIndexOf(File.separator)) + "\\src\\chaton_mignon.jpg";
		System.out.println("chemin absolu Image : " + absolutePathImage );

		File image = new File(absolutePathImage);
		String sImg = adapt.encodeImage(absolutePathImage);
		System.out.println(sImg);
	}

}
