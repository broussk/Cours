;DUPONT Corentin
;02/04/2020

In             ;0
Store Mem[0]   ;1
In             ;2
Store Mem[1]   ;3 -> a
Load Mem[0]    ;4
CMP Mem[1]     ;5 -> b
JC 9           ;6
Load 0         ;7
JMP 10         ;8
Load 1         ;9
Out            ;10
End            ;11
