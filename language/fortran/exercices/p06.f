C Le programme qui calcule l'expresion de la page 139
	program expresion
	integer interation
	real somme1,somme2,pass,inferieur,superieur,temporare
	print *,'Introdui le numero de iteration'
	read *,iteration
	print *,'Introdui les limite de interval'
	read *,inferieur
	read *,superieur
	pass=(superieur-inferieur)/iteration
	do 100 i=1,iteration
	somme1=1
	somme2=2
	temporare=inferieur+pass*i
		do 200 j=1,4
			somme1=somme1+puissance(j,temporare)
200		continue
	somme2=somme2+temporare*temporare-3*temporare
	print *,'Location:',temporare,'expresion',somme1/somme2
100	continue
	stop
	end
C Function qui fait la pusissance d'un numero
	real function puissance(nr,numero)
	real numero
	integer nr
	puissance=1
	do 1 k=1,nr
	puissance=puissance*numero
1	continue
	return
	end