import java.util.Scanner;
import java.lang.Math;

public class pendu2 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int nbEssais=0, joueur=1, cpt1=0, cpt2=0;
        String carac, nbJoueur;
        char carac1, nbJoueur1;

        System.out.print("Nombre de joueur (1 ou 2) : ");
        nbJoueur=sc.nextLine();
        nbJoueur1=nbJoueur.charAt(0);

        if (nbJoueur1=='1') {
            char [] motSol=convertir(dictionnaire());
                    //test dictionnaire()
            /*for (int g=0; g<motSol.length; g++) {
                System.out.print(motSol[g]);
            }*/

            char [] masque=creerMasque(motSol.length);

            do{
                afficherEssais(nbEssais, masque);
                System.out.print("Entrez un caractere en majuscule : ");    
                carac=sc.nextLine();
                carac1=carac.charAt(0);
                if (!jouer(motSol, masque, carac1)) {
                    nbEssais++;
                }
                System.out.println("nbEssais="+nbEssais);
            }while(nbEssais!=5 && !estFini(masque));

            afficherEssais(nbEssais,masque);

            if (nbEssais==5) {
                System.out.println("Vous avez perdu !");
            }
            else{
                System.out.println("Vous avez gagner ! ");
            }
        }
        else {
            do{
                System.out.println("Le mot a faire deviner du joueur "+joueur+" : ");
                char [] motSol=initialisationSolution();
                while(motSol[0]=='0'){
                    System.out.println("Le mot a faire deviner incorrecte, en ecrire un autre : ");
                    motSol=initialisationSolution();
                }

                char [] masque=creerMasque(motSol.length);

                do{
                    afficherEssais(nbEssais, masque);
                    System.out.print("Entrez un caractere en majuscule : ");    
                    carac=sc.nextLine();
                    carac1=carac.charAt(0);
                    if (!jouer(motSol, masque, carac1)) {
                        nbEssais++;
                    }
                    System.out.println("nbEssais="+nbEssais);
                }while(nbEssais!=5 && !estFini(masque));

                if (joueur==1) {
                    if (nbEssais==5) {
                        System.out.println("Vous avez perdu !");
                        cpt1++;
                    }
                    else{
                        System.out.println("Vous avez gagner ! ");
                        cpt1--;
                    }
                }
                else {
                    if (nbEssais==5) {
                        System.out.println("Vous avez perdu !");
                        cpt2++;
                    }
                    else{
                        System.out.println("Vous avez gagner ! ");
                        cpt2--;
                    }
                }
                joueur++;
            }while(joueur!=3);
            if (cpt1==cpt2) {
                System.out.println("Joueur, vous etes a egalite!");
            }
            else {
                if (cpt1<cpt2) {
                    System.out.println("Le joueur 2 gagne la partie ! Bravo !");
                }
                else{
                    System.out.println("Le joueur 1 gagne la partie ! Bravo !");
                }
            }   
        }
    }

    public static boolean estValide (String mot){
        int taille, cpt=0;

        taille=mot.length();

        if (taille<4) {
            return false;
        }

        for (int i=0; i<taille; i++) {
            char caracMot = mot.charAt(i);
            for (int j='A'; j<='Z'; j++) {
                if (caracMot==j) {
                    cpt++;
                }
            }
        }

        if (cpt!=taille) {
            return false;
        }

        return true;
    }

    public static char [] convertir (String mot){
        char [] charMot= new char [mot.length()];

        for (int i=0; i<mot.length(); i++) {
            charMot[i]=mot.charAt(i);
        }
        return charMot;
    }

    public static char [] initialisationSolution (){
        Scanner sc = new Scanner(System.in);
        String mot;

        System.out.print("Entrez votre mot en majuscule : ");
        mot=sc.nextLine();
        
        if(estValide(mot)){
            return convertir(mot);
        }
        else{
        	return convertir("0");
        }
    }

    public static char [] creerMasque (int n){
        char [] masque= new char [n];
        for (int i=0; i<n; i++) {
            masque[i]='-';
        }
        return masque;
    }

    public static void afficher (char [] caracMot){
        for (int i=0; i<caracMot.length; i++) {
            System.out.print(caracMot[i]);
        }
        System.out.println();
    }

    public static boolean jouer (char [] motSol, char [] masque, char carac){
        boolean trouve=false;
        for (int i=0; i<motSol.length; i++) {
            if (motSol[i]==carac) {
                masque[i]=carac;
                trouve=true;
            }
        }
        return trouve;
    }

    public static void afficherEssais (int nbEssais, char [] masque){
        System.out.println("Il vous reste "+(5-nbEssais)+" essais !");

        afficher(masque);

        switch(nbEssais) {
            case 5: // La potence en entier et le pendu
                System.out.println(" /---\\\n |   |\n |   O\n |  /|\\\n |  / \\\n-^-");
                break;
            case 4: // La potence en entier
                System.out.println(" /---\\\n |   |\n |\n |\n |\n-^-");
                break;
            case 3: // La potence sans la corde
                System.out.println(" /---\\\n |\n |\n |\n |\n-^-");
                break;
            case 2: // Le corps de la potence
                System.out.println("\n |\n |\n |\n |\n-^-");
                break;
            case 1: // Le pied de la potence
                System.out.println("\n\n\n\n\n-^-");
                break;
        }
    }

    public static boolean estFini (char [] masque){
    	boolean fin=true;
        int cpt=masque.length;

        for (int i=0; i<masque.length; i++) {
            if (masque[i]=='-') {
                cpt--;
            }
        }

        if (cpt!=masque.length) {
            fin=false;
        }

        return fin;
    }

    public static String dictionnaire (){
        int alea;
        String mot;
        alea=(int)(Math.random()*10);
        switch(alea){
            case 1:
                mot="FRAISE";
                break;
            case 2:
                mot="LIVRE";
                break;
            case 3:
                mot="BONBON";
                break;
            case 4:
                mot="CADRE";
                break;
            case 5:
                mot="CAHIER";
                break;
            case 6:
                mot="ORDINATEUR";
                break;
            case 7:
                mot="JAVA";
                break;
            case 8:
                mot="BOITE";
                break;
            case 9:
                mot="AMOUR";
                break;
            default :
                mot="TABARNAK";
                break;
        }
        return mot;
    }
}