C Le programme de test pour copier deux vectors par deux fisiers
	program main
	real a(5),b(5),c(5)
	open(1,file='in1')
	open(2,file='in2')
	open(3,file='out1')
	do 100 i=1,5
		read (1,*) a(i)
		read (2,*) b(i)
100	continue
	print *,'Le premier fisier'
	call printv(5,a)
	print *,'Le deuxieme fisier'
	call printv(5,b)
	print *,'Apellons la subroutine de calcul'
	test=reunifie(5,5,a,b)
	if (test.eq.1) then
		print *,'Succes de concatene cest deux fisiers'
	else
		print *,'Error de concatene cest deux fisiers'	
	endif
	close(1)
	close(2)
	close(3)
	stop
	end

	subroutine printv(nr,vector)
	integer nr
	real vector(nr)
	do 1 i=1,nr
		print *,vector(i)
1	continue
	return
	end

	real function reunifie(nr1,nr2,vector1,vector2)
	integer nr1,nr2
	real vector1(nr1),vector2(nr2)
	write (3,*),'Le premier'
	call printf(3,nr1,vector1)
	write (3,*),'Le deuxieme'
	call printf(3,nr2,vector2)
	reunifie=1
	return
	end

	subroutine printf(fisier,nr,vector)
	integer nr,fisier
	real vector(nr)
	do 2 i=1,nr
		write (fisier,*) vector(i)
2	continue
	return
	end
