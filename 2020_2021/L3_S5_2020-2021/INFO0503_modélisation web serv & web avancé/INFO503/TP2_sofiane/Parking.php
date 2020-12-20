<?php
class Parking{

    // attributs

    private static $id = 0;
    private $numeroParking;
    private $places = array();

    // constructeur par initialisation

    public function __construct($places){
        $this->numeroParking = self::$id;
        Parking::$id++;
        $this->places = $places;
    }

    // getters

    public function getNumeroParking(){
        return $this->numeroParking;
    }

    public function getPlace(){
        return $this->places;
    }

    // setter

    public function setNumeroParking(int $numeroParking){
        $this->numeroParking = $numeroParking;
    }

    public function setPlace(Place $place){
        $this->place = $place;
    }

    public function addPlace($place){
        $pls = array();
        $pls = new Place(count($places) + 1);
        for($i = 0; $i < $this->places->length;$i++){
            $pls[i] = new Place($this->places[i]);
        }
        $pls[$pls->length - 1] = new Place($place);
        $this->places = $pls;
    }
/*
    public function placesString(){
        $stringListe = is_numeric("");
        for($i = 0; $i <count($this->places) ;$i++){
            $stringListe += is_numeric($this->places[$i]->__toString()) + is_numeric("\n");
        }
        return $stringListe;
    }
    */

    // methode toString

    public function __toString(){
        return "Parking [numParking=" . $this->numeroParking . "]";
    }
}