;DUPONT Corentin
;02/04/2020

In             ;0
Store Mem[0]   ;1
In             ;2
Store Mem[1]   ;3 -> a
Load Mem[0]    ;4
CMP Mem[1]     ;5 -> b
JC 12          ;6
Load Mem[0]    ;7
CMP Mem[1]     ;8
JZ 12          ;9
Load 0         ;10
JMP 13         ;11
Load 1         ;12
Out            ;13
End            ;14
