C Le programme qui resoudre la probleme 11 de la pag 204
	program p11_204
	real inferieur,superieur,tolerance,g
	integer j
	external g
	print *,'Introdu la tolerance necesare'
	read *,tolerance
	inferieur=-1
	superieur=5
	print *,'Les limites des interval',inferieur,superieur
	do 99 j=8,0,-1
C Pourqoi il ne functione avec les declaration inferieur et superiur devent la functione do 
C mais il functione si nu ne initialization pas les argument de function bisect
C avec des variable direct mais avem des variable intermediare
		var1=inferieur
		var2=superieur
		print *,'Le numero est',j
		print *,'La racine patratique est',bisect(var1,var2,tolerance,g,j),' avec la tolerance',tolerance
 99	continue
	stop
	end

C Il fait la bisection
	real function bisect(a,b,t,f,numero)
	real a,b,t,f,mid
	integer numero
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
	real x
	integer racine
	g=x*x*x-6*x*x+12*x-racine
	return
	end

