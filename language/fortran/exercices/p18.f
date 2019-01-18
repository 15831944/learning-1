C Le programme pour resoudre la probleme 4 de pag 164
	program p4_164
	real x,pass
	integer numeros
	print *,'Introdui le numeros de intervals'
	read *,numeros
	print *,'La verification des equation trigonometrics'
	x=-1.0
	pass=2*acos(x)/numeros
	print *,'La equation est sin(x)*sin(x)+cos(x)*cos(x)=1'
	do 100 i=0,numeros
	x=pass*i
	if(abs(sin(x)*sin(x)+cos(x)*cos(x)-1).lt.1e-6) then
		print *,'Equation est verifie pour',x
	else
		print *,'Equation n est pas verifie pour',x
	endif
100	continue
	print *,'Equation est sin(2x)=2*sin(x)*cos(x)'
	do 101 i=0,numeros
	x=pass*i
	if(abs(sin(2*x)-2*cos(x)*sin(x)).lt.1e-6) then
		print *,'Equation est verifie pour',x
	else
		print *,'Equation n est pas verifie pour',x
	endif
101	continue
	stop
	end
	