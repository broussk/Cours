<?php
class Commande{
    protected $voitures = array();
    static $id = 0;
    protected $identifiantCommande = -1;

    public function __construct(array $voitures){
        self::$id++;
        $this->identifiantCommande = self::$id;
        for($i = 0; $i < count($voitures); $i++){
            array_push($this->voitures, $voitures[$i]);
        }
    }

    public function getVoituresCommande() : array {return $this->voitures;}
    public function getIdentifiantCommande() : int {return $this->identifiantCommande;}

    public function setVoituresCommande(array $voitures = null){
        if($voitures != null){
            $this->voitures = array();
            for($i = 0; $i < count($voitures); $i++){
                array_push($this->voitures, $voitures[$i]);
            }
        }
    }

//Méthodes
    public function ajouterVoitureCommande(Voiture $voiture = null){
        if($voiture != null){
            array_push($this->voitures, $voiture);
        }
    }

    public function retirerVoitureCommande(Voiture $voiture = null){
        if($voiture != null){
            for($i = 0; $i < count($this->voitures); $i++){
                if($this->voitures[$i]->getIDVoiture() == $voiture->getIDVoiture() && $this->voitures[$i]->getModele()->getNom() == $voiture->getModele()->getNom()&& date_format($this->voitures[$i]->getDateFabrication(), 'Y-m-d') === date_format($voiture->getDateFabrication(), 'Y-m-d')){
                    $this->voitures[$i] = null;
                }
            }
        }
    }

    public function voituresTabToString() : String {
        $returnedString = "";
        if($this->voitures != null){
            for($i = 0; $i < count($this->voitures); $i++){
                if($this->voitures[$i] != null){$returnedString .= $this->voitures[$i]->__toString() . "\t";}
            }
        }
        else {$returnedString .= "aucune voitures dans la commande.";}
        return $returnedString;
    }

    public function __toString() : String{
        return "identifiantCommande : " . $this->getIdentifiantCommande() . " voitures : " . $this->voituresTabToString();
    }
}