C Le programme 8.11 qui trouve la racine d'une equation
	programe root
	real inferieur,superieur,tolerance,g,bisect
	external g
	print *,'Introdu le interval et la tolerance necesare'
	read *,inferieur,superieur,tolerance
	print *,'Les limites de interval sont',inferieur,superieur
	print *,'La racine est',bisect(inferieur,superieur,tolerance,g),' avec la tolerance',tolerance
	stop
	end
	
	real function bisect(a,b,t,f)
	real a,b,t,f,mid
	mid=(a+b)/2
100	if (abs(b-a).gt.t) then
		if((f(a)*f(mid)).le.0.0) then
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
	g=(x-1)*(x-4)
	return
	end
	