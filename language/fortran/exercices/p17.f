C Le programme 6.17 de pag 135
	program pr6_17
	real a,b,largeur,hauteur,area,x
	integer n,i
	print *,'Enter limits if integral and number of intervals'
	read *,a,b,n
	area=0.0
	largeur=(b-a)/n
	x=a
	do 100 i=0,n-1
		hauteur=x*x
		area=area+hauteur*largeur
		x=x+largeur
100	continue
	print *,'Limits of integration were',a,b
	print *,'Number of intervals was',n
	print *,'Approximate area is',area
	stop
	end