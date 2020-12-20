# Commande devant "normalement" être présente pour vérifier la version de CMake utilisée
# Precise la version minimale pour assurer le bon fonctionnement de la génération de code
cmake_minimum_required(VERSION 3.0)

# Commande devant être présent dans le CMakeLists.txt de plus haut niveau
# Détaille le nom du projet et le cas échéant le langage associé
# Ici on précise le C++
project (HelloWorld CXX)

# Commande qui crée une variable locale
set (SRC src)

# Permet la création de l'exécutable HelloWorld à partir du code source qui est dans le répertoire src
# Remarquez les {} pour avoir la valeur de la variable
add_executable(HelloWorld ${SRC}/HelloWorld.cpp)
