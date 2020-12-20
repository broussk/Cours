package constructeurAuto;

import Usines.Usine;

public class Stock {
	private String idStock;
	private static int IDint = 0;
	private static char IDchar = 'A';
	private Usine usine;
	
	public Stock(Usine usine) {
		this.idStock = upID();
		this.usine = usine;
	}
	
	public Stock(Stock st) {
		this.idStock = upID();
		this.usine = st.usine;
	}

	private String upID() {
		String id = ""+ IDchar + IDint;
		if(Stock.IDint == 9999999) {
			Stock.IDint = 0;
			if(IDchar >= 'A' && IDchar <= 'Z') {
				Stock.IDchar++;
			}
			else if(IDchar >= 'a' && IDchar <= 'z') {
				Stock.IDchar++;
			}
			else if(IDchar == 'Z') {
				Stock.IDchar = 'a';
			}
			else if(IDchar == 'z') {
				Stock.IDchar = 'A';
			}
			else {
				Stock.IDchar = '@';
			}
		}
		Stock.IDint ++;
		return id;
	}

	public String getIdStock() {
		return idStock;
	}

	public Usine getUsine() {
		return usine;
	}

	public void setParking(Usine usine) {
		this.usine = usine;
	}

	@Override
	public String toString() {
		return "Stock [idStock=" + idStock + ", Usine=" + usine.toString() + "]";
	}
}
