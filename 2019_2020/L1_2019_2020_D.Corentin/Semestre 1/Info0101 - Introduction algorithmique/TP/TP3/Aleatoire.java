import java.util.Scanner;
public class Aleatoire{
	static Scanner clavier = new Scanner(System.in);
	public static void main(String[] args){
		
		/*int n = clavier.nextInt();
		double a = 0.0;
		for (int i=0; i<n;i++){
			 a = Math.random();
			 System.out.println(a);
		}
	  */
	  
	  /*int n = clavier.nextInt();
	  double a = 0.0;
	  double b = 0.0;
		for (int i=0; i<n;i++){
			 a = Math.random();
			 double c = Math.min(a,b);
			 System.out.println(a);
			 System.out.println("Min : " + c);
		}
	*/
	  /*int n = clavier.nextInt();
	  int a = 0;
	  
		for (int i=0; i<n;i++){
			 a = (int)(Math.random()*(10 - 0 ));	 
			 System.out.println(a);
	
		}
	*/
    
	  
		int n = clavier.nextInt();
		for (int i=0; i<n;i++){	 
			 System.out.println(-5+ (int)(Math.random() * ((5 - (-5)) + 1)));
	
		}
		
	}
	
}