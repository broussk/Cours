import java.util.Scanner;
public class Notes {

    static Scanner clavier = new Scanner(System.in);

    public static void remplissage(double tb[]) {
        int i = 0;

        System.out.println("Note sur ?");
        int nt = clavier.nextInt();
        while (i < tb.length) {
            System.out.println("Note : ");
            double n = clavier.nextDouble();
            if (n < nt && n < 0) {
                System.out.println("La note doit être saisie entre 0 et  " + nt + ".");
                System.out.println("Nouvelle saisie : ");
                n = clavier.nextDouble();
                tb[i] = n;
                i = i + 1;
            } else {
                tb[i] = n;
                i = i + 1;
            }
        }
    }

    public static void afficherTAB(double tb[]) {
        System.out.println("-----");
        for (int i = 0; i < tb.length; i++) {
            System.out.println("| " + tb[i] + " |");
        }
        System.out.println("-----");
    }

    public static double moyenneNotes(double tb[]) {
        double somme = 0.0;
        for (int i = 0; i < tb.length; i++) {
            somme += tb[i];
        }

        double moy = (double) somme / tb.length;
        return moy;
    }

    public static void main(String[] args) {
        System.out.print("Saisir le nombre de notes : ");
        int taille = clavier.nextInt();
        double t[] = new double[taille];
        remplissage(t);
        afficherTAB(t);
        System.out.print("------------------------------");
        System.out.print("Moyennes des notes : ");
        System.out.print(moyenneNotes(t));
        System.out.print("------------------------------");

    }



}