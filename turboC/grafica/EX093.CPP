/*
 * Grafica in TurboC de Profesor Octavian Aspru
 * Editura ADIAS Rm Valcea 1994
 */
/*
 * farcoreleft
 * intoarce marimea memoriei nefolosite in heapul far
 */
#include <stdio.h>
#include <alloc.h>
int main(void)
{
	printf("Diferenta dintre cel mai inalt bloc alocat in heapul far\n");
	printf("si virful heapului far este : %lu octeti\n",farcoreleft());
	return 0;
}