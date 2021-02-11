;DUPONT Corentin
;02/04/2020
;Il faut spécifier les valeurs des cases mémoires 1 et 2 en paramétre d'exécution

Load Mem[1]
Add Mem[2]
Store Mem[3]
Load Mem[1]
Mul Mem[2]
Store Mem[4]
Load Mem[1]
Out
Load Mem[4]
Out
End
