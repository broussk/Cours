import java.util.Scanner;
import java.util.Arrays;
import java.util.Date;
public class Recherche{

    public static int aleatoire(int min, int max){
        return (int) (Math.random()*((max + 1) -min))+min;
    }

    public static int[] genererTableau(int taille, int min, int max){
        int tab[] = new int[taille];
        for(int i =0; i<tab.length; i++){
            tab[i] = aleatoire(min, max);
        }
        return tab;
    }

    public static void afficher(int t[]){
         System.out.print("[");
        for(int i = 0; i<t.length; i++){
            System.out.print(t[i] + ", ");
        }
         System.out.print("]");
    }

    public static int rechercheSequentielle(int tab[], int nbr){
        int i = 0;
        boolean find = false;
        while(!find && i<tab.length){
          if(tab[i] == nbr){
              find = true;
          }else {
            i++;
          }
        }
        if(!find){
          i = -1;
        }
        return i;

    }

    public static int rechercheSequentielleTriee(int tab[], int nbr){
        int i = 0;
        boolean find = false;
        while(tab[i] < nbr && i<tab.length){
          if(tab[i] == nbr){
              find = true;
          }else {
            i++;
          }
        }
        if(i==tab.length || tab[i]!=nbr){
            i = -1;
        }
        return i;
    }


    public static long getTemps() {
      Date d = new Date();
      return d.getTime();
    }


    public static int rechercheDichotomique(int[] t, int val) {
      int binf = 1;
      int bsup = t.length - 1;
      int p = (binf + bsup) / 2;
      int i = -1;
      do {
          p = (binf + bsup) / 2;
          if (val == t[p]){
            i = p;
          }
          else if (t[p] < val) {
          binf = p + 1;
          }
          else{
            bsup = p - 1;
          }
      }
      while ((val != t[p]) & (binf <= bsup));
      return i;
  }


    public static void main(String[] args){
         Scanner cl = new Scanner(System.in);

        /*
        System.out.print("Entrer une taille de tableau : ");
        int taille = cl.nextInt();
        System.out.print("Entrer la borne minimal : ");
        int mini = cl.nextInt();
        System.out.print("Entrer la borne maximale : ");
        int maxi = cl.nextInt();
        int tab[]  = genererTableau(taille, mini, maxi);
        System.out.print("Tableau : ");
        afficher(tab);
        System.out.print("\nValeur a rechercher : ");
        int nombre = cl.nextInt();
        System.out.println(rechercheSequentielle(tab, nombre));



        System.out.print("\nNombre de recherche: ");
        int nbrecherche = cl.nextInt();
        int tab2[]  = genererTableau(nbrecherche, mini, maxi);
        System.out.print("Tableau: ");
        afficher(tab);
        System.out.print("\nTableau de recherche: ");
        afficher(tab2);
        System.out.print("\n");
        for(int i = 0 ; i<tab2.length ; i++){
            System.out.println("Nombre: " + tab2[i] + " (indice: " + rechercheSequentielle(tab, tab2[i])+")");
        }
        System.out.print("\n");

        System.out.print("\nNombre de recherche: ");
        int nombre2 = cl.nextInt();
        int tab3[]  = genererTableau(nombre2, mini, maxi);
        System.out.print("\nTableau: ");
        afficher(tab3);
        System.out.println("\nRecherche sequentielle:");
        for(int i = 0 ; i<tab2.length ; i++){
            System.out.println("Nombre: " + tab3[i] + " (indice: " + rechercheSequentielle(tab3, tab3[i])+")");
        }

        Arrays.sort(tab3);
        System.out.print("\nTableau triee: " + Arrays.toString(tab3));
        System.out.println("\nRecherche sequentielle triée:");
        for(int i = 0 ; i<tab2.length ; i++){
            System.out.println("Nombre: " + tab3[i] + " (indice: " + rechercheSequentielle(tab3, tab3[i])+")");
        }
        */


        /* Comparaison des algo de recherche*/

        //System.out.print("Entrer une taille de tableau: ");
        int nt = cl.nextInt();
        //System.out.print("Entrer la borne minimal: ");
        int min = cl.nextInt();
        //System.out.print("Entrer la borne maximale: ");
        int max = cl.nextInt();
        //System.out.print("Nombre de recherche: ");
        int r = cl.nextInt();

        int t[]  = genererTableau(nt, min, max);
        int tr[]  = genererTableau(r, min, max);


        /*Recherche sequentielle*/
        long timeseq1 = getTemps();
        for(int i = 0 ; i<tr.length ; i++){
            System.out.println("Nombre: " + tr[i] + " (indice: " + rechercheSequentielle(t, tr[i])+")");
        }
        long timeseq2 = getTemps();
        long timefinalseq = timeseq2 - timeseq1;


        /*Recherche sequentielle triée*/
        long timeseqt1 = getTemps();
        Arrays.sort(t);
        for(int i = 0 ; i<tr.length ; i++){
            System.out.println("Nombre: " + tr[i] + " (indice: " + rechercheSequentielleTriee(t, tr[i])+")");
        }
        long timeseqt2 = getTemps();
        long timefinalseqt = timeseqt2 - timeseqt1;


        /*Recherche  dichotomique*/
        long timedic1 = getTemps();
        for(int i = 0 ; i<tr.length ; i++){
            System.out.println("Nombre: " + tr[i] + " (indice: " + rechercheDichotomique(t, tr[i])+")");
        }
        long timedic2 = getTemps();
        long timedicfinal = timedic2 - timedic1;


        System.out.println("Le temps de la recherche sequentielle est de: " + timefinalseq + "ms");
        System.out.println("Le temps de la recherche sequentielle triee est de: " + timefinalseqt + "ms");
        System.out.println("Le temps de la recherche dichotomique est de: " + timedicfinal + "ms");


    }

}
