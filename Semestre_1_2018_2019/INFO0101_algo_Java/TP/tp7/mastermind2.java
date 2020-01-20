import java.util.Scanner;
import java.lang.Math;

public class mastermind2 {

                    //fonction bonne
	public static void main(String[] args) {  
        Scanner sc = new Scanner(System.in);
        int taille=4, cpt=0;
        int [] sol;
        int [] t;

        sol=remplirSolution(taille);

        do{
            cpt++;
            t=saisirProposition(taille);
        }while(afficherResultat(t,sol)!=true); 

        System.out.println("Vous avez trouve en "+cpt+" tours.");       
    }

                    //fonction bonne
    public static void afficherTableauEntiers (int [] t){
        for (int i=0; i<t.length; i++) {
            System.out.print(t[i]+" ");
        }
    }

                    //fonction bonne
    public static void afficherTableauCaracteres (char [] t){
        for (int i=0; i<t.length; i++) {
            System.out.print(t[i]+" ");
        }
    }

                    //fonction bonne
    public static int [] remplirSolution (int taille){
        int [] t = new int [taille];
        for (int i=0; i<t.length; i++) {
           t[i] = (int)(Math.random()*10);
        }
        return t;
    }

                    //fonction bonne
    public static int [] saisirProposition (int taille){
        Scanner sc = new Scanner(System.in);
        int chiffre;
        int [] t = new int [taille];
        for (int i=0; i<4; i++) {
            do{
                System.out.print("Entrez un chiffre pour la case "+(i+1)+" : ");
                t[i]=sc.nextInt();
            }while(t[i]<0 || t[i]>9);            
        }
        return t;
    }

                    //fonction bonne
    public static boolean bienPlacee (int [] solution, int valeur, int position){
        boolean rep=false;
        for (int i=0; i<solution.length; i++) {
            if (valeur==position) {
                rep= true;
            }
            else{
                rep= false;
            }
        }
        return rep;
    }
    
                    //fonction bonne
    public static boolean malPlacee (int [] solution, int valeur, int position){
        boolean rep=false;
        for (int i=0; i<solution.length; i++){
            if(valeur==solution[i] && valeur!=position){
                rep=true;
            }
        }
        return rep;
    }

                    //fonction bonne
    public static char [] compare (int  [] proposition, int  [] solution){
        char []rep={' ',' ',' ',' '};
        for (int i=0; i<proposition.length; i++) {
            if (bienPlacee(solution,proposition[i],solution[i])) {
                rep[i]='B';
            }
            else {
                if (malPlacee(solution,proposition[i],solution[i])) {
                    rep[i]='M';
                }
                else {
                    rep[i]='F';
                }
            }
        }
        return rep;
    }

                    //fonction bonne
    public static boolean gagne(char[] resultat){
        int i=0;
        char [] sol={'B','B','B','B'};
        if (resultat[0]==sol[0] && resultat[1]==sol[1] && resultat[2]==sol[2] &&resultat[3]==sol[3]) {
            return true;
        }
        else{
            return false;
        }
    }

                    //fonction bonne
    public static boolean afficherResultat (int [] proposition, int [] solution){
        afficherTableauEntiers(proposition);
        System.out.println();
        afficherTableauCaracteres(compare(proposition, solution));
        System.out.println();
        return gagne(compare(proposition, solution));
    }
}