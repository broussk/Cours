<?php
class Actualite{
    private $titre;
    private $message;
    private $date;

    public function __construct(String $titre, String $message, String $date){
        $this->titre=$titre;
        $this->message=$message;
        $this->date=$date;
    }
    
    public function getTitre():String{ return $this->titre;}
    public function getMessage():String{ return $this->message;}
    public function getDate():String{ return $this->date;}

    public function __toString(){
        return $this->titre." : ".$this->message." (".$this->date.") ";
    }
    public static function fromString(String $ligne):Actualite{
        $element=explode(";",$ligne);
        return new Actualite ($element[0],$element[1],element[2]);
    }
}
