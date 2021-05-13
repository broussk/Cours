#Diagramme circulaire pour les données de l'exo1 de la série de TD
N=c(348,163,71,54,161,41)
names(N)=c("TVA","ISR","ISS","TPP","AI","RNF")
print(N)
frN=prop.table(N)
frN=round(frN,4)
print(frN)
par(mfrow=c(1,2))
lbs=paste(names(frN),paste(round(100*frN,2),"%",sep=""),sep="\n")
pie(frN,col=c("blue","red","yellow","cyan","green","magenta"),main="Budget de l'état",labels=lbs)
#Diagramme en tuyaux d'orgue
lbs1=paste(names(frN),paste(round(100*frN,2),"%",sep=""),sep=" : ")
barplot(frN,col=c("blue","red","yellow","cyan","green","magenta"),main="Budget de l'état",ylab="Propostion du budget",legend.text=lbs1,ylim=c(0,0.5))
