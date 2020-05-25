n=1000
mu=1
sd=1
Alpha = rnorm(n,mu,sd)
Alpha
hist(Alpha,freq=FALSE,col="purple",main="",ylab="GAAAAMMIIIIIIIIIIIIIIIIIIIIIIIIING",xlab="YA QUOI?!")
X=seq(mu-3,mu+3,by=0.1)
Y=dnorm(X,mu,sd)
lines(X,Y,type="l",col="red")
title("J'aimes pas les margoulins de bas étages","shrekt")
text(-2,0.4,"J'aimes les pâtes")
legend(0.3,0.3,"j'aimes le jambon")
