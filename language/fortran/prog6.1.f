C
C			Programul 6.1
C
C	Utilizarea unei functii definite
C
	program prog61
	F(x)=(x**2+(7+x**2)**0.5)/(1+x**2)**0.5
	READ 1,n,a,b
1	FORMAT (I5,F5.2,F5.2)
	s=1/2*(F(a)+F(b))
	m=n-1
	DO 2 k=1,m
	x=k*(b-a)/n
2	s=s+F(a+x)
	s=s*(b-a)/n
	PRINT 3,n,a,b,s
3	FORMAT ('N=',I5,2X,'A=',F6.2,2X,'B=',F6.2,2X,'S=',F10.6)
	STOP
	END
		