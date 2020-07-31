/*
 * Grafica in TurboC de Profesor Octavian Aspru
 * Editura ADIAS Rm Valcea 1994
 */
/*
 * linerel
 * deseneaza un segment de dreapta de la punctul curent pina
 * la o distanta data relativ fata de pozitia curenta a
 * cursorului  grafic.
 * cursorul grafic va fi pozitionat la capatul liniei avind
 * coordonatele determinate de distnatele dx si dy fata de pozitia
 * initiala a sa.
*/
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

int main(void)
{
	int gdriver = DETECT, gmode, errorcode;
	char msg[80];
	initgraph(&gdriver, &gmode, "H:\\borlandc\\bgi");
	errorcode = graphresult();
	if (errorcode != grOk)
	{
		printf("Eroare grafica: %s\n",grapherrormsg(errorcode));
		getch();
		exit(1);
	}
	/* muta pozitia curenta (CP) la locati (20,30) */
	moveto(20,30);
	sprintf(msg," (%d,%d)",getx(),gety());
	outtextxy(20,30,msg);
	/* deseneaza o liniee la o distanta relativa */
	linerel(100,100);
	sprintf(msg," (%d,%d)",getx(),gety());
	outtext(msg);
	getch();
	closegraph();
	return 0;
}