;DUPONT Corentin
;29/04/2020
;Il faut spécifier le valeur de la case mémoire 0 en paramétre d'exécution => Correspond au nombre total d'allumettes au départ

;Initialiation du premier joueur à jouer
Load 1         ;0
Store Mem[1]   ;1

;Affiche le joueur
Load Mem[1]    ;2
Out            ;3

;Affiche le nombre restant d'allumettes
Load Mem[0]   ;4
Out           ;5

;Valeur d'allumette à retirer
In            ;6
Store Mem[2]  ;7

;Est-ce que la valeur est invalide ? (0 ou strictement supérieur à 3, ou encore trop grand par rapport au nombre d'allumettes restantes)
CMP 0         ;8
JZ 6          ;9
CMP 3         ;10
JC 6          ;11
CMP Mem[0]    ;12
JC 6          ;13

;Si le choix est valide alors on retire le valeur au nombre d'alumettes restantes
Load Mem[0]   ;14
Sub Mem[2]    ;15
Store Mem[0]  ;16

;Est ce que le joueur actuel a pris les dernières allumettes ?
Load Mem[0]   ;17
CMP 0         ;18
JZ 31        ;19

;Mise à jour du prochain joueur à jouer
Load Mem[1]   ;20

CMP 1         ;21
JZ  25        ;22
CMP 2         ;23
JZ  28        ;24

Add 1         ;25
Store Mem[1]  ;26
JMP 2         ;27
Sub 1         ;28
Store Mem[1]  ;29
JMP 2         ;30


;Affiche le perdant
Load Mem[1]   ;31

CMP 1         ;32
JZ  36        ;33
CMP 2         ;34
JZ  39        ;35

Add 1         ;36
Out           ;37
JMP 42        ;38
Sub 1         ;39
Out           ;40
JMP 42        ;41

End           ;42
