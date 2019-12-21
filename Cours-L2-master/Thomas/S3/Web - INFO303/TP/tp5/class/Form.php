<?php
  class Form{
    protected $id;
    protected $action;
    protected $mode;
    public $fields=array();
    const MODE_GET = "get";
    const MODE_POST = "post";

  function __construct(string $id, string $action, string $mode){
    $this->id = $id;
    $this->action = $action;
    if(($mode!=self::MODE_GET)||($mode!=self::MODE_POST)){
      $this->mode=self::MODE_GET;
    }
    else{
      $this->mode=$mode;
    }
  }

  public function getId():string{
    return $this->id;
  }

  public function getAction():string{
    return $this->action;
  }

  public function getMode():string{
    return $this->mode;
  }

  public function __toString():string{
    $s="<form id=\"".$this->getId()."\" method=\"".$this->getMode()."\" action=\"".$this->getAction()."\">";
    foreach ($this->fields as $value) {
      $r=($value->__toString());
      $s=$s.$r;
    }
    $s=$s."</form>";
    return $s;
    }

  public function addField(FormField $ff){
    $this->fields[]=$ff;
  }
}
/*
Votre formulaire contient une liste de champs (les FormField). D'où l'attribut "fields" qui est un tableau.

Ainsi, la méthode addField se contente de prendre le champ passé en paramètre et de l'ajouter à "fields".

Du coup, la méthode __toString doit parcourir chaque champs de l'attribut fields et doit appeler la méthode __toString pour chacun.

Donc :
1) Modifier le toString de Form
2) Ajouter un toString pour chaque champ (FormFieldButton et FormFieldInput)
3) Compléter la méthode addField
*/
 ?>
