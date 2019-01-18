C Le programme qui resoudre la probleme 6 de pag 164
	program pr6_17
	real a,b,largeur,hauteur,area,x
	integer n,i
	print *,'Introdui le interval de integration'
	print *,'et le numero des intervals'
	read *,a,b,n
	area=0.0
	largeur=(b-a)/n
	x=a
	do 100 i=0,n-1
		hauteur=x*x+3
		area=area+hauteur*largeur
		x=x+largeur
100	continue
	print *,'Les limites des integral pour x*x+3',a,b
	print *,'Les numero des intervals',n
	print *,'La approximation de area est',area
	largeur=(b-a)/n
	x=a
	do 101 i=0,n-1
		hauteur=sin(x)
		area=area+hauteur*largeur
		x=x+largeur
101	continue
	print *,'Les limites des integral pour sin(x)',a,b
	print *,'Les numero des intervals',n
	print *,'La approximation de area est',area
	stop
	end