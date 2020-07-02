/* fisierul aplicatie testrnd.cpp */
#include <stdio.h>
/* include genrnd.h aflat in directorul curent */
#include "genrnd.h"
#define NR 10
void main()
{
	float tva[NR];
	int i;
	vainit();
	/* inscrierea unui tablou cu valori aleatoare subunitare */
	for (i = 0; i < NR; i++)
		printf("%8.6f ", tva[i] = vaunf()/(float)M);
	putchar('\n');
}