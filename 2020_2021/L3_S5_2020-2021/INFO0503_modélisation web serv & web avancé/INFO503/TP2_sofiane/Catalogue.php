<?php
//include('Commande.php');
class Catalogue{

    // attributs

    protected $catalogue  = array();
    protected $i = 0;
    private $resultat;
    // constructeur par initialisation

    public function __construct(){ 
        $catalogue[0] = new Voiture("DV-544-EG",null,null,null,Couleur::NOIR,null);
    }
    // methode ajouterVoiture

    public function ajouterVoiture(Voiture $v){
        //$voiture[i] = $v;
        //$i++;
        $catalogue[$this->i] = $v;
        $this->i++;
        array_push($this->catalogue,$v);
        $this->afficherVoiture();
    }



    // methode commander

    public function commander(Voiture $v){
        $commande = new Commande($v);
    }

    // methode afficherVoiture

    public function afficherVoiture(){
        foreach ($this->catalogue as $voiture) {
            echo($voiture);
        }
        
    }

    // methode supprimerVoiture

    public function supprimerVoiture(Voiture $v){
        for($i = 0; $i < count($catalogue); $i++){
            if($catalogue[$i] == $v){
                $catalogue[$i] = null;
            }
        }
        afficherVoiture();
    }

    // methode rechercherVoiture

    public function rechercherVoiture(Voiture $v){
        $this->resultat = false;
        for($i = 0; $i < count($this->catalogue); $i++){
            if($this->catalogue[$i] == $v){
                $this->resultat = true;
            }
        }
        return $this->resultat;
    }

    public function __toString(){
        $tab = implode(" , ",$this->catalogue);
        return $tab;
    }
}
?>