C Le programme qui fait la moyenne d'une liste des numeros nonvide
	program moyenne_nonvide
	real moyenne,numero,numeros
	print *,'Programme quit fait la moyenne des numeros nonzero'
	print *,'Intoduisez les numeros,pour fini introdui le 0'
	moyenne=0
	numeros=0
	read *,numero
1	if(numero.ne.0) then
		moyenne=moyenne+numero
		numeros=numeros+1
		read *,numero
		goto 1
	endif
	if(numeros.ne.0) then
		print *,'La moyenne est:',moyenne/numeros
	else
		print *,'Vous n avez pas introduire un numero'
	endif
	stop
	end
