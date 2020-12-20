<?php
class Usine{

    // attributs

    protected $nomUsine;
    protected $parking;

    // constructeur par initialisation

    public function __construct(String $nomUsine,Parking $parking){
        $this->nomUsine = $nomUsine;
        $this->parking = $parking;
    }

    // getters

    public function getNomUsine(){
        return $this->nomUsine;
    }

    public function getParking(){
        return $this->parking;
    }

    // setters

    public function setNomUsine(String $nomUsine){
        $this->nomUsine = $nomUsine;
    }

    public function setParking(Parking $parking){
        $this->parking = $parking;
    }

    // methode toString

    public function __toString(){
        return "Nom Usine : " . $this->nomUsine . " Parking : " . $this->parking;
    }
}