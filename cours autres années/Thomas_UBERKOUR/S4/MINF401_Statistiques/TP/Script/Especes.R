Especes<-factor(iris$Species)
tab.Especes<-table(Especes)
tab.Especes
hb=(tab.Especes/length(Especes)*100)

hb=paste(levels(iris$Species),hb,sep="")


pie(tab.Especes,main="Repartition des especes",col=c("yellow","green","cyan"))
