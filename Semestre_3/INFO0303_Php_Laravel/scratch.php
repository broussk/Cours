<!DOCTYPE html>
<html lang="fr">
<head>
    <title title="the title" ></title>
    <meta charset="utf-8">
    <meta name="viewport" content="width = device-width, initial-scale=1">
    <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/4.1.0/css/bootstrap.css">
</head>
<body>
<h1>Les tables de multiplication</h1>
<!--<table class="table table-stipped table-bondored">
    <tr>
        <td></td>
    </tr>
</table>-->
<?php //exo 1.1
for($i=1;$i<=10;$i++){
    echo "<table class='table table-stipped table-bondored'>";
    echo "<tr><td colspan='2'>Table ".$i."</td></tr>";
            for($j=0;$j<=10;$j++){
                echo "<tr><td>".$i." x ".$j."</td><td>".$i*$j."</td></tr>";
            }
        }
    echo "</table>";
    ?>
<?php //exo1.2
    for($i=1;$i<=10;$i++){
        echo "<a href='table$i.php' class='btn btn-primary'>$i</a>&nbsp;";
        $i=1;
        echo "<table class='table table-stipped table-bondored'>";
        echo "<tr><td colspan='2'>Table ".$i."</td></tr>";
            for($j=0;$j<=10;$j++){
                echo "<tr><td>".$i." x ".$j."</td><td>".$i*$j."</td></tr>";
            }

    }
    echo "</table>";
?>
<?php //exo 1.3
$table =1;
if(isset($_GET['table']))
    $table = intval($_GET['table']);
if(($table<1)||($table >10)) $table=1;
echo "<table class='table table-stipped table-bondored'>";
echo "<tr><td colspan='2'>Table $table</td></tr>";
for($j=0;$j<=10;$j++){
    echo "<tr><td>".$table. "x" .$j."</td><td>".$table*$j."</td></tr>";
}

?>
<!--1.3         php  non fini-->
<script type="text/javascript">
    function selection(i) {
        for (j=1;j<=10;j++){
            if(j==i) $('#table'+j).show();
            else $('#table'+j).hide();
    }
    }
</script>
<?php
for($i=1;$i<=10;$i++){
    echo "<a href='javascript:selection($i)' class='btn btn-primary'>$i</a>&nbsp;";
    $i=1;
    echo "<table  id='table$1' class='table table-stipped table-bondored' " .($i);
    echo "<tr><td colspan='2'>Table ".$i."</td></tr>";
    for($j=0;$j<=10;$j++){
        echo "<tr><td>".$i." x ".$j."</td><td>".$i*$j."</td></tr>";
    }

}
echo "</table>";
?>

<!-- 2.2-->
<!-- 3.2-->
</body>
</html>