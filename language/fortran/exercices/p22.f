C Le programme qui resoudre la probleme 2 de pag 169
	programe p2_169
	real k,grosseur,area,arg
	real dt,temperature1,temperature2,temperature3,chaleur
	real h_verre,i
	parameter(k=0.8372)
	parameter(h_verre=1.775)
	print *,'Introdui les temperatures et la grosseur de la verre'
	read *,temperature1,temperature2,grosseur
	arg=grosseur
	temperature3=(temperature2+temperature1)/2
	h=h_verre*sqrt(sqrt(temperature3-temperature1))
	chaleur=h*(temperature3-temperature1)
	pass=grosseur/10
	do 100 i=1,10
		arg=arg-i*pass
		dt=chaleur*arg/k
		print *,(i*pass/2),(temperature3+dt/2),(temperature3-dt/2)
100	continue
	stop
	end
	real function chaleurf(temp1,temp2,grosse)
	real temp1,temp2,h,temp3

	return
	end