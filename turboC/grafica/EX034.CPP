/*
 * Grafica in TurboC de Profesor Octavian Aspru
 * Editura ADIAS Rm Valcea 1994
 */
/*
 * setallpalette
 * modifica toate culorile specificate ale paletei
 * in cazul valorii -1 se mentine culoarea anterioarea
 */
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
int main(void)
{
	int gdriver = DETECT, gmode, errorcode;
	struct palettetype pal;
	int color, maxcolor, ht;
	int y = 10;
	char msg[80];
	initgraph(&gdriver, &gmode, "H:\\borlandc\\bgi");
	errorcode = graphresult();
	if (errorcode != grOk)
	{
		printf("Eroare grafica: %s\n", grapherrormsg(errorcode));
		getch();
		exit(1);
	}
	maxcolor = getmaxcolor();
	ht = 2* textheight("W");
	/* determina o copie a paletei */
	getpalette(&pal);
	/* afisarea paletei de culori implicate */
	for (color = 1; color <= maxcolor; color++)
	{
		setcolor(color);
		sprintf(msg, "Culoare: %d", color);
		outtextxy(1, y, msg);
		y += ht;
	}
	getch();
	/* culorile de iesire negru una cite note */
	for (color = 1; color <= maxcolor; color++)
	{
		setpalette(color, BLACK);
		getch();
	}
	/* restaurarea paletei de culori */
	setallpalette(&pal);
	getch();
	closegraph();
	return 0;
}