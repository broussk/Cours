<?php
include("Carburation.php");
class Moteur{

    const PUISSDEF = 110;
    // attributs

    protected $carburation;
    protected $puissance;
    static $id = 0;


    // constructeur par initialisation
    public function __construct($carburation,$puissance){
    	self::$id++;
        self::$id = self::$id;
        $this->carburation = $carburation;
        if($puissance < 1){
            $this->puissance = PUISSDEF;
        }else{
            $this->puissance = $puissance;
        }
    }

    // getter

    public static function getPuissDef(){
        return self::PUISSDEF;
    }

    public function getPuissance(){
        return $this->puissance;
    }

    public function getCarburation(){
        return $this->carburation;
    }

    public  function getId(){
        return self::$id;
    }

    //setters

    public function setCarburation(Carburation $carburation){
        $this->carburation = $carburation;
    }

    public function setPuissance(int $puissance){
        $this->puissance = $puissance;
    }

    // methode toString

    public function __toString():String{
        return " PuissDef : " . $this->getPuissDef() . " id : " .$this->getId() . " carburation : " . $this->getCarburation() . " puissance : " . $this->getPuissance();
    }
}
?>