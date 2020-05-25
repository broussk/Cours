<?php

?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Document</title>
</head>
<body>
<?php
if(isset($_POST['valdier'])){
    echo <<<HTML
        </div>
        <div class="card-footer bg-danger">
            identidiants incorrects.
        </div>
    HTML;
}
else
    echo "Bienvenue <span class='badge badge-primary'>".$utilsateur->getLogin.'</span>.</div>";
?>
        </div>
    </div>
</body>
</html>