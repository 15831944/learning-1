/*
 * Grafica in TurboC de Profesor Octavian Aspru
 * Editura ADIAS Rm Valcea 1994
 */
/*
 * rectangle
 * deseneaza conturul unui dreptunghi
 * utilizeaza pentru desenarea dreptunghiului culoarea, stilul de
 * linie si grosimea curente
 * pozitia cursorului grafic nu este modificata
 */
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

int main(void)
{
	int gdriver = DETECT, gmode, errorcode;
	int left, top, right, bottom;
	initgraph(&gdriver,&gmode, "H:\\borlandc\\bgi");
	errorcode = graphresult();
	if (errorcode != grOk)
	{
		printf("Eroare grafica: %s\n",grapherrormsg(errorcode));
		getch();
		exit(1);
	}
	left = getmaxx()/2 - 50;
	top = getmaxy()/2 - 50;
	right = getmaxx()/2 + 50;
	bottom = getmaxy()/2 + 50;
	rectangle(left, top, right, bottom);
	getch();
	closegraph();
	return 0;
}