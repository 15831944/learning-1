/*
 * Grafica in TurboC de Profesor Octavian Aspru
 * Editura ADIAS Rm Valcea 1994
 */
/*
 * farmalloc  farfree
 * alocare si dealocare pentru heapul far
 */
#include <stdio.h>
#include <alloc.h>
#include <string.h>
#include <dos.h>

int main(void)
{
	char far *fptr;
	char *str = "Hello";
	fptr = (char far *)farmalloc(10);
	/* movedata este folosita pentru ca poate fi un model de date mic
	* in care caz o subrutina obisnuita nu poate fi folosita deoarece
	* ar presupune ca pointer size este near */
	movedata(FP_SEG(str),FP_OFF(str),FP_SEG(fptr),FP_OFF(fptr),strlen(str));
	printf("Sirul far este: %Fs\n",fptr);
	farfree(fptr);
	return 0;
}