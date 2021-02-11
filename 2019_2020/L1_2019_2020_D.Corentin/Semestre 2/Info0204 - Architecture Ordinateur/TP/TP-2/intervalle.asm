;DUPONT Corentin
;07/04/2020

In                 ;0
Store Mem [1]      ;1
In                 ;2
Store Mem [2]      ;3
Load Mem [2]       ;4
SUB Mem [1]        ;5
JC 20              ;6
In                 ;7
Store Mem [0]      ;8
CMP Mem [2]        ;9
JC 17              ;10
Load Mem [1]       ;11
CMP Mem [0]        ;12
JC 17              ;13
Load 1             ;14
Out                ;14
JMP 19             ;15
Load 0             ;16
Out                ;17
JMP 28             ;18
Load Mem [1]       ;19
Store Mem [3]      ;20
Load Mem [2]       ;21
Store Mem [1]      ;22
Load Mem [3]       ;23
Store Mem [2]      ;24
JMP 7              ;25
Load 0             ;26
End                ;27
