C Le programme 8.7 qui solve la equation diferentiale
	program ode
	real x,y,drivate,h,dxdy
	integer i,pass
	parameter(g=9.8)
	parameter(R=6378260)
	print *,'Introdu le point initiale, la grandeur de pass et le numeros de pass'
	read *,x,y,h,pass
	print *,'La table de h,v value'
	print *,x,y
	do 100 i=1,pass
		derivate=dxdy(x,y)
		x=x+h
		y=y+derivate*h
		print *,x,y
100	continue
	stop
	end

	real function dxdy(h1,v1)
	real v1,h1,term1,term2
	term1=g*R*R
	term2=v1*(R+h1)*(R+h1)
	dxdy=-term1/term2
	return
	end
