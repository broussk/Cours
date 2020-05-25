I = array(c(0,6.5,9,11,13.5,17,6.5,9,3,0,0,0,9,12,16,1,0,0,11,1,12,30,3,0,13.5,3,10,13,24,1,17,0,0,1,8,3), dim=c(6,6))
X=rep(0,times=5)
Y=rep(0,times=5)
for(i in 1:5){
	X[i]=sum(I[i+1,2:6])
}
for(j in 1:5){
	Y[j]=sum(I[2:6,j+1])
}
I
X
Y
Xbar = rep(0,times=5)
for(k in 1:5){
Xbar[k] = sum((I[2:6,1]*I[2:6,k+1]))/Y[k]
}
Xbar

plot(Xbar,I[2:6,1],main="Courbe de regression",col="blue",xlab="Valeurs",ylab="Milieu de classe")
lines(I[2:6,1]~Xbar,col="red")
