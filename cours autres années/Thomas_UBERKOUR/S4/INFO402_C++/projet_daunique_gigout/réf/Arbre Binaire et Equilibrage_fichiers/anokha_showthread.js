function ano_redimensionnerCode() {
	$("pre.alt2").each(function() {
		$(this).css("width", ($(this).parent().width() - 12) + "px");
	});
}

function ano_etendreCode(objet) {
	var html = $(objet).parent().parent().parent().parent().parent().children("pre").html();
	
	if (html.length > 65500) {
		alert("Ce code est trop long pour être affiché dans une fenêtre à part. Vous pouvez cependant demander à le sélectionner pour le copier dans le presse-papiers et le coller dans votre éditeur de texte.");
		return false;
	}
	
	$.ajax({
		url: "/forums/anocode.php",
		dataType: "text",
		type: "POST",
		async: false,
		data: { code : html },
		success: function(id) { window.open("/forums/anocode.php?id=" + id); },
		error: function() { alert("Il y a eu un petit souci lors de la tentative d'afficher le code en plein écran."); }
	});
	
	return false;
}

function ano_selectionnerCode(objet) {
	var texte = $(objet).parent().parent().parent().parent().parent().find("td pre").get(0);
	
	if (texte == undefined)
		texte = $(objet).parent().parent().parent().parent().parent().children("pre").get(0);
	
	if (window.getSelection) {
		var selection = window.getSelection();
		var intervalle = document.createRange();
		intervalle.selectNodeContents(texte);
		selection.removeAllRanges();
		selection.addRange(intervalle);
		
	} else if (document.body.createTextRange) {
		var intervalle = document.body.createTextRange();
		intervalle.moveToElementText(texte);
		intervalle.select();
	}
	
	return false;
}

$(function() {
	var panel;

	/* Élargir les balises CODE */
	
	ano_redimensionnerCode();
	$(window).resize(ano_redimensionnerCode);

	/* Gestion de la fenêtre surgissante */

	function showPanel(e) {
		panel = $(".kha_extraPanel");
		
		if (panel.get(0) != undefined) {
			// panel déjà ouvert : on ferme alors le panel existant
			panel.fadeOut(function() { panel.remove(); });
			return true;
		}
		
		// pas de panel ouvert : on ouvre un panel
		panel = $('<div class="kha_extraPanel"></div>');
		var img = $('<img class="kha_loading" src="/forums/images/misc/progress.gif" />');	
		panel.append(img);
		
		panel.hide();
		$("body").append(panel);

		var x = e.pageX + 10;
		var dx = x + panel.width() - document.body.clientWidth + 5;
		if (dx > 0)
			x -= dx;

		panel.css({ "position": "absolute", "top": (e.pageY + 10), "left": x });
		panel.fadeIn();
		
		// gestion du clic sur la croix de fermeture
		
		$(".kha_title img").css("float", "right").click(function() {
			panel.fadeOut(function() { panel.remove(); });
		});
		
		return false;
	}
	
	/* Gestion de l'attribution de l'évènement clic, la requête Ajax correspondante et l'affichage dans la fenêtre surgissante */
	
	function definirRequete(objet, url, params) {
		objet.css("cursor", "pointer").click(function(e) {
			if (showPanel(e))
				return;
			
			params.u = $(this).attr("userid");
			params.d = (new Date()).getTime();
			
			if (params.u == undefined)
				params.u = $(this).attr("user");
			
			try {
				$.post(url, params, function(data) {
					panel.html(data);
					panel.find("img:eq(0)").css("cursor", "pointer").click(function() {
						$(this).parent().parent().fadeOut(function() { $(this).remove(); })});
				});
			} catch (ex) {
				panel.remove();
			}
		});
	}
	
	/* Définition des différents éléments cliquables */

	definirRequete($("span[role='points']"), "/forums/anopoints.php", { });
	definirRequete($("img[role='trophees']"), "/forums/anopoints.php", { m: "trophees" });
	definirRequete($("img[role='twitter']"), "/forums/kha_portail.php", { ws: "getTweets" });
	definirRequete($("img[role='blog']"), "/forums/kha_portail.php", { ws: "getBlog" });
	definirRequete($("img[role='news']"), "/forums/kha_portail.php", { ws: "getNews" });
	definirRequete($("img[role='publications']"), "/forums/kha_portail.php", { ws: "getPublications" });
	definirRequete($("img[role='traductions']"), "/forums/kha_portail.php", { ws: "getTraductions" });
	definirRequete($("img[role='relectures']"), "/forums/kha_portail.php", { ws: "getRelectures" });
	definirRequete($("img[role='certifications']"), "/forums/kha_portail.php", { ws: "getCertifications" });
	definirRequete($("img[role='livres']"), "/forums/kha_portail.php", { ws: "getLivres" });
	definirRequete($("img[role='gabarisations']"), "/forums/kha_portail.php", { ws: "getGabarisations" });
	definirRequete($("img[role='uploads']"), "/forums/kha_portail.php", { ws: "getUploads" });
	definirRequete($("img[role='faq']"), "/forums/kha_portail.php", { ws: "getFaq" });

	/* Afficher le profil étendu */

	$("img[role='profiletendu']").css("cursor", "pointer").click(function(e) {
		if (showPanel(e))
			return;
		
		var userid = $(this).attr("userid");
		panel.html($("div[role='profiletendu'][userid='" + userid + "']").html());
		panel.find("img:eq(0)").css("cursor", "pointer").click(function() {
				$(this).parent().parent().fadeOut(function() { $(this).remove(); })});
	});

	/* Gestion du champ code postal */

	var codepostal = $("#cfield_12");
	if (codepostal.get(0) != undefined) {
		var pays = $("#cfield_11");

		if (codepostal.val() == "n.d.")
			codepostal.prop("readonly", true);

		codepostal.keyup(function() {
			if (this.value != "n.d." || pays.val() == 1)
				this.value = this.value.replace(/[^0-9]/gi, "");
		});

		pays.change(function() {
			if (this.value == 1)
				codepostal.val("").prop("readonly", false);
			else
				codepostal.val("n.d.").prop("readonly", true);
		});
	}
});
