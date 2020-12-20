<!DOCTYPE html>
<html lang='fr'>
  <head>
    <title>Formulaire Ajout Voiture </title>
    <meta http-equiv="content-type" content="http://localhost/Projet_1_MEDDOURI_VANSCOOR/FormulaireAjoutVoiture.php; charset=utf-8"/>
  </head>
  <body>
    <h1>Formulaire Ajout Voiture</h1>

    <form method="POST"action="http://localhost:8080/ajout" name="formulaire">
        <?php
        $recupModele = json_decode(file_get_contents('modele.json'),true);
        $recupMoteur = json_decode(file_get_contents('moteur.json'),true);
        $recupCouleur = json_decode(file_get_contents('couleurs.json'),true);
        $recupOptions = json_decode(file_get_contents('options.json'),true);
        $newRecupOptions = $recupOptions;
        for($i = 0; $i < count($newRecupOptions);$i++){
          $newRecupOptions[$i] = str_replace(true,"(ajoute)",$recupOptions[$i]);
        }
        ?>
        <br>
        <label>Numero Identification</label><input type="text" name="numeroIdentification"/>
        <br/>
        <br>
        <label for="listeModele">Choisissez un modèle :</label>
        <select name="modele" id="listeModele">
          <option value="">--Veuillez choisir un modele--</option>
          <option value="<?php foreach($recupModele[0] as $element)echo($element);?>"><?php foreach($recupModele[0] as $element)echo($element);?></option>
          <option value="<?php foreach($recupModele[1] as $element)echo($element);?>"><?php foreach($recupModele[1] as $element)echo($element);?></option>
        </select>
        <br/>
        <br>
        <label for="listeMoteur">Choisissez un moteur :</label>
        <select name="moteur" id="listeMoteur">
          <option value="">--Veuillez choisir un moteur--</option>
          <option value="<?php foreach($recupMoteur[0] as $element)echo($element  . ",");?>"><?php echo("PuissDef, Id, Carburation, Puissance : "); foreach($recupMoteur[0] as $element)echo($element . "\n");?></option>
          <option value="<?php foreach($recupMoteur[1] as $element)echo($element . ",");?>"><?php echo("PuissDef, Id, Carburation, Puissance : "); foreach($recupMoteur[1] as $element)echo($element . "\n");?></option>
        </select>
        <br/>
        <br>
        <label>Date de Fabrication</label><input type="text" name="dateFabrication"/>
        <br/>
        <br>
        <label for="listeCouleur">Choisissez une couleur :</label>
        <select name="couleur" id="listeCouleur">
          <option value="">--Veuillez choisir une couleur--</option>
          <option value="<?php echo($recupCouleur[0])?>"><?php echo($recupCouleur[0])?></option>
          <option value="<?php echo($recupCouleur[1])?>"><?php echo($recupCouleur[1]);?></option>
          <option value="<?php echo($recupCouleur[2])?>"><?php echo($recupCouleur[2]);?></option>
          <option value="<?php echo($recupCouleur[3])?>"><?php echo($recupCouleur[3]);?></option>
          <option value="<?php echo($recupCouleur[4])?>"><?php echo($recupCouleur[4]);?></option>
          <option value="<?php echo($recupCouleur[5])?>"><?php echo($recupCouleur[5]);?></option>
          <option value="<?php echo($recupCouleur[6])?>"><?php echo($recupCouleur[6]);?></option>
          <option value="<?php echo($recupCouleur[7])?>"><?php echo($recupCouleur[7]);?></option>
          <option value="<?php echo($recupCouleur[8])?>"><?php echo($recupCouleur[8]);?></option>
          <option value="<?php echo($recupCouleur[9])?>"><?php echo($recupCouleur[9]);?></option>
          <option value="<?php echo($recupCouleur[10])?>"><?php echo($recupCouleur[10]);?></option>
          <option value="<?php echo($recupCouleur[11])?>"><?php echo($recupCouleur[11]);?></option>
          <option value="<?php echo($recupCouleur[12])?>"><?php echo($recupCouleur[12]);?></option>
          <option value="<?php echo($recupCouleur[13])?>"><?php echo($recupCouleur[13]);?></option>
        </select>
        <br/>
        <br>
        <p> Veuillez cocher les options que vous voulez ajouter à la voiture :</p>
        <INPUT type="checkbox" name="options1" value="<?php foreach($recupOptions[0] as $element)echo($element . "\n");?>"> <?php foreach($newRecupOptions[0] as $element)echo($element . "\n");?>
        <INPUT type="checkbox" name="options2" value="<?php foreach($recupOptions[1] as $element)echo($element . "\n");?>"> <?php foreach($newRecupOptions[1] as $element)echo($element . "\n");?>
        <INPUT type="checkbox" name="options3" value="<?php foreach($recupOptions[2] as $element)echo($element . "\n");?>"> <?php foreach($newRecupOptions[2] as $element)echo($element . "\n");?>
        <INPUT type="checkbox" name="options4" value=" <?php foreach($recupOptions[3] as $element)echo($element . "\n");?>"> <?php foreach($newRecupOptions[3] as $element)echo($element . "\n");?>
        <br/>
        <br>
        <button>Valider</button>
        <br/>
    </form>
 </body>
</html>