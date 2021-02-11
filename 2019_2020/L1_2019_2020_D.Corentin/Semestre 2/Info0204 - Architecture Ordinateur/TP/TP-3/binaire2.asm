;DUPONT Corentin
;29/04/2020

In              ;0
Store Mem[0]    ;1
Load 128        ;2
Store Mem[1]    ;3
Load Mem[0]     ;4
Div Mem[1]      ;5
Out             ;6
Load Mem[0]     ;7
MOD Mem[1]      ;8
Store Mem[0]    ;9
Load Mem[1]     ;10
Div 2           ;11
Store Mem[1]    ;12
CMP 0           ;13
JZ 16           ;14
JMP 4           ;15
END             ;16
