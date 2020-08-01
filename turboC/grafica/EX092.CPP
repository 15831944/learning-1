/*
 * Grafica in TurboC de Profesor Octavian Aspru
 * Editura ADIAS Rm Valcea 1994
 */
/*
 *  farrealloc
 * ajusteaza blocul alocat in heapul far
 */
#include <stdio.h>
#include <alloc.h>
int main(void)
{
	char far *fptr;
	fptr = (char far *)farmalloc(10);
	printf("Prima adresa: %Fp\n",fptr);
	fptr = (char far *)farrealloc(fptr,20);
	printf("Noua adresa: %Fp\n",fptr);
	farfree(fptr);
	return 0;
}