C Le programme 8.9
	program test
	real inferieur,superieur,g,simp
	external g
	integer numeros
	print *,'Introdu les limites d integralle et les numeros des intervales'
	read *,inferieur,superieur,numeros
	print *,inferieur,superieur,simp(inferieur,superieur,numeros,g)
	stop
	end

	real function simp(a,b,n,f)
	real a,b,largeur,somme1s,somme2s,area,somme1x,somme2x,f
	integer i,n
	somme1s=0
	somme2s=0
	largeur=(b-a)/n
	do 100 i=0,n/2
		somme1x=a+2*i*largeur
		somme2x=a+(2*i+1)*largeur
		somme1s=somme1s+f(somme1x)
		somme2s=somme2s+f(somme2x)
100	continue
	somme1s=somme1s-f(somme1x)
	simp=largeur*(f(a)+f(b)+2*somme1s+4*somme2s)/3
	return
	end

	real function g(x)
	real x
	g=x*x
	return
	end
	