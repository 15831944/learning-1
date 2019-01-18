C Le programme 8.8 qui resoudre l'equation diferentiale
	program ode2
	real x,y,derivate,h,dxdy,tx,ty
	integer i,pass
	print *,'Introdu la value initiale, largeur de pass et les numeros des pass'
	read *,x,y,h,pass
	print *,'Le table de value x,y'
	print *,x,y
	do 100 i=1,pass
		derivate=dxdy(x,y)
		tx=x+h
		ty=y+derivate*h
		derivate=(derivate+dxdy(tx,ty))/2
		y=y+derivate*h
		x=x+h
		print *,x,y
100	continue
	stop
	end

	real function dxdy(x,y)
	real x,y
	dxdy=x*y
	return
	end