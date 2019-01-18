C Le programme qui resoudre une equation de grade deux
	program equation
	real coef1,coef2,coef3,discriminant
	print *,'Introdui les coeficients in l order decroissance'
	read *,coef1
	read *,coef2
	read *,coef3
	discriminant=disc(coef1,coef2,coef3)
	if (discriminant.ge.0) then
		print *,'Positive solution=',sol1(coef1,coef2,discriminant)
		print *,'Negative solution=',sol2(coef1,coef2,discriminant)
	else
		print *,'L ecuation n a pas de solution reale'
	endif
	stop
	end

	real function disc(a,b,c)
	real a,b,c
	disc=b*b-4*a*c
	return
	end

	real function sol1(a,b,discrim)
	real a,b,discrim
	sol1=(-b+sqrt(discrim))/(2*a)
	return
	end
	
	real function sol2(a1,b1,discrim1)
	real a1,b1,discrim1
	sol2=(-b1-sqrt(discrim1))/(2*a1)
	return
	end