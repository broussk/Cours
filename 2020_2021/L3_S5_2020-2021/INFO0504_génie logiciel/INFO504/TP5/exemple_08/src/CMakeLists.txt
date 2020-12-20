# Permet d'avoir accès à la macro CHECK_INCLUDE_FILE_CXX
include(CheckIncludeFileCXX)

# Vérifie si cstdio est disponible
# la variable CSTDIO indique si oui ou non la recherche a été fructueuse 
CHECK_INCLUDE_FILE_CXX(cstdio CSTDIO)

# Test de la valeur de CSTDIO
if(NOT CSTDIO)
  message("====> No <cstdio> found")
endif()

# Vérifie si cstdio est disponible
# la variable CSTDLIB indique si oui ou non la recherche a été fructueuse 
CHECK_INCLUDE_FILE_CXX(cstdlib CSTDLIB)

# Test de la valeur de CSTDLIB
if(NOT CSTDLIB)
  message("====> No <cstdlib> found")
endif()

# Vérifie si cstdio est disponible
# la variable IOSTREAM indique si oui ou non la recherche a été fructueuse 
CHECK_INCLUDE_FILE_CXX(iostream IOSTREAM)

# Test de la valeur de IOSTREAM
if(NOT IOSTREAM)
  # Affichage du message de réussite
  message("====> No <iostream> found")
endif()
