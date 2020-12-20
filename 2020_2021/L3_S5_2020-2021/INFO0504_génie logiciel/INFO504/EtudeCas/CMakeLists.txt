# Commande devant "normalement" être présente pour vérifier la version de CMake utilisée
# Precise la version minimale pour assurer le bon fonctionnement de la génération de code
cmake_minimum_required(VERSION 3.0)

# Commande devant être présent dans le CMakeLists.txt de plus haut niveau
# Détaille le nom du projet et le cas échéant le langage associé
# Ici on précise le C++
project (Acsq_me CXX)

# Commande qui crée une variable locale
set (SRC src)
# Variable pour répertoire de tests
set (TEST tests)

# Commande qui donne le chemin vers un répertoire qui devrait aussi contenir un
# fichier CMakeList pour faire différentes choses ...
add_subdirectory(${SRC})
add_subdirectory(${TEST})

# Permet la création de l'exécutable Ascq_me à partir du code source qui est dans le répertoire src
# Remarquez les {} pour avoir la valeur de la variable
add_executable(Ascq_me ${SRC}/Ascq_me.cpp)

# Active la possibilité d'utiliser CPack
include(CPack)

# Active l'utilisation des tests depuis la racine du projet
include(CTest)