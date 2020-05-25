$(function() {

	var gabarit_b1 = $('#gabarit_b1');
    $(document.body).click(function(e) {
        if(!$(e.target).is(gabarit_b1)&&!$.contains(gabarit_b1[0],e.target)) {
            $('#gabarit_recherche .gabarit-btn-menu.recherche').removeClass('open');
			$('#gabarit-barreRecherche').hide();
			$('[role="gabarit-contacts"]').show();
        }
    });
	
	$('[role="gabarit-contacts"]').on('click', function() {
		window.location.href='https://club.developpez.com/contacts/';
	});
	
	$('[role="gabarit-recherche"]').on('click', function() { 
		if ($(this).hasClass('open')) {
			$(this).removeClass('open');
			$('#gabarit-barreRecherche').hide();
			$('[role="gabarit-contacts"]').show();
			
		} else {
			$(this).addClass('open');
			$('[role="gabarit-contacts"]').hide();
			$('#gabarit-barreRecherche').show();
			$('#gabarit-barreRecherche form input[type="text"]').focus();
		}
	});

});
