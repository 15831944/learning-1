/* exemmplu de utilizarea functiilor grafice in consola */
#include <stdio.h>
#include <conio.h>

void main(void)
{
	char str[103], *txt, i;
	cputs("Introduceti un text ( <= 100 de caractere): \r\n");
	/* inscrie numarul de caractere maxim */
	str[0] = 100;
	/* citeste textul, memoreaza in txt adresa */
	txt = cgets(str);
	cprintf("\r\nTextul are %d caractere.\r\n", str[1]);
	cprintf("Textul este: %s \r\n", txt);
	cputs("Si este memorat sub formaa:\r\n");
	for(i=0; str[i]; i++)
		cprintf("%2X ",str[i]);
	 /* afiseaza terminatorul \0 */
	 cprintf("%X\r\n",str[i]);
	 getch(); /* asteapta apasarea unei taste */
}