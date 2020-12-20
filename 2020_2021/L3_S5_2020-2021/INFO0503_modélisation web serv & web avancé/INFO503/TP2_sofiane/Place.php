<?php
class Place{

    // attributs

    private $rangee;
    private $numPlace;
    private $estVide;
    private $voiture;

    // constructeur par initialisation

    public function __construct($rangee,$numPlace){
    	$this->rangee = $rangee;
        $this->numPlace = $numPlace;
        $this->estVide = false;
        $this->voiture = null;
    }
    // getters

    public function getRangee(){
        return $this->rangee;
    }

    public function getNumPlace(){
        return $this->numPlace;
    }

    public function getEstVide(){
        return $this->estVide;
    }

    public function getVoiture(){
        return $this->voiture;
    }

    public function setVoiture($voiture){
        $this->voiture = $voiture;
        $this->estVide = true;
    }

    public function enleverVoiture(){
        if(!$this->estVide){
            return null;
        }
        $voiture = $this->$this->getVoiture();
        $this->voiture = null;
        $this->estVide = false;
        return null;
    }

    // methode toString

    public function __toString(){
        return "Place [rangee=" . $this->rangee . ", num=" . $this->numPlace . ", estVide=" . $this->estVide . "]";  //. ($this->estVide?($this->estVide . " ; Voiture : " . $this->voiture->__toString() . "]"):($this->estVide + "]"));
    }
}