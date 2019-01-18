C Le programme qui resoudre la probleme 6 de la pag 203
	program root
	real inferieur,superieur,tolerance,g,numero
	external g
	print *,'Introdu le numero'
	read *,numero
	print *,'Introdu l interval et la tolerance necesare'
	read *,inferieur,superieur,tolerance
	print *,'Les limites des interval',inferieur,superieur
	print *,'Le numero est',numero
	print *,'La racine patratique est',bisect(inferieur,superieur,tolerance,g,numero),' avec la tolerance',tolerance
	stop
	end

C Il fait la bisection
	real function bisect(a,b,t,f,numero)
	real a,b,t,f,mid,numero
	mid=(a+b)/2
100	if (abs(b-a).ge.t) then
		if(f(mid,numero).gt.0.0) then
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

	real function g(x,racine)
	real x,racine
	g=x*x-racine
	return
	end

