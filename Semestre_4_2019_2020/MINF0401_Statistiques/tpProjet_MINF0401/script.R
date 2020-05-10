#importation des données
Melons <- read.csv2(file="C:/Users/Nathan TONNELLE/Desktop/tpProjet_MINF0401/DonneesMelons.csv", header=TRUE, sep=';', dec=',')

str(Melons)
m=Melons

options( "digits"=7)
##Q1
##qualitative nominale

#effectif
eff_Annee=table(m$Annee)
eff_Annee

#fréquence
fr_Annee=prop.table(eff_Annee) 
fr_Annee

#effectif cumulé croissant
effcumul_Annee= cumsum(eff_Annee)
effcumul_Annee

#fréquence cumulé croissant
frcumul_Annee= cumsum(fr_Annee)
frcumul_Annee

#diagramme circulaire
abbr.noms=c("1996","1997","1998","1999","2000","2001","2002","2003","2004","2005")
abbr.noms 
names(eff_Annee)=abbr.noms
eff_annee
lbls=paste(abbr.noms," : ",paste(round(100*fr_Annee,2),"%"))###fréquence x 100+%
pie(eff_Annee,col=rainbow(8),main="Diagramme de pourcentage d'enregistrement par années",labels=lbls)


#effectif
eff_Variete=table(m$Variete)
eff_Variete

#fréquence
fr_Variete=prop.table(eff_Variete) 
fr_Variete

#effectif cumulé croissant
effcumul_Variete= cumsum(eff_Variete)
effcumul_Variete

#fréquence cumulé croissant
frcumul_Variete= cumsum(fr_Variete)
frcumul_Variete

#diagramme circulaire
abbr.noms=c("Anata","Bastille","Cezanne","Escrito","Fidji","Heliobel","Hugo","Indola","Manta","Mehari","Metis","Theo")
abbr.noms 
names(eff_Variete)=abbr.noms
eff_variete
lbls=paste(abbr.noms," : ",paste(round(100*fr_Variete,2),"%"))###fréquence x 100+%
pie(eff_Variete,col=rainbow(8),main="Diagramme de pourcentage des variétés",labels=lbls)


##qualitative ordinale

#effectif
eff_Creneau=table(m$Creneau)
eff_Creneau

#fréquence
fr_Creneau=prop.table(eff_Creneau) 
fr_Creneau

#effectif cumulé croissant
effcumul_Creneau= cumsum(eff_Creneau)
effcumul_Creneau

#fréquence cumulé croissant
frcumul_Creneau= cumsum(fr_Creneau)
frcumul_Creneau

#diagramme en bâtons
plot(fr_Creneau, main = "Diagramme en bâtons des fréquences de créneaux", xlab = "de précoce à tardif", ylab = "fréquence des plantations")


#effectif
eff_Couverture=table(m$Couverture)
eff_Couverture

#fréquence
fr_Couverture=prop.table(eff_Couverture) 
fr_Couverture

#effectif cumulé croissant
effcumul_Couverture= cumsum(eff_Couverture)
effcumul_Couverture

#fréquence cumulé croissant
frcumul_Couverture= cumsum(fr_Couverture)
frcumul_Couverture

#diagramme en bâtons
abbr.noms=c("total","troué","sans")
abbr.noms 
names(eff_Couverture)=abbr.noms
plot(eff_Couverture, main = "Diagramme en bâtons des effectifs \ndes couvertures des plantations", xlab = "", ylab = "effectif de couverture")



#quantitative discrète

#effetif
eff_Plantation=table(m$Plantation)
eff_Plantation

#fréquence
fr_Plantation=prop.table(eff_Plantation) 
fr_Plantation

#effectif cumulé croissant
effcumul_Plantation = cumsum(eff_Plantation)
effcumul_Plantation

#fréquence cumulé croissant
frcumul_Plantation = cumsum(fr_Plantation)
frcumul_Plantation

#diagramme en barre 
plot(eff_Plantation, col=rainbow(5), main = "Diagramme en bâtons des effectifs \nde la précocité des plantations", xlab = "Nombre de jours après le 1er Janvier", ylab = "nombre d'enregistrements")
plot(effcumul_Plantation, main = "Diagramme des effectifs cumulé \nde la précocité de plantation", xlab = "numéro de la modalité", ylab = "nombre d'enregistrements")

#sommaire
sum_Plantation=summary(m$Plantation)
sum_Plantation

#minimum
min_Plantation=sum_Plantation[1]
min_Plantation

#maximum
max_Plantation=sum_Plantation[6]
max_Plantation

#etendue
abbr.noms=c("Etendue")
abbr.noms 
etendue_Plantation=max_Plantation-min_Plantation
names(etendue_Plantation)=abbr.noms
etendue_Plantation

#médiane
med_Plantation=sum_Plantation[3]
med_Plantation	

#quartiles
quart1_Plantation=sum_Plantation[2]
quart1_Plantation
quart3_Plantation=sum_Plantation[5]
quart3_Plantation

#moyenne
moy_Plantation=sum_Plantation[4]
moy_Plantation

#variance
var_Plantation=var(m$Plantation)
var_Plantation
##var2_Plantation=mean(m$Plantation^2)-mean(m$Plantation)^2
##var2_Plantation

#écart-type	
##et2_Plantation=sqrt(mean(m$Plantation^2)-mean(m$Plantation)^2)
##et2_Plantation
et_Plantation=sd(m$Plantation)
et_Plantation


#effetif
eff_Duree=table(m$Duree)
eff_Duree

#fréquence
fr_Duree=prop.table(eff_Duree) 
fr_Duree

#effectif cumulé croissant
effcumul_Duree= cumsum(eff_Duree)
effcumul_Duree

#fréquence cumulé croissant
frcumul_Duree= cumsum(fr_Duree)
frcumul_Duree

#diagramme en barre 
plot(eff_Duree, col=rainbow(5), main = "Diagramme en bâtons \nde la Duree des plantations", xlab = "Durée de la plantation (en jours)", ylab = "nombre d'enregistrements")
plot(effcumul_Duree, main = "Diagramme des effectifs cumulés \nsur la Duree des plantations", xlab = "numéro de la modalité", ylab = "nombre d'enregistrements")

#sommaire
sum_Duree=summary(m$Duree)
sum_Duree

#minimum
min_Duree=sum_Duree[1]
min_Duree

#maximum
max_Duree=sum_Duree[6]
max_Duree

#etendue
abbr.noms=c("Etendue")
abbr.noms 
etendue_Duree=max_Duree-min_Duree
names(etendue_Duree)=abbr.noms
etendue_Duree

#médiane
med_Duree=sum_Duree[3]
med_Duree	

#quartiles
quart1_Duree=sum_Duree[2]
quart1_Duree
quart3_Duree=sum_Duree[5]
quart3_Duree

#moyenne
moy_Duree=sum_Duree[4]
moy_Duree

#variance
var_Duree=var(m$Duree,na.rm=TRUE)
var_Duree

#écart-type	
et_Duree=sd(m$Duree,na.rm=TRUE)
et_Duree


#effetif
eff_Rdt=table(m$Rdt)
eff_Rdt

#fréquence
fr_Rdt=prop.table(eff_Rdt) 
fr_Rdt

#effectif cumulé croissant
effcumul_Rdt= cumsum(eff_Rdt)
effcumul_Rdt

#fréquence cumulé croissant
frcumul_Rdt= cumsum(fr_Rdt)
frcumul_Rdt

#diagramme en barre 
plot(eff_Rdt, col=rainbow(10), main = "Diagramme en bâtons \nde du Randement des plantations", xlab = "Randement de la plantation (en Tonnes/Hect)", ylab = "nombre d'enregistrements")
plot(effcumul_Rdt, col=rainbow(10), main = "Diagramme des effectifs cumulés \nsur le Randement des plantations", xlab = "numéro de la modalité", ylab = "nombre d'enregistrements")

#sommaire
sum_Rdt=summary(m$Rdt)
sum_Rdt

#minimum
min_Rdt=sum_Rdt[1]
min_Rdt

#maximum
max_Rdt=sum_Rdt[6]
max_Rdt

#etendue
abbr.noms=c("Etendue")
abbr.noms 
etendue_Rdt=max_Rdt-min_Rdt
names(etendue_Rdt)=abbr.noms
etendue_Rdt

#médiane
med_Rdt=sum_Rdt[3]
med_Rdt	

#quartiles
quart1_Rdt=sum_Rdt[2]
quart1_Rdt
quart3_Rdt=sum_Rdt[5]
quart3_Rdt

#moyenne
moy_Rdt=sum_Rdt[4]
moy_Rdt

#variance
var_Rdt=var(m$Rdt,na.rm=TRUE)
var_Rdt

#écart-type	
et_Rdt=sd(m$Rdt,na.rm=TRUE)
et_Rdt


#effetif
eff_Poids=table(m$Poids)
eff_Poids

#fréquence
fr_Poids=prop.table(eff_Poids) 
fr_Poids

#effectif cumulé croissant
effcumul_Poids= cumsum(eff_Poids)
effcumul_Poids

#fréquence cumulé croissant
frcumul_Poids= cumsum(fr_Poids)
frcumul_Poids

#diagramme en barre 
plot(eff_Poids, col=rainbow(10), main = "Diagramme en bâtons \nde du Poids des melons des plantations", xlab = "Poids moyen de melons de la plantation (en g)", ylab = "nombre d'enregistrements")
plot(effcumul_Poids, col=rainbow(10), main = "Diagramme des effectifs cumulés \nsur le Poids moyen des melons des plantations", xlab = "numéro de la modalité", ylab = "nombre d'enregistrements")

#sommaire
sum_Poids=summary(m$Poids)
sum_Poids

#minimum
min_Poids=sum_Poids[1]
min_Poids

#maximum
max_Poids=sum_Poids[6]
max_Poids

#etendue
abbr.noms=c("Etendue")
abbr.noms 
etendue_Poids=max_Poids-min_Poids
names(etendue_Poids)=abbr.noms
etendue_Poids

#médiane
med_Poids=sum_Poids[3]
med_Poids	

#quartiles
quart1_Poids=sum_Poids[2]
quart1_Poids
quart3_Poids=sum_Poids[5]
quart3_Poids

#moyenne
moy_Poids=sum_Poids[4]
moy_Poids

#variance
var_Poids=var(m$Poids,na.rm=TRUE)
var_Poids

#écart-type	
et_Poids=sd(m$Poids,na.rm=TRUE)
et_Poids





#quantitative continue

#effetif
eff_N=table(m$N)
eff_N

#fréquence
fr_N=prop.table(eff_N) 
fr_N

#histogramme
hist(m$N,col=rainbow(5),nclass=100, main="Histogramme du traitement \ndes plantations avec N", xlab="modalités", ylab="effectifs",xlim=c(0,500), ylim=c(0,30), freq=TRUE)

#diagramme boite à moustaches
boxplot(m$N, col="red", main = "Plantations traité avec N", ylab = "quantitée des apports de N aux plantations")
rug(m$N, side = 2)

#sommaire
sum_N=summary(m$N)
sum_N

#variance
var_N=var(m$N,na.rm=TRUE)
var_N

#écart-type	
et_N=sd(m$N,na.rm=TRUE)
et_N


#effetif
eff_P=table(m$P)
eff_P

#fréquence
fr_P=prop.table(eff_P) 
fr_P

#histogramme
hist(m$P,col=rainbow(5),nclass=100, main="Histogramme du traitement \ndes plantations avec P", xlab="modalités", ylab="effectifs",xlim=c(50,250), ylim=c(0,30), freq=TRUE)

#diagramme boite à moustaches
boxplot(m$P, col="red", main = "Plantations traité avec P", ylab = "quantitée des apports de P aux plantations")
rug(m$P, side = 2)

#sommaire
sum_P=summary(m$P)
sum_P

#variance
var_P=var(m$P,na.rm=TRUE)
var_P

#écart-type	
et_P=sd(m$P,na.rm=TRUE)
et_P


#effetif
eff_K=table(m$K)
eff_K

#fréquence
fr_K=prop.table(eff_K) 
fr_K

#histogramme
hist(m$K,col=rainbow(5),nclass=100, main="Histogramme du traitement \ndes plantations avec K", xlab="modalités", ylab="effectifs",xlim=c(50,250), ylim=c(0,30), freq=TRUE)

#diagramme boite à moustaches
boxplot(m$K, col="red", main = "Plantations traité avec K", ylab = "quantitée des apports de K aux plantations")
rug(m$K, side = 2)

#sommaire
sum_K=summary(m$K)
sum_K

#variance
var_K=var(m$K,na.rm=TRUE)
var_K

#écart-type	
et_K=sd(m$K,na.rm=TRUE)
et_K




##Q2
#position
summary(m$Annee)

#dispersion

#forme
##chargement des fonctions pour l'asymétrie et l'aplatissement de Fisher
library(e1071) 

##asymétrie sans NA
asym_Annee= skewness(m$Annee)
asym_Annee

##asymétrie avec NA
asym_Duree= skewness(m$Duree,na.rm=TRUE)
asym_Duree

##aplatissement sans NA
aplat_Annee= kurtosis(m$Annee)
aplat_Annee

##aplatissemnet avec NA
aplat_Duree= kurtosis(m$Duree,na.rm=TRUE)
aplat_Duree





#Q3
#Diagramme pour quantitative discrète
##diagramme en baton
plot(eff_Poids, col=rainbow(15), main = "Diagramme en bâtons \ndu Poids moyen des melons", xlab = "Poids moyen (en g)", ylab = "effectif")

##courbe escalier
effectifs.cumules <- function (x) {
  x.name <- deparse(substitute(x))
  n <- length(x)
  plot( 1:n ~ sort(x,na.last=TRUE),type='s', main="Courbe cumulative des \n effectifs du Poids moyens des melons", xlab="Poids moyen (en g)", ylab='effectifs cumulés')
}    
effectifs.cumules(m$Poids)


#Diagramme pour quantitative continue
##histogramme
hist(m$K,col=rainbow(10),nclass=100, main="Histogramme du traitement \ndes plantations avec K", xlab="modalités", ylab="effectifs",xlim=c(50,250), ylim=c(0,30), freq=TRUE)

##courbe cumulative
effectifs.cumules <- function (x) {
  x.name <- deparse(substitute(x))
  n <- length(x)
  plot( 1:n ~ sort(x,na.last=TRUE),type='l', main="Courbe cumulative des effectifs\n du traitement des plantations avec K", xlab="modalités", ylab='effectifs cumulés')
}    
effectifs.cumules(m$K)


#Lois
nbDonnee = 135
##loi normale
rand_norm=as.integer(abs(rnorm(nbDonnee )*100))
rand_norm
sum_norm=summary(rand_norm)
sum_norm

plot(table(rand_norm), col=rainbow(15), main = "Diagramme en bâtons \nde la loi normale \nPour Poids", xlab = "modalités", ylab = "effectif")

hist(rand_norm,col=rainbow(10),nclass=100, main="Histogramme de la loi normale\nPour K", xlab="modalités", ylab="effectifs",xlim=c(0,300), ylim=c(0,10), freq=TRUE)


##loi exponentielle
rand_exp=as.integer(rexp(nbDonnee ,.1)*10)
rand_exp
sum_exp=summary(rand_exp)
sum_exp

plot(table(rand_exp), col=rainbow(15), main = "Diagramme en bâtons \nde la loi exponentielle\nPour Poids", xlab = "modalités", ylab = "effectif")

hist(rand_exp,col=rainbow(10),nclass=100, main="Histogramme de la loi exponentielle\nPour K", xlab="modalités", ylab="effectifs",xlim=c(0,550), ylim=c(0,15), freq=TRUE)
	

##loi uniforme
rand_unif=as.integer(runif(nbDonnee))
rand_unif
sum_unif=summary(rand_unif)
sum_unif

plot(table(rand_unif), col=rainbow(15), main = "Diagramme en bâtons \nde la loi uniforme\nPour Poids", xlab = "modalités", ylab = "effectif")

hist(rand_unif,col=rainbow(10),nclass=100, main="Histogramme de la loi uniforme\nPour N", xlab="modalités", ylab="effectifs",xlim=c(0,110), ylim=c(0,20), freq=TRUE)



#Q4
##les diagrammes à boite
boxplot(m$Plantation,horizontal=TRUE,col="green",main="Répartition de la précocité de la plantation",ylim=c(50,200), xlab="jours")
summary(m$Plantation)
boxplot(m$Duree,horizontal=TRUE,col="green",main="Répartition de la durée de plantation",ylim=c(50,100), xlab="jours")
summary(m$Duree)
boxplot(m$N,horizontal=TRUE,col="green",main="Répartition des apports en N de la plantation",ylim=c(0,500), xlab="N")
summary(m$N)
boxplot(m$P,horizontal=TRUE,col="green",main="Répartition des apports en P de la plantation",ylim=c(50,250), xlab="P")
summary(m$P)
boxplot(m$K,horizontal=TRUE,col="green",main="Répartition des apports en K de la plantation",ylim=c(50,250), xlab="K")
summary(m$K)
boxplot(m$Rdt,horizontal=TRUE,col="green",main="Répartition du Rendement de  la plantation",ylim=c(0,450), xlab="Tonnes/Hectares")
summary(m$Rdt)
boxplot(m$Poids,horizontal=TRUE,col="green",main="Répartition du Poids moyen des melon de la plantation",ylim=c(600,1400), xlab="grammes")
summary(m$Poids)


options( "digits"=3)
##partie 2
#Q0
##tableau à doubles entrées

table2D_Variete_Annee = table(m$Variete,m$Annee)
table2D_Variete_Annee_2= cbind(addmargins(prop.table(table2D_Variete_Annee)*100),
c(margin.table(table2D_Variete_Annee,1),sum(table2D_Variete_Annee)))
table2D_Variete_Annee_2

#Q1
##distribution marginale
dist_margin_table2D_var1 = table2D_Variete_Annee_2[,ncol(table2D_Variete_Annee_2)]
dist_margin_table2D_var1

dist_margin_table2D_var2 = table2D_Variete_Annee_2[nrow(table2D_Variete_Annee_2),]
dist_margin_table2D_var2

##parmètres
summ_margin_table2D=summary(table2D_Variete_Annee_2)
summ_margin_table2D

##variance
###intra

abbr.noms=c("Somme_n")
abbr.noms 
som_n=table(m$Annee)[1]+table(m$Annee)[2]+table(m$Annee)[3]+table(m$Annee)[4]
+table(m$Annee)[5]+table(m$Annee)[6]+table(m$Annee)[7]+table(m$Annee)[8]
+table(m$Annee)[9]+table(m$Annee)[10]
names(som_n)=abbr.noms
som_n

abbr.noms=c("Somme_nVar")
abbr.noms 
som_nVar=table(m$Annee)[1]*var(table2D_Variete_Annee[,1],na.rm=TRUE)
+table(m$Annee)[2]*var(table2D_Variete_Annee[,2],na.rm=TRUE)
+table(m$Annee)[3]*var(table2D_Variete_Annee[,3],na.rm=TRUE)
+table(m$Annee)[4]*var(table2D_Variete_Annee[,4],na.rm=TRUE)
+table(m$Annee)[5]*var(table2D_Variete_Annee[,5],na.rm=TRUE)
+table(m$Annee)[6]*var(table2D_Variete_Annee[,6],na.rm=TRUE)
+table(m$Annee)[7]*var(table2D_Variete_Annee[,7],na.rm=TRUE)
+table(m$Annee)[8]*var(table2D_Variete_Annee[,8],na.rm=TRUE)
+table(m$Annee)[9]*var(table2D_Variete_Annee[,9],na.rm=TRUE)
+table(m$Annee)[10]*var(table2D_Variete_Annee[,10],na.rm=TRUE)
names(som_nVar)=abbr.noms
som_nVar

abbr.noms=c("Moyenne des variances")
abbr.noms 
moyenne_vars=som_nVar/som_n
names(moyenne_vars)=abbr.noms
moyenne_vars

###inter
table2D=addmargins(table2D_Variete_Annee)

x1=(3*table2D[3,1]+9*table2D[9,1])/table2D[13,1]

x2=(3*table2D[3,2]+9*table2D[9,2])/table2D[13,2]

x3=(3*table2D[3,3]+4*table2D[4,3]+9*table2D[9,3])/table2D[13,3]

x4=(3*table2D[3,4]+4*table2D[4,4]+9*table2D[9,4])/table2D[13,4]

x5=(3*table2D[3,5]+4*table2D[4,5]+5*table2D[5,5]+9*table2D[9,5]+10*table2D[10,5])/table2D[13,5]

x6=(1*table2D[1,6]+3*table2D[3,6]+5*table2D[5,6]+8*table2D[8,6]+9*table2D[9,6]+10*table2D[10,6])/table2D[13,6]

x7=(1*table2D[1,7]+2*table2D[2,7]+3*table2D[3,7]+4*table2D[4,7]+5*table2D[5,7]+6*table2D[6,7]+7*table2D[7,7]+8*table2D[8,7]+9*table2D[9,7]+10*table2D[10,7]+11*table2D[11,7]+12*table2D[12,7])/table2D[13,7]

x8=(1*table2D[1,8]+2*table2D[2,8]+3*table2D[3,8]+4*table2D[4,8]+7*table2D[7,8]+8*table2D[8,8]+9*table2D[9,8]+10*table2D[10,8]+11*table2D[11,8]+12*table2D[12,8])/table2D[13,8]

x9=(1*table2D[1,9]+2*table2D[2,9]+3*table2D[3,9]+4*table2D[4,9]+5*table2D[5,9]+7*table2D[7,9]+8*table2D[8,9]+9*table2D[9,9]+10*table2D[10,9]+11*table2D[11,9]+12*table2D[12,9])/table2D[13,9]

x10=(1*table2D[1,10]+2*table2D[2,10]+3*table2D[3,10]+4*table2D[4,10]+5*table2D[5,10]+7*table2D[7,10]+8*table2D[8,10]+9*table2D[9,10]+11*table2D[11,10]+12*table2D[12,10])/table2D[13,10]

x=(5*x1+3*x2+11*x3+10*x4+9*x5+6*x6+25*x7+20*x8+36*x9+20*x10)/135

numerateur_inter=table2D[13,1]*((x1-x)*(x1-x))+table2D[13,2]*((x2-x)*(x2-x))+table2D[13,3]*((x3-x)*(x3-x))+table2D[13,4]*((x4-x)*(x4-x))+table2D[13,5]*((x5-x)*(x5-x))+table2D[13,6]*((x6-x)*(x6-x))+table2D[13,7]*((x7-x)*(x7-x))+table2D[13,8]*((x8-x)*(x8-x))+table2D[13,9]*((x9-x)*(x9-x))+table2D[13,10]*((x10-x)*(x10-x))
numerateur_inter
denominateur_inter=135
denominateur_inter
result_inter=numerateur_inter/denominateur_inter
result_inter



#Q2
##construction d'un tableau d'indépendance des variables
table2D_Variete_Annee = table(m$Variete,m$Annee)
table2D_Variete_Annee_2= cbind(addmargins(prop.table(table2D_Variete_Annee)*100),
c(margin.table(table2D_Variete_Annee,1),sum(table2D_Variete_Annee)))
table2D_Variete_Annee_2
tableauKhi=table2D_Variete_Annee_2
tableauKhi

Khi2=chisq.test(tableauKhi)
Khi2$observed 
Khi2$expected 
Khi2$residuals 
Khi2$residuals^2


#Q3
##droite de régression

plot(m$Variete,m$Annee,xlim=c(0,500),ylim=c(0,200)) 
abline(lm(m$Annee~m$Variete)$coefficients, col="red",lwd=2)

plot(m$Variete~m$Annee)

plot(m$Duree,m$Rdt,xlim=c(0,500),ylim=c(0,500)) 
abline(lm(m$Rdt~m$Duree)$coefficients, col="red",lwd=2)	




options( "digits"=7)
#partie 3
#Q1
##fonctions par la méthode de Monte Carlo
f1 = function(x){1/(1+x^2)}
integrate(f1,lower=-1,upper=1)$value
curve(f1,from=-1,to=1)

f2 = function(x){sin(x^2)}
integrate(f2,lower=0,upper=Inf)$value
curve(f2,from=0,to=1000)

##affichage graph et aire hachures
###f1
x <- seq(from = -1, to = 1, length = 1000)
y <- f1(x)
par(cex = 1)
plot(x, y, type = "l", las = 1, ylab = "f1(x)", xlab = "x",
main = "y = 1/(1+x^2)", xaxt = "n")
abline( h = 0.5, col = grey(0.5))
axis(side = 1, at = c(-1,-0.5,0,0.5,1), label = expression(-1, -0.5, 0, 0.5, 1))
polycurve <- function(x, y, base.y = min(y), ...) {
	polygon(x = c(min(x), x, max(x)), y = c(base.y, y, base.y),...)
}
polycurve(x, y, density=c(10),angle=c(45))

###f2
x <- seq(from = 0, to = 10, length = 100)
y <- f2(x)
par(cex = 1)
plot(x, y, type = "l", las = 1, ylab = "f2(x)", xlab = "x",
main = "y = sin(x^2)", xaxt = "n")
abline( h = 0, col = grey(0.5))
axis(side = 1, at = c(0:10), label = expression(0,1,2,3,4,5,6,7,8,9,10))
polycurve <- function(x, y, base.y = min(y), ...) {
	polygon(x = c(min(x), x, max(x)), y = c(base.y, y, base.y),...)
}
polycurve(x, y, density=c(10),angle=c(45))


#comparaison val théorique
val_f1=integrate(f1,lower=-1,upper=1)$value
val_f1
valTheo_f1=pi/2
valTheo_f1

val_f2=integrate(f2,lower=0,upper=Inf)$value
val_f2
valTheo_f2=(sqrt(2*pi))/4
valTheo_f2
