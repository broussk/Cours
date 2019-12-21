#!/bin/bash

for F in $*
do
fichier=`file $F`
resul=`ls -lh $F`
echo "Nom du fichier : $F"
echo "Type : ${fichier#*:} "
echo "Repertoire : $PWD"
echo "Taille : `ls -lh $F | cut -d " " -f8`"
echo "Proprietaire : `ls -lh $F | cut -d " " -f3`"
echo "Droits : `ls -lh $F | cut -d " " -f1`"
echo "Cree le : `ls -lh $F | cut -d " " -f10,11,12 `"
printf "\n"
done







