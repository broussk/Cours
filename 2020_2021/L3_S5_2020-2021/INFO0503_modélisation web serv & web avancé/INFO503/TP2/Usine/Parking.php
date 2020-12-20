<?php
class Parking{

    static $id = 0;
    protected $numeroParking;
    protected $places = array();

    public function __construct(array $places = null){
        self::$id++;
        $this->numeroParking = self::$id;
        $this->places = $places;
    }

    public function getNumeroParking() : int {return $this->numeroParking;}
    public function getPlace() : array {return $this->places;}

    public function setPlace(array $places = null){
        $this->places = $places;
    }

//Méthodes
    public function __toString() : String {
        return "numParking : " . $this->getNumeroParking() . " Places : " . $this->placesString();
    }

    public function placesString() : String {
        $stringListe = "";
        for($i = 0; $i < count($this->places); $i++){
            $stringListe .= $this->places[$i]->__toString() . "\t";
        }
        return $stringListe;
    } 

    public function addPlace(Place $place){
        array_push($this->places, $place);
    }
}