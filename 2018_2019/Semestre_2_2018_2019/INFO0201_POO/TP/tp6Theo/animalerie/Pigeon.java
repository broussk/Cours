package animalerie;


public class Pigeon extends AOiseau {

  public Pigeon(String n) {
    super(n);
  }

  public Pigeon(){
    super();
  }

  public String toString(){
    return ("Pigeon "+super.toString());
  }

  public void crier(){
    System.out.println("roo, roo");
  }

}
