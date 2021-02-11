;DUPONT Corentin
;07/04/2020

In             ;0
Store Mem[0]   ;1 -> a
In             ;2
Store Mem[1]   ;3 -> b
CMP Mem[0]     ;4
JC 7           ;5
JMP 13         ;6

;J'échange a et b pour avoir la plu grande valeur dans a
Load Mem[0]    ;7
Store Mem[2]   ;8
Load Mem[1]    ;9
Store Mem[0]   ;10
Load Mem[2]    ;11
Store Mem[1]   ;12

;Euclide
Load Mem[0]    ;13
Mod Mem[1]     ;14
Store Mem[3]   ;15
CMP 0          ;16
JZ 23          ;17
Load Mem[1]    ;18
Store Mem[0]   ;19
Load Mem[3]    ;20
Store Mem[1]   ;21
JMP 13         ;22

;Affichage du PGCD (case mémoire de b)
Load Mem[1]    ;23
Out            ;24
End            ;25
