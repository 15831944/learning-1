; Exemple din Antrenamente LISP de Mihaela Malita, Editura Universitatii din Bucuresti 1998
; recursivitatea
(LAST '(A B C)); (C)
(LAST '(A (B C))); ((B C))
(DEFUN FACT (N) (COND ((= N 0) 1)(T (* N (FACT (- N 1)))))) ; se poate si (1- N)
(FACT 4)
(DEFUN FACT1 (N R) (COND ((= N 0) R)(T (FACT1 (- N 1)(* N R))))) ; cu recursivitate pe coada
(FACT1 4 1)
(DEFUN FIB (N) (COND ((= N 0) 1) ((= N 1) 1)(T (+ (FIB (1- N))(FIB(- N 2))))))
(FIB 5); 8
(DEFUN FIBC (N X Y)(COND ((= N 0) X)(T (FIBC (1- N) Y (+ X Y))))); cu recursivitate pe coada
(FIBC 5 1 1)
(DEFUN ACK (N M) (COND ((ZEROP N)(1+ M))((ZEROP M)(ACK (1- N) 1))(T (ACK (1- N) (ACK N (1- M))))))
(ACK 2 2)
;tabel logaritmic
(DEFUN TABEL-LOG (PAS VAL) (COND ((<= VAL 0) ''STOP) (T (PRINT (LOG VAL)) (TABEL-LOG PAS (- VAL PAS)))))
(TABEL-LOG 1 3)
;tabel in care se da functia
(DEFUN TABEL (FUN PAS VAL) (COND ((<= VAL 0) 'STOP) (T (PRINT (FUNCALL FUN VAL)) (TABEL FUN PAS (- VAL PAS)))))
(TABEL 'LOG 1 3)