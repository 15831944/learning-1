C Le programme 8.6 qui fait la calculation d'une serie
	program expon2
	real x, somme,term
	integer i
	somme=1.0
	print *,'Introdu la value x'
	read *,x
	term=x
	i=1
100 	if((abs(term).gt.1e-9) .and. (i.le.100)) then
		i=i+1
		somme=somme+term
		term=term*x/i
		goto 100
	endif
	print *,'La value de expoential a',x,' est',somme,' dans',i,' termens'
	stop
	end