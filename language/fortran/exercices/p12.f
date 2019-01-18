C Le programme pour fait la resoudre de la probleme 6 a pag 147
	program moyenne_positive
	integer numeros
	real numero,moyenne
	print *,'Introduisez les numeros pour calcule la moyenne'
	print *,'Pour fini introdui un negative numero'
	moyenne=0
	numeros=0
	read *,numero
100	if (numero.lt.0) then
		goto 200
	endif
	if (numero.ne.0) then
		numeros=numeros+1
		moyenne=moyenne+numero
	endif
	read *,numero
	goto 100
200	if (numeros.ne.0) then
		print *,'La moyenne est:',moyenne/numeros
	else
		print *,'Vous n avez pas introdui un numero valide'
	endif
	stop
	end