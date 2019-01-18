C Le programme qui fait le exercise 5 de la pag 147 la serie de Fibonnaci
	program fibonnaci
	integer nr
	real anterieur,courant,futur
	print *,'Introdui le numero pour calcule la serie de Fibonnaci'
	read *,nr
	anterieur=1
	courant=1
	if(nr.eq.1) then
		futur=1
		goto 200
	elseif (nr.eq.2) then
		futur=1
		goto 200
	endif
	do 100 i=3,nr
	futur=courant+anterieur
	anterieur=courant
	courant=futur
100	continue
200	print *,'Pour le numero',nr,' La serie de Fibonnaci est',futur
	stop
	end