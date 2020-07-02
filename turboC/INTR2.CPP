/* exemplu de intreruperi hardware */
#include <stdio.h>
#include <dos.h>
#include <conio.h>
#define INTR 0X1C
/* pointer de functie interrupt */
void interrupt (*ssi_sist)(...);

int cont = 0; /* contor de timp */
/* subrutina de service a intreruperilor */
void interrupt ssi_apl(...)
{
	/* incrementeaza contorul global */
	cont++;
	ssi_sist();
	/* apelul subrutinei DOS */
}

void main(void)
{
	/* memoreaza adresa DOS */
	ssi_sist=getvect(INTR);
	/* instaleaza subrutina aplicatie */
	setvect(INTR,ssi_apl);
	/* afiseaza valoarea contorului pina la apasarea unei taste */
	while(!kbhit())
		printf(" %d", cont);
	/* restabileste adresa DOS */
	setvect(INTR, ssi_sist);
}