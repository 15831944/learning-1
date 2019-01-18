C Le programme 8.13 qui trouve la racine d'une equation
	program root
	external g,gprime
	real estimate,tol1,tol2,g,gprime,newton
	print *,'Introdu le estimate initial, la tolerance verticale et la tolerance dans'
	print *,'les points d inflexion'
	read *,estimate,tol1,tol2
	print *,'La racine est',newton(estimate,tol1,tol2,g,gprime)
	stop
	end

	real function newton(a,t1,t2,f,fprime)
	real a,t1,t2,f,fprime,x
	x=a
100	if(abs(f(x)).ge.t1) then
101		if(abs(fprime(x)).le.t2) then
			x=x+1.0
			goto 101
		endif
		x=x-f(x)/fprime(x)
		goto 100
	endif
	newton=x
	return
	end
	
	real function g(x)
	real x
	g=(x-1)*(x-4)
	return
	end

	real function gprime(x)
	real x
	gprime=2*x-5
	return
	end