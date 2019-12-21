package animalerie;

public abstract class AInsecte extends AAnimal {
  public static final int PATTES_DEFAUT =6;

  public AInsecte(String n, int nb) {
    super(PATTES_DEFAUT,nb,n);
  }

  public AInsecte(){
    super(PATTES_DEFAUT,4,"Bidule");
  }

  public String toString(){
    return (getNom()+", insecte a "+getNbPattes()+" patte(s) et "+getNbAiles()+" aile(s).");
  }

  public abstract void crier();

}
