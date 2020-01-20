<?php
  class FormFieldButton extends FormField{
    protected $type;
    const TYPE_SUBMIT = "submit";
    const TYPE_RESET = "reset";
    const TYPE_BUTTON = "button";

    public function __construct(string $id, string $nom, string $label, string $type){
      parent::__construct($id,$nom,$label);
      if(($this->type!=self::TYPE_SUBMIT)||($this->type!=self::TYPE_RESET)||($this->type!=self::TYPE_BUTTON)){
        $this->type = self::TYPE_BUTTON;
      }
      else{
        $this->type = $type;
      }
    }

    public function getType():string{
      return $this->type;
    }

    public function type2string(string $type):string{
      switch($type){
        case "TYPE_SUBMIT":
          $type = "submit";
          break;
        case "TYPE_RESET":
          $type = "reset";
          break;
        case "TYPE_BUTTON":
          $type = "button";
          break;
        default:
          $type = "submit";
          break;
      }
      return $type;
    }

    public function __toString():string{
      return
      "
      <button style=\"margin-left: 1em; margin-top: 5px;\" id=\"".$this->getId()."\" type=\"".$this->type2string($this->getType())."\" class=\"btn btn-primary\" name=\"".$this->getNom()."\">".$this->getNom()."</button>
      ";
    }
  }
 ?>
