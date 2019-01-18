C Le programme qui fait la grandeur d'integrale pour la function f(x)=x*x
	program grandeur
	real hauteur,largeur,a,b,aire,x
	integer n,i
	print *,'Introduisez les limites d integrale et les numeros des'
	print *,'intervales'
	read *,a,b,n
	aire=0.0
	largeur=(b-a)/n
	do 100 i=0,n-1
		x=a+i*largeur
		hauteur=x*x
		aire=aire+hauteur*largeur
100	continue
	print *,'Les limites de integrale sont:',a,b
	print *,'Les numeros des intervales sont:',n
	print *,'L aire aproximative est:',aire
	stop
	end