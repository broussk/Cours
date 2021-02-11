package fr.corentin.tp.TP3.Toutou;

public class TestToutou {
    public static void main(String[] args) {
        Toutou t1 = new Toutou();
        System.out.println(t1.toString());

        Toutou meddor, milou;

        try {
            meddor = new Toutou("Meddor", -11);
        } catch (IllegalArgumentException e) {
            System.out.println("Erreur! Le Toutou sera initialise avec 0 puces");
            meddor = new Toutou("Meddor", 0);
        }

        System.out.println(meddor.toString());

        try {
            milou = new Toutou("Milou", 4);
        } catch (IllegalArgumentException e) {
            System.out.println("Erreur! Le Toutou sera initialise avec 0 puces");
            milou = new Toutou("Milou", 0);
        }

        try {
            milou.setPuce(-42);
        } catch (IllegalArgumentException e) {
            System.out.println("Erreur! Le Toutou sera initialise avec 0 puces");
            milou.setPuce(0);
        }

        System.out.println("Milou et Meddor sont ils égaux ? " + meddor.egalA(milou));
    }
}
