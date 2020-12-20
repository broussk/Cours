<?php
class Stock{
    protected $idStock;
    static $IDint = 0;
    static $IDchar = 'A';
    protected $usine;

    public function __construct(Usine $usine = null){
    	$this->idStock = $this->upID();
        $this->usine = $usine;
    }

    public function getIdStock() : int {return $this->idStock;}
    public function getUsine() : Usine {return $this->usine;}

    public function setUsine(Usine $usine = null){$this->usine = $usine;}

//Méthodes
    public function __toString() : String {
        if($this->usine != null){return "idStock : " . $this->idStock . " Usine : " . $this->usine->__toString();}
        else{return "idStock : " . $this->idStock . " Usine : Aucune Usine.";}
    }

    private function upID() : String {
        $id = self::$IDchar . self::$IDint;
        if(Stock::$IDint == 9999999){
            Stock::$IDint = 0;
            if(Stock::$IDchar >= 'A' && Stock::$IDchar <= 'Z'){
                Stock::$IDchar++;
            }else if(Stock::$IDchar >='a' && Stock::$IDchar <= 'z'){
                Stock::$IDchar++;
            }else if(Stock::$IDchar == 'Z'){
                Stock::$IDchar = 'a';
            }else if(Stock::$IDchar == 'z'){
                Stock::$IDchar = 'A';
            }else{
                Stock::$IDchar = '@';
            }
        }
        Stock::$IDint++;
        return $id;
    }
}