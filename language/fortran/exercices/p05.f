C Le programme de affiche la puissance de deux numero in paralel
	program main
	real numero1,numero2,sortie1,sortie2
	integer puissance1,puissance2
	print *,'Introduisez les numeros'
	print *,'Le premier numero'
	read *,numero1
	print *,'Le deuxieme numero'
	read *,numero2
	print *,'Introduisez les puissances des numeros'
	print *,'La puissance pour le premier numero'
	read *,puissance1
	print *,'La puissance pour le deuxieme numero'
	read *,puissance2
	sortie1=puissancef(numero1,puissance1)
	sortie2=puissancef(numero2,puissance2)
	print *,'La puissance des numeros sont'
	print *,sortie1,sortie2
	stop
	end
C La function qui fait la puissace d'un numero
	real function puissancef(numero,puissance)
	real numero,temporare
	integer puissance
	temporare=1
	do 1 i=1,puissance
	temporare=temporare*numero
1	continue
	puissancef=temporare
	return
	end