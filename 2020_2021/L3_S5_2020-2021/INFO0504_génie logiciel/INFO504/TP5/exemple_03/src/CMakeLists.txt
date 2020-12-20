# Permet d'avoir accès à la macro CHECK_INCLUDE_FILE_CXX
include(CheckIncludeFileCXX)

# Vérifie si cstdio est disponible
# la variable CSTDIO indique si oui ou non la recherche a été fructueuse 
CHECK_INCLUDE_FILE_CXX(cstdio CSTDIO)

# Test de la valeur de CSTDIO
if(CSTDIO)
  # Affichage du message de réussite
  message("====> We did it!")
endif()

# Vérifie si cstlib est disponible
# la variable CSTDLIB indique si oui ou non la recherche a été fructueuse 
CHECK_INCLUDE_FILE_CXX(cstdlib CSTDLIB)

# Test de la valeur de CSTDLIB
if(CSTDLIB)
  # Affichage du message de réussite
  message("====> We did it!")
endif()

# Vérifie si iostream est disponible
# la variable IOSTREAM indique si oui ou non la recherche a été fructueuse 
CHECK_INCLUDE_FILE_CXX(iostream IOSTREAM)

# Test de la valeur de IOSTREAM
if(IOSTREAM)
  # Affichage du message de réussite
  message("====> We did it!")
endif()

# Recherche d'un fichier inexistant
# Et affichage de l'échec
CHECK_INCLUDE_FILE_CXX(swiper SWIPER)
if(NOT SWIPER)
  message("====> Swiper, no swiping! \n      Swiper, no swiping!\n      Swiper, no swiping!\n      Oh, man!")
endif()
