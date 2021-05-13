#Histogrammes pour les dnnées iris
SL=iris$Sepal.Length
SW=iris$Sepal.Width
PL=iris$Petal.Length
PW=iris$Petal.Width
SP=iris$Species
par(mfrow=c(1,2))
m=15
m1=15
My=round(mean(SL),3)
Va=round(var(SL),3)
Mn=min(SL)
Mx=max(SL)
hist(SL,freq=FALSE,main="Histogramme pour SL",col=rainbow(5),xlab="Longueur",ylab="Densité",xlim=c(Mn-1,Mx+1), nclass=m)
legend("topright",legend=paste(c("Moy=","Var=","m="),c(My,Va,m),sep=""),box.col="green")
x=seq(Mn-1,Mx+1,0.1)
y=dnorm(x,My,sqrt(Va))
lines(x,y,type="l",col="red")m=15
My1=round(mean(SW),3)
Va1=round(var(SW),3)
Mn1=min(SW)
Mx1=max(SW)
hist(SW,freq=FALSE,main="Histogramme pour SW",col=rainbow(5),xlab="Largeur",ylab="Densité",xlim=c(Mn1-1,Mx1+1), nclass=m1)
legend("topright",legend=paste(c("Moy=","Var=","m="),c(My1,Va1,m1),sep=""),box.col="green")
x1=seq(Mn1-1,Mx1+1,0.1)
y1=dnorm(x1,My1,sqrt(Va1))
lines(x1,y1,type="l",col="red")
