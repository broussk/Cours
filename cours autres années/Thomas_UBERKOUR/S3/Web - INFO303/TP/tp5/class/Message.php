<?php
  class Message{
    private $jour;
    private $heure;

    function __construct(string $jour, string $heure){
      $this->jour = $jour;
      $this->heure = $heure;
    }

    function getHeure() : string{
      return $this->heure;
    }

    function getJour() : string{
      return $this->jour;
    }

    function __toString() : string{
      return "[".$this->jour." - ".$this->heure."]";
    }
  }
 ?>
