C Le programme fait la moyenne et la standard deviation sur les numeros
C introduisez par vous
	program moyen_stdd
	integer	numeros
	real numero,deviation,moyenne,sum,sum2
	print *,'Le program qui calcule la moyenne et la standard deviation'
	print *,'pour les numeros qui sont introduisez par vous'
	print *,'Pour fini introdui le numero 0'
	read *,numero
	sum2=numero*numero
	sum=numero
	numeros=1
1	if (numero.ne.0) then
	read *,numero
	sum=sum+numero
	sum2=sum2+numero*numero
	numeros=numeros+1
	goto 1
	endif
	numeros=numeros-1
	moyenne=sum/numeros
	deviation=sqrt((sum2-1/numeros*sum*sum)/(numeros-1))
	print *,'La moyenne est:',moyenne,' La deviation est:',deviation
	stop
	end