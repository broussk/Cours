<?php

class Voiture implements JsonSerializable{
    private $numeroIdentification;
    private $modele;
    private $moteur;
    private $dateFabrication;
    private $couleur;
    private $options = array();

    public function __construct($numeroIdentification, $modele, $moteur, $dateFabrication, $couleur, $options){
        $this->numeroIdentification = $numeroIdentification;
        $this->modele = $modele;
        $this->moteur = $moteur;
        $this->dateFabrication = $dateFabrication;
        $this->couleur = $couleur;
        $this->options = $options;
    }

    public function getNumeroIdentification(){return $this->numeroIdentification;}
    public function getMoteur() {return $this->moteur;}
    public function getModele(){return $this->modele;}
    public function getDateFabrication() {return $this->dateFabrication;}
    public function getCouleur() {return $this->couleur;}
    public function getOptions() {return $this->options;}

    public function getStringOptions():String{
        $rep = "";
        foreach($this->options as $element){
            $rep .= $element->getNomOptions() . ",";
        }
        return $rep;
    }

    public function __toString(){
        return 
        "numeroIdentification : " . $this->numeroIdentification 
        . " modele : " . $this->modele 
        . " moteur : " . $this->moteur 
        . " couleur : " . $this->couleur 
        . " options : " . $this->getStringOptions();
    }

    public function jsonSerialize() : array{
        return [
            'numeroIdentification' => $this->numeroIdentification, 
            'modele'=> $this->modele, 
            'moteur' => $this->moteur, 
            'dateFabrication' => $this->dateFabrication, 
            'couleur' => $this->couleur, 
            'options'=> $this->getStringOptions()
        ];
    }

    public static function FromJson($json){
        $table = json_decode($json);
        return new self(
            $table->numeroIdentification,
            $table->modele,
            $table->moteur,
            $table->dateFabrication,
            $table->couleur,
            $table->options
        );
    }
}
?>