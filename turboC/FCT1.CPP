/* exemplificare functii */
/* declaratii pentru functii din biblioteca */
#include <stdio.h>
/* prtotipuri ale functiilor definite in program */
void afmax(float, float);
/* ... alte prototipuri si declaratii globale pentru date */

void main()
{
	float r1, r2;
	r1 = 10.5;
	r2 = 20.5;
	afmax(r1,r2); /* apelul functiei afmax */
}

/* definitii ale functiilor */
void afmax(float n1, float n2)
{
	float max;
	max = (n1 > n2) ? n1:n2;
	printf("Max = %f; Medie = %f\n", max, (n1+n2)/2);
}