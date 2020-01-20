iris=read.table("C:/Users/Thoma/Desktop/Cours-L2/Thomas/S4/MINF401_Statistiques/TP/Script/iris.dat",header=TRUE)
Especes = factor(iris$Species)
tab.Especes = table(Especes)
tab.Especes
pie(tab.Especes,main="Repartition des especes",col=c("yellow","green","cyan"))