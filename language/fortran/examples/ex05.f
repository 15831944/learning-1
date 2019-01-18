C Le programme 8.3 qui fait la integration avec la trapezoidal rule
	program trapezoidal_integrall
	real inferieur,superieur,area,largeur,x,f
	integer numeros,i
	print *,'Introdui les limites d integrale et les numeros des intervales'
	read *,inferieur,superieur,numeros
	largeur=(superieur-inferieur)/numeros
	area=(F(inferieur)+f(superieur))/2.0
	do 100 i=1,numeros-1
		x=inferieur+i*largeur
		area=area+f(x)
100	continue
	area=area*largeur
	print *,'Les limites d integralle sont',inferieur,superieur
	print *,'Les numeros des intervales sont',numeros
	print *,'L aproximatife area est',area
	stop
	end

	real function f(x)
	real x
	f=sin(x)*cos(x)/exp(x)
	return
	end
