/*Préchargement des images*/
var images=new Array();
images[0]=new Image();
images[0].src="../img/anat_abdos_droit_trans.png";
images[1]=new Image();
images[1].src="../img/anat_abdos_oblique_trans.png";
images[2]=new Image();
images[2].src="../img/anat_adducteurs_trans.png";
images[3]=new Image();
images[3].src="../img/anat_avantbras_trans.png";
images[4]=new Image();
images[4].src="../img/anat_biceps_trans.png";
images[5]=new Image();
images[5].src="../img/anat_deltoides_trans.png";
images[6]=new Image();
images[6].src="../img/anat_dorsaux_trans.png";
images[7]=new Image();
images[7].src="../img/anat_fessiers_trans.png";
images[8]=new Image();
images[8].src="../img/anat_ischios_trans.png";
images[9]=new Image();
images[9].src="../img/anat_mollets_trans.png";
images[10]=new Image();
images[10].src="../img/anat_pecs_trans.png";
images[11]=new Image();
images[11].src="../img/anat_quadriceps_trans.png";
images[12]=new Image();
images[12].src="../img/anat_trapezes_trans.png";
images[13]=new Image();
images[13].src="../img/anat_triceps_trans.png";
images[14]=new Image();
images[14].src="../img/trans.png";

/*Changement des images pour aperçu rouge lors du passage de la souris sur un muscle*/
function changerImg(zone,nr) {
  var pic=document.getElementById("hovered")
  pic.src=images[nr].src
  zone.onmouseout=function(){
    pic.src=images[14].src
  }
}

/*Redimensionnement des zones clicables pour l'anatomie*/
window.onload = function () {
    var ImageMap = function (map, img) {
            var n,
                areas = map.getElementsByTagName("area"),
                len = areas.length,
                coords = [],
                previousWidth = 4875;
            for (n = 0; n < len; n++) {
                coords[n] = areas[n].coords.split(',');
            }
            this.resize = function () {
                var n, m, clen,
                    x = img.offsetWidth / previousWidth;
                for (n = 0; n < len; n++) {
                    clen = coords[n].length;
                    for (m = 0; m < clen; m++) {
                        coords[n][m] *= x;
                    }
                    areas[n].coords = coords[n].join(',');
                }
                previousWidth = document.body.clientWidth;
                return true;
            };
            window.onresize = this.resize;
        },
        imageMap = new ImageMap(document.getElementById("Anatomie"), document.getElementById("hovered"));
    imageMap.resize();
    return;
}
