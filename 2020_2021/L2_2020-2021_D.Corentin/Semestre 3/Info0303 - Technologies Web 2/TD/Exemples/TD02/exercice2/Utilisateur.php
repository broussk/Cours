<?php
class Utilisateur {
  
    // PHP version < 7.4
    private $login;
    private $motDePasse;
    
    // PHP version 7.4
    /*private string $login;
    private string $motDePasse;*/
    
    const LOGIN = "toto";
    const MOTDEPASSE = "toto";

    public function __construct($login = "", $motDePasse = "") {
        $this->login = $login;
        $this->motDePasse = $motDePasse;
    }
    
    public function getLogin() : string {
        return $this->login;
    }
    
    public function afficherForm() {
        echo <<<HTML
<div class="form-group">
  <label for="inputLogin">Login :</label>
  <input id="inputLogin" name="inputLogin" type="text" class="form-control" value="{$this->login}"/>
</div>
<div class="form-group">
  <label for="inputMotDePasse">Mot de passe :</label>
  <input id="inputMotDePasse" name="inputMotDePasse" type="password" class="form-control" value=""/>
</div>
HTML;
    }
    
    public static function fromForm() : Utilisateur {
        $login = "";
        $motDePasse = "";
        
        if(isset($_POST['inputLogin']))
            $login = $_POST['inputLogin'];
        if(isset($_POST['inputMotDePasse']))
            $motDePasse = $_POST['inputMotDePasse'];
        
        return new Utilisateur($login, $motDePasse);
    }
    
    public function verification() : bool {
        if(($this->login == self::LOGIN) &&
           ($this->motDePasse == self::MOTDEPASSE))
            return true;
        else
            return false;
    }
}