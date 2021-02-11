import java.util.Scanner;

public class Max{
  static Scanner clavier = new Scanner(System.in);
  public static void main(String[] args){

    /*System.out.print("Combien  : ");
    double n1 = clavier.nextDouble();
    System.out.print("Saisir un second  nombre : ");
    double n2 = clavier.nextDouble();
    System.out.print("Le maximum entre " + n1 + " et " + n2 + " : " + max(n1,n2));
    */

   System.out.print("Combien de nombre ? : ");
   int n = clavier.nextInt();
   double max = 0.0;

   for (int i = 0; i<n; i++){
     System.out.print("Saisir un nombre : ");
     double n1 = clavier.nextDouble();
     max = max(max, n1);
   }

   System.out.print("Le maximum entre les " + n + " nombres entres est : " + max);

  }

  public static double max(double a, double b){
    double max = a;
    if (a<b){
      max = b;
    }
    return max;
  }

}
