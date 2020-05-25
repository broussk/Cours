import java.util.Scanner;

class calculatrice{
    public static void main(String[] args) {
        Scanner clavier = new Scanner(System.in);
        int a,b, resultat=0, tape;

        for (int i=1;i<=5 ;i++ ) {
            System.out.print("Saisir une valeur A : ");
            a = clavier.nextInt();
            System.out.print("Saisir une valeur B : ");
            b = clavier.nextInt();
            System.out.println("Saisir un nombre pour indiquer l'operation a effectuer:");
            System.out.println("1: somme");
            System.out.println("2: soustraction");
            System.out.println("3: multiplication");
            System.out.println("4: division");
            tape = clavier.nextInt();

            switch(tape){
                case 1: 
                    System.out.print("vous avez tape " +a+ " et " +b+ " et choisi la somme, le resultat est:");
                    resultat = a+b;
                break;
                case 2:
                    System.out.print("vous avez tape " +a+ " et " +b+ " et choisi la soustraction, le resultat est:");
                    resultat = a-b;
                break;
                case 3:
                    System.out.print("vous avez tape " +a+ " et " +b+ " et choisi la multiplication, le resultat est:");
                    resultat = a*b;
                break;
                case 4:
                    if (b>0) {
                        System.out.print("vous avez tape " +a+ " et " +b+ " et choisi la division, le resultat est:");
                        resultat = a/b;
                    }
                    else { 
                        System.out.print("erreur");
                    }
                break;
                default:
                    System.out.print("erreur");
                break;
            }
            System.out.println(resultat);
        }
        
    }
}