/*
 * programul afiseaza codul ASCII al caracterului introdus de la
 * tastatura in hexa si apoi in binar
 */

#include <stdio.h>
#include <conio.h>

void main()
{
	char c,b,i;
	printf("Introduceti un caracter: ");
	c = getche();
	/* afisare cod ascii */
	printf("\n%c = %#x = ", c,c);
	/* ciclu de afisare a codului binar */
	i = 7;
	while (i >= 0) {
		b = c>>i & 1;
		printf("%d",b);
		i--;
	}
	putchar('\n');
}