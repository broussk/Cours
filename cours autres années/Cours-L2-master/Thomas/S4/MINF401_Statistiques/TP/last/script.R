F = read.table("C:/Users/Thoma/Desktop/Cours-L2/Thomas/S4/MINF401_Statistiques/TP/last/fichier.dat",header=FALSE)
F
X=rep(0,times=5)
Y=rep(0,times=5)
for(i in 1:5){
	X[i]=sum(F[i+1,2:6]);
	Y[i]=sum(F[2:6,i+1]);
}
X
Y
Xbar=rep(0,times=5)
Ybar=rep(0,times=5)
for(i in 1:5){
	Xbar[i] = sum(as.numeric(F[2:6,1])%*%as.numeric(F[2:6,i+1]))/Y[i];
	Ybar[i] = sum(as.numeric(F[1,2:6])%*%as.numeric(F[i+1,2:6]))/X[i]
}
ox = as.numeric(F[2:6,1])
oy = as.numeric(F[1,2:6])
plot(ox,Ybar,type="o",pch=16,col="red",xlab="Colonnes",ylab="Lignes",main="Courbe de régression")
lines(Xbar,oy,type="o",pch=16,col="blue")

legend( x="topleft", 
        legend=c("Courbe de X en Y","Courbe de Y en X"),
        col=c("blue","red"), lwd=1, lty=c(1,1),pch=c(16,16),bg="gray")