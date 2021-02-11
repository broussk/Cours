import java.util.Scanner;
import java.util.Date;
public class Tries {

    public static int aleatoire(int min, int max) {
        return (int)(Math.random() * ((max + 1) - min)) + min;
    }

    public static int[] genererTableau(int taille, int min, int max) {
        int tab[] = new int[taille];
        for (int i = 0; i < tab.length; i++) {
            tab[i] = aleatoire(min, max);
        }
        return tab;
    }


    public static long getTemps() {
        Date d = new Date();
        return d.getTime();
    }

    public static int[] clone(int tab[]) {
        int tabclone[] = new int[tab.length];
        for (int i = 0; i < tab.length; i++) {
            tabclone[i] = tab[i];
        }
        return tabclone;
    }

    public static void triSelection(int tab[]) {
        long t1 = getTemps();
        for (int i = 0; i < tab.length - 1; i++) {
            int index = i;
            for (int j = i + 1; j < tab.length; j++) {
                if (tab[j] < tab[index]) {
                    index = j;
                }
            }
            int min = tab[index];
            tab[index] = tab[i];
            tab[i] = min;
        }
        //afficher(tab);
        long t2 = getTemps();
        long tf = t2 - t1;
        System.out.print("Le temps du trie par selection est de:" + tf + "ms\n");

    }

    public static void triSelectionEchange(int tab[]) {
        int min;
        int x;
        long t1 = getTemps();
        for (int i = 0; i < tab.length - 1; i++) {
            min = i;
            for (int j = i + 1; j < tab.length; j++) {
                if (tab[j] < tab[min]) {
                    min = j;
                }
                if (min != i) {
                    x = tab[i];
                    tab[i] = tab[min];
                    tab[min] = x;
                }
            }
        }
        //afficher(tab);
        long t2 = getTemps();
        long tf = t2 - t1;
        System.out.print("Le temps du trie par selection echange est de:" + tf + "ms\n");
    }

    public static void triInsertion(int tab[]) {
        int cpt;
        int element;
        long t1 = getTemps();

        for (int i = 1; i < tab.length; i++) {
            element = tab[i];
            cpt = i - 1;
            while (cpt >= 0 && tab[cpt] > element) {
                tab[cpt + 1] = tab[cpt];
                cpt--;
            }
            tab[cpt + 1] = element;
        }
        //afficher(tab);
        long t2 = getTemps();
        long tf = t2 - t1;
        System.out.print("Le temps du trie par insertion est de:" + tf + "ms\n");

    }

    public static void afficher(int t[]) {
        for (int i = 0; i < t.length; i++) {
            System.out.print(t[i] + " ");
        }
    }


    public static void main(String[] args) {
        Scanner cl = new Scanner(System.in);
        System.out.print("Entre une taille de tableau: ");
        int taille = cl.nextInt();
        System.out.print("Entrer la borne minimal: ");
        int min = cl.nextInt();
        System.out.print("Entrer la borne maximale: ");
        int max = cl.nextInt();

        int t[] = genererTableau(taille, min, max);
        int ct[] = clone(t);

        //afficher(t);
        System.out.print("\n");
        triSelection(ct);
        triSelectionEchange(ct);
        triInsertion(ct);
    }
}
