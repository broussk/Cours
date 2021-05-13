#Permet de crée un tableau de 5 lignes 
matable=matrix(c(9,12,1,3,0,3,16,12,10,0,0,1,30,13,1,0,0,3,24,8,0,0,0,1,3),byrow=TRUE,ncol=5)

colnames(matable)=c("[5,8[","[8,10[","[10,12[","[12,15[","[15,19[")
rownames(matable)=c("[5,8[","[8,10[","[10,12[","[12,15[","[15,19[")
print(matable)

#Calcul les Fréquence relatives effectif/(n total = 150)
frtable=prop.table(matable)
print(frtable)

#On a la distribution de X 
#Solution maginal 
#On somme les effectif de lignes
#on fait une boucle pour calculer la somme de chaque ligne
#Il faut déclarer le vecteur MargeX 5 fois pour 5 lignes
#Puis on calcul mag i, somme / differente colonnes
MargeX=rep(0,times=5)
for(i in 1:5){MargeX[i]=sum(matable[i,])}
print(MargeX)

MargeY=rep(0,times=5)
for(i in 1:5){MargeY[i]=sum(matable[,i])}
print(MargeY)

frMargeX=prop.table(MargeX)
frMargeY=prop.table(MargeY)

print(frMargeX)
print(frMargeY)

X=c(6.5,9,11,13.5,17)
Y=c(6.5,9,11,13.5,17)

Xbar=t(MargeX)%*%X/sum(MargeX)
Ybar=t(MargeY)%*%Y/sum(MargeY)



#
Xbar=t(frMargeX)%*%X
Ybar=t(frMargeY)%*%Y

print(Xbar)
print(Ybar)

VarX=(t(MargeX)%*%(X*X))/sum(MargeX)-Xbar^2
VarY=(t(MargeY)%*%(Y*Y))/sum(MargeY)-Ybar^2
#
VarX=(t(frMargeX)%*%(X*X))-Xbar^2
VarY=(t(frMargeY)%*%(Y*Y))-Ybar^2

print(VarX)
print(VarY)

#
# moyenne conditionnelle de X sachant Y
Xcond=rep(0,times=5)
for(i in 1:5){Xcond[i]=t(X)%*%matable[,i]/MargeY[i]}
print(Xcond)
#
# moyenne conditionnelle de Y sachant X
Ycond=rep(0,times=5)
for(i in 1:5){Ycond[i]=t(Y)%*%matable[i,]/MargeX[i]}
print(Ycond)
#
plot(X,Ycond, type="l",main="Courbes de régression",col="red",lwd=2.5)
lines(Xcond,Y,type="l",col="blue",lwd=2.5)
legend("topleft",legend=c("X en Y", "Y en X"),
col=c("blue","red"), lwd=2.5, cex=0.8)
# table dans le cas où X et Y sont indépendantes
matablet=rep(0,times=25)
dim(matablet)=c(5,5)
for(i in 1:5){
  for(j in 1:5){
    matablet[i,j]=(MargeX[i]*MargeY[j])/sum(MargeX)
}
}
colnames(matablet)=c("[5,8[","[8,10[","[10,12[","[12,15[","[15,19[")
rownames(matablet)=c("[5,8[","[8,10[","[10,12[","[12,15[","[15,19[")
print(matable)
print(matablet)

DN2 = 0
for(i in 1:5){
  for(j in 1:5){
    DN2 = DN2 + ((matable[i,j]- MargeX[i] * MargeY[j] / sum(MargeX))^2)/(MargeX[i] * MargeY[j] / sum(MargeX))
}
}
print(DN2)
