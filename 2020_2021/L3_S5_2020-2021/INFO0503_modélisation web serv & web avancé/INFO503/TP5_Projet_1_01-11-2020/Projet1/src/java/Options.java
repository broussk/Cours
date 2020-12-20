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

    public String getNomOptions() {return this.option;}
    public boolean getContientOptions() {return this.contient;}

    public String toString() {
        return (this.option + " : " + this.contient);
    }
}