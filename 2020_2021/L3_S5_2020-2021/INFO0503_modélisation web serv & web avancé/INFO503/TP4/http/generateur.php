<?php
header("Content-type: application/json");

if(isset($_POST['login']) && isset($_POST['motDePasse'])) {
    if(($_POST['login'] == "toto") && ($_POST['motDePasse'] == "toto"))
        $tableau = [ "code" => "OK", "message" => "login correct" ];
    else
        $tableau = [ "code" => "erreur", "message" => "login incorrect" ];
}
else
    $tableau = [ "code" => "erreur", "message" => "données manquantes." ];

echo json_encode($tableau);