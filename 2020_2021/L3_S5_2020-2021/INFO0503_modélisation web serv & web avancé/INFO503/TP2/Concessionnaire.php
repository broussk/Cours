<?php
class Concessionnaire{
    protected $nom;
    protected static $id = 0;
    protected $idConcessionnaire = -1;
    protected $catalogue;

    public function __construct(Catalogue $catalogue, String $nom = "VoitureVendeur"){
        self::$id++;
        $this->idConcessionnaire = self::$id;
        $this->nom = $nom;
        $this->catalogue = $catalogue;
    }

    public function getNom() : String {return $this->nom;}
    public function getIdConcessionnaire() : int {return $this->idConcessionnaire;}
    public function getCatalogue() : Catalogue {return $this->catalogue;}

    public function setNom(String $nom = "VoitureVendeur"){$this->nom = $nom;}
    public function setCatalogue(Catalogue $catalogue = null){$this->catalogue = $catalogue;}

    public function __toString() : String{
        if($this->catalogue != null) {return "nom : " . $this->getNom() . " idConcessionnaire : " . $this->getIdConcessionnaire() . " catalogue : " . $this->catalogue->__toString();}
        else{return "nom : " . $this->getNom() . " idConcessionnaire : " . $this->getIdConcessionnaire() . " catalogue : Vide.";}
    }
}