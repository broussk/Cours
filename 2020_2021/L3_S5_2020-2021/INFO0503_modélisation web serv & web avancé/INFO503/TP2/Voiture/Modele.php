<?php
class Modele implements JsonSerializable{
    protected  $modele;

    public function __construct(String $modele = "boiteu"){
        $this->modele = $modele;
    }

    public function getNom(): String{return $this->modele;}

    public function setModele(String $modele = "boiteu"){$this->modele = $modele;}

//Méthodes
    public function __toString() : String {
        return " nom : " . $this->getNom();
    }

    public function jsonSerialize() : array {
        return ['nom' => $this->getNom()];
    }
}
?>