/*
 * Grafica in TurboC de Profesor Octavian Aspru
 * Editura ADIAS Rm Valcea 1994
 */
/*
 * setbkcolor
 * selecteaza culoarea de fond curenta a paletei utilizate
 */
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

int main(void)
{
	int gdriver = EGA, gmode = EGAHI, errorcode;
	int bkcol, maxcolor, x, y;
	char msg[80];
	initgraph(&gdriver, &gmode, "H:\\borlandc\\bgi");
	errorcode = graphresult();
	if (errorcode != grOk)
	{
		printf("Eroare grafica: %s\n", grapherrormsg(errorcode));
		getch();
		exit(1);
	}
	/* indexul maximum de culoarea suportat */
	maxcolor = getmaxcolor();
	settextjustify(CENTER_TEXT, CENTER_TEXT);
	x = getmaxx()/2;
	y = getmaxy()/2;
	/* bucla prin intermediul culorilor disponibile */
	for (bkcol = 0;bkcol <=maxcolor; bkcol++)
	{
		cleardevice();
		/* selectarea unei noi culori de fond */
		setbkcolor(bkcol);
		if (bkcol == WHITE)
			setcolor(EGA_BLUE);
		sprintf(msg, "Culoare de fond: %d", bkcol);
		outtextxy(x,y,msg);
		getch();
	}
	closegraph();
	return 0;
}