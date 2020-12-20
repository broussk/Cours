<?php
class Options implements JsonSerializable{
    protected $GPS;
    protected $VitreElectriques;
    protected $Climatisation;
    protected $CameraDeRecul;
    protected $toitOuvrant;
    protected $alarme;
    protected $airBagLatéraux;

    public function __construct(bool $GPS = false, bool $VitreElectriques = false, bool $Climatisation = false, bool $CameraDeRecul = false, bool $toitOuvrant = false, bool $alarme = false, bool $airBagLatéraux = false){
        $this->GPS = $GPS;
        $this->VitreElectriques = $VitreElectriques;
        $this->Climatisation = $Climatisation;
        $this->CameraDeRecul = $CameraDeRecul;
        $this->toitOuvrant = $toitOuvrant;
        $this->alarme = $alarme;
        $this->airBagLatéraux = $airBagLatéraux;
    }

    public function getGPS() : bool {return $this->GPS;}
    public function getVitreElectriques() : bool {return $this->VitreElectriques;}
    public function getClimatisation() : bool {return $this->Climatisation;}
    public function getCameraDeRecul() : bool {return $this->CameraDeRecul;}
    public function getToitOuvrant() : bool {return $this->toitOuvrant;}
    public function getAlarme() : bool {return $this->alarme;}
    public function getAirBagLatéraux() : bool {return $this->airBagLatéraux;}

    public function setGPS(bool $GPS = false){$this->GPS = $GPS;}
    public function setVitreElectriques(bool $VitreElectriques = false){$this->VitreElectriques = $VitreElectriques;}
    public function setClimatisation(bool $Climatisation = false){$this->Climatisation = $Climatisation;}
    public function setCameraDeRecul(bool $CameraDeRecul = false){$this->CameraDeRecul = $CameraDeRecul;}
    public function setToitOuvrant(bool $toitOuvrant = false){$this->toitOuvrant = $toitOuvrant;}
    public function setAlarme(bool $alarme = false){$this->alarme = $alarme;}
    public function setAirBagLatéraux(bool $airBagLatéraux = false){$this->airBagLatéraux = $airBagLatéraux;}

//Méthodes
    public function __toString() : String {
        return 
        "GPS : " . $this->afficherBoolean($this->getGPS()) 
        . " VitreElectriques : " . $this->afficherBoolean($this->getVitreElectriques()) 
        . " Climatisation : " . $this->afficherBoolean($this->getClimatisation()) 
        . " CameraDeRecul : " . $this->afficherBoolean($this->getCameraDeRecul()) 
        . " ToitOuvrant : " . $this->afficherBoolean($this->getToitOuvrant()) 
        . " Alarme : " . $this->afficherBoolean($this->getAlarme()) 
        . " AirBagLateraux : " . $this->afficherBoolean($this->getAirBagLatéraux());
    }

    private function afficherBoolean(bool $boolean) : String{
        $affichage = ($boolean) ? (1) : (0);
        return $affichage;
    }
    public function jsonSerialize() : array {
        return [
            'GPS' => $this->getGPS(), 
            'VitreElectriques'=> $this->getVitreElectriques(), 
            'Climatisation' => $this->getClimatisation(), 
            'CameraDeRecul' => $this->getCameraDeRecul(), 
            'ToitOuvrant' => $this->getToitOuvrant(), 
            'Alarme'=> $this->getAlarme(), 
            'AirBagLateraux'=> $this->getAirBagLatéraux()];
    }
}