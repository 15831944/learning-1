C Le programme 8.10 
	program root
	real inferieur,superieur,tolerance,g,bisecteur
	external g
	print *,'Introdu l interval et la tolerance necesare'
	read *,inferieur,superieur,tolerance
	print *,'Les limites des interval',inferieur,superieur
	print *,'La racine est',bisect(inferieur,superieur,tolerance,g),' avec la tolerance',tolerance
	stop
	end

C Il fait la bisection
	real function bisect(a,b,t,f)
	real a,b,t,f,mid
	mid=(a+b)/2
100	if (abs(b-a).ge.t) then
		if(f(mid).gt.0.0) then
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
	g=(x-1)*(x+4)
	return
	end

