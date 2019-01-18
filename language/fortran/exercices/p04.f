C Un programme qui affiche la puissance d'un numero.
	program main
	integer puissance
	real resoudre,numero
	print *,'Le numero'
	read *,numero
	print *,'La puissance'
	read *,puissance
	resoudre=puissance_r(numero,puissance)
	print *,'Le resoudre est:',resoudre
	stop
	end
C La function qui fait la puissance d'un numero
	real function puissance_r(numero,puissance)
	real numero,temporare
	integer puissance
	temporare=1
	do 1 i=1,puissance
	temporare=temporare*numero
1	continue
	puissance_r=temporare
	return
	end