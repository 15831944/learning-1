C Le programme quit fait la moyenne des numero est il returne ausi le pus
C grande des numero
	program moyenne_et_grande
	real moynne,grande,somme,numero
	integer numeros,encore
	character test
	print *,'Introduisez les numeros'
	print *,'Pour fini introdui le 0'
	numeros=0
	read *,numero
	grande=numero
	encore=0
1	if (numero.ne.0) then
		numeros=numeros+1
		somme=somme+numero
		read *,numero
		if (numero.gt.grande) then 
			grande=numero
		endif
		goto 1
	else if(encore.eq.1) then
		numeros=numeros+1
		read *,numero
		if (numero.gt.grande) then 
			grande=numero
		endif
		encore=0
		goto 1
	endif
	print *,'Voules vous termine (o/n)?'
	read *,test
	if(test.eq."o")  then
		encore=0
		goto 3
	else
		encore=1
		goto 1
	endif
3	print *,'La moyenne est:',somme/numeros
	print *,'Le plus grande numero est:',grande
	stop
	end