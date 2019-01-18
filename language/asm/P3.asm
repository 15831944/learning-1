	org	100h
	mov	ax,cs
	mov	ds,ax
	mov	ax,3
	int	10h			;sterge ecranul
	mov	di,0b1ch
	mov	ah,2
	mov	dx,di
	int	10h			;pozitionare cursor
	mov	si,offset	mesaj
adr1	mov	al,[si]
	mov	bx,0fh
	mov	cx,1
	mov	ah,9
	int	10h			;scrie un caracter
	inc	di
	mov	ah,2
	mov	bh,0
	mov	dx,di
	int	10h			;avans cursor
	inc	si
	cmp	si,offset	endms
	jle	adr1
	int	20h			;terminat program
mesaj		db	'TEST VIDEO'
endms		equ	$
	end.