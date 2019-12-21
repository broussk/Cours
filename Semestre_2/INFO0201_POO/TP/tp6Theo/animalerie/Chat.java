package animalerie;


public class Chat extends AMammifere {

  public Chat(String n) {
    super(n);
  }

  public Chat(){
    super();
  }

  public String toString(){
    return ("Chat "+super.toString());
  }

  public void crier(){
    System.out.println("miaou, miaou");
  }

}
