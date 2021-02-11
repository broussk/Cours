#NA = donnée manquante
#NaN = not a number

sink("C://Users/eowal/Desktop/Cours/L2/Semestre 4/Minf0401 - Statistique/TP/TP1/result.dat")
A <- c(-2,7,0,12,3,6)
print(A)

B = c(-3,6,2,4,-1,5)
print(B)

C = 1:30 #Affiche 1 à 30 par 1
print(C)

D = seq(1,30,by = 1) #Affiche 1 à 30 par 1
print(D)

E = seq(0,30,by = 5) #Affiche 1 à 30 par 5
print(E)

F = rep(3,times = 10)#Affiche 10 fois le chiffre 3
print(F)

fruits = c("orange","banane","poire","pomme")
print(fruits)

AA = A*B      #multiplication de A et B composante par composante
print(AA)

BB = A/B  #division de A et B composante par composante
print(BB)

CC = t(A)%*%B #produit scalaire de A et B
print(CC)

BL = bool = A == 0
print(BL)

S = sum(A)   #fait la somme des valeurs de A
print(S)

P = prod(A)  #fait le produits des valeurs de A
print(P)

is.vector(A)  #vérifie si A est un vecteur

print(A[3])

is.na(A[6])   #vérifie si A[6] est une valeur manquante

labs = paste(c("X", "Y"), 1:10, sep ="")
print(labs)

n = length(A)
print(n)

T = 1:150
dim(T) = c(3,5,10) #transforme T en tableau de dimension 3 avec le nombre de composant 3,5 et 10
print(T)

a = T[3,3,3]
a = T[3,,]
print(a)

X <- array(1:20, dim = c(4,5))
Y <- array (seq(5,100,by=5), dim=c(5,4))
print(X)
print(Y)

sink()
