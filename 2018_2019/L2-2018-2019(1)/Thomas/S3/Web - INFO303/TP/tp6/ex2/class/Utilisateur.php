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

    public static function afficherForm(bool $connexion){
        if($connexion===true){
        echo "  <div class=\"form-group col-md-6\">
            <label for=\"login\">Login</label>
            <input name=\"login\"  type=\"text\" class=\"form-control\" id=\"login\" placeholer=\"Entrez votre pseudo ici\" required>
          </div>
          <div class=\"form-group col-md-6\">
            <label for=\"password\">Mot de passe</label>
            <input name=\"password\"  type=\"password\" class=\"form-control\" id=\"password\" placeholer=\"Entrez votre mot de passe\" required>
          </div>
          <button style=\"margin-left: 1em; margin-top: 5px;\" id=\"seConnecter\" type=\"submit\" class=\"btn btn-primary\" name=\"seConnecter\">Se connecter</button>
          ";
        }
      if($connexion===false){
        echo
        "
        <div class=\"form-group col-md-6\">
          <label for=\"login\">Login</label>
          <input name=\"login\"  type=\"text\" class=\"form-control\" id=\"login\" placeholer=\"Entrez votre mot de passe\" value=\"\" required>
          <small id=\"passwordHelpInline\" class=\"text-muted\">Votre login doit comporter au moins 3 caractères</small>
        </div>
        <div class=\"form-group col-md-6\">
          <label for=\"password\">Mot de passe</label>
          <input name=\"password\"  type=\"password\" class=\"form-control\" id=\"password\" placeholer=\"Entrez votre mot de passe\" required>
          <small id=\"passwordHelpInline\" class=\"text-muted\">Mot de passe : Au moins 1 Majuscule, 1 caractère spécial [#?!@$%^&*-] et 6 de longueur</small>
        </div>
        <div class=\"form-group col-md-6\">
          <label for=\"verifPassword\">Vérification mot de passe</label>
          <input name=\"verifPassword\"  type=\"password\" class=\"form-control\" id=\"verifPassword\" placeholer=\"Entrez de nouveau votre mot de passe\" required>
        </div>
        <button style=\"margin-left: 1em; margin-top: 5px;\" id=\"createLog2\" type=\"submit\" class=\"btn btn-primary\" name=\"createLog2\">S'inscire</button></br>
        ";
      }
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
    ///////////////////////////////////
    //PHPLIVEREGEX
    ///////////////////////////////////
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
