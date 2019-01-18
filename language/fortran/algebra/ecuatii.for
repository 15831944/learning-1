C Rezolvarea ecuatiei de gradul 2
      PROGRAM ECUATIE2
      REAL A1,A2,A3
      I=0
1     READ(*,2,END=16)A1,A2,A3
2     FORMAT(3F10.2)
      PRINT *,I,A1,A2,A3
      I=I+1
      WRITE(*,3) I,A1,A2,A3
3     FORMAT(' ECUATIA ',I2,' CU PARAMETRII A1 = ',F11.2,';A2 = ',
     1F11.2,'A3 = ',F11.2)
      IF(A1)6,4,6
4     WRITE(*,5)
5     FORMAT(10X,'ECUATIA ESTE DE GRADUL 1'//120('*')//)
      GO TO 1
6     D=A2**2-4*A1*A3
      IF(D)9,7,14
7     X=-A2/(2*A1)
      WRITE(*,8)X
8     FORMAT(10X,'ECUATIA ARE SOLUTIA DUBLA X= ',F11.2//120('*')//)
      GO TO 1
9     D1=-D
      D2=SQRT(D1)
      XX=-A2/(2*A1)
      IF(A1)10,11,11
10    A4=-A1
      GO TO 12
11    A4=A1
12    YY=D2/(2*A4)
      WRITE(*,13) XX,YY,XX,YY
13    FORMAT(10X,' ECUATIA ARE SOLUTII IMAGINARE : X1 =',F11.2,' + ',
     1F11.2,' I ; X2= ',F11.2,' - ',F11.2,' I '//120('*')//)
      GO TO 1
14    D1=SQRT(D)
      A4=2*A1
      X1=(-A2+D1)/A4
      X2=(-A2-D1)/A4
      WRITE(*,15)X1,X2
15    FORMAT(10X,' ECUATIA ARE SOLUTII REALE DISTINCE : X1 = ',F11.2,
     1' X2 = ',F11.2//120('*')//)
      GO TO 1      
16    STOP
      END