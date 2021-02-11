;DUPONT Corentin
;02/04/2020
;Il faut spécifier le valeur de la case mémoire 12 en paramétre d'exécution

Load Mem[12]
CMP 10
JZ 5
Load 0
JMP 6
Load 7
Store Mem[18]
End
