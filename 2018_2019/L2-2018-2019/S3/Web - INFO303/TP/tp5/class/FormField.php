<?php
  abstract class FormField{
    protected $id;
    protected $nom;
    protected $label;

    public function __construct(string $id, string $nom, string $label){
      $this->id=$id;
      $this->nom=$nom;
      $this->label=$label;
    }

    public function getId():string{
      return $this->id;
    }

    public function getNom():string{
      return $this->nom;
    }

    public function getLabel():string{
      return $this->label;
    }
  }
?>
