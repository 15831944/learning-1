C Le programme quit resoudre la probleme 1 et 2 de pag 167
	program p1_2_167
	real e,masse,h,c,f1
	parameter(e=1.602e-19)
	parameter(masse=9.11e-31)
	parameter(h=6.63e-34)
	parameter(c=3e+8)
	parameter(f1=6000e-10)
	real vitesse,frequence,material,cinetique
	character teste
100	print *,'Introdui la constante de material'
	read *,materiel
	frequence=e*materiel/h
	print *,'La maxime largeur d ounde est',c/frequence
	frequence=c/f1
	cinetique=(h*frequence-e*materiel)
	if (cinetique.lt.0) then
		vitesse=sqrt(-2*cinetique/masse)
		print *,'La vitesse d emision est imaginare ','j',vitesse
	else
		vitesse=sqrt(2*cinetique/masse)
		print *,'La vitesse d emision est',vitesse
	endif
	print *,'La energie cinetique est',cinetique
	print *,'Voulez vous continue o/n'
	read *,teste
	if (teste.eq.'o') then
		goto 100	
	endif
	stop
	end