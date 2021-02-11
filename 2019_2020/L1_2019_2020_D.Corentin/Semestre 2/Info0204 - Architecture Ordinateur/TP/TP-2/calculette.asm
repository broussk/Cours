;DUPONT Corentin
;07/04/2020

In            ;0
Store Mem[0]  ;1 -> a
In            ;2 -> b
Store Mem[1]  ;3
In            ;4 -> c
Store Mem[2]  ;5


;Je regarde quel opération à faire
CMP 0         ;6
JZ 45         ;7
CMP 1         ;8
JZ 20         ;9
CMP 2         ;10
JZ  23        ;11
CMP 3         ;12
JZ  26        ;13
CMP 4         ;14
JZ  29        ;15
CMP 5         ;16
JZ  35        ;17

;Si la valeur de "c" est au dessus de 5
CMP 0         ;18
;Retour à la demande de l'opération (c)
JC 4          ;19

;a+b
Load Mem[0]   ;20
Add Mem[1]    ;21
JMP 43        ;22

;a-b
Load Mem[0]   ;23
SUB Mem[1]    ;24
JMP 43        ;25

;a*b
Load Mem[0]   ;26
Mul Mem[1]    ;27
JMP 43        ;28

;a/b
Load Mem[1]   ;29
CMP 0         ;30
JZ 41         ;31
Load Mem[0]   ;32
DIV Mem[1]    ;33
JMP 43        ;34

;a%b
Load Mem[1]   ;35
CMP 0         ;36
JZ 41         ;37
Load Mem[0]   ;38
Mod Mem[1]    ;39
JMP 43        ;40

Load 0        ;41
JMP 43        ;42

Out           ;43

;Retour à la demande de l'opération (c)
JMP 4         ;44
End           ;45
