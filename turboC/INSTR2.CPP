/* citeste un caracter de la tastatura si afiseaza codul ascii
 * foloseste o instructiune while pentru a inroduce mai multe
 * elemente si cind se tasteaza CR se opreste este versiunea
 * imbunatatita a instr1
 */
#include <stdio.h>
#include <ctype.h>
#include <conio.h>

void main(void)
{
	char c;
	clrscr();
	c = 0;
	while (c != '\r') {
		printf("\nApasati o tasta: ");
		c = getche();
		if (isprint(c))
			printf("\nCodul ASCII %X, caracterul %c\n", c, c);
		else
			printf("\nCodul ASCII %X, neafisabil\n", c);
	}
}
