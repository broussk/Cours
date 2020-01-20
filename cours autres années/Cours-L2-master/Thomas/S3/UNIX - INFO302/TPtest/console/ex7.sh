#!/bin/bash

fichier=$1
nb_ligne=`cat $1 | wc -l`
for F in `seq 1 $nb_ligne`
do
	ma_chaine=`cat $1 | head -$F | tail -1`
	nb_mot=`echo $ma_chaine | wc -w`
	
		for i in `seq 1 $nb_mot`
		do
			mot=`echo $ma_chaine | cut -d " " -f$i | tr -d " ,."`
		#	echo " le mot est $mot"
			prem_lettre=${mot:0:1}
			if [ $prem_lettre == s ]
			then
				echo "bon pour : $mot"
				echo $mot >> s_words
			fi
		done
done
