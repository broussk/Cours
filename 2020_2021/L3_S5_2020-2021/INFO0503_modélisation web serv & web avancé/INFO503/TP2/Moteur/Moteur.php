<?php
include("/UwAmp/www/INFO503/TP2/Moteur/Carburation.php");
class Moteur implements JsonSerializable{
    protected $carburation;
    protected $puissance;
    static $id = 0;
    protected $idMoteur = -1;

    public function __construct(String $carburation = Carburation::ESSENCE, $puissance = 5, int $idMoteur = 0){
        if($idMoteur == 0) {
            self::$id++;
            $this->idMoteur = self::$id;
        }
        else{
            $this->idMoteur = $idMoteur;
        }
        $this->carburation = $carburation;
        $this->puissance = $puissance;
    }

    public function getPuissance() : int {return $this->puissance;}
    public function getCarburation() : String {return $this->carburation;}
    public function getIdMoteur() : int {return $this->idMoteur;}

    public function setCarburation(String $carburation = Carburation::ESSENCE){$this->carburation = $carburation;}
    public function setPuissance(int $puissance = 5){$this->puissance = $puissance;}

//Méthodes 
    public function __toString() : String {
        return " idMoteur : " . $this->getIdMoteur() . " carburation : " . $this->getCarburation() . " puissance : " . $this->getPuissance();
    }

    public function jsonSerialize() : array {
        return ['idMoteur' => $this->getIdMoteur(), 'carburation'=> $this->getCarburation(), 'puissance' => $this->getPuissance()];
    }
}
?>