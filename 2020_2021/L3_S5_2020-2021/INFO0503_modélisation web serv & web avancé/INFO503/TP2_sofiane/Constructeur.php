<?php
class Constructeur{

    // attributs

    private static $id = 0;
    private $idConstructeur;
    private $nom;
    private $usines;
    private $stocks;
    private $stringListe;
    private $string2Liste;

    public function __construct(){
    	$nb = func_num_args();
        $args = func_get_args();
        $constructeur = "constructeur$nb";
        if (method_exists(__CLASS__,$constructeur)){
            $this->$constructeur("",$args,$args);
        }
    }

    public function constructeur0($nom,$usine,$stock){
        $this->idConstructeur = $id;
        Constructeur::$id++;
        $this->nom = $nom;
        $this->usines = new Usine(1);
        $this->usines[0] = new Usine(1);
        $this->stocks = new Stock(1);
        $this->stocks[0] = $stock;
    }

    public function constructeur1($nom,$usines,$stock){
        $this->idConstructeur = $id;
        Constructeur::$id++;
        $this->nom = $nom;
        $this->usines = $usines;
        $this->stocks = new Stock(1);
        $this->stocks[0] = stock;
    }

    public function constructeur3($nom,$usines,$stocks){
        $this->idConstructeur = self::$id;
        Constructeur::$id++;
        $this->nom = $nom;
        $p = new Parking(null);
        $this->usines = new Usine(1,$p);
        $this->usines = $usines;
        $this->stocks = $stocks;
    }

    public function constructeur4($nom,$usines,$stocks){
        $this->constructeur = $id;
        Constructeur::$id++;
        $this->nom = $nom;
        $this->usines = $usines;
        $this->stocks = $stocks;
    }

    public function constructeur5($constructeur){
        $this->idConstructeur = $id;
        Constructeur::$id++;
        $this->nom = $constructeur->nom;
        $this->usines= $constructeur->usines;
        $this->stocks = null;
    }

    // getters

    public function getNom(){
        return $this->nom;
    }

    public function getUsines(){
        return $this->usines;
    }

    public function getStocks(){
        return $this->stocks;
    }

    public function getIdConstructeur(){
        return $this->idConstructeur;
    }

    // setters

    public function setNom($nom){
        $this->nom = $nom;
    }

    public function setUsines($usines){
        $this->usines = $usines;
    }

    public function setStocks($stock){
        $this->stocks = new Stock(1);
        $this->stocks[0] = $stock;
    }

    public function setStock1($stocks){
        $this->stocks = $stocks;
    }

    public function usinesString(){
        for($i = 0; $i < count($this->usines);$i++){
            $this->stringListe = $this->usines[$i];
        }
        return $this->stringListe;
    }

    public function stocksString(){
        for($i = 0; $i < count($this->stocks);$i++){
            $this->string2Liste = $this->stocks[$i];
        }
        return $this->string2Liste;
    }

    public function __toString(){
        return "Constructeur [idConstructeur=" . $this->idConstructeur . ", nom ="  . $this->getNom(). ", usines=" . $this->usinesString() . ", stocks=" . $this->stocksString() . "]";
    }

}
?>