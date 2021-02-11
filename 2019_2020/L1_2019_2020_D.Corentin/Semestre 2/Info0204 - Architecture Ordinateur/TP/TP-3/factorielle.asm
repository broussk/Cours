;DUPONT Corentin
;21/04/2020

Load 1         ;0
Store Mem[2]   ;1
In             ;2
Store Mem[0]   ;3
Store Mem[1]   ;4
CMP Mem[2]     ;5
JZ 15          ;6
Load Mem[0]    ;7
Mul Mem[2]     ;8
Store Mem[0]   ;9
Load Mem[2]    ;10
Add 1          ;11
Store Mem[2]   ;12
Load Mem[1]    ;13
JMP 5          ;14
Load Mem[0]    ;15
Out            ;16
End            ;17
