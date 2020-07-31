/*
 * Grafica in TurboC de Profesor Octavian Aspru
 * Editura ADIAS Rm Valcea 1994
 */
/*
 * line
 * deseneaza un segment de dreapta intre doua puncte specificate
 * pozitia cursorului dupa desenarea liniei ramina nemodificata
 */
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
int main(void)
{
	int gdriver = DETECT, gmode, errorcode;
	int xmax, ymax;
	initgraph(&gdriver,&gmode, "H:\\borlandc\\bgi");
	errorcode = graphresult();
	if (errorcode != grOk)
	{
		printf("Eroare grafica: %s\n", grapherrormsg(errorcode));
		getch();
		exit(1);
	}
	setcolor(getmaxcolor());
	xmax = getmaxx();
	ymax = getmaxy();
	line(0,0,xmax,ymax);
	getch();
	closegraph();
	return 0;
}