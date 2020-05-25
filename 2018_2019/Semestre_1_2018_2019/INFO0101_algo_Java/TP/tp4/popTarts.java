import java.util.Scanner;
import java.lang.Math;

public class popTarts {
	public static void main(String[] args) {  
		Scanner sc = new Scanner(System.in);
		int menu=1, cptParties=0, cptGagne=0, cptPerdu=0;
		while(menu==1){
			cptParties++;
			if (jouer()==1) {
				System.out.println("Le joueur a gagne ! BRAVO !!");
				cptGagne++;
			}
			else{
				System.out.println("L'ordinateur a gagne ! DOMMAGE !!");
				cptPerdu++;
			}
			System.out.println("Que voulez-vous faire:");
			System.out.println("1 = rejouer");
			System.out.println("2 = quitter");
			System.out.println("3 = afficher les statistiques de vos parties precedentes");
			menu=sc.nextInt();
			if (menu==3) {
				System.out.println("Vous avez joue     : "+cptParties+" parties.");
				System.out.println("Vous en avez gagne : "+cptGagne+" parties.");
				System.out.println("Vous en avez perdu : "+cptPerdu+" parties.");
			}
		}
    }

    public static int jeuOrdi(int n) {
    	double prisOrdi;
    	prisOrdi=Math.random()*3+1;

    	if (n==1 || n==2) {
			prisOrdi=1;
		}
		if (n==3) {
			prisOrdi=2;
		}

    	n=n-(int)prisOrdi;
    	
    	System.out.println("L'ordinateur a ramasse "+(int)prisOrdi+" pop-Tarts.");
    	return n;
    }

    public static int jeuJoueur(int n){
    	Scanner sc=new Scanner(System.in);
    	int prisJoueur=1;
    	do{
	   		System.out.print("Combien de pop-Tarts voulez-vous en ramasser : ");
	    	prisJoueur=sc.nextInt();
	    }while (prisJoueur<1||prisJoueur>3);
   		n=n-prisJoueur;
    	return n;
    }

    public static int jouer(){
    	double n;
    	int popTarts, res=0;
    	do{
        	n=Math.random()*20+1;
    	}while (n<10);
    	popTarts=(int)n;
    	System.out.println("Il y a "+ popTarts+" popTarts.");
    	while(popTarts>0){
    		for (int i=1; i<=2; i++) {
    			if (i==1) {
    				System.out.println("C'est a vous de jouer JOUEUR !");
					popTarts=jeuJoueur(popTarts);
					System.out.println("Il reste "+popTarts+" pop-Tarts.");
					res=0;
    			}
    			else {
    				if (popTarts>0) {
	    				popTarts=jeuOrdi(popTarts);
						System.out.println("Il reste "+popTarts+" pop-Tarts.");
						res=1;
    				}
    			}
    		}
    	}
		return res;
    }
}