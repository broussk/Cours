package Voiture;

public class TestOption {

	public static void main(String[] args) {
		Option opt1 = new Option("radio digitale", true);
		Option opt2 = new Option("caméra de recul", true);
		Option opt3 = new Option("tablette tactile à l'avant", true);
		Option opt4 = new Option("assistance au maintien de voie", true);
		Option opt5 = new Option("avertissement de collision", true);
		Option opt6 = new Option("air bags avant", true);
		Option opt7 = new Option("air bags latéraux", true);
		Option opt8 = new Option("vitres electriques", true);
		Option opt9 = new Option("toit ouvrant", true);
		Option opt10 = new Option("alarme intégrée", true);
		Option[] options = new Option[] {opt1,opt2,opt3,opt4,opt5,opt6,opt7,opt8,opt9,opt10};

		System.out.println("\nOptions : ");
		for(int i = 0; i < 10; i++) {
			System.out.println("opt" + i + " : " + options[i].getNomOption() + "\t " + options[i].getContainOption());
		}
		System.out.println("\nOptions : ");
		for(int i = 0; i < 10; i++) {
			System.out.println("opt" + i + " : " + options[i].toString());
		}
	}

}
