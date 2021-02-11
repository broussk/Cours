<?php
class Actualite {
    
    // PHP version < 7.4
    private $titre;
    private $message;
    private $date;
    
    // PHP version 7.4
    /*private string $titre;
    private string $message;
    private string $date;*/
    
    public function __construct(string $titre, string $message, string $date) {
        $this->titre = $titre;
        $this->message = $message;
        $this->date = $date;
    }
        
    public function getTitre() : string {
        return $this->titre;
    }

    public function getMessage() : string {
        return $this->message;
    }

    public function getDate() : string {
        return $this->date;
    }
 
    public static function fromString(string $ligne) : Actualite {
        $t = explode(';', $ligne);
        if(count($t) == 3)
            return new Actualite($t[0], $t[1], $t[2]);
        else
            return new Actualite('', '', '');
    }
 
    public function __toString() : string {
        return $this->titre." : ".$this->message." [".$this->date."]";
    }    
}