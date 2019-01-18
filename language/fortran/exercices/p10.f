C Le programme fait la somme et la moyenne des entie numeros qui sont plus 
C grande que 0
	programe somme
	real somme,moyenne,numeros,numero
	print *,'Introduisez les numeros,pour fini introduisez le 0'
	somme=0
	numeros=0
	read *,numero
1	if(numero.ne.0) then
	if(numero.gt.0) then
	somme=somme+numero
	numeros=numeros+1
	endif
	read *,numero
	goto 1
	endif
	moyenne=somme/numeros
	print *,'La somme est:',somme,'La moyenne est:',moyenne
	stop
	end
	