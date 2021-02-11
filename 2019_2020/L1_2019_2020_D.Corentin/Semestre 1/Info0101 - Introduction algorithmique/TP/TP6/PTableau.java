import java.util.Scanner;
 public class PTableau{
     static Scanner clavier = new Scanner(System.in);
     public static void main (String[] arg){
         /*double tab[] = new double[3];
         tab[0] = 2.45;
         tab[1] = 23.65;
         tab[2] = 0.01;

         System.out.print(tab);*/

         System.out.println("Entrer taille tableau");
         int taille = clavier.nextInt();
         double tab[] = new double[taille];

         double max = 0.0;

         for(int i = 0 ; i<tab.length;i++) {
          System.out.print("Case ["+i+"] : ");
          tab[i]= clavier.nextDouble();
          if (tab[i] > max){
              max = tab[i];
          }
         }
         
         
         for(int i = 0 ; i<tab.length;i++) {
          System.out.print(tab[i] + " ");
         }

          System.out.print("Le max est : " + max);

     }
 }



































