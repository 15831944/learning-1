; Exemple din Antrenamente LISP de Mihaela Malita, Editura Universitatii din Bucuresti 1998
; LISTE
(SETF X '(A B C)); (A B C)
`(X Y Z); (X Y Z)
`(,x y z); (A B C Y Z)
(PRINT  `(X este ,X)); (X ESTE A B C)
(PRINT `(X este ,@X)); (X ESTE A B C)
(LIST 'B 'C) (B C)
(LIST '(N) '(F M)); ((N) (F M))
(LIST 'A '(B C) 'D); (A (B C) D)
(APPEND '(A B) '(C D)); (A B C D)
(APPEND '(A (B)) '(C (D)) `(E)); (A (B) C (D) E)
(APPEND '(A (B)) NIL '(E)); (A (B) E)
(MEMBER 'A '(B A C D)); (A C D)
(MEMBER '(A B) '(8 (C D) (A B))); :KEY 'EQUAL); nu merge ...
(MEMBER 3 '(2 4 5 7) :KEY '>); nu merge ...
(DEFUN NEXT (E L) (COND ((NULL L) NIL) ((EQUAL E (CAR L)) (CADR L)) (T (NEXT E (CDR L)))))
(NEXT 'A '(B A C D)); C
(NEXT 'A '(B A A C D)); A
(NTH 0 '(A B C)); A
(NTH 4 '(A B C)); NIL
(LENGTH '(A)); 1
;(LENGTH 'A); not a sequence
(LENGTH '(A (B D) C)); 3
(DEFUN LENGTHR (L) (COND ((ATOM L) 0) (T (1+ (LENGTHR (CDR L)))))); defintia recursiva
(LENGTHR '(A (B D) C)); 3
(DEFUN LENGTHC (L N) (COND ((NULL L) N) (T (LENGTHC (CDR L) (1+ N))))); recursivitate pe coada
(LENGTHC '(A (B D) C) 0); 3
(ASSOC 'C '((A 1)(B 2)(C 3)(D 4))); (C 3)
(ASSOC 3 '((1 2)(2 3)(3 8)(4 16)(3 9))); (3 8)
(RASSOC 'A '((3 . C)(1 . A)(2 . b))); (1 . A)
(SUBST 'B 'A '(2 3 A 4 (A) 5)); (2 3 B 4 (B) 5) in antrenamente lisp spunea ca este pe un singur nivel
(DEFUN SUBST-tot (nou vechi L) (COND ((ATOM L) L)((EQUAL VECHI (CAR L)) (CONS NOU (SUBST-tot nou vechi (CDR L))))(T (CONS (SUBST-tot nou vechi (CAR L)) (SUBST-tot nou vechi (CDR L))))))
(SUBST-tot 'B 'A '(2 3 A 4 (A) 5)); (2 3 B 4 (B) 5)
(DEFUN SUBST-1 (nou vechi L) (COND ((NULL L) NIL) ((EQUAL VECHI (CAR L)) (CONS NOU (SUBST-1 NOU VECHi (CDR L))))(T (CONS (CAR L)(SUBST-1 NOU VECHI (CDR L))))))
(SUBST-1 'B 'A '(2 3 A 4 (A) 5)); (2 3 B 4 (B) 5)
(SUBLIS '((UNU . 1)(DOI . 2)) '(UNU SI DOI)); (1 SI 2)
(SUBLIS '((a . x)(b . y)(c . z)) ' (a (a)(b c)(c))); (x (x)(y z)(z))
(DEFUN SUBLIS-1 (A L)(COND ((NULL A) L) (T (SUBLIS-1 (CDR A)(SUBST-tot (CAAR A) (CDAR A) L)))))
(SUBLIS-1 '((a . x)(b . y)(c . z)) ' (a (a)(b c)(c))); (x (x)(y z)(z))
(REMOVE 'A '(A (B A) C A)); ((B A) C)
;(REMOVE 'A '(A (B A) C A) :KEY 'EQ); ((B A) C) nu merge EQ
(REMOVE 'NIL '(NIL A NIL)); (A)
(DEFUN REMOVE1 (A L) (COND ((NULL L ) NIL)((EQ A (CAR L)) (REMOVE1 A (CDR L)))(T (CONS (CAR L)(REMOVE A (CDR L)))))); echivalent cu (REMOVE A L : KEY 'EQ)
(REMOVE1 'A '(A (B A) C A)); ((B A) C)
(DEFUN TAKE (N L) (COND ((NULL L) NIL)((ZEROP N) (CDR L)) (T (CONS (CAR L)(TAKE (1- N)(CDR L)))))); sterge din lista elementul N
(TAKE 1 '(A (B A) C A)); (A C A)
(REVERSE '(A B (C D) E)); (E (C D) B A)
(DEFUN REVERSER (L)(COND ((NULL L) NIL)(T (APPEND (REVERSER (CDR L))(CONS (CAR L) NIL))))); pe un singur nivel recursiva
(REVERSER '(A B (C D) E)); (E (C D) B A)
(DEFUN REVERSEC (L R)(COND ((NULL L) R)(T (REVERSEC (CDR L)(CONS (CAR L) R))))); recursivitate la coada
(REVERSEC '(A B (C D) E) NIL); (E (C D) B A)
(DEFUN REVERSE-TOT (L) (COND ((ATOM L) L) (T (APPEND (REVERSE-TOT (CDR L))(LIST (REVERSE-TOT (CAR L))))))); inverseaza tot indiferent de paranteze
(REVERSE-TOT '(A (B C) 3 (D E))); ((E D) 3 (C B) A) 
