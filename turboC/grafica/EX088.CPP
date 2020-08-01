/*
 * Grafica in TurboC de Profesor Octavian Aspru
 * Editura ADIAS Rm Valcea 1994
 */
/*
 * allocmem si _dos_allocmem
 * aloca segmentul de memorie dos
 */
#include <dos.h>
#include <alloc.h>
#include <stdio.h>

int main(void)
{
	unsigned int size, segp;
	int stat;
	size = 64; /* 64 x 16 = 1024 bytes */
	stat = allocmem(size,&segp);
	if (stat == -1)
		printf("allocmem:Alocarea memoriei pentru segment: %x\n",segp);
	else
		printf("allocmem:Priviti: numarul maxim de praragrafe folosite este %u\n",stat);
	stat = _dos_allocmem(size,&segp);
	if (stat == 0)
		printf("_dos_allocmem:Alocarea memoriei pentru segment: %x\n",segp);
	else
		printf("_dos_allocmem:Priviti: numarul maxim de praragrafe folosite este %u\n",stat);

	return 0;
}
