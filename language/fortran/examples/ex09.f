C Le programme 8.7 qui solve la equation diferentiale
	program ode
	real x,y,drivate,h,dxdy
	integer i,pass
	print *,'Introdu le point initiale, la grandeur de pass et le numeros de pass'
	read *,x,y,h,pass
	print *,'La table de x,y value'
	print *,x,y
	do 100 i=1,pass
		derivate=dxdy(x,y)
		x=x+h
		y=y+derivate*h
		print *,x,y
100	continue
	stop
	end

	real function dxdy(x,y)
	real x,y
	dxdy=x*y
	return
	end
