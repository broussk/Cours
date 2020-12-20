# Permet d'avoir accès à la macro CHECK_INCLUDE_FILE_CXX
include(CheckIncludeFileCXX)

# Vérifie si cstddef est disponible
# la variable CSTDDEF indique si oui ou non la recherche a été fructueuse 
CHECK_INCLUDE_FILE_CXX(cstddef CSTDDEF)

# Test de la valeur de CSTDDEF
if(NOT CSTDDEF)
  message("====> No <cstddef> found")
endif()

# Indique que le fichier myStrlen.cxx doit devenir une librairie statique
add_library(MyStrlen myStrlen.cxx)
