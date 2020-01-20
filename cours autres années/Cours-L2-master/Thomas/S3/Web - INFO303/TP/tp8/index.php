<?php
spl_autoload_register(function ($class) {
    include 'class/'.$class.'.php';
});
include 'BDconfig.php';

$user = new Utilisateur("test","test");
UtilisateurModel::create($user);
?>
