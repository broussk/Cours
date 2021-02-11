import java.util.Scanner;

public class Mastermind2{
  
    public static void afficherTableauEntiers(int[] tb){
        for (int i = 0 ; i<tb.length ; i++){
            System.out.print(tb[i] + " ");
        }
        System.out.println("");
    }

    public static void afficherTableauCaracteres(char[] tbc){
        for (int i = 0 ; i<tbc.length ; i++){
            System.out.print(tbc[i] + " ");
        }
        System.out.println("");
    }

    public static int[] remplirSolution(int taille){
       int tab[] = new int[taille];
       int tab2[] = new int [taille];
       for (int i = 0 ; i<tab.length ; i++){
          tab[i] = (int) (Math.random()*(10-0))-0;
        }
    return tab; 
    }

    public static int[] saisirProposition(int taille, int min, int max){
     Scanner cl = new Scanner(System.in);
     int tbr[] = new int[taille];
     int r;
     for(int i = 0; i<tbr.length; i++){
         r = cl.nextInt();
         if(r<=max && r>=min){
             tbr[i] = r;
         } else {
            System.out.println("Reponse impossible ! Veuillez resaisir une reponse : ");
            r = cl.nextInt();
         }
     }
    return tbr;
   }

   public static boolean bienPlacee(int[] solution, int valeur, int position){
       return (solution[position] == valeur);
   }

   public static boolean malPlacee(int[] solution, int valeur, int position){
         boolean malPlacee = false;
         if(solution[position] != valeur){
             for(int i = 0; i<solution.length; i++){
                 if(solution[i] == valeur){
                   malPlacee = true;
                 }
             }
         }
    return malPlacee;
   }

   public static char[] compare(int[] proposition, int[] solution) {
       char tbc[] = new  char[solution.length];
       for(int i = 0; i<solution.length; i++){
           if(bienPlacee(proposition,solution[i],i) == true){
              tbc[i] = 'B';
           }
           else if (malPlacee(proposition,solution[i],i) == true){
              tbc[i] = 'M';
           }
           else {
              tbc[i] = '-';
           }
       }
    return tbc;
   }

   public static boolean gagne(char[] resultat){
       boolean gagner = true;
       for (int i = 0; i<resultat.length;i++){
          if (resultat[i] != 'B'){
              gagner = false;
              break;
          }
       }
    return gagner;
   }

   public static boolean afficherResultat(int[] proposition, int[] solution) {
       boolean gg = false;
       System.out.print("Proposition : ");
       afficherTableauEntiers(proposition);
       System.out.print("\nResultat    : ");
       afficherTableauCaracteres(compare(solution, proposition));
       if (gagne(compare(solution, proposition))){
           gg = true;
       }
    return gg;    
   }



   //Main
   
   public static void main(String[] args){
       Scanner cl = new Scanner(System.in);
       System.out.print("Saisir une taille : ");
       int taille = cl.nextInt();
       System.out.print("Entrer le minimum des valeurs a saisir : ");
        int min = cl.nextInt();
       System.out.print("Entrer le minimum des valeurs a saisir :  ");
        int max = cl.nextInt();
       int tb[] = remplirSolution(taille);
       boolean gagner = false;
       int partie = 0;
       while(!gagner){
           int tbr[] = saisirProposition(taille, min, max);
           if(afficherResultat(tbr, tb) == true){
                   gagner = true;
           } else {
               System.out.println("Mauvaise combinaison :( . Retentez votre chance : ");
           }
           partie++;
       }
       System.out.println("Bravo vous avez trouver la combinaison qui ete : ");
       afficherTableauEntiers(tb);
       System.out.println("Vous avez reussi en " + partie + " tours !");
    }
}