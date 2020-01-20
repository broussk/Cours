package animalerie;

public abstract class AOiseau extends AAnimal {
  public static final int PATTES_DEFAUT =2;
  public static final int AILES_DEFAUT=2;

  public AOiseau(String n) {
    super(PATTES_DEFAUT,AILES_DEFAUT,n);
  }

  public AOiseau(){
    super(PATTES_DEFAUT,AILES_DEFAUT,"Bidule");
  }

  public String toString(){
    return (getNom()+", oiseau a "+getNbPattes()+" patte(s) et "+getNbAiles()+" aile(s).");
  }

  public abstract void crier();

}
