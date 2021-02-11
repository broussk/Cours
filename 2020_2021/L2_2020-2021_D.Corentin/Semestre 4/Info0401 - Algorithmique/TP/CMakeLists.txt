cmake_minimum_required(VERSION 3.17)
project(TP C)

set(CMAKE_C_STANDARD 99)

add_executable(Exo1 TP1/Exo1.c)
add_executable(Exo2 TP1/Exo2.c)
add_executable(Exo4 TP1/NombreParfait.c)
add_executable(Exo5 TP1/Normalisation.c)
add_executable(AndMatrice TP1/IntersectionMatrice.c)
add_executable(CompareMatrice TP1/ComplementMatrice.c)
add_executable(MinMaxMatrice TP1/MinMaxMatrice.c)
add_executable(UnionMatrice TP1/UnionMatrice.c)
add_executable(TailleChaine TP2/TailleChaine.c)
add_executable(Concatenation TP2/Concatenation.c)
add_executable(Tassement TP2/Tassement.c)
add_executable(Permutation TP2/Permutation.c)
add_executable(Fibonnaci TP3/Fibonnaci.c)
add_executable(Fibonnaci_bis TP3/Fibonnaci_bis.c)
add_executable(Majorite TP3/Majorite.c)
add_executable(Fusion TP3/Trie.c)
add_executable(FibonnaciRec TP3/FibonnaciRec.c)
add_executable(MulMatrice TP3/MulMatrice.c)
add_executable(Trie TP3/Trie.c)




add_executable(main Pile/main.c Pile/pile.h Pile/pile.c)