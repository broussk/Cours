#NA = donnee manquante
#NaN = not a number

sink("C://Users/eowal/Desktop/Cours/L2/Semestre 4/Minf0401 - Statistique/TP/TP1/result.dat")
A <- c(-2,7,0,12,3,6)
print(A)

B = c(-3,6,2,4,-1,5)
print(B)

C = 1:30 #Affiche 1 Ã  30 par 1
print(C)

D = seq(1,30,by = 1) #Affiche 1 Ã  30 par 1
print(D)

E = seq(0,30,by = 5) #Affiche 1 Ã  30 par 5
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

is.vector(A)  #vÃ©rifie si A est un vecteur

print(A[3])

is.na(A[6])   #vÃ©rifie si A[6] est une valeur manquante

labs = paste(c("X", "Y"), 1:10, sep ="")
print(labs)

n = length(A)
print(n)

Z = 1:150
dim(Z) = c(3,5,10) #transforme T en tableau de dimension 3 avec le nombre de composant 3,5 et 10
print(Z)

print("--------------------------------------------------------")

E1 = Z[1,,]
print(E1)
F2 = Z[,2,]
print(F2)
G7 = Z[,,7]
print(G7)
E34 = Z[3,4,]
print(E34)
E238 = Z[2,3,8]
print(E238)

XX <- array(1:30, dim = c(5,6))
print(XX)

YY <- array (c(1:3, 3:1), c(2,3))
print(YY)

ZZ <- array (0, c(4,2))
print(ZZ)

TXX <- aperm(XX, c(2,1))  #transposition de tableau
print(TXX)

print("---------------------Statistique--------------------")

state <- c("tas","sa","qld","nsw","nsw","nt","wa","wa","qld","vic","nsw","vic","qld","qld","sa","tas","sa","nt","wa","vic","qld","nsw","nsw","wa","sa","act","nsw","vic","vic","act")

statef <- factor(state)

incomes <- c(60, 49, 40, 61, 64, 60, 59, 54, 62, 69, 70, 42, 56, 61, 61, 61, 58, 51, 48, 51, 48, 65, 49, 49, 41, 48, 52, 46, 59, 46)

incmeans <- tapply(incomes, statef, mean) #moyenne
print(incmeans)
incsums <- tapply(incomes, statef, sum) #somme
print(incsums)
incvar <- tapply(incomes, statef, var) #variance
print(incvar)
incmax <- tapply(incomes, statef, max) #max
print(incmax)

print("---------------------Matrice--------------------")


m <- seq(1, 50, by=2)
n = length(m)
print(n)

M = array(m, c(5,5))
r = seq(-60,60,by=5)
N1 = length(r)
print(N1)

R = array(r, c(5,5))
print(M)
print(R)

l = row(M)
print(l)
c = ncol(M)
print(c)

MUL = M*R #multiplication par composant
print(MUL)

TMUL = M%*%R #multiplication de la matrice M et R
print(TMUL)

print(t(M)%*%R)
print(crossprod(M,R))


d = det(M)
print(d)

u = runif(25, 1, 49)
print(u)


U = array(u, c(5,5))
print(U)



du = det(U)
print(du)

diag(U)

v = solve(U) #inverse la mtrice U et la stocke dans V
print(U)
print(v)

IRIS <- read.table("C://Users/eowal/Desktop/Cours/L2/Semestre 4/Minf0401 - Statistique/TP/TP1/data1.dat", header=TRUE) #lire un fichier
print(IRIS)

#-------------------------------------------------------------Sépales-------------------------------------------------------------

hist(IRIS $ Sepal.Length, freq=FALSE, main= "Histogramme pour la longeur des sépales", col=rainbow(5), nclass = 18, xlab = "Longeur des sépales", ylab = "Fréquence")
lg = legend("topright", legend=c("n", "=", n),col="blue", horiz=TRUE)
#barplot(IRIS $ Species)

fas = table(IRIS $ Species)
frs = prop.table(fas)
barplot(frs, main="Espèce des iris", col = rainbow(5))
pie(frs, main= "Diagramme circulaire des espèces", col= rainbow(5))


mu= mean(iris $ Sepal.Length)
print(mu)

sigma2= var(iris $ Sepal.Length)
print(sigma2)

Min = min(iris $ Sepal.Length)
print(Min)

Max = max(iris $ Sepal.Length)
print(Max)

x = seq(Min, Max, by=0.1)
print(x)

xx = (x-mu)/sqrt(sigma2)
print(xx)

y = pnorm(xx)
print(y)


#courbe cummulative pour la série longeurs des sépales
plot(ecdf(iris $ Sepal.Length), col="red", main="courbe cumulative des longueurs des sépales", lwd = 1)
lines(x, y, type="l", col="blue")

legend(4, 0.98, legend=c("cumul.Norm", "cumul.SL"), lty = 1:2, cex = 0.8, col=c("blue","red"), box.col="green")


#-------------------------------------------------------------Pétales-------------------------------------------------------------


hist(IRIS $ Petal.Length, freq=FALSE, main= "Histogramme pour la longeur des petales", col=rainbow(5), nclass = 18, xlab = "Longeur des pétales", ylab = "Fréquence")
lg = legend("topright", legend=c("n", "=", n),col="blue", horiz=TRUE)
#barplot(IRIS $ Species)

fas = table(IRIS $ Species)
frs = prop.table(fas)
barplot(frs, main="Espèce des iris", col = rainbow(5))
pie(frs, main= "Diagramme circulaire des espèces", col= rainbow(5))


mu= mean(iris $ Petal.Length)
print(mu)

sigma2= var(iris $ Petal.Length)
print(sigma2)

Min = min(iris $ Petal.Length)
print(Min)

Max = max(iris $ Petal.Length)
print(Max)

x = seq(Min, Max, by=0.1)
print(x)

xx = (x-mu)/sqrt(sigma2)
print(xx)

y = pnorm(xx)
print(y)


#courbe cummulative pour la série longeurs des pétales
plot(ecdf(iris $ Petal.Length), col="red", main="courbe cumulative des longueurs des petales", lwd = 1)
lines(x, y, type="l", col="blue")

legend(1, 0.98, legend=c("cumul.Norm", "cumul.PL"), lty = 1:2, cex = 0.8, col=c("blue","red"), box.col="green")

sink()
