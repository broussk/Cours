# Ceci est un commentaire car commençant par un #

# Commande devant être présent dans le CMakeLists.txt de plus haut niveau
# Détaille le nom du projet et le cas échéant le langage associé
project (HelloWorld)

# Commande précisant l'exécutable à créer avec les fichiers associés à utiliser
add_executable (HelloWorld HelloWorld.cpp)
