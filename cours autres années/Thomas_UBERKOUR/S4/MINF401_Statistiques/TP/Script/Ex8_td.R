#t<-array(c(0,6.5,9,11,13.5,17,6.5,9,3,0,0,0,9,12,16,1,0,0,11,1,12,30,3,0,13.5,3,10,13,24,1,17,0,0,1,8,3),dim=c(6,6))

#X=rep(0,times=5)
#Y=rep(0,times=5)
#X2=0
#Y2=0

#for(i in 1:5){
#  X[i]=sum(t[i+1,2:6])
#}
#for(j in 1:5){
#  Y[j]=sum(t[2:6,j+1])
#}

#t
#X
#Y

#Xbar=rep(0,times=5)
#for(k in 1:5){
#  Xbar[k]=(sum(t[1,2:6]%*%t[2:6,k+1]))/Y[k]
#}
#Ybar=rep(0,times=5)
#for(k in 1:5){
#  Ybar[k]=(sum(t[2:6,1]%*%t[k+1,2:6]))/X[k]
#}

#Ox=t[2:6,1]
#Oy=t[1,2:6]
#plot(Ox,Ybar,type="l",col="red")
#lines(Ybar,Oy,type="l",col="blue")

#Xbar

#plot(Xbar,t[1,2:6],main="Courbe de regression",ylab="Milieu Classes")
#lines(t[1,2:6]~Xbar,col="yellow",lwd=1)

#--Avec un fichier--#

yes <- read.table(file = "D:/cours/Cours-L2/Thomas/S4/MINF401_Statistiques/TP/Script/deug.dat",header=FALSE)
X2=rep(0,times=5)
Y2=rep(0,times=5)
for(i in 1:5){
  X2[i]=sum(yes[i+1,2:6])
}
for(j in 1:5){
  Y2[j]=sum(yes[2:6,j+1])
}
Xbar2=rep(0,times=5)
Ybar2=rep(0,times=5)
for(i in 1:5){
 Xbar2[i]=sum(as.numeric(yes[2:6,1])%*%as.numeric(yes[2:6,i+1]))/Y2[i]  
}
for(i in 1:5){ Ybar2[i]=sum(as.numeric(yes[1,2:6])%*%as.numeric(yes[i+1,2:6]))/X2[i]  
}
Ox=as.numeric(yes[2:6,1])
Oy=as.numeric(yes[1,2:6])
plot(Ox,Ybar2,type="l",col="red",main="Courbes de regression",ylab="Y",xlab = "X")
lines(Ybar2,Oy,type="l",col="blue")

legend("topleft", legend=c("Courbe de X en Y", "Courbe de Y en X"),col=c("red", "blue"), density=55, inset=1/100,
       lty=1:1 , cex=1.25 , box.lty=1 , box.lwd = 2 , text.font=4 , text.col = rainbow(10) , bg="grey",box.col="black",angle=300)



