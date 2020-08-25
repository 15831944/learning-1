; Exemple din Antrenamente LISP de Mihaela Malita, Editura Universitatii din Bucuresti 1998
; LAMBDA
((lambda(x)(+ x 5)) 4); 9
(lambda(y)(* 2 y));
((lambda(z)(* 2 z)) 3); 6
((lambda(x)(+ x 5))((lambda(z)(* 2 z)) 3)); 11
((lambda(x y)(+ x y (* x y))) 3 8); 35
((lambda(z)(* z z z)) 3); 27
((lambda(x)(CONS x x)) '(A  B)); ((A B) A B)
((lambda(z) 1) 'ORICE); 1
((lambda() 8)); 8
((lambda(z)( + z 3)) 7);10
((lambda(x y)(+ x y (* x y))) 1 2); 5
((lambda(x)(+ x 3 5))((lambda(z)(* 2 z)) 1)); 10
;LET
(LET ((x 5)(y 3))(+ x y)); 8
(LET ()(PRINT 'CUCU)); CUCU
(LET (X)(CONS 2 NIL)); (2)
(LET ((X 'A)) (CONS X NIL)); (A)
(LET ((X 'A)(Y 'B))(CONS X Y)); (A . B)
(LET* ((X 'A)(Y X))(CONS X Y)); (A . A)
(LET* ((X 'A)(Y X)(Z Y))); NILL
;(LIST (X Y Z))
(LABELS ((ADUN5(z)(+ 5 z)))(ADUN5 10)); 15
(DEFUN REVERSE(L)(LABELS ((REV (L R)(COND ((NULL L) R)(T (REV (CDR L)(CONS (CAR L) R))))))(REV L NIL)));
(LENGTH '(A B (C D)));
;(DEFUN LENGTH(L)(LABELS ((L-AUX(L N)(COND ((NULL L) N)(T (L-AUX (CDR L)(1 + N))))))(L-AUX L 0)));
(FUNCTIONP 'DUBLU); T -- NIL
(FUNCTIONP 'LIST); T  -- NIL
(DEFUN YES_OR_NO_P (&OPTIONAL TEXT) (IF TEXT (PRINC TEXT))(PRINC "(Y/N)?=") (MEMBER (READ) '(Y YES DA D OK T TRUE)))
(YES_OR_NO_P "Vreti sa continuati");
(YES-OR-NO-P)

