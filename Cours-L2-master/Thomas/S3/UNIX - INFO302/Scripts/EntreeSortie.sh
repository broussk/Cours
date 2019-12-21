#!/bin/bash

# $1 vaut nomFichier et $2 vaut nbLignes
nom=$1
lignes=$2
fic=`cat $nom`
for lignes in $fic
do
	echo $lignes
done

