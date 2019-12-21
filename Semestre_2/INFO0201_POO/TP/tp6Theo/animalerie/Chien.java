package animalerie;


public class Chien extends AMammifere {

  public Chien(String n) {
    super(n);
  }

  public Chien(){
    super();
  }

  public String toString(){
    return ("Chien "+super.toString());
  }

  public void crier(){
    System.out.println("ouaf,ouaf");
  }

}
