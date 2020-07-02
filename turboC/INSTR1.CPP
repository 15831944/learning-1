/* instructiuni de decizie citeste de la tastura si face conversia */
#include <stdio.h>
#include <ctype.h>
#include <conio.h>

void main()
{
	char c;
	clrscr();
	printf("Apasati o tasta: ");
	c = getche();
	if (isprint(c))
		printf("\nCodul ASCII %X, caracterul %c\n", c,c);
	else
		printf("\nCodul ASCII %X neafisabil\n",c);
}
