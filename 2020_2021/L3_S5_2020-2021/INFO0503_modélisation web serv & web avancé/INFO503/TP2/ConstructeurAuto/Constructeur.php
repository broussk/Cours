<?php
class Constructeur{
    static $id = 0;
    protected $idConstructeur;
    protected $nom;
    protected $usines = array();
    protected $stocks = array();

    public function constructeur(String $nom = "constructeurAuto", array $usines = null, array $stocks = null){
        self::$id++;
        $this->idConstructeur = self::$id;
        $this->nom = $nom;
        if($usines != null){
           for($i = 0; $i < count($this->usines);$i++){
                array_push($this->usines, $usines[$i]);
            } 
        }
        if($stocks != null){
            for($i = 0; $i < count($this->stocks);$i++){
                array_push($this->stocks, $stocks[$i]);
            }
        }
    }

    public function getNom() : String {return $this->nom;}
    public function getUsines() : array {return $this->usines;}
    public function getStocks() : array {return $this->stocks;}
    public function getIdConstructeur() : int{return $this->idConstructeur;}

    public function setNom(String $nom = "constructeurAuto"){$this->nom = $nom;}
    public function setUsines(array $usines = null){$this->usines = $usines;}
    public function setStocks(array $stock = null){$this->stocks = $stock;}

//Méthodes
    public function __toString() : String {
        return "idConstructeur : " . $this->getIdConstructeur() . " nom : "  . $this->getNom(). " usines : " . $this->usinesString() . " stocks : " . $this->stocksString();
    }

    public function usinesString() : String {
        $stringListe = "";
        $nb = count($this->usines);
        if($nb != 0){
            for($i = 0; $i < $nb; $i++){
                $stringListe .= $this->usines[$i]->__toString();
            }
        }
        else{$stringListe .= "Aucune Usine reliée.";}
        return $stringListe;
    }

    public function stocksString() : String {
        $stringListe = "";
        $nb = count($this->stocks);
        if($nb != 0){
            for($i = 0; $i < $nb; $i++){
                $stringListe .= $this->stocks[$i]->__toString() . "\t";
            }
        }
        else{$stringListe .= "Aucun Stock relié.";}
        
        return $stringListe;
    }
}
?>