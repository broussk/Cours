package animalerie;

public abstract class AMammifere extends AAnimal {
  public static final int PATTES_DEFAUT =4;

  public AMammifere(String n) {
    super(PATTES_DEFAUT,0,n);
  }

  public AMammifere(){
    super(PATTES_DEFAUT,0,"Bidule");
  }

  public String toString(){
    return (getNom()+", mammifere a "+getNbPattes()+" patte(s) et "+getNbAiles()+" aile(s).");
  }

  public abstract void crier();

}
