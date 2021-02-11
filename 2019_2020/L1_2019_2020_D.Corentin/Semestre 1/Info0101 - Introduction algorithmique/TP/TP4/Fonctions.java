import java.util.Scanner;

public class Fonctions{
  static Scanner clavier = new Scanner(System.in);
  public static void main(String[] args){

   System.out.print("Que voulez vous faire ? : \n1) Factorielle \n2) Puissance \n3) PGCD ");
   int choix = clavier.nextInt();

   switch (choix){
     case 1 :
      System.out.print("Entrer un premier nombre : ");
      int nb = clavier.nextInt();
      System.out.print("La factoriellle de " + nb + " est " + factorielle(nb));
     break;

     case 2 :
     System.out.print("Entrer un premier nombre : ");
     int x = clavier.nextInt();
     System.out.print("Entrer une puissance : ");
     int y = clavier.nextInt();
     System.out.print(x + " à la puissance " + y + " vaut : " + puissance(x,y));
     break;

     case 3 :
       int a;
       int b;
       do{
         System.out.print("Entrer un premier nombre : ");
         a = clavier.nextInt();
         System.out.print("Entrer un second nombre : ");
         b = clavier.nextInt();

       }while(estValide(a,b) == false);

       System.out.print("Le PGCD de " + a + " et " + b + " est : " + pgcd(a,b));
     break;

     default: System.out.print("Choix inconnu.");

   }

  }

  public static int factorielle(int a){
    int r =1;
    for (int i=1; i<=a; i++){
      r = r*i;
    }
    return r;
  }

  public static int puissance (int x, int y){
    int res = 1;
    for (int i = 1; x<y; i++){
      res = res*y;
    }
    return res;
  }

  public static int pgcd(int a, int b){
    int r = 1;
    while (r != 0){
      r = a%b;
      a = b;
      b = r;
    }
    return a;
  }

  public static boolean estValide(int a, int b){
    boolean valide = false;
    if (a > 0 && b > 0){
      valide = true;
    } else {
      System.out.print("Saisie invalide. Resaisisez des valeurs : ");
    }
    return valide;
  }





}
