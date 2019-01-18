C Le programme qui fait la integralle avec le rectangle rule le programme 8.1
	program rectangle_integralle
	real inferieur,superieur,largeur,hauteur,area,x,f
	integer numeros,i
	print *,'Introdui les numeros d interval et les limites de integration'
	read *,inferieur,superieur,numeros
	area=0.0
	largeur=(superieur-inferieur)/numeros
	do 100 i=0,numeros-1
		x=inferieur+i*largeur
		hauteur=f(x)
		area=area+hauteur*largeur
100	continue
	print *,'Les limites d integration sont',inferieur,superieur
	print *,'Les numeros d intervales sont',numeros
	print *,'L area approximative est', area
	stop
	end
	
	real function f(x)
	real x
	f=x*x
	return
	end