/*
 * Grafica in TurboC de Profesor Octavian Aspru
 * Editura ADIAS Rm Valcea 1994
 */
/*
 * setpalette
 * modifica o culoare a paletei
 */
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
int main(void)
{
	int gdriver = DETECT, gmode, errorcode;
	int color, maxcolor, ht;
	int y = 10;
	char msg[80];
	initgraph(&gdriver,&gmode, "H:\\borlandc\\bgi");
	errorcode = graphresult();
	if (errorcode != grOk)
	{
		printf("Eroare grafica: %s\n", grapherrormsg(errorcode));
		getch();
		exit(1);
	}
	maxcolor = getmaxcolor();
	ht = 2*textheight("W");
	/* afiseaza culorile implicite */
	for (color = 1; color <= maxcolor; color++)
	{
		setcolor(color);
		sprintf(msg,"Culoarea: %d", color);
		outtextxy(1,y, msg);
		y+=ht;
	}
	getch();
	/* permite iesirea culorilor una cite una */
	for (color = 1; color <= maxcolor; color++)
	{
		setpalette(color, BLACK);
		getch();
	}
	closegraph();
	return 0;
}