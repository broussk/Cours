<?php
class Utilisateur{
    private $login;
    private $mdp;

    public function __construct($login ="", $mdp=""){
        $this->login=$login;
        $this->mdp=$mdp;
    }

    public function getLogin():String{return $this->login;}
    public function getMdp():String{return $this->mdp;}
    public function setLogin(String $login){$this->login=$login;}
    public function setMdp(String $mdp){$this->mdp=$mdp;}

    public function afficherForm(){
        echo <<<HTML
            <div class="form-group">
                <label for="inputLogin">Login :</label>
                <input id="inputLogin" name="inputLogin" type="text" class="form-control" value="($this->login)"/>
            </div>
            <div class="form-group">
                <label for="inputMdp">Mot de passe :</label>
                <input id="inputMdp" name="inputMdp" type="password" class="form-control" value=""/>
            </div>
        HTML;
    }

    public static function fromForm():Utilisateur{
        $login="";
        $mdp="";

        if(isset($_POST['inputLogin']))
            $login = $_POST['inputLogin'];
        if(isset($_POST['inputMdp']))
            $mdp=$_POST['inputMdp'];
        
        return new Utilisateur($login,$mdp);
    }

    const LOGIN = "toto";
    const MDP = "toto";

    public function verification() :bool{
        if($this->==self::LOGIN)&&($this->mdp==self::MDP)
            return true;
        else   
            return false;
    }
}
