C Le programme pour fait la moyenne de cinque entie numero
	program main
	integer numero
	real moyenne
	real a(5)
	numero=5
	print *,'Introduisez les numeros'
	do 100 i=1,numero
	read *,a(i)
100	continue
	moyenne=moyennef(a,numero)
	print *,'La moyenne est:',moyenne
	stop
	end
C La function qui fait la moyenne d'un vector de real numero
C Il ne marche pas avem de numero real,il marche s'il returne un numero
C entie
	real function moyennef(vector,nr)
	integer nr
	real vector(nr)
	real medie
	medie=vector(1)
	do 1 i=2,nr
	medie=medie+vector(i)
1	continue
	moyennef=medie/nr
	return
	end