C Le programme qui fait la integralle avec la simpson rule
	program simp
	real a,b,largeur,somme1s,somme2s,area,somme1x,somme2x,f
	integer numeros,i
	print *,'Introduis les limites d integralle et les numeros de intervals'
	read *,a,b,numeros
	somme1s=0
	somme2x=0
	largeur=(b-a)/n
	do 100 i=1,numeros/2
		somme1x=a+2*i*largeur
		somme2x=a+(2*i-1)*largeur
		somme1s=somme1s+f(somme1x)
		somme2s=somme2s+f(somme2x)
100 	continue
	somme1s=somme1s-f(somme1x)
	area=largeur*(f(a)+f(b)+2*somme1s+4*somme2s)/3
	print *,'Les limites des integration sont',a,b
	print *,'Les numeros des intervales sont',numeros
	print *,'L approximatife area ',area
	stop
	end
	real function f(x)
	real x
	f=sin(x)*cos(x)/exp(x)
	return
	end