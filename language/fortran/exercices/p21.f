C Le programme qui resoudre la probleme 1 de pag 169
	programe p1_169
	real k,grosseur,area,chaleur
	real dt,temperature3o,temperature3i,temperature1,temperature2,temperature3
	real h,h_verre
	parameter(k=0.8372)
	parameter(h_verre=1.775)
	print *,'Introdui les temperatures et la grosseur de la verre'
	read *,temperature1,temperature2,grosseur
	temperature3=(temperature2+temperature1)/2
	h=h_verre*sqrt(sqrt(temperature3-temperature1))
	chaleur=h*(temperature3-temperature1)
	dt=chaleur*grosseur/k
	temperature3o=temperature3+dt/2
	temperature3i=temperature3-dt/2
	h=h_verre*sqrt(sqrt(temperature3i-temperature1))
	chaleur=h*(temperature3i-temperature1)
	print *,'Le transfer de chaleur per area est',chaleur
	print *,'Introdui l area de verre'
	read *,area
	print *,'Le transfer de chaleur est',chaleur*area
	stop
	end