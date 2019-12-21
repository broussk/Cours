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
      return /*"Id : ".$id."\n*/"Login : ".$login."\nMot de passe : ".$password;
    }

    // function getId():int{
    //   return $this->id;
    // }

    function getLogin():string{
      return $this->login;
    }

    function getPassword():string{
      return $this->password;
    }

    function verification(string $choice):bool{
      $verif=false;
      $fichier = file("password.txt");
      $id = file_get_contents("password.txt");
      if($choice==="verifLogin"){
        $logpass = $this->getLogin().";".$this->getPassword();
        foreach ($fichier as $key => $value) {
          $valueTrimmed = trim($value);
          if($valueTrimmed===$logpass){
            $verif=true;
          }
        }
      }
      elseif($choice==="verifInscription"){
        $verifLogin = false;
        if(preg_match('/[a-zA-Z0-9]{3,}/',$this->getLogin())){
          // echo "Login conforme</br>";
          foreach ($fichier as $key => $value) {
            $explodedValue = explode(";",$value);
            // echo "Test sur $explodedValue[0] : ";
            if(($explodedValue[0]!==$this->getLogin())){
              // echo "Différend</br>";
              $verifLogin = true;
            }
            else{
              break;
            }
          }
        }
        else echo "Erreur, login non conforme</br>";
        if($verifLogin===true){
          $verifPwd = false;
          if(preg_match('/^(?=.*?[A-Z])(?=.*?[a-z])(?=.*?[#?!@$%^&*-.]).{6,}$/',$this->getPassword())){
            // echo "Mdp conforme</br>";
            $verifPwd = true;
          }
          else{
            echo "Erreur, mot de passe non conforme</br>";
          }
        }
        if($verifLogin===true && $verifPwd===true){
          $verif = true;
        }
      }
      return $verif;
    }

    function inscription(){
      $t = file('password.txt');
      $log = $this->getLogin().";".$this->getPassword()."\n";
      $t[] = $log;
      file_put_contents("password.txt",$t);
    }

    function connexion(){
      $_SESSION[self::SESSION] = $this;
    }

    function isConnected():bool{
      $verif = false;
      if(($_SESSION[self::SESSION]->getLogin()==$this->login)&&($_SESSION[self::SESSION]->getPassword()==$this->password)){
        $verif = true;
      }
      return $verif;
    }

    function deconnexion(){
      $_SESSION = array();
    }
  }
