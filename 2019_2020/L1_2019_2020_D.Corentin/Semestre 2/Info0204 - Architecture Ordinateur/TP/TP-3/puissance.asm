;DUPONT Corentin
;21/04/2020

In              ;0
Store Mem[0]    ;1 -> x

In              ;2
Store Mem[1]    ;3 -> n


Load 1          ;4 -> car x^0 toujours égale à 1
Store Mem[2]    ;5


CMP Mem[1]      ;6
JZ 15           ;7
Load Mem[0]     ;8
Mul Mem[0]      ;9
Store Mem[0]    ;10
Load Mem[2]     ;11
Add 1           ;12
Store Mem[2]    ;13
JMP 6           ;14


Load Mem[0]     ;15
Out             ;16
End             ;17
