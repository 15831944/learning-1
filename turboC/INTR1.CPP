/*
 * exemplu ce ilustreaza utilizarea intreruperii SW pentru
 * apelul unei functii DOS 12H pentru citirea atributelor unui fisier
 */
#include <dos.h>
#include <process.h>
#include <stdio.h>

int main(void)
{
	char nm_fis[80];
	union REGS inregs, outregs;
	struct SREGS segregs;
	printf("Nume fisier ? ");
	gets(nm_fis);
	/* inscrie parametrii functiei DOS */
	inregs.h.ah = 0x43;
	inregs.h.al = 0x21;
	inregs.x.dx = FP_OFF(nm_fis);
	segregs.ds = FP_SEG(nm_fis);
	/* apeleaza functia dos */
	int86x(0x21, & inregs, &outregs, &segregs);
	/* afiseaza rezultatul */
	printf("Atribute: %X\n", outregs.x.cx);
	return 0;
}
