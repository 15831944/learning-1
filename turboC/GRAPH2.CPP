/*
 * se afiseaza pe ecran o coloana de text si este salvata intr-un
 * tablou. La apasarea unei taste se sterge ecranul, apoi se
 * reface textul initial si, in final, se dubleaza coloana de text
 */
#include <stdlib.h>
#include <conio.h>

void main()
{
	char *buf, i;
	clrscr();
	for(i = 1; i < 25; i++) {
		gotoxy(10,i);
		cprintf("Linia nr: %2d", i);
	}
	gotoxy(10,i);
	cputs("Apasa o tasta");
	getch();
	buf=(char *)malloc(25*13*2);
	gettext(10,1,22,25,buf);
	clrscr();
	gotoxy(10,10);
	cputs("Apasa o tasta");
	getch();
	clrscr();
	puttext(10,1,22,25,buf);
	getch();
	puttext(30,1,42,25,buf);
	getch();
	clrscr();
}