;Acesta este un comentatariu in LISP
; Exemple din Antrenamente LISP de Mihaela Malita, Editura Universitatii din Bucuresti 1998

(DEFUN DUBLU(N) (+ N N))
;
(DEFUN SALUT() (PRINT 'Buna!))
;
(DEFUN ADUN-CU-1 (); aduna cu 1 la numarul citit
  (PRINT (+ 1 (READ)))
  (PRINT 'CONTINUAM?)
  (IF (EQUAL 'DA (READ)) (ADUN-CU-1))
  )
;
(ADUN-CU-1)
