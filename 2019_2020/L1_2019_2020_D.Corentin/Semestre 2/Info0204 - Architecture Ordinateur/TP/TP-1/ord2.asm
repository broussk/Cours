;DUPONT Corentin
;02/04/2020
;Il faut spécifier les valeurs des cases mémoires 1 et 2 en paramétre d'exécution

Load Mem[1]     ;0
CMP Mem[2]      ;1
JC 9            ;2
Load Mem [2]    ;3
Store Mem[4]    ;4
Load Mem [1]    ;5
Store Mem[3]    ;6
JMP 13          ;7
Load Mem [1]    ;8
Store Mem[4]    ;9
Load Mem [2]    ;10
Store Mem[3]    ;11
Load Mem[3]     ;12
Out             ;13
Load Mem[4]     ;14
Out             ;15
End             ;16
