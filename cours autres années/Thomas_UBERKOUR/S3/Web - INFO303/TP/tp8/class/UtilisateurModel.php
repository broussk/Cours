<?php
spl_autoload_register(function ($class) {
    include 'class/'.$class.'.php';
});

class UtilisateurModel{
  // function arrayToUser(array $tab):Utilisateur{
  //   $id = $tab["id"];
  //   $login = $tab["login"];
  //   $password = $tab["password"];
  //   return new Utilisateur($id,$login,$password);
  //   // print_r($u);
  // }

  public static function create(Utilisateur $user){
    $bdd = MyPDO::getInstance();
    $SQL = "INSERT INTO utilisateur(:idUser,:login,:password)";
    $req = $bdd->prepare($SQL);
    $req->execute(array(
      "idUser" => NULL,
      "login" => $user->getLogin(),
      "password" => $user->getPassword(),
    ));
  }

  function read(int $id):Utilisateur{
    $reponse = $bdd->query('SELECT * FROM utilisateur');
    while($donnees = $reponse->fetch()){
      echo "Id : ".$donnees['id']."\nLogin : ".$donnees['login']."\nPassword : ".$donnes['password']."\n\n";
    }
    $reponse->closeCursor();
  }
}
?>
