import java.util.Scanner;
public class TriSelection {

    static Scanner clavier = new Scanner(System.in);
    public static double[] allocation(int n) {
        double tb[] = new double[n];
        return tb;
    }

    public static void afficher(double tb[]) {
        for (int i = 0; i < tb.length; i++) {
            System.out.print(tb[i] + " ");
        }
        System.out.println("");
    }

    public static void rempliraleatoire(double tb[], int a, int b) {
        for (int i = 0; i < tb.length; i++) {
            tb[i] = a + (Math.random() * ((b - a) + 1));
            tb[i] = tb[i] * 10;
            tb[i] = (int) tb[i];
            tb[i] = tb[i] / 10;
        }
    }

    public static int indiceMinimum(double tb[]) {
        double min = 100;
        int imin = 0;
        for (int i = 0; i < tb.length; i++) {
            if (tb[i] < min) {
                min = tb[i];
                imin = i;
            }
        }
        return imin;
    }

    public static double maximum(double tb[]) {
        double max = tb[1];
        for (int i = 0; i < tb.length; i++) {
            if (tb[i] > max) {
                max = tb[i];
            }
        }
        return max;
    }

    public static void triselection(double tb[]) {
        double tb1[] = allocation(tb.length);
        for (int i = 0; i < tb1.length; i++) {
            tb1[i] = tb[indiceMinimum(tb)];
            tb[indiceMinimum(tb)] = maximum(tb);
        }
        afficher(tb1);
    }

    public static void main(String[] args) {
        Scanner clavier = new Scanner(System.in);
        System.out.println("Saisir la taille du tableau");
        int n = clavier.nextInt();
        System.out.println("Borne a:");
        int a = clavier.nextInt();
        System.out.println("Borne b:");
        int b = clavier.nextInt();
        double tb[] = allocation(n);
        rempliraleatoire(tb, a, b);
        System.out.println("Tableau non-trie: ");
        afficher(tb);

        System.out.println("Tableau trie: ");
        triselection(tb);
    }
}