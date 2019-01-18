        org     100h
        mov     ax,cs
        mov     ds,ax
        jmp     salt                    ;salt la prima instructiune
nrsir   dw      9                       ;cuvint care contine nr de siruri,
                                        ;numaratoarea incepe de la 0
sir     db      'program',0             ;def siruri alfanumerice terminate
                                        ;cu byte 0
        db      'de',0
        db      'ordonare',0
        db      'pentru',0
        db      'siruri',0
        db      'alfanumerice',0
        db      'terminate',0
        db      'cu',0
        db      'octet',0
        db      'zero',0
start   mov     cx,nrsir                ;aici incepe programul cu incarcarea
                                        ;in CX a nr de siruri
bucla   mov     al,byte ptr nrsir
        sub     al,cl                   ;incarcarea in al a nr sirului curent
                                        ;AL=nrsir CL
        call    calcad                  ;calculeaza adresa de inceput a sirului
                                        ;curent (adr in BX)
        mov     dx,bx                   ;stocheaza adr in BX
        inc     al
        call    calcad                  ;calculeaza adr de inceput a sirului
                                        ;curent+1 (adr in BX)
        call    comp                    ;compara sirurile de la adr continute
                                        ;in BX si DX
        jg      adr1                    ;daca ordinea este buna sare la adr1
        call    schimb                  ;altfel apeleaza schimb
        mov     cx,nrsir                ;si pregateste cx pt reluarea iterati-
        inc     cx                      ;ei de la inceput
adr1    loop    bucla                   ;repeta programul pina la ultimul sir
        int     20h                     ;revenire in DOS
calcad  push    cx
        push    ax                      ;conserva registrele AX siBX
        mov     bx,offset sir           ;incarca in BX adr primului sir
        and     al,al                   ;daca AL este zero
        jz      adr4                    ;salt la adr4 (in BX este adr sirului
                                        ;0)
        mov     cl,al                   ;pune in CX nr sirului din AL
        mov     ch,0
        xor     al,al                   ;face AL=0 (referinta de comparatie)
adr2    cmp     [bx],al                 ;compara continutul locatiei de memorie
                                        ;cu adresa data de BX cu AL
        je      adr3                    ;daca egalitate salt la adr3
        inc     bx                      ;altfel trece la elementul urmator
        jmp     adr2
adr3    inc     bx                      ;in BX adr de inceput a unui sir si
        loop    adr2                    ;daca nu este cel dorit repeta de la
                                        ;adr2
adr4    pop     ax                      ;reface registrele AX si CX
        pop     cx
        ret
cmp     push    ax                      ;incarca registrele AX si BX
        push    bx
        mov     si,dx                   ;pune adr de inceput a unui sir de
                                        ;comparat in SI
reia    losb                            ;pune in AL un octet al sirului
        cmp     [bx],al                 ;compara un octet al celui de-al doilea
                                        ;sir de comparat cu AL satind fanioanele
        je      egal                    ;daca egalitate salt la egal
        pop     bx
        pop     ax                      ;reface registrele AX si BX
        ret
egal    inc     bx                      ;trece la elementul urmator
        jmp     reia
schimb  push    ax                      ;conserva AX si CX
        push    cx
reit    mov     si,dx                   ;incarca in SI si DI adr sirului de
        mov     di,dx                   ;transferat
        lodsb                           ;incarca in AL octetul de la adr SI
        mov     cx,offset  start-1
        sub     cx,dx                   ;incarca pe CX cu diferenta dintre
                                        ;inceputul sirului sisfirsitul zonei
                                        ;de date
        repnz   movsb                   ;transfera toti octetii din aceasta zona
        stosb                           ;pune in ultima locatie a zonei de
                                        ;date octetul din AL
        cmp     al,0                    ;compara daca s-a ajuns la sfirsitul sir
        je      ies                     ;daca da,salt la ies
        jmp     reit                    ;altfel salt la reit
ies     pop     cx                      ;reface CX si AX
        pop     ax
        ret
        call    schimb                  ;altfel aplel schimb
        mov     cx,nrsir                ;pregateste CX pentru reluare
        inc     cx                      ;iteratii de la inceput
adr1    loop    bucla                   ;repeta programul pina la ultimul sir
        int     20h                     ;revenire in DOS
calcad  push    cx                      ;consrva registrele CX si AX
        push    ax
        mov     bx,offset  sir          ;incarca in BX adr primului sir
        and     al,al                   ;daca AL este 0
        jz      adr4                    ;salt la adr4
