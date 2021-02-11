;DUPONT Corentin
;02/04/2020

In
Store Mem[0] ;a
In
Store Mem[1] ;b
In
Store Mem[2] ;c
In
Store Mem[3] ;x
Mul Mem[3]
Store Mem[4] ;x²
Load Mem[0]
Mul Mem[4]
Store Mem[5] ;ax²
Load Mem[1]
Mul Mem[3]
Add Mem[5]
Store Mem[5] ;ax² + bx
Load Mem[2]
Add Mem[5]
Store Mem[5] ;ax² + bx + c
Out
End
