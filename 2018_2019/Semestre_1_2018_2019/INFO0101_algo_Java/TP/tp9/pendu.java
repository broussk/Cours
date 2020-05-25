import java.util.Scanner;

public class pendu {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int nbEssais=0;
        String carac;
        char carac1;

        System.out.println("Le mot a faire deviner : ");
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

        afficherEssais(nbEssais,masque);

        if (nbEssais==5) {
            System.out.println("Vous avez perdu !");
        }
        else{
        	System.out.println("Vous avez gagner ! ");
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
}