var courant = 0;
function next() {
    requete = $.ajax({
        type: 'POST',
        url: 'donnees.php',
        data: { "numero" : courant },
        dataType: 'json'
    });
    requete.done(function (response, textStatus, jqXHR) {
        if('erreur' in response) {
            $('#content').html("Une erreur est survenue...");
        }
        else {
            courant = response['next'];
            $('#content').html(response['actualite']['titre']);
            setTimeout(next, 3000);
        }
    });
    requete.fail(function (jqXHR, textStatus, errorThrown){
        console.log(jqXHR);
    });    
}