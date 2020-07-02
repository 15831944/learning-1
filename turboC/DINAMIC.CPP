/*
 * functia inval() permite introducerea de la tastatura a unui
 * numar oarecare de valori reale, care sunt prelucrate in
 * main si apoi memoria alocata este eliberata.
 */

#include <stdio.h>
#include <stdlib.h>

int nr;
float *inval(void)
{
	float *ptr;
	int i;
	printf("Precizati numarul de valori (float): ");
	scanf("%d", &nr);
	if (!(ptr = (float *)malloc(sizeof(float)*nr))) {
		puts("Memorie insuficient");
		return NULL;
	}
	for (i = 0; i < nr; i++) {
		printf("Indroduceti valoarea %d ",i);
		scanf("%f", ptr + i);
	}
	return ptr;
}

void main()
{
	float *p;
	int i;
	p = inval();
	/* ... utilizarea tabloului */

	for (i = 0; i < nr; i++)
		printf("%f ", p[i]);
	putchar('\n');
	free(p);
}