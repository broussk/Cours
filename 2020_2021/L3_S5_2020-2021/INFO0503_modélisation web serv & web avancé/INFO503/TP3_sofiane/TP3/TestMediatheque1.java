import java.util.*;
import java.util.Scanner;
import mediatheque1.*;

public class TestMediatheque1{
    public static void main(String[] args){
        Auteur a1 = new Auteur("Eichiro Oda","01/01/1975");
        Livre l1 = new Livre("One piece",a1);
        System.out.println(l1.toString());
        Mediatheque m1 = new Mediatheque();
        m1.ajouterLivre(l1);
    }
}