package animalerie;


public class Abeille extends AInsecte {
  public static final int AILES_DEFAUT =4;

  public Abeille(String n) {
    super(n, AILES_DEFAUT);
  }

  public Abeille(){
    super();
  }

  public String toString(){
    return ("Abeille "+super.toString());
  }

  public void crier(){
    System.out.println("bzz, bzz");
  }

}
