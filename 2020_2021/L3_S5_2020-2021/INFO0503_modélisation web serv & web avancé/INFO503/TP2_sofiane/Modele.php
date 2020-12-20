<?php
class Modele{

    protected  $modele;

    // constructeur par initialisation

    public function __construct(String $modele){
        $this->modele = $modele;
    }

    // getters

    public function getModele(){
        return $this->modele;
    }

    //setter

    public function set($modele){
        $this->modele = $modele;
    }

    // methode toString

    public function __toString() : String{
        return " nom : " . $this->modele;
    }
}
?>