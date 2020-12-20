<?php
class Place{
    protected $rangee;
    protected $numPlace;
    protected $occupee;
    protected $voiture;

    public function __construct($rangee = 'A', $numPlace = 0, $voiture = null){
        $this->rangee = $rangee;
        $this->numPlace = $numPlace;
        if($voiture != null){
            $this->occupee = true;
            $this->voiture = $voiture; 
        }
        else{
            $this->occupee = false;
            $this->voiture = null;
        }
    }

    public function getRangee() : String {return $this->rangee;}
    public function getNumPlace() : int {return $this->numPlace;}
    public function getOccupee() : bool {return $this->occupee;}
    public function getVoiture() {return $this->voiture;}

    public function setVoiture(Voiture $voiture = null){
        if($voiture != null){
            $this->occupee = true;
            $this->voiture = $voiture; 
        }
        else{
            $this->occupee = false;
            $this->voiture = null;
        }
    }
    public function setOccupee(bool $bool = false){
        if($this->getVoiture() != null ){echo("la place que vous avez sélectionnée est occupée.");}
        else{$this->occupee = $bool; echo("Voiture mise en place.");}
    }

//Méthodes
    public function __toString() : String{
        $occupation = ($this->getOccupee()) ? ($this->afficherBoolean($this->getOccupee()) . " Voiture : " . $this->getVoiture()->__toString()) : ($this->afficherBoolean($this->getOccupee()));
        return "rangee : " . $this->getRangee() . " num : " . $this->getNumPlace() . " occupee : " . $occupation;
    }

    public static function enleverVoiture($place){        
        $voiture = $place->getVoiture();
        if($place->getOccupee()){
            $place->voiture = null;
            $place->occupee = false;
        }
        return $voiture;
    }

    private function afficherBoolean(bool $boolean) : String{
        $affichage = ($boolean) ? (1) : (0);
        return $affichage;
    }
}