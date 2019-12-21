$(function() {
    var voteEnCours = false;

    $("[role='ano_plus']").click(function() { ano_voter(1, this); });
    $("[role='ano_moins']").click(function() { ano_voter(-1, this); });

    function ano_voter(vote, div) {
        if (voteEnCours)
            return;

        var msg = $(div).attr("p");

        voteEnCours = true;
        $.post("/forums/kha_helpful.php", { d:(new Date()).getTime(), a: (vote == 1 ? "plus" : "minus"), p: msg }, function(result) {
            voteEnCours = false;

            var plustitle, moinstitle, plusimg, moinsimg;

            if (result.cancelled) {
                plustitle = "Voter pour ce message (pertinent, utile, je confirme...)";
                moinstitle = "Voter contre ce message (inutile, faux, pas d'accord...)";
                plusimg = moinsimg = "";

            } else {
                plustitle = moinstitle = "Vous avez déjà voté, cliquez pour changer votre vote";
                plusimg = vote == 1 ? "dejavote" : "gris";
                moinsimg = vote == -1 ? "dejavote" : "gris";
            }

            var gauchestyle = "background: url(https://forum.developpez.be/images/buttons/pouce";
            var droitestyle = ".png) no-repeat scroll left center transparent; cursor: pointer";

            $("[role='ano_plus'][p='" + msg + "']").attr("title", plustitle).attr("style", gauchestyle + "haut" + plusimg + droitestyle).html(result.plus);
            $("[role='ano_moins'][p='" + msg + "']").attr("title", moinstitle).attr("style", gauchestyle + "bas" + moinsimg + droitestyle).html(result.minus);

        }, "json");
    }
});
