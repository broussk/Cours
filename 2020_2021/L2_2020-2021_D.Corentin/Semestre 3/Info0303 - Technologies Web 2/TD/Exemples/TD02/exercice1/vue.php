<?php
if(isset($actualite)) {
?>
<div class='col-sm-4'>
  <div class='card border-dark mb-4'>
    <div class='card-header text-center'><?php echo $actualite->getTitre(); ?></div>
    <div class='card-body'><?php echo $actualite->getMessage(); ?></div>
    <div class='card-footer text-center'><?php echo $actualite->getDate(); ?></div>
  </div>
</div>
<?php
}