<?php
class Usine{
    protected $nomUsine;
    protected $parking;

    public function __construct(String $nomUsine = "UsineInconnueDuPublic", $parking = null){
        $this->nomUsine = $nomUsine;
        $this->parking = $parking;
    }

    public function getNomUsine() : String {return $this->nomUsine;}
    public function getParking() : Parking {return $this->parking;}

    public function setNomUsine(String $nomUsine = "UsineInconnueDuPublic"){$this->nomUsine = $nomUsine;}
    public function setParking(Parking $parking = null){$this->parking = $parking;}

//Méthodes
    public function __toString() : String{
        return " nomUsine : " . $this->getNomUsine() . " Parking : " . $this->parkingsString();
    }

    public function parkingsString() : String {
        $stringListe = "";
        if($this->parking != null){
            $places = $this->parking->getPlace();
            for($i = 0; $i < count($places); $i++){
                $stringListe .= $places[$i]->__toString() . "\t";
            }
        }
        else{ $stringListe .= "Aucun Parking.";}
        
        return $stringListe;
    }
}