<?php
class Commande{

    // attributs

    private $voitures = array();
    private static $id = 0;
    private $identifiantCommande;
    private $voitureTabString;

    // constructeur par initialisation
/*
    public function __construct(Voiture $voiture){
        $this->voiture = $voiture;
    }
*/
    public function __construct(){
    	$nb = func_num_args();
        $args = func_get_args();
        $commande = "commande$nb";
        if (method_exists(__CLASS__,$commande)){
            $this->$commande($args);
        }
    }

    public function commande0(){
        $this->identifiantCommande = $identifiantCommande;
        $identifiantCommande++;
        $this->voitures = new Voiture(1);
        $this->voitures[0] = null;
    }

    public function commande1($voiture){
        $this->identifiantCommande = self::$id;
        Commande::$id++;
        $this->voitures = new Voiture("",null,null,null,Couleur::NOIR,null);
        $this->voitures = $voiture;
    }

    public function commande3($voitures){
        $this->identifiantCommande = $id;
        Commande::$id++;
        $this->voitures[0] = $voiture;
    }
    
    // getters

    public function getVoituresCommande(){
        return $this->voitures;
    }

    // setters

    public function setVoituresCommandes($voitures){
        $this->voitures = new Voiture($voitures.length);
        $this->voitures = $voitures;
    }

    public function setVoituresCommande($voiture){
        $this->voitures = new Voiture(1);
        $this->voitures[0] = $voiture;
    }

    public function ajouterVoitureCommande($voiture){
        $ajouterVoitureTab = array();
        $ajouterVoitureTab = new Voiture($this->voitures->length + 1);
        for($i = 0; $i < $this->voitures->length;$i++){
            $ajouterVoitureTab[i] = $this->voitures[i];
        }
        $ajouterVoitureTab[$ajouterVoitureTab->length -1] = $voiture;
        $voitures = $ajouterVoitureTab;
    }

    public function ajouterVoitureCommande1(Voiture $voitures){
        $ajouterVoitureTab = array();
        $ajouterVoitureTab = new Voiture($this->voitures->length + $voitures->length+1);
        for($i = 0; $i < $this->voitures->length;$i++){
            $ajouterVoitureTab[i] = $this->voitures[i];     
        }
        for($i = $this->voitures->length;$j < $voitures->length;$i++){
            $ajouterVoitureTab[i] = $voitures[j];
            $j++;
        }
        $this->voitures = $ajouterVoitureTab;
    }

    public function voituresTabToString(){
        if($this->voitures != null){
            for($i = 0; $i < count($this->voitures);$i++){
                $this->voituresTabString = $this->voitures[$i]->__toString();
            }
        }else{
            if($this->voitures[0] == null && $this->voitures[1] == null){
                $voituresTabString = "aucune voiture";
            }
        }
        return $this->voituresTabString;
    }

    public function __toString(){
        return "Commande [identifiantCommande = " . $this->identifiantCommande . ", voitures = " . $this->voituresTabToString() . "]";
    }
}