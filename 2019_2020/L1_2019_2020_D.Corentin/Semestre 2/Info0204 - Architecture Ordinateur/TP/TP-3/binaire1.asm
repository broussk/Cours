;DUPONT Corentin
;21/04/2020


In            ;0 -> valeur à convertire
Store Mem[0]  ;1
Load 8        ;2 -> nombre de bit sur 1 octect
Store Mem[1]  ;3

;BOUCLE 1
Load Mem[0]   ;4
CMP 0         ;5
JZ 16         ;6
Mod 2         ;7
Out           ;8
Load Mem[0]   ;9
Div 2         ;10
Store Mem [0] ;11

;Retire 1 bit au nombre de bit total (8)
Load Mem[1]   ;12
Sub 1         ;13
Store Mem[1]  ;14

;Saut retour BOUCLE 1
JMP 4         ;15

;BOUCLE 2
;Charge le nombre de bit restant non utilisé pour les remplacer par des 0 à l'affichage
Load Mem[1]   ;16
CMP 0         ;17
JZ 25         ;18
Load Mem[1]   ;19
Sub 1         ;20
Store Mem[1]  ;21
Load 0        ;22
Out           ;23

;Saut retour BOUCLE 2
JMP 16        ;24

End           ;25
