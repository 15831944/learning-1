/* exemplu de utilizare culori pe text mode */
#include <conio.h>
void main()
{
	cputs("Afisare cu atribut normal\r\n");
	textattr(BLUE*16|RED);
	highvideo();
	cputs("Afisare cu intensitate mare\r\n");
	getch();
	lowvideo();
	cputs("Afisare cu intensitate redusa\r\n");
	normvideo();
	cputs("Revenire la atributul normal\r\n");
	getch();
}
