##shell script to download all volumes of Lord Knuth's Art of Computer Programming:
##(you can copy from the next line at once, since all the styled texts will recognized as comments in the shell)

#!/bin/sh

##Volume 1 - Fundamental Algorithms, 3rd Edition
wget -c http://broiler.astrometry.net/~kilian/The_Art_of_Computer_Programming%20-%20Vol%201.pdf -O art_of_compProg-vol1 &&

##Volume 2 - Seminumerical Algorithms, 2nd Edition
wget -c https://archive.org/download/B-001-002-137/Addison.Wesley.Donald.E.Knuth.The.Art.of.Computer.Programming.Volume.2.pdf -O art_of_compProg-vol2.pdf &&

##Volume 3 - Sorting and Searching, 2nd Edition
wget -c https://archive.org/download/B-001-001-250/B-001-001-250.pdf -O art_of_compProg-vol3.pdf &&

##Volume 4A- Combinatorial Algorithms
wget -c https://users.dcc.uchile.cl/~nbaloian/cc3001-02/Libros/Algoritmos%20y%20Estructura%20de%20Datos/The%20Art%20of%20Computer%20Programming%20Vol.4A%20-%20Combinatorial%20Algor.pdf -O art_of_compProg-vol4.pdf
