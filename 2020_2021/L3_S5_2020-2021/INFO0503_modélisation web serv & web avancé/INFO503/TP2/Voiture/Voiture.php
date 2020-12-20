<?php
include("/UwAmp/www/INFO503/TP2/Moteur/Moteur.php");
include("/UwAmp/www/INFO503/TP2/Voiture/Options.php");
include("/UwAmp/www/INFO503/TP2/Voiture/Modele.php");
include("/UwAmp/www/INFO503/TP2/Voiture/Couleur.php");

class Voiture implements JsonSerializable{
    protected $modele;
    protected $moteur;
    protected $dateFabrication;
    protected $couleur;
    protected $options;
    protected $idVoiture = -1;
    static $id = 0;
    
    public function __construct($modele, $moteur, $couleur, $options, $dateFabrication, $idVoiture = 0){
        if($idVoiture != 0){$this->idVoiture = $idVoiture;}
        else {
            self::$id++;
            $this->idVoiture = self::$id;
        }
        $this->modele = $modele;
        $this->moteur = $moteur;
        $this->dateFabrication = $dateFabrication;
        $this->couleur = $couleur;
        $this->options = $options;
    }

    public function getIDVoiture() {return $this->idVoiture;}
    public function getMoteur() {return $this->moteur;}
    public function getModele() {return $this->modele;}
    public function getDateFabrication() : DateTime {return $this->dateFabrication;}
    public function getCouleur() : String {return $this->couleur;}
    public function getOptions() : Options {return $this->options;}

    public function setCouleur(String $couleur = Couleur::BEIGE){$this->couleur = $couleur;}
    public function setOption($options){$this->options = $options;}

//Méthodes
    public function __toString() : String {
        $thisModele = $this->getModele();
        $thisMoteur = $this->getMoteur();
        return "id : " . $this->getIDVoiture() 
        //. $this->getModele()->prout()
        . " modele : " . $thisModele->__toString()
        . " moteur : " . $thisMoteur->__toString() 
        . " date de fabrication : " . date_format($this->getDateFabrication(), 'Y-m-d') 
        . " couleur : " . $this->getCouleur() 
        . " options : " . $this->getOptions()->__toString();
    }
    
    public function jsonSerialize() : array {
        return ['idVoiture' => $this->getIDVoiture(), 'modele'=> $this->getModele(), 'moteur' => $this->getMoteur(), 'dateFabrication' => $this->getDateFabrication(), 'couleur' => $this->getCouleur(), 'options'=> $this->getOptions()];
    }

    public static function FromJson($json) : Voiture {
        $table = json_decode($json);
        return new self(
            new Modele($table->modele->nom)
            , new Moteur($table->moteur->carburation, $table->moteur->puissance, $table->moteur->idMoteur)
            , $table->couleur
            , new Options($table->options->GPS, $table->options->VitreElectriques, $table->options->Climatisation, $table->options->CameraDeRecul, $table->options->ToitOuvrant, $table->options->Alarme, $table->options->AirBagLateraux)
            , new DateTime($table->dateFabrication->date, new DateTimeZone($table->dateFabrication->timezone))
            , $table->idVoiture);
    }
}
?>