/*Calcul de l'IMC*/
function calculerImc()
{
    var taille=document.IMC.taille.value;//recup valeur champ taille
    //gestion du format de la taille (avec un ou sans point ou avec une virgule)
    if(taille.indexOf(".")===-1 && taille.indexOf(",")===-1){//si taille n'a pas pas point et pas de virgule (taille est en centim�tre)
        taille=taille/100;
    }else if(taille.indexOf(",")>=0){//sinon si taille a une virgule (formt chiffre fran�ais)
        taille=taille.replace(",",".");//remplacement dans la chaine de la virgule par un point
    }

    var poids=document.IMC.poids.value;
    var calcul=poids/(taille*taille);
    document.getElementById('resultat').innerHTML=calcul;
    if(calcul<=16.5){
        document.getElementById('avis').innerHTML="Famine";
		document.getElementById('avisMoi').innerHTML="Non, je ne ferais pas de blagues sur les Somaliens...";
    }else if(calcul<=18.5){
        document.getElementById('avis').innerHTML="Maigreur";
		document.getElementById('avisMoi').innerHTML="100%, tu es une fille et tu te trouves encore trop grosse";
    }else if(calcul<=25){
        document.getElementById('avis').innerHTML="Corpulance normale";
		document.getElementById('avisMoi').innerHTML="Aucune originalité";
    }else if(calcul<=30){
        document.getElementById('avis').innerHTML="Surpoids";
		document.getElementById('avisMoi').innerHTML="Continue comme ça dans 10ans tu ressemblera à BigMama";
    }else if(calcul<=35){
        document.getElementById('avis').innerHTML="Obésité modéré";
		document.getElementById('avisMoi').innerHTML="Il serait temps de te mettre au sport, même mon cochon a l'air plus en forme";
    }else if(calcul<=40){
        document.getElementById('avis').innerHTML="Obésité sévère";
		document.getElementById('avisMoi').innerHTML="Tu as trouvé un mirroir assez gros pour te regarder entièrement ?";
    }else if(calcul>40){
        document.getElementById('avis').innerHTML="Obésité morbide";
		document.getElementById('avisMoi').innerHTML="Même un éléphant est moins gros que toi";
    }


    return false;
}

function scrollWindow()
  {
  window.top.window.scrollTo(0,0);
  }


/*Zone de tests / codes pas encore validés*/
sfHover = function() {
        var sfEls = document.getElementById("menu").getElementsByTagName("LI");
        for (var i=0; i<sfEls.length; i++) {
                sfEls[i].onmouseover=function() {
                        this.className+=" sfhover";
                }
                sfEls[i].onmouseout=function() {
                        this.className=this.className.replace(new RegExp(" sfhover\\b"), "");
                }
        }
}
if (window.attachEvent) window.attachEvent("onload", sfHover);
