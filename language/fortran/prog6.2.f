C
C				PROGRAMUL 6.2
C
C		Evaluarea unei functii logice
C
	logical a,x,y,l,b(2)
	data b/.TRUE.,.FALSE./
	l(x,y)=(.NOT.x.OR.y).AND.(.NOT.y.OR.x).OR.y
	DO 1 i=1,2
	DO 1 j=1,2
	x=l(b(i),b(j))
1	PRINT 2,b(1),b(2),x
2	FORMAT (' ','L(',L1,',',L1,')=',L2)
	STOP
	END