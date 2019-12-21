#!/bin/bash

# Eco 3
#for i in $*
#do
#	fichier=$i
#	nom=${fichier%.*}
#	mv $* ${nom}.data 
#done

# Exo 1
#fichier=`echo $* | tr -d " "`
#taille=${#fichier}
#for i in `seq 0 $taille`
#do
#	mot="${fichier:$i:1}"
#	echo -n " $mot"
#done
#echo -e "\n"

minuscule=`echo $* | tr -d " "[:upper:][0-9]`
majuscule=`echo $* | tr -d " "[:lower:][0-9]`
chiffres=`echo $* | tr -d " "[a-z][A-Z]`

echo -e "Nombre de minuscule : ${#minuscule} \nNombre de majuscules : ${#majuscule}\nNombre de chiffres : ${#chiffres}" 
