;DUPONT Corentin
;22/04/2020

In            ;0
Store Mem[0]  ;1 -> n

Load 0        ;2
Store Mem[1]  ;3 -> a

Load Mem[1]   ;4
Mul Mem[1]    ;5 -> a²

CMP Mem[0]    ;6 -> Est-ce qu'on a "a² <= n" ?
Jc 12         ;7 -> Si "!(a²<= n)" on incrément "a" de 1
Load Mem[1]   ;8
Add 1         ;9
Store Mem[1]  ;10
JMP 4         ;11
Load Mem[1]   ;12
Sub 1         ;13
Out           ;14
End           ;15
