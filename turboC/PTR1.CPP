/*
 * pointeri, pentru vizualizarea adreselor se foloseste functia
 * printf() cu specificatorul "%p", adresele sunt afisate in hexa
 */
#include <stdio.h>

void main(void)
{
	int iv = 10;
	int *iptr;
	printf("\nVariabila iv se afla la adresa %p\n", &iv);
	printf("si are valoarea iv = %d\n", iv);
	iptr = &iv;
	printf("\nVariabila iptr are valoarea %p\n", iptr);
	printf("si adreseaza obiectul: %d\n", *iptr);
	*iptr = 20;
	printf("\nAcum, iv are valoarea %d\n",iv);
}