; Exemple din Antrenamente LISP de Mihaela Malita, Editura Universitatii din Bucuresti 1998

(= 2 3) ; NILL
(< 5 8) ; T
(NUMBERP 8.9) ; T
(NUMBERP 'melania) ; NILL
(INTEGERP 8.9) ; NILL
(INTEGERP 10) ; T
(INTEGERP 'A) ; T
(SETF A 7) ; 7
(ZEROP A) ; NILL
(MINUSP 7) ; NILL
(PLUSP -8); NILL
(SETF L '(+ 1 2 3)); L -> (+ 1 2 3)
(EVAL L) ; 6
(CAR '(A B)) ; A first from list
(CAR '(((A B) C) D)) ; ((A B) C) first from list
(CDR '(A B)) ; B last from list
(CDR '(((A B) C) D)) ; D last from list
(CDR (CDR '(A B C))) ; C
(CDR '(A . B)) ; B
; compressed ones CDDR = CDR CDR
(CDR (CDR '((A 1) B 2))) ; (2)
(CDDR '((A 1) B 2)) ; (2)
(CDR (CDR (CAR '((A B) C)))); NILL
(CDDAR '((A B) C)) ; NILL
; Constructors
(CONS 'A '(B C)); (A B C)
(CONS '(1 2) '((A B)(C D))); ((1 2)(A B)(C D))
(CONS '(A) '(1 2 3)); ((A) 1 2 3)
; equals
(EQ 'A 'A); T
(EQUAL (CAR '(A (B C)))(CAR '(A (B) C))); T
(IF (> 8 0) 'pozitiv 'negativ); POZITIV
(ABS -5.3); 5.3
(COND (T (+ 7 8)) ('NU-AJUNGE-NICIODATA)); 15
(COND ((= 7 6) 'RAU) ((7 6)(+ 3 4)(* 5 4))); 20
(COND ((= 3 4) 'NU) ((EQ () NIL)(SETF L 'DA) 'BINE)); BINE
(COND ((= 1 2) 'RAU) ((+ 4 5)(SETF L (* 3 4))(+ L 1))(T 'NU-ANJUNGE-AICI)); 13
(/= 5 6); T
(/= 5 5); NIL
(MIN 5 4) ; 4
(MAX 1 3 5 2 6 8 9 8); 9
(DEFUN F (X) (+ (* 10 X)2))
(F 5); 52
(DEFUN CUB (X) (* X X X))
(DEFUN SUMA-CUBURI (X Y) (+ (CUB X) (CUB Y)))
(SUMA-CUBURI 3 2); 35
(CUB 3); 27
(SETF L '(1 2 3)); (1 2 3)
(SETF X (CONS '+ L)) (+ 1 2 3)
(EVAL X); 6
(APPLY '+ L); 6
;exercitii
(CAR '(STING . DREPT)); STING
(CAR '(A . B)); A
(CAR '(A . (B . C))); A
(CAR (CAR '((A B) C))); A
(CAR '(CAR '(A B))); CAR
(CDR '(CAR '(A B))); ('(A B))
(CAR '(((A . B) . (C . D)))); ((A . B) C . D)
(CDR '(((A . B) . (C . D)))); NIL
(CAR '((A . B) . (C . D))); (A . B)
(CDR '((A . B) . (C . D))); (C . D)
(CAR (CAR '((A 1)(B 2)))); A
(ATOM 'a); T
(ATOM T); T
(ATOM '(atom atom)); NIL
(ATOM (ATOM T)); T
(CONS 'CAR 'CAR); (CAR . CAR)
(CONS 'A '(B)); (A B)
(CONS '(A) '(B C)); ((A) B C)
(CONS '(1 2) '(B C)); ((1 2) B C)
(CONS '(A B) '(B . C)); ((A B) B . C)
(CONS '(A) '(B . C)); ((A) B . C)
(CONS 'A NIL); (A)
(CONS '(NIL) NIL); ((NIL))
(CDR '((A B) C)); (C)
(CDR '((A B) (C D))); ((C D))
(CDR '(A . (B . C))); (B . C)
(CONS 'A 'B); (A . B)
(CONS 'STINGA 'DREAPTA); (STINGA . DREAPTA)
(CONS 'A '((B) C)); (A (B) C) 
(CONS '((A)) '((B) (C))); (((A)) (B) (B))
(CONS 'A '(B C)); (A B C)
(CONS '((A . B) . C) 'D); (((A. B) . C) . D)
(CONS 'A '(B (C D))); (A B (C D)) 
(CONS '(A . 1) '((B . 2)(C . 3))); ((A . 1) (B . 2) (C . 3))
(CONS NIL '(B C)); (NIL B C)
(CONS '(A B C) NIL); ((A B C))
(CONS NIL '(A B)); (NIL A B)
(CONS '(A B) NIL); ((A B))
(COND (T)); T 
(COND (T 'REGE) (T 'AS)); REGE
;(COND (((SETF DELTA -2) 0) 'ARE-SOLUTII) ((= DELTA 0) 'RADACINI-EGALE) (T 'NU-ARE-SOLUTII))
(COND ((CAR '(NIL NIL))(* 7 8))((CDR '(NIL NIL))(+ 2 3)(* 5 3))(T 'NIMIC)); 15
(COND ((CONS 2 '(3 4)))(T (* 6 5))); (2 3 4)
(COND ('(A) '(B))(T (* 6 5))); (B)
(COND ((EQ 'A 'B) 'BINE) ((EQ 'A (CAR '(A D)))(* 5 4))); 20

