public class Binaire {
  public static void entier2binaire(int num, int oc) {
      int binaire[] = new int[oc];
      for (int i = 0; i <= binaire.length - 1; i++) {
          binaire[i] = num % 2;
          num = num / 2;
      }
      for (int i = binaire.length - 1; i >= 0; i--) {
          System.out.print(binaire[i]);
      }
  }

  public static int binaire2entier(int bin[]) {
      int decimal = 0;
      int power = 0;
      for (int i = bin.length - 1; i >= 0; i--) {
          int tmp = bin[i] % 10;
          decimal += tmp * Math.pow(2, power);
          power++;
      }
      return decimal;
  }

  public static void somme(int bin1[], int bin2[]) {
      int b1 = binaire2entier(bin1);
      int b2 = binaire2entier(bin2);
      int somme = b1 + b2;
      int sommetpm = somme;

      //Calcul du nombre de  bit pour représenté la somme.
      int bit = 0;
      while (sommetpm != 0) {
          sommetpm = sommetpm / 2;
          bit += 1;
      }
      entier2binaire(somme, bit);
  }


  public static void complementA2(int bin[]) {
      boolean inverser = false;
      int binA2[] = new int[bin.length];
      int i = bin.length - 1;

      //Cherche l'indice du premier 1 en partant de la droite.
      while (inverser == false) {
          for (int j = bin.length - 1; j >= 0; j--) {
              if (bin[i] == 1) {
                  inverser = true;
              } else {
                  i = i - 1;
              }
          }
      }

      //Convertit les 0 en 1 et inversement à la gauche du premier 1.
      for (int k = bin.length - 1; k >= 0; k--) {
          if (k < i) {
              if (bin[k] == 1) {
                  bin[k] = 0;
                  binA2[k] = bin[k];
              } else if (bin[k] == 0) {
                  bin[k] = 1;
                  binA2[k] = bin[k];
              }
          } else {
              bin[k] = bin[k];
              binA2[k] = bin[k];
          }
      }

      //Affiche le tableau du complément à 2
      for (int t = 0; t <= binA2.length - 1; t++) {
          System.out.print(binA2[t]);
      }
  }



    public static void main(String[] args) {
        // Test de la convertion décimale en binaire.
        System.out.print("La representation binaire de 134 sur 8 octets est : ");
        entier2binaire(134, 8);
        System.out.println("\n");

        //Test de la somme.
        int t1[] = {1,1,0,0,1,0,1,0};//202
        int t2[] = {0,0,0,0,1,0,1,1};//11
        System.out.print("La somme 11001010 (202) + 00001011(11) vaut : ");
        somme(t1, t2);
        System.out.println("\n");

        // Test de la convertion binaire en décimale.
        int tab[] = {1,0,0,0,0,1,1,0};//134
        int bd =  binaire2entier(tab);
        System.out.print("Le chiffre binaire 10000110 vaut en decimale : " + bd);
        System.out.println("\n");

        //Test du complément à 2
        int tab2[] = {1,0,0,0,0,1,1,0};
        System.out.print("Le complement a 2 de 10000110 est : ");
        complementA2(tab2);

    }
}
