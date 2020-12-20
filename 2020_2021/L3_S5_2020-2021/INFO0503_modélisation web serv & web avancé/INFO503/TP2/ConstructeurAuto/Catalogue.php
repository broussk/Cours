<?php
class Catalogue{
    protected $catalogue  = array();
    protected $idCatalogue = -1;
    static $id = 0;

    public function __construct(array $voitures = null){
        self::$id++;
        $this->idCatalogue = self::$id;
        if($voitures != null){
            for($i = 0; $i < count($voitures); $i++){
                array_push($this->catalogue, $voitures[$i]);
            }
        }
    }

    public function getIdCatalogue() : int {return $this->idCatalogue;}
    public function getCatalogue() : array {return $this->catalogue;}

//Méthodes
    //ajouterVoiture
    public function ajouterVoiture(Voiture $voiture){
        array_push($this->catalogue, $voiture);
    }

    //supprimerVoiture
    public function supprimerVoiture(Voiture $voiture = null){
        if($voiture != null){
            for($i = 0; $i < count($this->catalogue); $i++){
                if($this->catalogue[$i]->getIDVoiture() == $voiture->getIDVoiture() && $this->catalogue[$i]->getModele()->getNom() == $voiture->getModele()->getNom()&& date_format($this->catalogue[$i]->getDateFabrication(), 'Y-m-d') === date_format($voiture->getDateFabrication(), 'Y-m-d')){
                    $this->catalogue[$i] = null;
                }
            }
        }
    }

    //rechercherVoiture
    public function rechercherVoiture(Voiture $voiture = null) {
        $resultat = "[";
        if($voiture != null){
            for($i = 0; $i < count($this->catalogue); $i++){
                if($this->catalogue[$i] != null){
                    if($this->catalogue[$i]->getIDVoiture() == $voiture->getIDVoiture() && $this->catalogue[$i]->getModele()->getNom() == $voiture->getModele()->getNom()&& date_format($this->catalogue[$i]->getDateFabrication(), 'Y-m-d') === date_format($voiture->getDateFabrication(), 'Y-m-d')){
                        $resultat .= $i . " ; ";
                    }
                }
            }
        }
        $resultat .= "]";
        echo ("résultat de la recherche : " . $resultat);
    }

    public function voituresCatalogueToString() : String {
        $returnedString = "";
        $nb = count($this->catalogue);
        if($nb != 0){
            for($i = 0; $i < $nb; $i++){
                if($this->catalogue[$i] != null) $returnedString .= $this->catalogue[$i]->__toString() . "\t";
            }
        }
        else{$returnedString .= "Aucune Voiture dans le Catalogue.";}        
        return $returnedString;
    }
    
    public function __toString() : String {
        return "idCatalogue : " . $this->getIdCatalogue() . " catalogue : " . $this->voituresCatalogueToString();
    }
}
?>