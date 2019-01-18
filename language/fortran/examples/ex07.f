C Le programme 8.5 pour evalue une serie
	program expon
	real x,somme,term
	integer i
	somme=1
	term=1
	print *,'Introdu la value de x'
	read *,x
	do 100 i=1,100
		term=term*x/i
		somme=somme+term
100	continue
	print *,'La value d exponetial a' ,x,'est',somme
	stop
	end
