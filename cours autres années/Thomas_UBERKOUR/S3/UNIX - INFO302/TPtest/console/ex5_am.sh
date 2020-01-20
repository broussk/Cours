#!/bin/bash

fichier=$1
nom_fichier=${fichier%.*}
nb_ligne=`wc -l $1 | cut -d " " -f8`

if [ -s $1 ]
then

for F in `seq 1 $nb_ligne`
do
	if [ $((F%2)) -eq 0 ]
	then
		maligne=`cat $1 | head -$F | tail -1`
		echo "$F $maligne" >> ${nom_fichier}_pair.txt
	else
		maligne=`cat $1 | head -$F | tail -1`
		echo "$F $maligne" >> ${nom_fichier}_impair.txt
	fi
done

else 
	echo "Votre fichier est malheureusement vide, RIP"
fi

