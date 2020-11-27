
//conteneur
liste de marchandise
ArrayList<String> marchandise;
double identifiant;


public JSONObject toJSON(){
    JSONObject jo = new JSONObject();
    JSONArray array = new JSONArray();

    for(int i = 0; i < marchandise.size(); i++) {
         array.put(marchandise.get(i).toJSON());
    }

    jo.put("marchandise",array);
    jo.put("identifiant",identifiant);
    return jo;

}
public static Conteneur fromJSON(JSONObject jsonData){
	return new Conteneur(jsonData.getArray("marchandise"), jsonData.getString("identifiant"));
}
