<?php
  class FormFieldInput extends FormField{
    protected $type;
    protected $var;
    protected $placeH;
    const TYPE_TEXT = "text";
    const TYPE_PWD = "password";

    public function __construct(string $id, string $nom, string $label, string $type, string $var, string $placeH){
      parent::__construct($id,$nom,$label);
      $this->var = $var;
      $this->placeH = $placeH;
      $this->type = $type;
      if(($type!==self::TYPE_TEXT)&&($this->type!==self::TYPE_PWD)){
        $this->type = self::TYPE_TEXT;
      }
      else{
        $this->type = $type;
      }
    }

    public function getType():string{
      return $this->type;
    }
    public function getDefault():string{
      return $this->default;
    }
    public function getPlaceH():string{
      return $this->placeH;
    }
    public function type2string(string $type):string{
      switch($type){
        case "TYPE_TEXT":
          $type = "text";
          break;
        case "TYPE_PWD":
          $type = "password";
          break;
        default:
          $type = "text";
          break;
      }
      return $type;
    }

    public function __toString():string{
      $s =
      "
      <div class=\"form-group col-md-6\">
        <label for=\"".$this->getLabel()."\">".$this->getLabel()."</label>
        <input name=\"".$this->getNom()."\"  type=\"".$this->getType()."\" class=\"form-control\" id=\"".$this->getId()."\" placeholer=\"".$this->getPlaceH()."\" required>
      </div>
      ";
      return $s;
    }
  }
 ?>
