class testToutou{
	public static void main (String[] args){
		Toutou milou=new Toutou();
		Toutou medor=new Toutou();
		try{milou = new Toutou("Milou",4);
		}catch(IllegalArgumentException e){
			milou.setPuces(0);
		}
		try{
			medor = new Toutou("Medor",-11);
		}catch(IllegalArgumentException e){
			medor = new Toutou("Medor",5);
		}
		System.out.println(medor.toString());
		try{milou.setPuces(-4);
		}catch(IllegalArgumentException e){
			milou.setPuces(0);
		}
		System.out.println(milou.toString());
		System.out.println(milou.egalA(medor));
	}
}
