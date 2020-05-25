import java.util.Scanner;
import java.lang.Math;

public class mastermind3 {
                    //fonction bonne
	public static void main(String[] args) {  
        Scanner sc = new Scanner(System.in);
        int taille, cpt1=0, cpt2=0, minimum=0, maximum, nbJoueurs, joueur=0, cpt=0;

        System.out.print("Combien de joueur(s) [1 a 2] : ");
        nbJoueurs=sc.nextInt();
        do{
            System.out.print("Veuillez entrer une taille de cases (avec un minimum de 4 cases) : ");
            taille=sc.nextInt();
        }while(taille <4);
        
        System.out.print("Saisissez le minimum (inclut) que vous souhaitez : ");
        minimum=sc.nextInt();
        System.out.print("Saisissez le maximum (exclu) que vous souhaitez : ");
        maximum=sc.nextInt();

        int [] t = new int [taille];
        int [] sol = new int [taille];

        if (nbJoueurs==1) {
            sol=remplirSolution(taille, minimum, maximum);
            do{
                cpt++;
                t=saisirProposition(taille, minimum, maximum);
            }while(afficherResultat(t,sol)!=true); 
            System.out.println("Vous avez trouve la solution en "+cpt+" tours. Bravo !");
        }
        else{
            do{
                System.out.println("Joueur "+(joueur+1)+" qui joue, autre joueur veuillez placer les chiffres:");   
                for (int i=0; i<taille; i++) {
                    do{
                        System.out.print("Case "+(i+1)+" : ");
                        sol[i]=sc.nextInt();
                    }while(sol[i]<minimum || sol[i]>=maximum);
                }

                for (int j=0; j<100; j++) {
                    System.out.println();
                }
                
                System.out.println("Le joueur qui n'a pas placer les numeros joue : ");
                System.out.println("Bon jeu !");      

                do{
                    if (joueur==0) {
                        cpt1++; 
                    }
                    else{
                        cpt2++;
                    }
                    
                    t=saisirProposition(taille, minimum, maximum);
                }while(afficherResultat(t,sol)!=true); 

                joueur++;
            }while(joueur!=2);
            if (cpt1>cpt2) {
                joueur=2;
            }
            else{
                if (cpt2>cpt1) {
                    joueur=1;
                }
                else{
                    joueur=0;
                }
            }
            if (joueur != 0) {
                System.out.print("Le joueur qui a gagne est le joueur "+joueur+" qui a trouver la soltion plus rapidement que l'autre joueur! Bravo a lui!");  
            }
            else{
                System.out.print("Les 2 joueurs sont a egalite. Bravo a vous !");
            }
        }
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

                    //trouver un autre traitement des cases !
    public static int [] remplirSolution (int taille, int min, int max){
        int [] t = new int [taille];
        int k=0;
        for (int i=0; i<t.length; i++) {
            t[i] = (int)(Math.random()*(max-min)+min);
            for (int j=0; j<i; j++) {
                if (t[i]==t[j]){
                    t[i] = (int)(Math.random()*(max-min)+min);
                    //System.out.print("ti"+t[i]);
                }
            }
            //System.out.print(t[i]+" ");
        }
        return t;
    }

                    //fonction bonne
    public static int [] saisirProposition (int taille, int minimum, int maximum){
        Scanner sc = new Scanner(System.in);
        int chiffre;
        int [] t = new int [taille];
        for (int i=0; i<t.length; i++) {
            do{
                System.out.print("Entrez un chiffre pour la case "+(i+1)+" : ");
                t[i]=sc.nextInt();
            }while(t[i]<minimum || t[i]>maximum);            
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
        char []rep=new char [proposition.length];
        int cpt=0;
        for (int i=0; i<proposition.length; i++) {
            if (bienPlacee(solution,proposition[i],solution[i])) {
                rep[i]='B';
            }
            else {
                if (malPlacee(solution,proposition[i],solution[i])) {
                    rep[i]='M';
                }
                else {
                    rep[i]=' ';
                    cpt++;
                }
            }
        }
        if (cpt==proposition.length) {
            for (int j=0; j<proposition.length; j++) {
                if (j==0){
                    rep[j]='N';
                }
                else {
                    if (j==proposition.length-1 || j==proposition.length-2) {
                        rep[proposition.length-1]='L';
                        rep[proposition.length-2]='L';
                    }
                    else{
                        rep[j]='U';
                    }
                }
            }
        }
        return rep;
    }

                    //fonction bonne
    public static boolean gagne(char[] resultat, int taille){
        int cpt=0;
        char [] sol = new char [taille];
        for (int j=0; j<sol.length; j++) {
            sol[j]='B';
        }
        for(int i=0; i<sol.length; i++){
            if (resultat[i]==sol[i]) {
                cpt++;
                System.out.print("cpt="+cpt);
            }
        }
        System.out.println("cpt1:"+cpt);
        if (cpt==sol.length) {
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
        System.out.println("proposition.length"+proposition.length);
        return gagne(compare(proposition, solution), proposition.length);
    }
}