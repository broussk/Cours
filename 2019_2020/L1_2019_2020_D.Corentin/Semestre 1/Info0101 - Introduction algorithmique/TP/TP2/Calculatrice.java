import java.util.Scanner;

class Calculatrice{
	
	public static void main(String [] args){
		Scanner clavier = new Scanner (System.in);
		
		System.out.println("Bienvenue dans une simple calculatrice :)");
		
		
		int continuer = 1;
		int nbreCalcul = 0;
     
        while (continuer == 1 && nbreCalcul < 5) {
		
			    System.out.print("Entrer une premiere valeur : ");
				int a = clavier.nextInt();
				System.out.print("Entrer une deuxieme valeur : ");
				int b = clavier.nextInt();
				System.out.print("Choissisez une operation (+ ou - ou * ou / : ");
				char ope = clavier.next().charAt(0);
				
				int res = 0;
				
				if( b==0 && ope == '/' ){
					System.out.print("Vous ne pouvez pas diviser par 0. Resaisisez une valeur : ");
					b = clavier.nextInt();
				}
				
				switch(ope){
					case '+' : res = a+b;
					break;
					
					case '-' : res = a-b;
					break;
					
					case '*' : res = a*b;
					break;
					
					case '/' : res = a/b;
					break;
				}
		
				System.out.println("Le resultat de " + a + ope + b + " est : " + res);
				System.out.println("Voulez-vous refaire un calcul ? (1 : oui, 2 : non)");
				continuer = clavier.nextInt();
				if(continuer == 1){
					nbreCalcul++;
				}
			} 
			
			
		}
					
}

