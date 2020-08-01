/*
 * Grafica in TurboC de Profesor Octavian Aspru
 * Editura ADIAS Rm Valcea 1994
 */
/*
 * coreleft
 * intoarce marimea meloriei nefolosite
 * pentru  modelele tiny, small si medium returneaza unsigned
 * pentru modelelecompact, large si huge returneaza unsigned long
 */
#include <stdio.h>
#include <alloc.h>
int main(void)
{
	printf("Diferenta intre blocul superior alocat si\n");
	printf("virful heapului este : %lu octeti\n",(unsigned long) coreleft());
	return 0;
}