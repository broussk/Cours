;DUPONT Corentin
;02/04/2020
;Il faut spécifier les valeurs des cases mémoires 1 et 2 en paramétre d'exécution

In              ;0
MOD 2           ;1
JZ 18           ;2

;C'est impair
;Je m'occupe de la casse mémoire 1

Load Mem[1]     ;3
Add Mem[2]      ;4
Store Mem[3]    ;5

;Je m'occupe de la casse mémoire 2

Load Mem[1]     ;6
Mul Mem[1]      ;7
Store Mem[4]    ;8  -> le carré de la valeur de la case mémoire 1
Load Mem[2]     ;9
Mul Mem[2]      ;10
Store Mem[5]    ;11 -> le carré de la valeur de la case mémoire 2
Load Mem[4]     ;12
Sub Mem[5]      ;13

;Je réaffecte les valueur des cases mémoires temporaire aux cases 1 et 2

Store Mem[2]    ;14
Load Mem[3]     ;15
Store Mem[1]    ;16

JMP 28          ;17

;C'est pair
;Je m'occupe de la casse mémoire 1

Load Mem[1]     ;18
Add Mem[2]      ;19
Store Mem[3]    ;20

;Je m'occupe de la casse mémoire 2

Load Mem[1]     ;21
Mul Mem[2]      ;22
Store Mem[4]    ;23

;Je réaffecte les valueur des cases mémoires temporaire aux cases 1 et 2

Load Mem[3]     ;24
Store Mem[1]    ;25
Load Mem[4]     ;26
Store Mem[2]    ;27

;J'affiche les cases mémoires 1 et 2

Load Mem[1]     ;28
Out             ;29
Load Mem[2]     ;30
Out             ;31
End             ;32
