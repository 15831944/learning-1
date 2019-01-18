C Le programme qui fait le moyenne pour les numeros que ils sont introduire par
C toi
	program main
	integer numeros
	real numero
	real moyenne
	print *,'Introduisez les numeros'
	print *,'Pour fini introdui le numero 0'
	read *,numero
	moyenne=numero
	numeros=1
1	if(numero .ne. 0) then
		read *,numero
		moyenne=moyenne+numero
		numeros=numeros+1
		goto 1
	endif
	numeros=numeros-1
	print *,'Le moyenne est:',moyenne/numeros
	stop
	end