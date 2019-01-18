C Le programme 8.12 qui trouve la racine d'une equation
	program root
	real inferieur,superieur,tolerance,g,bisec
	external g
	print *,'Introdu le interval et la tolerance necesare'
	read *,inferieur,superieur,tolerance
	print *,'Les limites de interval',inferieur,superieur
	print *,'La racine est',bisec(inferieur,superieur,tolerance,g),' avec la tolerance',tolerance
	stop
	end

	real function bisec(a,b,t,f)
	real a,b,t,f,mid
	mid=(a+b)/2
100	if (abs(f(mid)).ge.t) then
		if ((f(a)*f(mid)).le.0.0) then
			b=mid
		else
			a=mid
		endif
		mid=(a+b)/2
		goto 100
	endif
	bisec=mid
	return
	end
	
	real function g(x)
	real x
	g=(x-1)*(x-4)
	return
	end