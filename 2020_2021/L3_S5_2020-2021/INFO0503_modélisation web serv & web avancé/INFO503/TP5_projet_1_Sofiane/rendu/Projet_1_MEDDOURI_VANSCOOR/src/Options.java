/*
public class Options extends Voiture{
    //attributs
    protected boolean GPS;
    protected boolean Vitre;
    protected boolean clim;
    //Constructeur
    public Options(){
      super();
      GPS=false;
      Vitre=false;
      clim=false;
    }
    public Options(boolean GPS,boolean Vitre,boolean clim){
      this.GPS=GPS;
      this.Vitre=Vitre;
      this.clim=clim;
    }
    public Options(Options op){
      this.GPS=op.GPS;
      this.Vitre=op.Vitre;
      this.clim=op.clim;
    }
    //getter
    public boolean getGPS(){
      return GPS;
    }
    public boolean getVitre(){
      return Vitre;
    }
    public boolean getClim(){
      return clim;
    }
    //setter
    void setGPS(boolean b){
      this.GPS=b;
    }
    void setVitre(boolean b){
      this.Vitre=b;
    }
    void setClim(boolean b){
      this.clim=b;
    }

    // methode toString

    public String toString(){
      return " GPS : " + getGPS() + " Vitre : " + getVitre() + " Clim : " + getClim();
    }
    */

  public class Options{
    private String option;
    private boolean contient;

    public Options(){
      this.option = "";
      this.contient = false;
    }
      
    public Options(String nom) {
      this.option = nom;
      this.contient = false;
    }
      
    public Options(String nom, boolean contient) {
      this.option = nom;
      this.contient = contient;
    }
      
    public Options(Options o) {
      this.option = o.option;
      this.contient = o.contient;
    }
      
    public String getNomOptions() {
      return this.option;
    }
      
    public boolean getContientOptions() {
      return this.contient;
    }
      
    public String toString() {
      return (this.option + " : " + this.contient);
    }
}
