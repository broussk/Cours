;DUPONT Corentin
;29/04/2020
;Il faut spécifier le valeur de la case mémoire 0 en paramétre d'exécution => Correspond à la valeur que l'utilisateur doit trouver
;Il faut spécifier le valeur de la case mémoire 1 en paramétre d'exécution => Correspond au nombre limite de coup

;Compteur de coup
Load 0              ;0
Store Mem[3]        ;1


;Incrémentation du compteur de coup de 1
Load Mem[3]         ;2
Add 1               ;3
Store Mem[3]        ;4

;Est-ce qu'on dépasse le nombre de coup maximale ?
CMP Mem[1]          ;5
Jc 18               ;6

;Valeur entrée par l'utilisateur
In                  ;7
Store Mem[2]        ;8
CMP Mem[0]          ;9

;La valeur entrée est-elle plus grande que la solution ?
JC 15               ;10

;La valeur entrée est-elle la solution ?
JZ 18               ;11

;Affiche 0 car proposition trop petite puis retour à la demande de valeau
Load 0              ;12
Out                 ;13
JMP 2               ;14

;Affiche 1 car proposition trop grande puis retour à la demande de valeau
Load 1              ;15
Out                 ;16
JMP 2               ;17

;Affiche le résultat car proposition correcte ou nombre de coup atteint
Load Mem[2]         ;18
Out                 ;19


;Affiche le nombre de coup
Load Mem[3]         ;20
Sub 1               ;21
Out                 ;22

End                 ;23
