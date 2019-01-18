C Le program qui fait la corection de tire pour les canons
	program canon
	real limite1,limite2,vitese,angle
	print *,'Introdui les limite de angle et la vitese'
	read *,limite1,limite2,vitese
	print '(G20.10,G20.10,E20.10)', limite1, limite2, vitese
	print *
	print '(A15,A33)','Angle','Distance'
	angle=limite1
100	if (Angle.lt.limite2) then
		print 101,angle,rangef(angle,vitese)
101		format(G35.20,E30.20)
		angle=angle+0.05
		goto 100
	endif
	stop
	end
C La function qui calcule la distance de tir
	real function rangef(elevation,vitesei)
	real elevation,vitesei
	parameter(G=9.8)
	rangef=2*vitesei*vitesei*sin(elevation)*cos(elevation)/G
	return
	end