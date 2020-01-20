iris=read.table("C:/Users/Thoma/Desktop/Cours-L2/Thomas/S4/MINF401_Statistiques/TP/Script/iris.dat",header=TRUE)
mean(iris$Sepal.Length)
par(mfrow=c(2,2))
n=(max(iris$Sepal.Length)-min(iris$Sepal.Length))/0.2
p=(max(iris$Petal.Length)-min(iris$Petal.Length))/0.2
m=(max(iris$Sepal.Width)-min(iris$Sepal.Width))/0.2
q=(max(iris$Petal.Width)-min(iris$Petal.Width))/0.2
hist(iris$Sepal.Length,freq=FALSE,col=rainbow(20),breaks=n,main="Histogramme longueur S�pales")
hist(iris$Sepal.Width,freq=FALSE,col="yellow",breaks=m,main="Histogramme largeur S�pales")
hist(iris$Petal.Width,freq=FALSE,col="yellow",breaks=q,main="Histogramme largeur p�tales")
hist(iris$Petal.Length,freq=FALSE,col=rainbow(20),breaks=p,main="Histogramme longueur p�tales")
cov(iris$Sepal.Length,iris$Sepal.Width)
cov(iris$Petal.Length,iris$Petal.Width)
cor(iris$Sepal.Length,iris$Sepal.Width)
cor(iris$Petal.Length,iris$Petal.Width)
Especes = factor(iris$Species)
tab.Especes = table(Especes)
tab.Especes
pie(tab.Especes,main="Repartition des especes",col=c("yellow","green","cyan"))
