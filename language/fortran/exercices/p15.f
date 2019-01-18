C Le programme pour resoudre les exercices 1 et 2 de pag 164
	program exercices_1_2_164
	real x,y
	print *,'Introdui les argumentes'
	read *,x,y
	print *,'La somme est:',somme(x,y)
	print *,'La difference est:',difference(x,y)
	print *,'La exponentiale est:',exponentiale(x)
	print *,'Le sinus patratique est:',sinus(x)
	stop
	end
	real function somme(coef1,coef2)
	real coef1,coef2
	somme=coef1+coef2
	return
	end
	real function difference(coef1,coef2)
	real coef1,coef2
	difference=coef1-coef2
	return
	end
	real function exponentiale(coef)
	real coef
	exponentiale=exp(-coef*coef/2)
	return
	end
	real function sinus(coef)
	real coef
	sinus=sin(coef)*sin(coef)
	return
	end