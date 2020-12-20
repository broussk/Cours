# Commande devant "normalement" être présente pour vérifier la version de CMake utilisée
# Precise la version minimale pour assurer le bon fonctionnement de la génération de code
cmake_minimum_required(VERSION 3.0)

# Commande devant être présent dans le CMakeLists.txt de plus haut niveau
# Détaille le nom du projet et le cas échéant le langage associé
# Ici on précise le C++
project (HelloWorld CXX)

# Fixe la version du programme
set (HelloWorld_MAJOR_VERSION 1)
set (HelloWorld_MINOR_VERSION 6)

# Commande qui crée une variable locale
set (SRC src)
# Variable pour répertoire de headers
set (INC include)

# Indique la transformation du .h.in en .h
configure_file(
  "${PROJECT_SOURCE_DIR}/${INC}/HelloWorld.h.in"
  "${PROJECT_BINARY_DIR}/${INC}/HelloWorld.h"
  )

# On ajoute le répertoire include pour la recherche de headers (celui de HelloWorld.h)
include_directories ("${PROJECT_BINARY_DIR}/${INC}")

# On ajoute le répertoire MyStrlen pour la recherche de header
include_directories ("${PROJECT_SOURCE_DIR}/MyStrlen")

# Commande qui donne le chemin vers un répertoire qui devrait aussi contenir un
# fichier CMakeList pour faire différentes choses ...
add_subdirectory(${SRC})

# On ira voir dans le répertoire pour compiler la bibliothèque statique
add_subdirectory(MyStrlen)

# Permet la création de l'exécutable HelloWorld à partir du code source qui est dans le répertoire src
# Remarquez les {} pour avoir la valeur de la variable
add_executable(HelloWorld ${SRC}/HelloWorld.cxx)

# On fait l'édition de lien avec MyStrelen
target_link_libraries (HelloWorld  MyStrlen)
