<?php
  class Utilisateur{
    protected $login;
    protected $password;
    protected static $fichierPassword;
    const SESSION = "usersConnected";

    function __construct(string $login, string $password){
      $this->login=$login;
      $this->password=$password;
    }

    function __toString():string{
      return "Login : ".$login."\nMot de passe : ".$password;
    }

    function getLogin():string{
      return $this->login;
    }

    function getPassword():string{
      return $this->password;
    }

    /*function fromForm(string $login, string $password):Utilisateur{
      $t = file('password.txt');
      $log = "$login;$password\n";
      $alreadyDefined=0;
      foreach ($t as $key => $value) {
        if($value===$log){
          $alreadyDefined=1;
        }
      }
      if($alreadyDefined!=1){
        $t[] = $log;
        file_put_contents("password.txt",$t);
        $alreadyDefined=0;
      }
      $user = new Utilisateur($login,$password);
      return $user;
    }*/

    function verification():bool{
      $fichier = file("password.txt");
      $id = file_get_contents("password.txt");
      $logpass = $this->login.";".$this->password;
      // echo $id;
      $verif=false;
      foreach ($fichier as $key => $value) {
        $valueTrimmed = trim($value);
        // $logpassTrimmed = trim($logpass);
        // echo $valueTrimmed."</br>".$logpass."</br>";
        if($valueTrimmed===$logpass){
          $verif=true;
        }
        // if($verif==true){
        //   echo "true</br></br>";
        // }
        // else{
        //   echo "false</br></br>";
        // }
      }
      return $verif;
    }

    function connexion(){
      $_SESSION[self::SESSION] = clone $this;
    }

    function isConnected(string $login, string $password):bool{
      $verif = false;
      if(($_SESSION[self::SESSION]->login==$this->login)&&($_SESSION[self::SESSION]->password==$this->password)){
        // var_dump($_SESSION[self::SESSION]);
        $verif = true;
      }
      // else{
      //   echo "Débug";
      // }
      return $verif;
    }

    function deconnexion(){
      $_SESSION = array();
    }
  }
