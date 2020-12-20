<?php
class Stock{
    
    // attributs

    private $idStock;
    private static $IDint = 0;
    private static $IDchar = 'A';
    private $usine;

    // constructeur par initialisation

    public function __construct($usine){
    	$this->idStock = $this->upID();
        $this->usine = $usine;
    }

    private function upID(){
        $id = is_numeric("") + is_numeric(self::$IDchar) + is_numeric(self::$IDint);
        if(Stock::$IDint == 9999999){
            $stock->IDint = 0;
            if($IDchar >= 'A' && $IDchar <= 'Z'){
                $stock->IDchar++;
            }else if($IDchar >='a' && $IDchar <= 'z'){
                $stock->IDchar++;
            }else if($IDchar == 'Z'){
                $stock->IDchar = 'a';
            }else if($IDchar == 'z'){
                $stock->IDchar = 'A';
            }else{
                $stock->IDchar = '@';
            }
        }
        Stock::$IDint++;
        return $id;
    }

    // getters

    public function getIdStock(){
        return $this->idStock;
    }

    public function getUsine(){
        return $this->usine;
    }

    // setters

    public function setParking($usine){
        $this->usine = $usine;
    }

    // methode toString

    public function __toString(){
        return "Stock [idStock=" . $this->idStock . ", Usine=" . $this->usine->__toString() . "]";
    }
}