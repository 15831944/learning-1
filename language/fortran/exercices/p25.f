C Le programme qui resoudre la probleme 12 de la pag 204
	program root
	real inferieur,superieur,tolerance,g,g1,numero
	external g,g1
	print *,'Introdu l interval et la tolerance necesare'
	read *,inferieur,superieur,tolerance
	print *,'Les limites des interval',inferieur,superieur
	print *,'La intersection est',bisect(inferieur,superieur,tolerance,g,g1),' avec la tolerance',tolerance
	stop
	end

C Il fait la bisection
	real function bisect(a,b,t,funct,funct1)
	real a,b,t,funct,mid,teste,funct1
	mid=(a+b)/2
100	if (abs(b-a).ge.t) then
		teste=funct(mid)-funct1(mid)
		if(teste.gt.0.0) then
			b=mid
		else
			a=mid
		endif
		mid=(a+b)/2
	goto 100
	endif
	bisect=mid
	return
	end

	real function g(x)
	real x
	g=x*x-4
	return
	end

	real function g1(x)
	real x
	g1=x+2
	return
	end