<?php
class Options{

    // attributs

    protected $GPS;
    protected $Vitre;
    protected $Clim;

    // Constructeur par initialisation

    public function __construct(bool $GPS,bool $Vitre, bool $Clim){
        $this->GPS = $GPS;
        $this->Vitre = $Vitre;
        $this->Clim = $Clim;
    }

    // getters

    public function getGPS(){
        return $this->GPS;
    }

    public function getVitre(){
        return $this->Vitre;
    }

    public function getClim(){
        return $this->Clim;
    }

    // setter

    public function setGPS(bool $GPS){
        $this->GPS = $GPS;
    }

    public function setVitre(bool $Vitre){
        $this->Vitre = $Vitre;
    }

    public function setClim(bool $Clim){
        $this->Clim = $Clim;
    }

    // methode toString

    public function __toString(){
        return "GPS : " . $this->GPS . " Vitre : " . $this->Vitre . " Clim : " . $this->Clim;
    }
}