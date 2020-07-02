/* genrator de numere pseudoaleatoare prima varianta cu definirea in
 * interiorul unui singur fisier
 */
#include <stdio.h>
#define M 2796203
#define A 125
#define C 0
/* generator pseudoaleator */
unsigned long vaunf(void)
{
	static unsigned long va = 98761234;
	va = (A*va+C) %M;
	return va;
}

/* exemplu de utilizare */
void main()
{
	float tva[100];
	int i;
	/* inscrierea unui tablou de valori aleatoare subunitare */
	for (i = 0 ; i < 100; i ++)
		printf("%8.6f ", tva[i] = vaunf()/(float)M);
}