/*
 * Grafica in TurboC de Profesor Octavian Aspru
 * Editura ADIAS Rm Valcea 1994
 */
/*
 * freemem si _dos_freemem
 * elibereaza segmentul de memorie dos alocat anterior
 */
#include <dos.h>
#include <alloc.h>
#include <stdio.h>
int main(void)
{
	unsigned int size, segp;
	int stat;
	size = 64; /* 64*16 = 1024 bytes */
	stat = allocmem(size,&segp);
	if (stat <0)
		printf("S-a alocat segmentul de memorie: %x\n",segp);
	else
		printf("Negresit: numarul maxim de pragrafe disponibile este %u\n",stat);
	freemem(segp);
	return 0;
}