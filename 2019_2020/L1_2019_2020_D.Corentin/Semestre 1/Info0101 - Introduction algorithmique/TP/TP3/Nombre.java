import java.util.Scanner;
public class Nombre {
    static Scanner clavier = new Scanner(System.in);
    public static void main(String[] args) {
        
		
		/*
		
		int nbr = (int)(Math.random() * ((1024 - 1) + 1));
        System.out.println(nbr);
        int n = 0;


        while (n != nbr) {
            System.out.println("Quel est le nombre ?");
            n = clavier.nextInt();
            
			if (n < nbr) {
                System.out.println("Trop petit.");
            } 
	
			else if (n > nbr) {
				System.out.println("Trop grand.");
            }
			else if (n == nbr) {
            System.out.println("Bien joue tu as trouve");

        }
    }
	
	*/
	
	/*
	
		int nbr = (int)(Math.random() * ((1024) + 1));
        System.out.println(nbr);
        int n = 1;
        int min = -1;
        int max = 1025;



        while (n != nbr) {
            System.out.println("Quel est le nombre ?");
            n = clavier.nextInt();

            if (n < nbr) {
                if (n <= min) {
                    System.out.println("Trop petit je te l'ai deja dit!");
                } else if (n > min) {
                    System.out.println("Trop petit.");
                    min = n;
                }
            } else if (n > nbr) {
                if (n >= max) {
                    System.out.println("Trop grand je te l'ai deja dit!");
                } else if (n < max) {
                    System.out.println("Trop grand.");
                    max = n;
                }
            } else if (n == nbr) {
                System.out.println("Bien joue tu as trouve");

            }
        }
		
	*/
    	
    /*
    	int nbr = (int)(Math.random() * ((1024) + 1));
        System.out.println(nbr);
        int n = 1;
        int min = -1;
        int max = 1025;
        int essais = (int) (Math.log(1024)/Math.log(2));
      

        System.out.println("Vous devez trouver un nombre entre 1 et 1024. Vous avez "+ essais + " essais.");

        while (n != nbr ) {
            System.out.print("Quel est le nombre ? ");
            n = clavier.nextInt();
            essais = essais -1;

            if (n < nbr) {
                if (n <= min) {
                    System.out.println("Trop petit je te l'ai deja dit!");
                    System.out.println("Il vous reste " + essais + " essais.");
                } else if (n > min) {
                    System.out.println("Trop petit.");
                    System.out.println("Il vous reste " + essais + " essais.");
                    min = n;
                }
             
            } else if (n > nbr) {
                if (n >= max) {
                    System.out.println("Trop grand je te l'ai deja dit!");
                    System.out.println("Il vous reste " + essais + " essais.");
                } else if (n < max) {
                    System.out.println("Trop grand.");
                    System.out.println("Il vous reste " + essais + " essais.");
                    max = n;
                }
                
            } else if (n == nbr) {
                System.out.println("Bien joue tu as trouve");

            }
            
            if (essais == 0 ) {
            	System.out.println("Perdus. Le nombre qu'il fallait trouver est : " + nbr);
            	break;
            }
        }
	
	  */ 
	 
	 
		System.out.print("Entrer la borne minimale : ");
	  	int bmin = clavier.nextInt();
		System.out.print("Entrer la borne maximale : ");
		int bmax = clavier.nextInt();
		
        
		int nbr = (int)(Math.random() * ((bmax-bmin) + 1));
        System.out.println(nbr);
        int n = 1 + nbr;
        int min = -1;
        int max = 1025;
        int essais = (int) (Math.log(bmax)/Math.log(2));
      

        System.out.println("Vous devez trouver un nombre entre "+ bmin +" et "+ bmax + ". Vous avez "+ essais + " essais.");

        while (n != nbr ) {
            System.out.print("Quel est le nombre ? ");
            n = clavier.nextInt();
            essais = essais -1;

            if (n < nbr) {
                if (n <= min) {
                    System.out.println("Trop petit je te l'ai deja dit!");
                    System.out.println("Il vous reste " + essais + " essais.");
                } else if (n > min) {
                    System.out.println("Trop petit.");
                    System.out.println("Il vous reste " + essais + " essais.");
                    min = n;
                }
             
            } else if (n > nbr) {
                if (n >= max) {
                    System.out.println("Trop grand je te l'ai deja dit!");
                    System.out.println("Il vous reste " + essais + " essais.");
                } else if (n < max) {
                    System.out.println("Trop grand.");
                    System.out.println("Il vous reste " + essais + " essais.");
                    max = n;
                }
                
            } else if (n == nbr) {
                System.out.println("Bien joue tu as trouve !");

            }
            
            if (essais == 0 ) {
            	System.out.println("Perdus. Le nombre qu'il fallait trouver est : " + nbr);
            	break;
            }
        }
		
	 
}
}
