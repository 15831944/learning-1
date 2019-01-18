C Le programme fait la grandeur d'une integrale pour la fucntion f(x)=x*x
	program grandeur
	real a,b,largeur,hauteur,aire,x
	integer n,i
	print *,'Introduisez les limite d integrale et les numeros'
	print *,'intervale'
	read *,a,b,n
	aire=0.0
	largeur=(b-a)/n
	x=a
	do 100 i=0,n-1
		hauteur=x*x
		aire=aire+largeur*hauteur
		x=x+largeur
100	continue
	print *,'Les limites d integrale sont:',a,b
	print *,'Le numero des intervales sont:',n
	print *,'L aire aproximative est:',aire
	stop
	end