<?php
spl_autoload_register(function ($class) {
  include 'class/'.$class.'.php';
});
session_start();

// var_dump($user);
// echo "</br>";

if(isset($_SESSION[Utilisateur::SESSION])){
  afficherBienvenue($_SESSION[Utilisateur::SESSION]);
}
else{
  afficherForm();
  if(isset($_POST['seConnecter'])){
    $user = fromForm($_POST['login'],$_POST['password']);
    if($user->verification("verifLogin")){
      $user->connexion();
      if($user->isConnected()){
        afficherBienvenue($user);
      }
      else{
        afficherForm();
      }
      header("Refresh: 0");
    }
  }
}

// $_SESSION=$user;
// $_SESSION[Utilisateur::SESSION] = $user;
// var_dump($user);
// echo "</br>";
// var_dump($_SESSION);
// echo "</br>";
// var_dump($_SESSION[Utilisateur::SESSION]);
// echo "</br>";
//
// if($user->isConnected()){
//   echo "connecté";
// }
// else{
//   echo "deconnecté";
// }
//
// $user->deconnexion();
// if(!isset($_SESSION[Utilisateur::SESSION])){
//   echo "déconnecté";
// }
//
// // $user->connexion();
// if($user->isConnected()){
//   echo "connecté";
// }
// else{
//   echo "deconnecté";
// }



















  function fromForm(string $login, string $password):Utilisateur{
      $user = new Utilisateur($login,$password);
    return $user;
  }

  function afficherForm():void{
    echo "
    <form name=\"form\" method=\"post\" action=\"#\">
    <div class=\"form-group col-md-6\">
    <label for=\"login\">Login</label>
    <input name=\"login\"  type=\"text\" class=\"form-control\" id=\"login\" placeholer=\"Entrez votre pseudo ici\" required>
    </div>
    <div class=\"form-group col-md-6\">
    <label for=\"password\">Mot de passe</label>
    <input name=\"password\"  type=\"password\" class=\"form-control\" id=\"password\" placeholer=\"Entrez votre mot de passe\" required>
    </div>
    <button style=\"margin-left: 1em; margin-top: 5px;\" id=\"seConnecter\" type=\"submit\" class=\"btn btn-primary\" name=\"seConnecter\">Se connecter</button></br>
    </form>
    <form name=\"form\" method=\"post\" action=\"inscription.php\">
    <button style=\"margin-left: 1em; margin-top: 5px;\" id=\"createLog\" type=\"submit\" class=\"btn btn-primary\" name=\"createLog\">S'inscire</button>
    </form>
    ";
  }

  function afficherBienvenue(Utilisateur $u):void{
    echo "
    Bienvenue ".$u->getLogin()."</br></br>
    <form name=\"form\" method=\"post\" action=\"deconnexion.php\">
      <button style=\"margin-left: 1em; margin-top: 5px;\" id=\"deconnexion\" type=\"submit\" class=\"btn btn-primary\" name=\"deconnexion\">Déconnexion</button>
    </form>
    ";
  }
 ?>
