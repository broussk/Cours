<?php
class Concessionnaire{

    // attributs

    private $nom;
    private static $id = 0;
    private $idConcessionnaire;
    private $catalogue;

    // constructeur par initialisation

    public function __construct($catalogue){
    	$this->idConcessionnaire = self::$id;
        Concessionnaire::$id++;
        $this->nom = "VoitureVendeur";
        $this->catalogue = $catalogue;
    }
    // getter

    public function getNom(){
        return $this->nom;
    }

    public function getIdConcessionnaire(){
        return $this->idConcessionnaire;
    }

    public function getCatalogue(){
        return $this->catalogue;
    }


    // setter

    public function setNom($nom){
        $this->nom = $nom;
    }

    public function setCatalogue($catalogue){
        $this->catalogue = $catalogue;
    }

    // methode toString

    public function __toString(){
        return "Concessionnaire [nom=" . $this->getNom() . ", idConcessionnaire=" . $this->getIdConcessionnaire() . ", catalogue=" . $this->catalogue. "]";
    }
}