C Le programme 8.14 qui fait la integralle
	program integ
	real inferieur,superieur,g
	real area1,area2
	integer numeros
	external g
	print *,'Introdu les limites de integralle et les numeros des intervales'
	read *,inferieur,superieur,numeros
	print *,'Les limites de integration sont',inferieur,superieur
	print *,'Les numeros des intervals sont',numeros
	call simp(inferieur,superieur,numeros,g,area1,area2)
	print *,'La premier approximation de integral est',area1
	print *,'La deuxieme approximation de integral est',area2
	stop
	end

	subroutine simp(a,b,n,f,area1,area2)
	real a,b,largeur,somme1s,somme2s
	real area1,area2,somme1x,somme2x,f
	integer n,i
	somme1s=0.0
	somme2s=0.0
	largeur=(b-a)/n
	do 100 i=1,n/2
		somme1x=a+2*i*largeur
		somme2x=a+(2*i-1)*largeur
		somme1s=somme1s+f(somme1x)
		somme2s=somme2s+f(somme2x)
100	continue
	somme1s=somme1s-f(somme1x)
	area1=largeur*(f(a)+f(b)+2*somme1s+4*somme2s)/3
	somme1s=somme1s+somme2s
	somme2s=0
	largeur=largeur/2
	do 101	i=0,n-1
		somme2x=a+(2*i+1)*largeur
		somme1s=somme1s+f(somme2x)
101	continue
	area2=largeur*(f(a)+f(b)+2*somme1s+4*somme2s)/3
	return
	end

	real function g(x)
	real x
	g=sin(x)*cos(x)/exp(x)
	return
	end