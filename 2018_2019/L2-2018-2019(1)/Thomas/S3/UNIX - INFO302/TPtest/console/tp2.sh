#!/bin/bash

i=1
echo "Nombre de fichier a afficher :  $# "

for i in $#
mot=$`i`
do
echo "Nom du fichier : $mot "
echo "Type : `file -b $mot`"
echo "Repertoire : `pwd`"
echo "Taille : `ls -lh $mot | cut -d " " -f11` "
echo "Proprietaire : `ls -lh $mot | cut -d " " -f4` "
echo "Droits : `ls -lh $mot| cut -d " " -f1` "
echo "Cree le : `ls -lh $mot| cut -d " " -f13,14,15 ` "	
done
